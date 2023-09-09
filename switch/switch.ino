int sw = 8;
int led1 = 7;
int led2 = 3;
void setup() {
Serial.begin(9600);
pinMode(led1 , OUTPUT);
pinMode(led2 , OUTPUT);
pinMode(sw , INPUT_PULLUP);
}
void loop() {
int value = digitalRead(sw);

if(value == 0){
  digitalWrite(led1 , HIGH);
  digitalWrite(led2 , HIGH);
  Serial.println("Led on");
}
else{
  digitalWrite(led1 , LOW);
  digitalWrite(led2 , LOW);
  Serial.println("Led off");

}
}
