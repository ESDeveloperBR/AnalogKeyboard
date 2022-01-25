#include "AnalogKeyboard.h"

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Constructor >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/* #Creates the object to be used as Keyboard and assigns the pin to which the analog readings will be taken.
- pinKeyboard: Pin for analog reading of keyboard circuit;
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







boolean AnalogKeyboard::hold(uint8_t key){
    uint16_t readValue = analogRead(_pinKeyboard);
    uint16_t toleranceValue = _addressKey[key] * (float(_readingAccuracy) / 100);

    /*
    if(readValue != 4095){
        Serial.print("key: ");
        Serial.println(key);

        Serial.print("readValue: ");
        Serial.println(readValue);

        Serial.print("_addressKey[key]: ");
        Serial.println(_addressKey[key]);

        Serial.print("toleranceValue: ");
        Serial.println(toleranceValue);

        Serial.print("ValorMenor: ");
        Serial.println(_addressKey[key] - toleranceValue);

        Serial.print("ValorMaior: ");
        Serial.println(_addressKey[key] + toleranceValue);

        Serial.println("-----------");
    }
    */

    if( ((_addressKey[key] - toleranceValue) <= readValue )  &&  ( readValue <= (_addressKey[key] + toleranceValue) )  ) { 
        return true;
    }
    return false;
}

