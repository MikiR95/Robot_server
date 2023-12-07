// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rover_interfaces:msg/MotorControl.idl
// generated code does not contain a copyright notice

#ifndef ROVER_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__STRUCT_HPP_
#define ROVER_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rover_interfaces__msg__MotorControl __attribute__((deprecated))
#else
# define DEPRECATED__rover_interfaces__msg__MotorControl __declspec(deprecated)
#endif

namespace rover_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorControl_
{
  using Type = MotorControl_<ContainerAllocator>;

  explicit MotorControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0ll;
      this->direction = "";
    }
  }

  explicit MotorControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : direction(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0ll;
      this->direction = "";
    }
  }

  // field types and members
  using _speed_type =
    int64_t;
  _speed_type speed;
  using _direction_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _direction_type direction;

  // setters for named parameter idiom
  Type & set__speed(
    const int64_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__direction(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->direction = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rover_interfaces::msg::MotorControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const rover_interfaces::msg::MotorControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rover_interfaces::msg::MotorControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rover_interfaces::msg::MotorControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rover_interfaces::msg::MotorControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rover_interfaces::msg::MotorControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rover_interfaces::msg::MotorControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rover_interfaces::msg::MotorControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rover_interfaces::msg::MotorControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rover_interfaces::msg::MotorControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rover_interfaces__msg__MotorControl
    std::shared_ptr<rover_interfaces::msg::MotorControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rover_interfaces__msg__MotorControl
    std::shared_ptr<rover_interfaces::msg::MotorControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorControl_ & other) const
  {
    if (this->speed != other.speed) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorControl_

// alias to use template instance with default allocator
using MotorControl =
  rover_interfaces::msg::MotorControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rover_interfaces

#endif  // ROVER_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__STRUCT_HPP_
