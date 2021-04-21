#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include <Arduino.h>

#include <sensors/sensor.h>

class AnalogSensor : public Sensor<float> {
    public:
        AnalogSensor(uint8_t id, uint8_t pin):Sensor<float>(id){
        this->pin = pin;
        };
    private:
        uint8_t pin;
        float read();
};

float AnalogSensor::read() {
    return analogRead(this->pin);
}

#endif