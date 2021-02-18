#include <Arduino.h>

#include <processors/transformer.h>

#include <processors/aggregator.h>

void setup() {
}

void loop() {
  float raw_signal = analogRead(A0);

  float processed_signal = ScaleTransformer :: transform(raw_signal);

  float aggregated_value = Aggregator :: averageWindow(processed_signal)
}