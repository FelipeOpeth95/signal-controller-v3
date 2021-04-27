#ifndef VELOCITY_H
#define VELOCITY_H

#include <Arduino.h>
#include <entities/value.h>

class Velocity : public Value<float>{
    public:
        Velocity():Value(){};
        Velocity(float value, uint8_t source):Value(value, source){};
};
    
#endif