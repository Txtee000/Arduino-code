 #include <ESP32Servo.h>
 Servo myservo;
 Servo myservo2;

 int pot = 14;
 int pot2 = 34;
 
 int value1 = 0;
 int value2 = 0;
 
 
void setup() {
myservo.attach(13);
myservo2.attach(27);
pinMode(pot,OUTPUT);
pinMode(pot2,OUTPUT);
Serial.begin(9600);
}

void loop() {
myservo.write(value1);
myservo2.write(value2);
delay(50);

value1 = analogRead(pot);
value1 = map(value1,0,4095,0,180);
value2 = analogRead(pot2);
value2 = map(value2,0,4095,0,180);
Serial.println(value1);
Serial.println(value2);

}
