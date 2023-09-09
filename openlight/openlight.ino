int A = 7;
int B = 9;
int C = 10;
int D = 11;
int R = A0;
void setup() {
  // put your setup code here, to run once:
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(R,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int n = analogRead(R);
Serial.println(n);

if(n>=1000){
  digitalWrite(D,HIGH);
}
else if(n>=750){
  digitalWrite(C,HIGH);
}
else if(n>=500){
  digitalWrite(B,HIGH);
}
else if(n>=250){
  digitalWrite(A,HIGH);
}
else{
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
}
}
