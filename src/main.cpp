#include <Arduino.h>

#include <processors/transformer.h>

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  float raw_signal = analogRead(A0);

  float processed_signal = ScaleTransformer :: transform(raw_signal);
}