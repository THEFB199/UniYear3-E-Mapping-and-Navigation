
%% Read in image -- IMAGE TAKEN AT START
TopCamImage = imread("TopCamSnap.png");

%% would go around this secion applying Rubbish dection network designed by Jordan
% Apply mask to get only rubbish and ignore crabs
[BW, Filtered] = RubbishMask(TopCamImage);
Filled = imfill(BW, 'holes');
Opened_Disk = imopen(Filled,strel('disk',5));
Opened_Rectangle = imopen(Filled,strel('rectangle',[3,15]));

% currently only looking for disks and rectangels in the image
Combined = imbinarize(Opened_Disk + Opened_Rectangle);
Regions = regionprops(Combined,'Centroid','BoundingBox');

%% Get robot position - Currently assuming on the right hand side of image mid way down.
% this is also where the trash drop off is
imsize = size(Combined);
RobotStart = [(imsize(1)/2),imsize(2)];

%% Show the image
imshow(TopCamImage);
hold on;
for i = 1:length(Regions) 
rectangle('Position', Regions(i).BoundingBox,'EdgeColor','r','LineWidth',2);
plot(uint32(Regions(i).Centroid(1)),uint32(Regions(i).Centroid(2)), 'r+', 'MarkerSize', 15, 'LineWidth', 2);
end
plot(RobotStart(2),RobotStart(1), 'r+', 'MarkerSize', 15, 'LineWidth', 2);
%% Calculate best items to go to first
Distances = [];

for i = 1:length(Regions) 
    Distance(i) = sqrt((RobotStart(1)^2-Regions(i).Centroid(1)^2)+(RobotStart(2)^2-Regions(i).Centroid(2)^2)); %#ok aware size changes
end

%% Example output for matlab of the order (index number with distance)

for i = 1:(length(Distance)-1)
    [Goal, Pos] = max(Distance); % show the index pos and distance
    Distance(Pos) = 0;
    Centroid = Regions(Pos).Centroid; % show the centroid to head to 
    disp(['Distance: ', num2str(Goal) , ' Centroid Cordinated X: ', num2str(Centroid(1)), ' Y: ', num2str(Centroid(2))]); 
end

%% Setup ROS Network Link

%%% PLEASE NOTE THIS WILL NOT WORK WITHOUT A FUNCTIONING ROS NETWORK


% Here we are setting the goals in sequence so that the robot will got to
% the goal, return to the rubbish drop off point then go back out to the
% next point. The waterline is dealt with using the cost map and if the
% robot can not get to the goal then the next item will be tried.

[client,PoseMsg] = rosactionclient('/move_base_simple/goal');
waitForServer(client)
Rejected = 0; % useful for tracking errors
for i = 1:(length(Distance)-1) % loop through rubbish in section
    
    [Goal, Pos] = max(Distance);
    Distance(Pos) = 0; % set to 0 so it is no longer the max distance away
    
    PoseMsg.Point.X = Regions(Pos).Centroid(1);
    PoseMsg.Point.Y = Regions(Pos).Centroid(2);
    Quaternion.W = 0; %way out so set forward so bucket if facing the object
    
    [resultMsg,resultState] = sendGoalAndWait(actClient,goalMsg,10);
    
    if (resultState == ('aborted' || 'rejected')) %#ok These are ros message returns too
        Rejected = Rejected + 1;
    
    end
end

