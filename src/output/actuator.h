#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <Arduino.h>
#include <output/signal.h>

template<class T>
class Actuator {
    public:
        Actuator(uint8_t id);
        void setValue(Signal<T> value);
        Signal<T> getValue();
        uint8_t getId();
        void excecute();
    private:
        bool hasToChange;
        Signal<T> value;
        uint8_t  id;
        virtual void write(Signal<T> value);
};

template<class T>
Actuator<T>::Actuator(uint8_t id) {
    this->id = id;
};

template<class T>
void Actuator<T>::setValue(Signal<T> value) {
    this->hasToChange = true;
    this->value = value;
};

template<class T>
uint8_t Actuator<T>::getId() {
    return this->id;
};

template<class T>
void Actuator<T>::excecute() {
    if (this->hasToChange) {
        this->write(this->value);
        this->hasToChange = false;
    }
}

template<class T>
Signal<T> Actuator<T>::getValue() {
    return this->value;
};

#endif