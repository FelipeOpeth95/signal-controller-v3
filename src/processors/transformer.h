#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <Arduino.h>

template<class T>
    T PID(T input, float kp, float ki, float kd, float setpoint){
        
        float value = map(input,0, 1023,0, 255);
        
        float current_time = millis();
        float elapsed_time = current_time - previous_time;

        float error = setpoint - value;
        float acum_error = error + (error * elapsed_time;

        float rate_error = (error - last_error)/elapsed_time;

        float output = kp*error + ki*acum_error + kd*rate_error;

        float last_error = error;
        float previous_time = current_time;
        
        return T(output)
    }

#endif