#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ROSPiNav2/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_ROSPiNav2_geometry_msgs_Twist> Sub_ROSPiNav2_136;

// For Block ROSPiNav2/Subscribe1
extern SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_ROSPiNav2_sensor_msgs_Joy> Sub_ROSPiNav2_137;

void slros_node_init(int argc, char** argv);

#endif
