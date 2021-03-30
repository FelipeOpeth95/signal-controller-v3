#include <Arduino.h>
#include <settings.h>

#include <processors/transformer.h>
#include <processors/aggregator.h>

#include <sensors/analog_sensor.h>

AnalogSensor sensor = AnalogSensor(0x7E, A0);

float kp = 100;
float kd = 10;
float ki = 0.0005;
float setpoint = 45;

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
    float transformed_read = PID<float>(scaled_read, kp, ki, kd, setpoint);
  }
}