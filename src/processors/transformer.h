#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <Arduino.h>


template<class T>
    T scaler(T input){
        float value = map(input,0, 1023,0, 45);
        return T(value);
    }

template<class T>
class PID{
    public:
        PID();    
        float PID_output(T value);
    private:
        float kp = 100;
        float kd = 10;
        float ki = 0.0005;
        float setpoint = 45;
        float previous_time = 0;
        float last_error = 0;      
};

template<class T>
float PID<T>::PID_output(T value){
    float current_time = millis();
    float elapsed_time = current_time - previous_time;

    float error = setpoint - value;
    float acum_error = error + (error * elapsed_time);

    float rate_error = (error - last_error)/elapsed_time;

    float output = kp*error + ki*acum_error + kd*rate_error;

    float last_error = error;
    float previous_time = current_time;
        
    return T(output);
}

    // T PID(T input){
    //     float current_time = millis();
    //     float elapsed_time = current_time - previous_time;

    //     float error = setpoint - input;
    //     float acum_error = error + (error * elapsed_time;

    //     float rate_error = (error - last_error)/elapsed_time;

    //     float output = kp*error + ki*acum_error + kd*rate_error;

    //     float last_error = error;
    //     float previous_time = current_time;
        
    //     return T(output)
    // }

#endif