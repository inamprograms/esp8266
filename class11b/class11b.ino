#include "DHT.h"
#define DHT_PIN D4 // pin 2     
#define DHTTYPE DHT11   
DHT dht(DHT_PIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(DHT_PIN,INPUT);
  dht.begin();
}

void loop() {
  
  delay(2000);

  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
//  float f = dht.readTemperature(true);
  
//  if (isnan(h) || isnan(t) || isnan(f)) {
//    Serial.println(F("Failed to read from DHT sensor!"));
//    return;
//  }

 
//  float hif = dht.computeHeatIndex(f, h);
//  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temperature: ");
  Serial.println(t);
//  Serial.print("°C ");
//  Serial.println(f);
//  Serial.print("°F  Heat index: ");
//  Serial.println(hic);
//  Serial.print("°C ");
//  Serial.println(hif);
//  Serial.println(F("°F"));
}
