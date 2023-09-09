int trig = 8;
int echo = 9;
int led1 = 3;
int led2 = 4;
long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);
pinMode(9,INPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig,LOW);
delayMicroseconds(2);

digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

duration = pulseIn(echo,HIGH);
distance = duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
if(distance <= 20){
  digitalWrite(led1 , HIGH);
  digitalWrite(led2 , LOW);
  delay(500);
  digitalWrite(led1 , LOW);
  digitalWrite(led2 , HIGH);
  delay(500);
}
else{
  digitalWrite(led1 , HIGH);
  digitalWrite(led2 , HIGH);
}
}
