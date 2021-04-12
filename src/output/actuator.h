#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <Arduino.h>
#include <output/signal.h>

template<class T>
class Actuator{
    public:
        Actuator(unint8_t id)
        void setValue(Signal<T> value);
        Signal<T> getvalue();
        uint8_t getId();
        void execute();
    private:
        bool hasToChange;
        Signal<T> value;
        unint8_t id
        virtual void write(Signal<T> value);
};

template<class T>
Actuator<T>::Actuator(uint8_t id){
    this->id = id;
}

template<class T>
void Actuator<T>::setValue(Signal<T> value){
    
}

template<class T>
uint8_t Actuator<T>::getId(){
    return this-> value;   
}



#endif