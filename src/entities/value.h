#ifndef VALUE_H
#define VALUE_H

#include <Arduino.h>

template<class T>
class Value {
    public:
        Value();
        Value(T value, uint8_t source);
        uint8_t getSource();
        T getValue();
    private: 
        T value;
        uint8_t source;
};

template<class T>
Value<T>::Value(T value, uint8_t source) {
    this->value = value;
    this->source = source;
}

template<class T> 
Value<T>::Value() {};

template<class T>
T Value<T>::getValue(){
    return this->value;
}

template<class T>
uint8_t Value<T>::getSource() {
    return this->source;
}

#endif