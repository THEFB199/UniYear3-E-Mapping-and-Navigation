#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ROSPiNav2";

// For Block ROSPiNav2/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_ROSPiNav2_geometry_msgs_Twist> Sub_ROSPiNav2_136;

// For Block ROSPiNav2/Subscribe1
SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_ROSPiNav2_sensor_msgs_Joy> Sub_ROSPiNav2_137;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

