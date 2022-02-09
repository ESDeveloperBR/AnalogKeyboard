/**
 * @file AnalogKeyboard.h
 * @author Eder Joao Santini (ederjsantini@gmail.com)
 * @brief Class responsible for converting the analog keyboard reading into independent keys.
 * @version 0.2.2
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __ANALOGKEYBOARD_h
#define __ANALOGKEYBOARD_h

#include "Arduino.h"

/**
* @brief Class responsible for converting the analog keyboard reading into independent keys.
*/
class AnalogKeyboard {
    private:    
        uint8_t  _pinKeyboard;      // Keyboard read pin 
        uint16_t _addressKey[5];    // Key analog address
        boolean  _keyPress[5] = {false, false, false, false, false};      // Checks if the key is pressed
        boolean  _keyRelease[5] = {true, true, true, true, true};      // Checks if the key is release
        uint8_t  _readingAccuracy;  // Reading accuracy over established analog values
    
    public:
        /**
        * @brief Construct a new Analog Keyboard:: Analog Keyboard object
        * 
        * @param pinKeyboard Pin for analogue reading of the keyboard circuit (Required);
        * @param addressKey0 Analog address of key 0;
        * @param addressKey1 Analog address of key 1;
        * @param addressKey2 Analog address of key 2;
        * @param addressKey3 Analog address of key 3;
        * @param addressKey4 Analog address of key 4;
        * @param readingAccuracy Value in percentage to adjust the recognition accuracy of the analog reading of each key.
        */
        AnalogKeyboard(uint8_t pinKeyboard, uint16_t addressKey0 = 0, uint16_t addressKey1 = 870, uint16_t addressKey2 = 1657, uint16_t addressKey3 = 2457, uint16_t addressKey4 = 3322, uint8_t readingAccuracy = 20 );
 
        /**
        * @brief HOLD key method.
        * 
        * @param key Number of selected key;
        * @return boolean 
        */
        boolean hold(uint8_t key);

        /**
         * @brief Method PRESS the key.
         * 
         * @param key Number of selected key;
         * @return boolean 
         */
        boolean press(uint8_t key);

        /**
         * @brief Method RELEASE the key.
         * 
         * @param key Number of selected key;
         * @return boolean 
         */
        boolean release(uint8_t key);
};

#endif
