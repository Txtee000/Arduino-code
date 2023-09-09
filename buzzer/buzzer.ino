int buzz1 = 5;
void setup() {
pinMode(buzz1 , OUTPUT);
}

void loop() {
digitalWrite(buzz1 , HIGH);
delay(500);
digitalWrite(buzz1 , LOW);
delay(500);
}
