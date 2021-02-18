#ifndef ALARM_H
#define ALARM.H 

#include <Arduino.h>

namespace AlarmOutput{
    float activate_alarm(float input){
        if (input < 6.2 && input > 7.2){
            analogWrite(pin_LED, true);
            delay(100);
        }
    }
}
#endif