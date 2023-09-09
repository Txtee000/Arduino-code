int led1= 7;
int led2= 3;
int led3 = 4;
int led4 = 5;
int sensor1= 12;
void setup() {
pinMode(led1 , OUTPUT);
pinMode(led2 , OUTPUT);
pinMode(led3 , OUTPUT);
pinMode(led4 , OUTPUT);
pinMode(sensor1 , INPUT);
Serial.begin(9600);
}

void loop() {
int result = digitalRead(sensor1);
Serial.println(result);
if(result == 1){
  digitalWrite(led1 , LOW);
  digitalWrite(led2 , LOW);
  digitalWrite(led3 , LOW);
  digitalWrite(led4 , LOW);
  delay(500);
  digitalWrite(led1 , HIGH);
  delay(500);
  digitalWrite(led2 , HIGH);
  delay(500);
  digitalWrite(led3 , HIGH);
  delay(500);
  digitalWrite(led4 , HIGH);
  delay(500);
  digitalWrite(led4 , LOW);
  delay(500);
  digitalWrite(led3 , LOW);
  delay(500);
  digitalWrite(led2 , LOW);
  delay(500);
  digitalWrite(led1 , LOW);
}
else{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}
}
