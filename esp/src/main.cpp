#include <Arduino.h>
#include "HardwareSerial.h"
#include <WiFi.h>
#include <HTTPClient.h>

// Define custom UART ports
#define RXD2 16
#define TXD2 17

// Replace with your network credentials
const char *ssid = "Sweet Home";
const char *password = "F@timaH0meK@zem";

// HTTP POST URL
const char *postUrl = "http://192.168.1.102:3000/api/addSensorRecord";

HardwareSerial espSerial(2);

void setup()
{
  // Initialize Serial communication
  Serial.begin(9600);
  espSerial.begin(115200, SERIAL_8N1, RXD2, TXD2);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");

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

      // Create an HTTPClient object
      HTTPClient http;

      // Start the HTTP POST request
      http.begin(postUrl);
      http.addHeader("Content-Type", "application/json");

      // Create the JSON payload
      String jsonPayload = "{\"sensorId\":\"sensor1\", \"location\":\"ardakan\", \"amount\":200, \"smoke\":true}";

      // Send the POST request and get the response code
      int httpResponseCode = http.POST(jsonPayload);

      // Print the HTTP response code
      if (httpResponseCode > 0)
      {
        Serial.println("HTTP POST Request Sent, Response Code: " + String(httpResponseCode));
      }
      else
      {
        Serial.println("Error in sending POST request: " + String(httpResponseCode));
      }

      // Close the connection
      http.end();
    }
  }
}
