import rclpy
from rclpy.node import Node
from rover_interfaces.msg import MotorControl
import RPi.GPIO as GPIO

class MotorControl(Node):
    def __init__(self):
        super().__init__("motor_control_node")
        self.subscriber_ = self.create_subscription(
            MotorControl, 'motor_control_topic', self.motor_callback, 10)
        self.get_logger().info("Motor control subscriber node has been started")

    def motor_callback(self, msg):
        speed = msg.speed
        direction = msg.direction

        # Process the received message and control your DC motor here
        self.get_logger().info('Received motor control command: speed=%d, direction=%d' % (speed, direction))
        # Add your motor control logic based on the received message

        # ... (Rest of your motor control logic)

def main(args=None):
    rclpy.init(args=args)
    node = MotorControl()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
