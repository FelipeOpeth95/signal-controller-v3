#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <Arduino.h>


template<class T>
    T scaler(T input){
        float value = map(input,0, 1023,0, 45);
        return T(value);
    }


class PID{
    public:
        PID(float kp, float kd, float ki, float setpoint);    
        float output(float value);
        void set_point(float setpoint);
    private:
        float kp;
        float kd;
        float ki;
        float setpoint;
        float previous_time;
        float last_error;      
};

PID::PID(float kp, float kd, float ki, float setpoint = 45){
    this->kp = kp;
    this->kd = kd;
    this->ki = ki;
    this->last_error = 0;
    this->previous_time = millis();
    this->setpoint = setpoint;
}

void PID::set_point(float setpoint){
    this->setpoint = setpoint;
} 

float PID::output(float value){
    float current_time = millis();
    float elapsed_time = current_time - previous_time;

    float error = setpoint - value;
    float acum_error = error + (error * elapsed_time);

    float rate_error = (error - last_error)/elapsed_time;

    float output = kp*error + ki*acum_error + kd*rate_error;

    this-> last_error = error;
    this-> previous_time = current_time;
        
    return output;
}

#endif