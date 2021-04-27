#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include <sensors/read.h>
#include <entities/value.h>

template<class T>
class Sensor{
    public:
        Sensor(uint8_t id);
        Value<T> getValue();
        bool hasChanged();
        uint8_t getId();
        void execute ();
    private:
        bool changed;
        T raw_value;
        Value<T> value;
        uint8_t id;
        virtual T read();
};

template<class T>
Sensor<T>::Sensor(uint8_t id){
    this->id = id;
} 

template<class T>
Value<T> Sensor<T>::getValue(){
    this->changed = false;
    return this->value;
}

template<class T>
bool Sensor<T>::hasChanged(){
    return this-> changed;
}

template<class T>
uint8_t Sensor<T>::getId(){
    return this-> value;   
}

template<class T>
void Sensor<T>::execute(){
    T new_value = this->read();
    if (new_value != this->raw_value){
        this->changed = true;
        this->raw_value = new_value;
        this->value = Value<T>(new_value, this->id);
    }
}

#endif