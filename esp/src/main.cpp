#include <Arduino.h>
#include "HardwareSerial.h"

// UART 0 is using by computer.

// definie custom UART ports to use.
#define RXD2 16
#define TXD2 17

HardwareSerial espSerial(2);

void setup()
{
  Serial.begin(9600);

  espSerial.begin(115200, SERIAL_8N1, RXD2, TXD2);

  delay(1000);
  Serial.write("ESP32: Loopback program started");
}
void loop()
{
  if (espSerial.available())
  {
    String message = espSerial.readString();
    Serial.print(". ");
    Serial.println(message);
    if (message == "1")
    {
      Serial.println("ESP32:__SMOKE__");
    }
  }
}