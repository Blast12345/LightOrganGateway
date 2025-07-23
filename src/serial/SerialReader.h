#pragma once

#include <Arduino.h>
#include <optional>

using std::optional;
using std::nullopt;

class SerialReader {
    HardwareSerial *serial;

public:
    explicit SerialReader(HardwareSerial &serial) : serial(&serial) {}
    
    auto getNextLine() const -> optional<String> {
        if (serial->available() == 0) {
            return nullopt;
        }
        
        return serial->readStringUntil('\n');
    }
};
