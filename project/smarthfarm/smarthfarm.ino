#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6xnptUgt_"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_AUTH_TOKEN "ZhG_wZHJBOXdmJCu813m6oGSppr753xZ"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

char auth[] = "ZhG_wZHJBOXdmJCu813m6oGSppr753xZ";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "suwatpl_2.4G";
char pass[] = "5687862020";


BlynkTimer timer;
DHT dht;

int pinValue = 0;
int pinValue2 = 0;
int soil = 36; //ขา VP
int relay = 14;
int resultSoil = 0;
int humiditySoil = 0;

BLYNK_WRITE(V5){ //auto pump setting
  pinValue = param.asInt(); 
}
BLYNK_WRITE(V0){ //manual pump setting
  pinValue2 = param.asInt(); 
}


void setup()
{
  dht.setup(32);
  pinMode(soil, INPUT);
  pinMode(relay,OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop()
  {
  float temperature = dht.getTemperature();
  float fahrenheit = dht.toFahrenheit(temperature);
  int resultSoil = analogRead(soil);
  int humiditySoil = map(resultSoil,0,4095,1023,0);
  Serial.print("Status Auto=");
  Serial.println(pinValue);
  Serial.print("Status Manual=");
  Serial.println(pinValue2);
  Serial.print("temperature=");
  Serial.println(temperature);
  Serial.print("fahrenheit=");
  Serial.println(fahrenheit);
  Serial.print("humiditySoil=");
  Serial.println(humiditySoil);
   Serial.println("------------------------------");
 
  int resultRelay = digitalRead(relay);
//  Serial.println(resultRelay);
  
  Blynk.virtualWrite(V1, temperature); //รับค่าเพื่ออเเสดงผลใน blynk
  Blynk.virtualWrite(V3, fahrenheit);
  delay(dht.getMinimumSamplingPeriod());

  Blynk.virtualWrite(V4, humiditySoil);
  
//auto pump
if (pinValue == 1 and humiditySoil <= 285){ 
    
    digitalWrite(relay,HIGH);
    }else if(pinValue == 1 and humiditySoil > 285){
      digitalWrite(relay,LOW);  
    }
//manual pump
if (pinValue2 == 1 and pinValue == 0){ 
    digitalWrite(relay,HIGH);
    } 
if  (pinValue2 == 0  and pinValue == 0){
      digitalWrite(relay,LOW);  
    }
  Blynk.run();
}
