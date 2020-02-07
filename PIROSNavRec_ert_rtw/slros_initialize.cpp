#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "PIROSNavRec";

// For Block PIROSNavRec/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_PIROSNavRec_geometry_msgs_Twist> Sub_PIROSNavRec_21;

// For Block PIROSNavRec/Subscribe1
SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_PIROSNavRec_sensor_msgs_Joy> Sub_PIROSNavRec_110;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

