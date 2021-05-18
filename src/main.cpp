#include <Arduino.h>
#include <settings.h>

#include <processors/transformer.h>
#include <processors/aggregator.h>
#include <sensors/analog_sensor.h>
#include <output/signal.h>
#include <output/actuator.h>
#include <output/pump.h>
#include <entities/value.h>
#include <output/alarm.h>
#include <output/serial_print.h>

CircularBuffer<float> read = CircularBuffer<float>(15);
AnalogSensor sensor = AnalogSensor(0x7E, A0);
Pump pump = Pump(0x7F, 9);
PID  pid = PID(10, 5, 0.005, 45);

void setup() {
  Serial.begin(115200);
  pinMode(SETTING::SENSOR_INPUT, INPUT);
  pinMode(SETTING::ACTUADOR_OUTPUT, OUTPUT);

}

void loop() {

  sensor.execute();
   if(sensor.hasChanged()){
    float raw_read = sensor.getValue().getValue();
    float scaled_read = scaler<float>(raw_read);
    read.append(scaled_read);
    float level_mean = read.mean();
    bool signal_alarm = Alarm<float>(level_mean);
    float transformed_read = pid.output(scaled_read);
    pump.setValue(transformed_read);

    //serialPrint(Serial, raw_read, "Lectura potenciometro");
    serialPrint(Serial, scaled_read, "Lectura potenciometro escalada");
    //serialPrint(Serial, level_mean, "Lectura promedio nivel tanque");
    serialPrint(Serial, transformed_read, "Entrada variador");

    //delay(1500);
  }
  pump.excecute(); 
}