from evdev import InputDevice, ecodes
from time import sleep

device_path = '/dev/input/event2'
device = InputDevice(device_path)

axis_mappings = {
    ecodes.ABS_X: 'X',
    ecodes.ABS_RY: 'RY',
}

def joystick_control():
    
    x_abs_info = device.absinfo(ecodes.ABS_X)
    y_abs_info = device.absinfo(ecodes.ABS_Y)
    r2_key_info = device.absinfo(ecodes.ABS_RZ)
    if x_abs_info.value < 100:
        direction = 'left' 
        print(direction)
    elif x_abs_info.value > 140:
        direction = 'right' 
        print(direction)
    elif y_abs_info.value < 100:
        direction = 'forward' 
        print(direction)
    elif y_abs_info.value > 140:
        direction = 'backward' 
        print(direction)
    else:
        direction = 'stop'
        print(direction)

    if r2_key_info.value > 0:
        print("speed 100")

    
    

    


while True:
#     try:
#         for event in device.read():
#             if event.type == ecodes.EV_ABS:
#                 if event.code in axis_mappings:
#                     if event.code == ecodes.ABS_X:                        
#                         print(f"Axis X: {int(event.code)}")                      
                            

#                     if event.code == ecodes.ABS_RY:                        
#                         print(f"Axis RY: {int(event.code)}")
#                 sleep(1)
                            
                                            

#     except BlockingIOError:        
#         # No data available at the moment, sleep for a short duration
#         print("No data")
#         sleep(1)
#         pass

    joystick_control()
    sleep(1)

