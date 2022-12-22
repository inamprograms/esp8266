#include <WiFi.h>
#include "DHT.h"
#include <PubSubClient.h>
#define DHTPIN 13
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
float humidity;
float temperature;

WiFiClient esp32_client;
PubSubClient client(esp32_client);
const char *WIFI_SSID = "Inam ul Rehman";
const char *WIFI_PASS = "in123456";
const char *mqtt_server = "broker.mqttdashboard.com";
const int mqtt_port = 1883;
String client_id = "ESP32" + String(WiFi.macAddress());
const char *user_name = "inamul";
const char *user_password = "12345678";
const char *topic = "warehouse_topic";

void setup() {
   Serial.begin(9600);
   dht.begin();
   connect_ToWifi();
   client.setServer(mqtt_server,mqtt_port);
  
}
void connect_ToWifi()
{
    WiFi.begin(WIFI_SSID,WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(">");
        delay(50);
        Serial.println("< con >");
    }
    Serial.println("connected to wifi");
    Serial.print("Ip Allowed: ");
    Serial.println(WiFi.localIP());
    
}
void reconnect(){
  while(!client.connected()){
    Serial.println("Attempting MQTT connection...");  
    if(client.connect(client_id.c_str(),user_name,user_password);){
        Serial.println("client connected");
        if(temperature >=18 || humidity >= 100){
          client.publish(topic,"1"); 
        }
      }
      else{
        Serial.print("Failed to connect client ");
        Serial.print(client.state());
        Serial.println("try again in 5 seconds");
        delay(5000);
        }
    }
  
  }
void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("Hum: ");
  Serial.print(humidity);
 if (!client.connected()) {
    reconnect();
  }
  Serial.println("published message");
  if(temperature >=18 || humidity >= 100){
          client.publish(topic,"1"); 
        } 
}
