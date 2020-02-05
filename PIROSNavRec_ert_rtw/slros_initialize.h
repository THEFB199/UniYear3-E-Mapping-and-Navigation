#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block PIROSNavRec/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_PIROSNavRec_geometry_msgs_Twist> Sub_PIROSNavRec_21;

void slros_node_init(int argc, char** argv);

#endif
