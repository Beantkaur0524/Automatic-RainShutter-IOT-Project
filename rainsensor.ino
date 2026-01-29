#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "realme 5i";
const char* password = "sranshaab";

// Pin connected to the rain sensor (analog pin)
const int rainSensorPin = 35;

// LEDC channel connected to the built-in LED on the ESP32
const int ledChannel = 0;

void setup() {
  // Initialize the Serial Monitor
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Configure LEDC for controlling the built-in LED
  /*ledcSetup(ledChannel, 5000, 8);  // LEDC channel, frequency, resolution
  ledcAttachPin(2, ledChannel);*/

  pinMode(2,OUTPUT);
}

void loop() {
  // Read the rain sensor value
  int rainValue = analogRead(rainSensorPin);

  // Print the sensor value to the Serial Monitor
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  // Map the rain sensor value to the LEDC brightness range (0-255)
  int brightness = rainValue;

 if(rainValue < 2500){
  digitalWrite(2, HIGH);
 }
 else{
 digitalWrite(2,LOW);
  }

  // Delay before the next reading
  delay(1000);
}
