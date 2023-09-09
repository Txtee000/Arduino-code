#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6xnptUgt_"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_AUTH_TOKEN "ZhG_wZHJBOXdmJCu813m6oGSppr753xZ"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "ZhG_wZHJBOXdmJCu813m6oGSppr753xZ";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "suwatpl_2.4G";
char pass[] = "5687862020";



BlynkTimer timer;
int sw = 34;

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  digitalWrite(25,pinValue);
}
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  digitalWrite(26,pinValue);
}

void setup()
{
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(sw,OUTPUT);
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}
void loop()
{
  Blynk.run();
  int potvalue = digitalRead(sw);
  Blynk.virtualWrite(V2,potvalue);
  Serial.println(potvalue);
}
