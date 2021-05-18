#ifndef ALARM_H
#define ALARM_H

#include <Arduino.h>

template<class T>
T Alarm(float value){

        if(value<=45  && value>=40){
            Serial.println("Preacaución: El nivel del tanque está bajando");
            bool activate_alarm = true;  
            return T(activate_alarm);         
        }
        else if(value<=40){
            Serial.println("Alerta: El nivel del tanque está bajo el limite permitido");
            bool activate_alarm = true;
            return T(activate_alarm); 
        }
        else if(value>=45 && value<=50 ){
            Serial.println("El nivel del tanque ");
            bool activate_alarm = false;
            return T(activate_alarm); 
        }   
    }

#endif
