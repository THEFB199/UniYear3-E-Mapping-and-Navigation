# E-Mapping

# Summary

- launch files for Rtabmap and freenect on the pi provided in relavant folders.
- Pi4 code to send commands to the botboarduino can be found in the raspberry pi folder

- Currently ros is used witha kinect for RGBD mapping using RTABMap 
- The outputs:
  - localisation information
  - 3D point cloud map of the area
  - 2D occupancy grid of floor
  - Current pose
 
- using remote mapping in this current example http://wiki.ros.org/rtabmap_ros/Tutorials/RemoteMapping

- kinect camera needs to be calibrated, calibraion files can be found in this repo.

# Installation on ROS Computer (ubuntu)
## Note: this is to document the steps taken, all of this has already been completed on the ROS computer

### 1 Please install ros melodic 
http://wiki.ros.org/melodic/Installation/Ubuntu

### 1.1 Put into the bashrc
open nano
``` 
sudo nano ~/.bashrc
```
go to the bottom of the file and append the folowing commands (not ethe ip addresses may need ot be altered)
```
source /opt/ros/melodic/setup.bash
source ~/catkin_ws/devel/setup.bash
export ROS_MASTER_URI=http://158.125.52.50:11311 #this is the ip the master node is running on (the first pc to be roscore'd)
export ROS_IP=1158.125.52.50 #this is the ip of this machine
```

### 2 Current Ros packages required.
#### 2.1 rtabmap
recommeded to build from source to avoid problems https://github.com/introlab/rtabmap_ros#build-from-source

commands from wiki below for ease:
```
sudo apt-get install ros-melodic-rtabmap ros-melodic-rtabmap-ros
sudo apt-get remove ros-melodic-rtabmap ros-melodic-rtabmap-ros

cd ~
git clone https://github.com/introlab/rtabmap.git rtabmap
cd rtabmap/build
cmake ..
make
sudo make install

cd ~/catkin_ws
git clone https://github.com/introlab/rtabmap_ros.git src/rtabmap_ros
catkin_make
```
#### 2.2 Freenect (optional on Ros computer)
some problems were observed so build from source 
https://answers.ros.org/question/313893/unabe-to-install-freenect-in-ros-melodicubuntu-1804/
commands as follows
```
cd  ~    
git clone https://github.com/OpenKinect/libfreenect.git    
cd libfreenect    
mkdir build   
cd build    
cmake -L ..    
make
sudo make install
```
next run the following commands

```
cd ~/catkin_ws/src
git clone https://github.com/ros-drivers/freenect_stack.git
cd ..
catkin_make
```

# Installation on Pi 4 (ubuntu)
## Note this has been done on the SD card kept in the E1 package

- Please use the ubuntu distro for the Pi 4 where a link can be found in E-ProjectDocs
- Please note this will take up to 3 hours to complete

## To install freenect + the dependencies needed 
```
sudo apt update
sudo apt upgrade
sudo apt-get install cmake libudev0 libudev-dev freeglut3 freeglut3-dev libxmu6 libxmu-dev libxi6 libxi-dev
```
```
mkdir -p ~/software/source
cd ~/software/source
wget https://github.com/libusb/libusb/releases/download/v1.0.21/libusb-1.0.21.tar.bz2
tar -jxf libusb-1.0.21.tar.bz2
cd libusb-1.0.21
./configure
make -j1
sudo make install
```
```
cd ..
wget https://github.com/OpenKinect/libfreenect/archive/v0.5.5.tar.gz
tar -xvzf v0.5.5.tar.gz
cd libfreenect-0.5.5
mkdir build
cd build
cmake -L ..
make -j1
sudo make install
```

## To Install rtmap on Pi 4

https://github.com/introlab/rtabmap/wiki/Installation#raspberrypi
```
sudo apt-get install libpcl-dev libopencv-dev cmake libfreenect-dev libopenni2-dev libsqlite3-dev libvtk6-qt-dev
git clone https://github.com/introlab/rtabmap.git rtabmap
cd rtabmap/build
cmake ..
make -j1
sudo make install
sudo ldconfig
Rtabmap

```



