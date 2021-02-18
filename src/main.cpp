#include <Arduino.h>

#include <processors/transformer.h>

#include <processors/aggregator.h>

int pin_LED = 9;

void setup() {
  pinMode(pin_LED, OUTPUT); 
}

void loop() {
  float raw_signal = analogRead(A0);


  float processed_signal = ScaleTransformer :: transform(raw_signal);

  float aggregated_value = Aggregator :: averageWindow(processed_signal);

  float alarm = AlarmOutput :: activate_alarm(processed_signal);
}