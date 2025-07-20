#include "helpers/Wait.h"
#include <optional>

#include "serial/SerialReader.h"

SerialReader serialReader(Serial);

// cppcheck-suppress unusedFunction
void setup() {
  waitOneSecond(); // Give the device some time to warm up.

  Serial.begin(BAUD_RATE);
  Serial.println("Baud rate set to: " + String(BAUD_RATE));
}

// cppcheck-suppress unusedFunction
void loop() {
  optional<String> nextString = serialReader.getNextString();

  if (nextString) {
    Serial.println("USB Data Received: " + nextString.value());
  }
}
