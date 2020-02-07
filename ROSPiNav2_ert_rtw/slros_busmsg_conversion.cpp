#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_ROSPiNav2_geometry_msgs_Twist and geometry_msgs::Twist

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_ROSPiNav2_geometry_msgs_Twist const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertFromBus(&msgPtr->angular, &busPtr->Angular);
  convertFromBus(&msgPtr->linear, &busPtr->Linear);
}

void convertToBus(SL_Bus_ROSPiNav2_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertToBus(&busPtr->Angular, &msgPtr->angular);
  convertToBus(&busPtr->Linear, &msgPtr->linear);
}


// Conversions between SL_Bus_ROSPiNav2_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_ROSPiNav2_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_ROSPiNav2_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_ROSPiNav2_ros_time_Time and ros::Time

void convertFromBus(ros::Time* msgPtr, SL_Bus_ROSPiNav2_ros_time_Time const* busPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->sec =  busPtr->Sec;
  msgPtr->nsec =  busPtr->Nsec;
}

void convertToBus(SL_Bus_ROSPiNav2_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  busPtr->Sec =  msgPtr->sec;
  busPtr->Nsec =  msgPtr->nsec;
}


// Conversions between SL_Bus_ROSPiNav2_sensor_msgs_Joy and sensor_msgs::Joy

void convertFromBus(sensor_msgs::Joy* msgPtr, SL_Bus_ROSPiNav2_sensor_msgs_Joy const* busPtr)
{
  const std::string rosMessageType("sensor_msgs/Joy");

  convertFromBusVariablePrimitiveArray(msgPtr->axes, busPtr->Axes, busPtr->Axes_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->buttons, busPtr->Buttons, busPtr->Buttons_SL_Info);
  convertFromBus(&msgPtr->header, &busPtr->Header);
}

void convertToBus(SL_Bus_ROSPiNav2_sensor_msgs_Joy* busPtr, sensor_msgs::Joy const* msgPtr)
{
  const std::string rosMessageType("sensor_msgs/Joy");

  convertToBusVariablePrimitiveArray(busPtr->Axes, busPtr->Axes_SL_Info, msgPtr->axes, slros::EnabledWarning(rosMessageType, "axes"));
  convertToBusVariablePrimitiveArray(busPtr->Buttons, busPtr->Buttons_SL_Info, msgPtr->buttons, slros::EnabledWarning(rosMessageType, "buttons"));
  convertToBus(&busPtr->Header, &msgPtr->header);
}


// Conversions between SL_Bus_ROSPiNav2_std_msgs_Header and std_msgs::Header

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_ROSPiNav2_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr->frame_id, busPtr->FrameId, busPtr->FrameId_SL_Info);
  msgPtr->seq =  busPtr->Seq;
  convertFromBus(&msgPtr->stamp, &busPtr->Stamp);
}

void convertToBus(SL_Bus_ROSPiNav2_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->FrameId, busPtr->FrameId_SL_Info, msgPtr->frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  busPtr->Seq =  msgPtr->seq;
  convertToBus(&busPtr->Stamp, &msgPtr->stamp);
}

