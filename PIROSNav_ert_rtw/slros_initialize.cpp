#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "PIROSNav";

// For Block PIROSNav/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_PIROSNav_geometry_msgs_Twist> Sub_PIROSNav_21;

// For Block PIROSNav/Subscribe1
SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_PIROSNav_sensor_msgs_Joy> Sub_PIROSNav_110;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

