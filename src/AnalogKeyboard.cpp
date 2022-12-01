/**
 * @file AnalogKeyboard.cpp
 * @author ESDeveloperBR (esdeveloperbr@gmail.com)
 * @brief Class responsible for converting the analog keyboard reading into independent keys.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "AnalogKeyboard.h"
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Constructor >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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
AnalogKeyboard::AnalogKeyboard(uint8_t pinKeyboard, uint16_t addressKey0, uint16_t addressKey1, uint16_t addressKey2, uint16_t addressKey3, uint16_t addressKey4, uint8_t readingAccuracy) {
    _pinKeyboard     = pinKeyboard;
    _readingAccuracy = readingAccuracy;

    _addressKey[0] = addressKey0;
    _addressKey[1] = addressKey1;
    _addressKey[2] = addressKey2;
    _addressKey[3] = addressKey3;
    _addressKey[4] = addressKey4;
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Hold >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/**
* @brief HOLD key method.
* 
* @param key Number of selected key; 
* @return boolean 
*/
boolean AnalogKeyboard::hold(uint8_t key){
    uint16_t readValue = analogRead(_pinKeyboard);
    uint16_t toleranceValue = _addressKey[key] * (float(_readingAccuracy) / 100);

    if( ((_addressKey[key] - toleranceValue) <= readValue )  &&  ( readValue <= (_addressKey[key] + toleranceValue) )  ) { 
        return true;
    }
    return false;
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Press >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/**
* @brief Method PRESS the key.
* 
* @param key Number of selected key;
* @return boolean 
*/
boolean AnalogKeyboard::press(uint8_t key){
    if( !hold(key) & !_keyPress[key] ) {
        _keyPress[key] = true;
    } else if(hold(key) & _keyPress[key] ){
        _keyPress[key] = false;
        return true;
    }
    return false;
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Release >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/**
* @brief Method RELEASE the key.
* 
* @param key Number of selected key;
* @return boolean 
*/
boolean AnalogKeyboard::release(uint8_t key){
    if( !hold(key) & !_keyRelease[key] ) {
        _keyRelease[key] = true;
        return true;

    } else if(hold(key) & _keyRelease[key] ){
        _keyRelease[key] = false;
    }
    return false;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>