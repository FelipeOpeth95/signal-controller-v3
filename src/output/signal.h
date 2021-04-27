#ifndef SIGNAL_H
#define SIGNAL_H

#include <Arduino.h>
#include <entities/value.h>

class Signal : public Value<float> {
    public:
        Signal():Value(){};
        Signal(float value, uint8_t source):Value(value,source){};
};

#endif