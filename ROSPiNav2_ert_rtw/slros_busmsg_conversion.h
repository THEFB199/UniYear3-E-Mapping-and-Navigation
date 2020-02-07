#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>
#include <ros/time.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Header.h>
#include "ROSPiNav2_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_ROSPiNav2_geometry_msgs_Twist const* busPtr);
void convertToBus(SL_Bus_ROSPiNav2_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr);

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_ROSPiNav2_geometry_msgs_Vector3 const* busPtr);
void convertToBus(SL_Bus_ROSPiNav2_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convertFromBus(ros::Time* msgPtr, SL_Bus_ROSPiNav2_ros_time_Time const* busPtr);
void convertToBus(SL_Bus_ROSPiNav2_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convertFromBus(sensor_msgs::Joy* msgPtr, SL_Bus_ROSPiNav2_sensor_msgs_Joy const* busPtr);
void convertToBus(SL_Bus_ROSPiNav2_sensor_msgs_Joy* busPtr, sensor_msgs::Joy const* msgPtr);

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_ROSPiNav2_std_msgs_Header const* busPtr);
void convertToBus(SL_Bus_ROSPiNav2_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);


#endif
