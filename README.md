#AnalogKeryboard Library
This library is intended to convert analog signals coming from the ESP32-LAB PCB keyboard into independent keys, but it can also be used in other analog keyboard circuits with the appropriate parameter settings in the object constructor.

## AnalogKeyboard object constructor
The AnalogKeyboard library is already pre-adjusted for the ESP32-LAB board keyboard, but with a simple adjustment at the moment of instance of the AnalogKeyboard object, this library can serve another model of analog keyboards.

###The parameters are:
- pinKeyboard: Pin for analog reading of the keyboard circuit (Required);
- addressKey0: Analog address of key 0;
- addressKey1: Analog address of key 1;
- addressKey2: Analog address of key 2;
- addressKey3: Analog address of key 3;
- addressKey4: Analog address of key 4;
- ReadingAccuracy: Value in percentage to adjust the recognition accuracy of the analog reading of each key.

###Example: