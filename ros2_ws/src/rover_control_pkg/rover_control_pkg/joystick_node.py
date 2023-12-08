import rclpy
from rclpy.node import Node
from rover_interfaces.msg import MotorControl
import evdev
from evdev import InputDevice, categorize, ecodes

class JoystickNode(Node):
    def __init__(self, device_path='/dev/input/event2'):
        super().__init__('joystick_node')

        self.publisher_ = self.create_publisher(MotorControl, 'motor_control_topic', 10)
        self.timer_ = self.create_timer(0.15, self.callback_robot_news)
        self.get_logger().info('Joystick node has been started')
        self.speed = 50
        self.direction = 'stop'

        # Create an event device object for the joystick
        self.joystick_device = InputDevice(device_path)

        # Define axis and button mappings (modify these based on your joystick)
        self.axis_mappings = {
            ecodes.ABS_X: 'X',
            ecodes.ABS_Y: 'Y',
            # Add other axis mappings as needed
        }

        self.button_mappings = {
            ecodes.BTN_A: 'Button A',
            ecodes.BTN_B: 'Button B',
            # Add other button mappings as needed
        }

    def joystick_control(self):
        self.direction = 'stop'
        for event in self.joystick_device.read():
            if event.type == ecodes.EV_ABS:
                if event.code in self.axis_mappings:
                    if event.code == ecodes.ABS_X:                        
                        if event.value < 100:
                            self.direction = 'left' 
                        elif event.value > 140:
                            self.direction = 'right' 

                    if event.code == ecodes.ABS_Y:                        
                        if event.value < 100:
                            self.direction = 'forward' 
                        elif event.value > 140:
                            self.direction = 'backward' 
                        

            elif event.type == ecodes.EV_KEY:
                if event.code in self.button_mappings:
                    if event.value == 1:  # Button pressed
                        # Implement button-specific logic
                        pass

    def callback_robot_news(self):
        self.joystick_control()

        joystick_msg = MotorControl()
        joystick_msg.speed = self.speed
        joystick_msg.direction = self.direction
        self.publisher_.publish(joystick_msg)

def main(args=None):
    rclpy.init(args=args)
    node = JoystickNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
