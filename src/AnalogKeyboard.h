#ifndef __ANALOGKEYBOARD_h
#define __ANALOGKEYBOARD_h

#include "Arduino.h"

class AnalogKeyboard {
    public:
        AnalogKeyboard(uint8_t pinKeyboard, uint16_t addressKey0 = 0, uint16_t addressKey1 = 870, uint16_t addressKey2 = 1657, uint16_t addressKey3 = 2457, uint16_t addressKey4 = 3322, uint8_t readingAccuracy = 20 );
        boolean hold(uint8_t key);
        boolean press(uint8_t key);
        boolean release(uint8_t key);

    private:    
        uint8_t  _pinKeyboard;      // Keyboard read pin 
        uint16_t _addressKey[5];    // Key analog address
        boolean  _keyPress[5] = {false, false, false, false, false};      // Checks if the key is pressed
        boolean  _keyRelease[5] = {true, true, true, true, true};      // Checks if the key is release
        uint8_t  _readingAccuracy;  // Reading accuracy over established analog values

};

#endif
