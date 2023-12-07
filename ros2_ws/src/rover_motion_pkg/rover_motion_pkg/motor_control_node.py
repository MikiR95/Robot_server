import rclpy
from rclpy.node import Node
from rover_interfaces.msg import MotorControl
import RPi.GPIO as GPIO

class MotorControl(Node):
    def __init__(self):
        super().__init__("motor_control_node")
        self.subscriber_ = self.create_subscription(MotorControl, 'motor_control_topic', self.motor_callback, 10)
        self.get_logger().info("Motor control subscriber node has been started")

        GPIO.setmode(GPIO.BCM)
        GPIO.setwarnings(False)

        # Front Motor
        self.F_in1_R = 5
        self.F_in2_R = 6
        self.F_in3_L = 13
        self.F_in4_L = 19
        self.F_enA_R = 12
        self.F_enB_L = 16
        GPIO.setup(self.F_enA_R, GPIO.OUT)
        GPIO.setup(self.F_enB_L, GPIO.OUT)
        GPIO.setup(self.F_in1_R, GPIO.OUT)
        GPIO.setup(self.F_in2_R, GPIO.OUT)
        GPIO.setup(self.F_in3_L, GPIO.OUT)
        GPIO.setup(self.F_in4_L, GPIO.OUT)
        GPIO.output(self.F_in1_R, GPIO.LOW)
        GPIO.output(self.F_in3_L, GPIO.LOW)
        GPIO.output(self.F_in4_L, GPIO.LOW)

        self.pFR = GPIO.PWM(self.F_enA_R, 1000)
        self.pFR.start(25)

        self.pFL = GPIO.PWM(self.F_enB_L, 1000)
        self.pFL.start(25)

        # Rear Motor
        self.R_in1_R = 4
        self.R_in2_R = 7
        self.R_in3_L = 8
        self.R_in4_L = 25
        self.R_enA_R = 20
        self.R_enB_L = 21
        GPIO.setup(self.R_enA_R, GPIO.OUT)
        GPIO.setup(self.R_enB_L, GPIO.OUT)
        GPIO.setup(self.R_in1_R, GPIO.OUT)
        GPIO.setup(self.R_in2_R, GPIO.OUT)
        GPIO.setup(self.R_in3_L, GPIO.OUT)
        GPIO.setup(self.R_in4_L, GPIO.OUT)
        GPIO.output(self.R_in1_R, GPIO.LOW)
        GPIO.output(self.R_in2_R, GPIO.LOW)
        GPIO.output(self.R_in3_L, GPIO.LOW)
        GPIO.output(self.R_in4_L, GPIO.LOW)

        self.pRR = GPIO.PWM(self.R_enA_R, 1000)
        self.pRR.start(25)

        self.pRL = GPIO.PWM(self.R_enB_L, 1000)
        self.pRL.start(25)

    def motor_callback(self, msg):
        msg = MotorControl()
        speed = msg.speed
        direction = msg.direction

        # Process the received message and control your DC motor here
        self.get_logger().info('Received motor control command: speed=%d, direction=%s' % (speed, direction))

        if msg.direction == "stop":  # Stop
            GPIO.output(self.F_in1_R, GPIO.LOW)
            GPIO.output(self.F_in3_L, GPIO.LOW)
            GPIO.output(self.F_in2_R, GPIO.LOW)
            GPIO.output(self.F_in4_L, GPIO.LOW)
            GPIO.output(self.R_in1_R, GPIO.LOW)
            GPIO.output(self.R_in3_L, GPIO.LOW)
            GPIO.output(self.R_in2_R, GPIO.LOW)
            GPIO.output(self.R_in4_L, GPIO.LOW)
        elif msg.direction == "forward":  # Forward
            GPIO.output(self.F_in1_R, GPIO.LOW)
            GPIO.output(self.F_in3_L, GPIO.LOW)
            GPIO.output(self.F_in2_R, GPIO.HIGH)
            GPIO.output(self.F_in4_L, GPIO.HIGH)
            GPIO.output(self.R_in1_R, GPIO.LOW)
            GPIO.output(self.R_in3_L, GPIO.LOW)
            GPIO.output(self.R_in2_R, GPIO.HIGH)
            GPIO.output(self.R_in4_L, GPIO.HIGH)
        elif msg.direction == "backward":  # Backward
            GPIO.output(self.F_in1_R, GPIO.HIGH)
            GPIO.output(self.F_in3_L, GPIO.HIGH)
            GPIO.output(self.F_in2_R, GPIO.LOW)
            GPIO.output(self.F_in4_L, GPIO.LOW)
            GPIO.output(self.R_in1_R, GPIO.HIGH)
            GPIO.output(self.R_in3_L, GPIO.HIGH)
            GPIO.output(self.R_in2_R, GPIO.LOW)
            GPIO.output(self.R_in4_L, GPIO.LOW)
        elif msg.direction == "right":  # Right
            GPIO.output(self.F_in1_R, GPIO.HIGH)
            GPIO.output(self.F_in3_L, GPIO.LOW)
            GPIO.output(self.F_in2_R, GPIO.LOW)
            GPIO.output(self.F_in4_L, GPIO.HIGH)
            GPIO.output(self.R_in1_R, GPIO.HIGH)
            GPIO.output(self.R_in3_L, GPIO.LOW)
            GPIO.output(self.R_in2_R, GPIO.LOW)
            GPIO.output(self.R_in4_L, GPIO.HIGH)
        elif msg.direction == "left":  # Left
            GPIO.output(self.F_in1_R, GPIO.LOW)
            GPIO.output(self.F_in3_L, GPIO.HIGH)
            GPIO.output(self.F_in2_R, GPIO.HIGH)
            GPIO.output(self.F_in4_L, GPIO.LOW)
            GPIO.output(self.R_in1_R, GPIO.LOW)
            GPIO.output(self.R_in3_L, GPIO.HIGH)
            GPIO.output(self.R_in2_R, GPIO.HIGH)
            GPIO.output(self.R_in4_L, GPIO.LOW)

        self.pFR.ChangeDutyCycle(speed)
        self.pFL.ChangeDutyCycle(speed)
        self.pRR.ChangeDutyCycle(speed)
        self.pRL.ChangeDutyCycle(speed)

def main(args=None):
    rclpy.init(args=args)
    node = MotorControl()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
