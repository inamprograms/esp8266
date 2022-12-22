#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "DHT.h"
#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;
HTTPClient http;

const char* host = "dweet.io";
const char* ssid = "";
const char* password = "";
const int port = 80;

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("<con>");
  }
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
void loop() {
  if(!client.connect(host,port)){
    Serial.println("Failed to connect to dweet.io");
    return;
    }
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  Serial.print("Humidity: ");
  Serial.print(h);
  
  Serial.print(" Temperature: ");
  Serial.println(t);

      String packet = String("GET /dweet/for/homeless-art?temperature=") + String(t) + "&humidity=" + String(h) + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n";
               

    client.print(packet);
//https://www.esp8266.com/viewtopic.php?p=33548
  int timeout = millis() + 5000;
  while (client.available() == 0) {
    if (timeout - millis() < 0) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  while(client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

}
