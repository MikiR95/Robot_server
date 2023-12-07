// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rover_interfaces:msg/MotorControl.idl
// generated code does not contain a copyright notice

#ifndef ROVER_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__STRUCT_H_
#define ROVER_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'direction'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MotorControl in the package rover_interfaces.
typedef struct rover_interfaces__msg__MotorControl
{
  int64_t speed;
  rosidl_runtime_c__String direction;
} rover_interfaces__msg__MotorControl;

// Struct for a sequence of rover_interfaces__msg__MotorControl.
typedef struct rover_interfaces__msg__MotorControl__Sequence
{
  rover_interfaces__msg__MotorControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rover_interfaces__msg__MotorControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROVER_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__STRUCT_H_
