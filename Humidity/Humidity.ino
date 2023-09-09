#include "DHT.h"
DHT dht;
void setup() {
Serial.begin(9600);
Serial.println();
dht.setup(9);
}

void loop() {
delay(dht.getMinimumSamplingPeriod());
float humidity = dht.getHumidity();
float temperature = dht.getTemperature();

Serial.print(dht.getStatusString());
Serial.print("\t");
Serial.print(humidity, 1);
Serial.print("\t\t");
Serial.print(temperature,1);
Serial.print("\t\t");
Serial.println(dht.toFahrenheit(temperature),1);
}
