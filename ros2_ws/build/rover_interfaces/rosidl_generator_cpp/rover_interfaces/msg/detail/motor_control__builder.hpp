// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rover_interfaces:msg/MotorControl.idl
// generated code does not contain a copyright notice

#ifndef ROVER_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__BUILDER_HPP_
#define ROVER_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rover_interfaces/msg/detail/motor_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rover_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorControl_direction
{
public:
  explicit Init_MotorControl_direction(::rover_interfaces::msg::MotorControl & msg)
  : msg_(msg)
  {}
  ::rover_interfaces::msg::MotorControl direction(::rover_interfaces::msg::MotorControl::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rover_interfaces::msg::MotorControl msg_;
};

class Init_MotorControl_speed
{
public:
  Init_MotorControl_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorControl_direction speed(::rover_interfaces::msg::MotorControl::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_MotorControl_direction(msg_);
  }

private:
  ::rover_interfaces::msg::MotorControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rover_interfaces::msg::MotorControl>()
{
  return rover_interfaces::msg::builder::Init_MotorControl_speed();
}

}  // namespace rover_interfaces

#endif  // ROVER_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__BUILDER_HPP_
