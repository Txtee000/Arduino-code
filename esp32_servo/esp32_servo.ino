#include <ESP32Servo.h>
Servo myservo;
void setup() {
myservo.attach(15);
Serial.begin(9600);
}

void loop() {
Serial.println();
myservo.write(0);
delay(1000);
myservo.write(90);
delay(1000);
}
