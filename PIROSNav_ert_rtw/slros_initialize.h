#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block PIROSNav/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_PIROSNav_geometry_msgs_Twist> Sub_PIROSNav_21;

// For Block PIROSNav/Subscribe1
extern SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_PIROSNav_sensor_msgs_Joy> Sub_PIROSNav_110;

void slros_node_init(int argc, char** argv);

#endif
