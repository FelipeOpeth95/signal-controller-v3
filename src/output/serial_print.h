#ifndef SERIAL_PRINT.H
#define SERIAL_PRINT.H

#include <Arduino.h>

void serialPrint (Stream &uart, float value, char* label){
    char output[64];
    sprintf(output, "%s -> %d \n", label, int(value));
    uart.print(output);
}
    

#endif