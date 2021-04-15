#ifndef AGGREGATOR_H
#define AGGREGATOR.H 

#include <Arduino.h>

template<class T>
class ReadValues{
    public:
        ReadValues(int);
        void append(T value);
        uint8_t get_size(){
            return this->size;
        };
        float mean();
    private:
        T *buffer;
        uint8_t size;
};

template<class T>
ReadValues<T>::ReadValues(int x){
    this->size = x;
    buffer = new T[size];
}

template<class T>
void ReadValues<T>::append(T value){
    for(int i = this->size - 1; i > 0; i--){
        this->buffer[i] = this->buffer[i - 1];
    }
    this->buffer[0] = value;
}

template<class T>
float ReadValues<T>::mean(){
    T sum = 0;
    for(int i = 0; i < this->size; i++) {
        sum += this->buffer[i];
    }
    return float(sum) / size;
}

#endif