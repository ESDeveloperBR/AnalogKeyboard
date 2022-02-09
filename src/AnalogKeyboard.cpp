#include "AnalogKeyboard.h"

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Constructor >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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
boolean AnalogKeyboard::hold(uint8_t key){
    uint16_t readValue = analogRead(_pinKeyboard);
    uint16_t toleranceValue = _addressKey[key] * (float(_readingAccuracy) / 100);

    if( ((_addressKey[key] - toleranceValue) <= readValue )  &&  ( readValue <= (_addressKey[key] + toleranceValue) )  ) { 
        return true;
    }
    return false;
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Press >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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
boolean AnalogKeyboard::release(uint8_t key){
    if( !hold(key) & !_keyRelease[key] ) {
        _keyRelease[key] = true;
        return true;
    } else if(hold(key) & _keyRelease[key] ){
        _keyRelease[key] = false;
    }
    return false;
}