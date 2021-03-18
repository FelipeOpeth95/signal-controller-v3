#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <Arduino.h>

template<class T>
    T scaler(T input, float scale){
        float value = map(input,0, 1023,0, 14);
        return T(value * scale)
    }

#endif