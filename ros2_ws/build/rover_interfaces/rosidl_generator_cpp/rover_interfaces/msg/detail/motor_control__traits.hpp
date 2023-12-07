// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rover_interfaces:msg/MotorControl.idl
// generated code does not contain a copyright notice

#ifndef ROVER_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__TRAITS_HPP_
#define ROVER_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rover_interfaces/msg/detail/motor_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rover_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorControl & msg,
  std::ostream & out)
{
  out << "{";
  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorControl & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rover_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rover_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rover_interfaces::msg::MotorControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  rover_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rover_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rover_interfaces::msg::MotorControl & msg)
{
  return rover_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rover_interfaces::msg::MotorControl>()
{
  return "rover_interfaces::msg::MotorControl";
}

template<>
inline const char * name<rover_interfaces::msg::MotorControl>()
{
  return "rover_interfaces/msg/MotorControl";
}

template<>
struct has_fixed_size<rover_interfaces::msg::MotorControl>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rover_interfaces::msg::MotorControl>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rover_interfaces::msg::MotorControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROVER_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__TRAITS_HPP_
