#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    // waiting for Serial 0 to connect
  }

  Serial1.begin(19200);
  while (!Serial)
  {
    // waiting for Serial1 to connect
  }

  delay(1000);
  Serial.write("Arduino: Loopback program started");
}

void loop()
{
  Serial1.write("--69--");
  Serial.write("--69--");
  delay(3000);
}