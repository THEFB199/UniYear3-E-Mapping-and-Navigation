#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "PIROSNavRec";

// For Block PIROSNavRec/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_PIROSNavRec_geometry_msgs_Twist> Sub_PIROSNavRec_21;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

