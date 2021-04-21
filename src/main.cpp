#include <Arduino.h>
#include <settings.h>

#include <processors/transformer.h>
#include <processors/aggregator.h>
#include <sensors/analog_sensor.h>
#include <output/signal.h>
#include <output/actuator.h>

CircularBuffer<int> read = CircularBuffer<int>(15);
AnalogSensor sensor = AnalogSensor(0x7E, A0);
//PID<float> pidoutput = 

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
    //float transformed_read = pidoutput. 

  }
}