#include <ESP32Servo.h>
Servo myservo;  // create servo object to control a servo
Servo myservo1;  // create servo object to control a servo
// 16 servo objects can be created on the ESP32

int pos1 = 0;    // variable to store the servo position
int pos2 = 0;    // variable to store the servo position

// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
int servoPin1 = 32;
int servoPin2 = 18;
int rainsensorPin = 35;
int interval = 2400;

void setup() {
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);    // standard 50 hz servo
  myservo1.setPeriodHertz(50);
  myservo.attach(servoPin1, 500, 2400); // attaches the servo on pin 18 to the servo object
  myservo1.attach(servoPin2, 500, 2400); // attaches the servo on pin 18 to the servo object
  // using default min/max of 1000us and 2000us
  // different servos may require different min/max settings
  // for an accurate 0 to 180 sweep
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int rainValue = analogRead(rainsensorPin);

  // Print the sensor value to the Serial Monitor
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  // Map the rain sensor value to the LEDC brightness range (0-255)
  int brightness = rainValue;

  if (rainValue < 2500) {
    if (pos1 != 180) {
      pos1 = 180;
      pos2 = 180;
      myservo.write(pos1);
      myservo1.write(pos2);
      delay(15);
    }
  } else {
    if (pos1 != 0) {
      pos1 = 0;
      pos2 = 0;
      myservo.write(pos1);
      myservo1.write(pos2);
      delay(15);
    }
  }

  // Delay before the next reading
  delay(1000);
}
