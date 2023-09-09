#include <Servo.h>
Servo myservo;
int sensor1 = 11;
void setup() {
myservo.attach(13);
pinMode(sensor1 , INPUT);
Serial.begin(9600);
}

void loop() {
int value = digitalRead(sensor1);
Serial.println(value);
if (value == 1){
  myservo.write(90);
  delay(1000); 
} 
else{
  myservo.write(0);
  delay(1000);
}
}
