#ifndef ANALOG_SENSOR.H
#define ANALOG_SENSOR.H

#include <Arduino.h>

#include <sensors/sensor.h>

class AnalogSensor : public Sensor<int> {
    public:
        AnalogSensor(uint8_t id, uint8_t pin):Sensor<int>(id){
        this->pin = pin;
        };
    private:
        uint8_t pin;
        int read();
};

int AnalogSensor::read() {
    return analogRead(this->pin);
}

#endif