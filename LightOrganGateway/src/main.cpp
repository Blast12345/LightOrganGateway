#include "esp-now/BroadcastPeer.h"
#include "esp-now/EspNowWrapper.h"
#include "helpers/Wait.h"
#include <WiFi.h>
#include <esp_now.h>
#include <optional>

#include "serial/SerialReader.h"

SerialReader serialReader(Serial);
// BroadcastPeer broadcastPeer;
// EspNowWrapper espNow;

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
    //   // Forward the data via ESP-NOW.
    //   // Send message via ESP-NOW
    //   // esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *)input.c_str(), input.length());
    //
    //   // if (result == ESP_OK)
    //   // {
    //   //   Serial.println("Sent with success");
    //   // }
    //   // else
    //   // {
    //   //   Serial.println("Error sending the data");
    //   // }
  }
}
