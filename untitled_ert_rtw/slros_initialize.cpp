#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "untitled";

// For Block untitled/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_untitled_geometry_msgs_Twist> Sub_untitled_21;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

