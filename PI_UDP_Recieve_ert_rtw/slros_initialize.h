#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block PI_UDP_Recieve/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_PI_UDP_Recieve_geometry_msgs_Twist> Sub_PI_UDP_Recieve_153;

void slros_node_init(int argc, char** argv);

#endif
