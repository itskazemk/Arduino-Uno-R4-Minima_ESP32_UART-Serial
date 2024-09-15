// Serial  => usb
// Serial1 => RX/TX

#include <Arduino.h>

int Threshold = 400;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    // waiting for Serial 0 to connect
  }

  Serial1.begin(115200);
  while (!Serial)
  {
    // waiting for Serial1 to connect
  }

  delay(1000);
  Serial.write("Arduino: Loopback program started");
}

void loop()
{
  int sensorValue = analogRead(A0);

  if (sensorValue > Threshold)
  {
    Serial.print(sensorValue);
    Serial.println(" | SMOKE DETECTED!");
    Serial1.write("1");
  }

  Serial1.write("--69--");
  Serial.write("--69--");
  delay(1500);
}