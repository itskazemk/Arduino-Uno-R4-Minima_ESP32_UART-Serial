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

  espSerial.begin(19200, SERIAL_8N1, RXD2, TXD2);

  delay(1000);
  Serial.write("ESP32: Loopback program started");
}
void loop()
{
  if (espSerial.available())
  {
    Serial.write("FROM CUSTOM UART");
    Serial.write(".");
    Serial.println(espSerial.readString());
  }
}