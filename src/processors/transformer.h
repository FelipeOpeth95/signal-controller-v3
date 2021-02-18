#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <Arduino.h>

namespace ScaleTransformer{
    float scale = 0.012;

    float transform(float input){
        float value = map(input,0, 1023,0,14);
        return value * scale;
    }
}

#endif