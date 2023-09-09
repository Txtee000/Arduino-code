#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
#include <FirebaseESP32.h>

char auth[] = "ZhG_wZHJBOXdmJCu813m6oGSppr753xZ"; 
char ssid[] = "suwatpl_2.4G";
char pass[] = "5687862020";

#define FIREBASE_HOST "https://project-59b5a-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "VwXav4ljahDGDiUjoW16GzIFqxox65tMVvJnMtTB"

BlynkTimer timer;
Servo myservo;

FirebaseData firebasedata;
FirebaseJson json;
FirebaseJson turnOn;
FirebaseJson resultPot;

int pot = 34;
int value1;

void setup(){
  Blynk.begin(auth, ssid, pass);
  myservo.attach(16);
  pinMode(pot,OUTPUT);
  Serial.begin(9600);

  
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {

    Serial.print(".");
    delay(300);
  }
  Serial.print("Wifi connected");
  Serial.print("IP Adress : ");
  Serial.print(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebasedata, 1000 * 60);

  Firebase.setwriteSizeLimit(firebasedata, "tiny");
  Serial.println("------------------------------------");
  Serial.println("Connected...");
}
void loop(){
  Blynk.run();
  value1 =  analogRead(pot);
  Serial.println(value1);
  delay(500);
  Blynk.virtualWrite(V10, value1);
  Firebase.updateNode(firebasedata, "/resultPot", resultPot);
  resultPot.set("/pot",value1);
}

BLYNK_WRITE(V1){
  int pinValue = param.asInt();
  if(pinValue == 1)
    {
    myservo.write(0);
    Firebase.updateNode(firebasedata, "/turnOn", turnOn);
    turnOn.set("/servo",1);
    delay(1000);
    myservo.write(90);
    } 
  else
    {
    myservo.write(0);
    Firebase.updateNode(firebasedata, "/turnOn", turnOn);
    turnOn.set("/servo",0);
    }
}
