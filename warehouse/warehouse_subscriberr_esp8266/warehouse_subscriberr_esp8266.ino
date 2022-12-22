#include <ESP8266WiFi.h>
#include <PubSubClient.h>
WiFiClient esp8266_client;
PubSubClient client(esp8266_client);
const char *WIFI_SSID = "Inam ul Rehman";
const char *WIFI_PASS = "in123456";
const char *mqtt_server = "broker.mqttdashboard.com";
const int mqtt_port = 1883;
String client_id = "ESP8266" + String(WiFi.macAddress());
const char *user_name = "inamul";
const char *user_password = "12345678";
const char *topic = "warehouse_topic";

void callback(char *topic, byte *payload, unsigned int length){
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("*] *");
    for(int i=0; i<length; i++){
       Serial.print((char)payload[i]);
      }
      Serial.println();
      if((char)payload[0] == '1'){
        digitalWrite(12,HIGH);
        }
      else if((char)payload[0] == '0'){
         digitalWrite(12,LOW);
        }
    }
void setup() {
   Serial.begin(9600);
   pinMode( 12,OUTPUT); //D6
   connect_ToWifi();
   client.setServer(mqtt_server,mqtt_port);
   client.setCallback(callback);
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
    if(client.connect(client_id.c_str(),user_name,user_password)){
        Serial.println("client connected");
        client.subscribe(topic); 
        Serial.print(topic);
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
  
 if (!client.connected()) {
    reconnect();
  }
 client.loop();

}
