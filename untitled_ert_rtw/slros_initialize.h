#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block untitled/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_untitled_geometry_msgs_Twist> Sub_untitled_21;

void slros_node_init(int argc, char** argv);

#endif
