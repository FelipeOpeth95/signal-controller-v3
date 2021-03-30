#include <Arduino.h>
#include <settings.h>

#include <processors/transformer.h>
#include <processors/aggregator.h>

#include <sensors/analog_sensor.h>


AnalogSensor sensor = AnalogSensor(0x7E, A0);

void setup() {
  Serial.begin(115200);
  pinMode(SETTING::SENSOR_INPUT, INPUT);
  pinMode(SETTING::ACTUADOR_OUTPUT, OUTPUT);

}

void loop() {

  sensor.execute();

  float raw_signal = analogRead(A0);


}