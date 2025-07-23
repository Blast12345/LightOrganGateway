#include <optional>
#include <WiFi.h>
#include "clients/ClientNetwork.h"
#include "serial/SerialReader.h"

constexpr unsigned DEBUG_DELAY = 5000;
constexpr unsigned WIFI_WARMUP = 1000;

SerialReader *serialReader;
ClientNetwork *clientNetwork;

void setup() {
    delay(DEBUG_DELAY);
    
    Serial.begin(BAUD_RATE);
    Serial.println("Baud rate set to: " + String(BAUD_RATE));
    serialReader = new SerialReader(Serial);
    
    WiFi.mode(WIFI_STA); // NOLINT
    
    /*
     * TODO: ESP-NOW will init successfully without this, but the peer fails to add without.
     * The delay also must be directly in the setup method; including it in the constructor does not seem to work.
     * This is very strange and my research has not yielded any results. Perhaps this is a bug in the ESP-NOW library?
    */
    delay(WIFI_WARMUP);
    
    clientNetwork = new ClientNetwork();
}

void loop() {
    const auto nextLine = serialReader->getNextLine();
    
    if (nextLine) {
        Serial.println("Serial data received: " + *nextLine);
        clientNetwork->broadcast(*nextLine);
    }
}
