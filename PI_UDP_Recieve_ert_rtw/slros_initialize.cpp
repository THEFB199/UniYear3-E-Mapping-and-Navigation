#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "PI_UDP_Recieve";

// For Block PI_UDP_Recieve/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_PI_UDP_Recieve_geometry_msgs_Twist> Sub_PI_UDP_Recieve_153;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

