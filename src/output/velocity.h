#ifndef VELOCITY_H
#define VELOCITY_H

#include <Arduino.h>
#include <output/signal.h>

class Velocity : public Signal<float>{
    public:
        Velocity():Signal(){};
        Velocity(float value):Signal(value){};
};
    
#endif