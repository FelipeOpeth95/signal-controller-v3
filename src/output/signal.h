#ifndef SIGNAL_H
#define SIGNAL_H

#include <Arduino.h>

template<class T>
class Signal {
    public:
        Signal();
        Signal(T value);
        T getValue();
    private:
        T value;
};

template<class T>
Signal<T>::Signal(T value) {
    this->value = value;
}

template<class T>
Signal<T>::Signal() {}

template<class T>
T Signal<T>::getValue() {
    return this->value;
}

#endif