#ifndef PUMP_H
#define PUMP_H

#include <Arduino.h>
#include <output/actuator.h>
#include <output/velocity.h>

class Pump : public Actuator<float> {
    public:
        Pump(uint8_t id, uint8_t pin):Actuator<float>(id){
            this->pin=pin;
        }
    private:
        uint8_t pin;
        void write(float value);
};


void Pump::write(float value) {
    uint8_t discrete_signal = map(value, 0, 775, 0, 255);
    analogWrite(this->pin, discrete_signal);
}

#endif