// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rover_interfaces:msg/MotorControl.idl
// generated code does not contain a copyright notice
#include "rover_interfaces/msg/detail/motor_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `direction`
#include "rosidl_runtime_c/string_functions.h"

bool
rover_interfaces__msg__MotorControl__init(rover_interfaces__msg__MotorControl * msg)
{
  if (!msg) {
    return false;
  }
  // speed
  // direction
  if (!rosidl_runtime_c__String__init(&msg->direction)) {
    rover_interfaces__msg__MotorControl__fini(msg);
    return false;
  }
  return true;
}

void
rover_interfaces__msg__MotorControl__fini(rover_interfaces__msg__MotorControl * msg)
{
  if (!msg) {
    return;
  }
  // speed
  // direction
  rosidl_runtime_c__String__fini(&msg->direction);
}

bool
rover_interfaces__msg__MotorControl__are_equal(const rover_interfaces__msg__MotorControl * lhs, const rover_interfaces__msg__MotorControl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // direction
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->direction), &(rhs->direction)))
  {
    return false;
  }
  return true;
}

bool
rover_interfaces__msg__MotorControl__copy(
  const rover_interfaces__msg__MotorControl * input,
  rover_interfaces__msg__MotorControl * output)
{
  if (!input || !output) {
    return false;
  }
  // speed
  output->speed = input->speed;
  // direction
  if (!rosidl_runtime_c__String__copy(
      &(input->direction), &(output->direction)))
  {
    return false;
  }
  return true;
}

rover_interfaces__msg__MotorControl *
rover_interfaces__msg__MotorControl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rover_interfaces__msg__MotorControl * msg = (rover_interfaces__msg__MotorControl *)allocator.allocate(sizeof(rover_interfaces__msg__MotorControl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rover_interfaces__msg__MotorControl));
  bool success = rover_interfaces__msg__MotorControl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rover_interfaces__msg__MotorControl__destroy(rover_interfaces__msg__MotorControl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rover_interfaces__msg__MotorControl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rover_interfaces__msg__MotorControl__Sequence__init(rover_interfaces__msg__MotorControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rover_interfaces__msg__MotorControl * data = NULL;

  if (size) {
    data = (rover_interfaces__msg__MotorControl *)allocator.zero_allocate(size, sizeof(rover_interfaces__msg__MotorControl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rover_interfaces__msg__MotorControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rover_interfaces__msg__MotorControl__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rover_interfaces__msg__MotorControl__Sequence__fini(rover_interfaces__msg__MotorControl__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rover_interfaces__msg__MotorControl__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rover_interfaces__msg__MotorControl__Sequence *
rover_interfaces__msg__MotorControl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rover_interfaces__msg__MotorControl__Sequence * array = (rover_interfaces__msg__MotorControl__Sequence *)allocator.allocate(sizeof(rover_interfaces__msg__MotorControl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rover_interfaces__msg__MotorControl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rover_interfaces__msg__MotorControl__Sequence__destroy(rover_interfaces__msg__MotorControl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rover_interfaces__msg__MotorControl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rover_interfaces__msg__MotorControl__Sequence__are_equal(const rover_interfaces__msg__MotorControl__Sequence * lhs, const rover_interfaces__msg__MotorControl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rover_interfaces__msg__MotorControl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rover_interfaces__msg__MotorControl__Sequence__copy(
  const rover_interfaces__msg__MotorControl__Sequence * input,
  rover_interfaces__msg__MotorControl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rover_interfaces__msg__MotorControl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rover_interfaces__msg__MotorControl * data =
      (rover_interfaces__msg__MotorControl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rover_interfaces__msg__MotorControl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rover_interfaces__msg__MotorControl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rover_interfaces__msg__MotorControl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
