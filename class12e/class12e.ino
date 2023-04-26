#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <WiFiManager.h>
//const char *Wifi_network_ssid = "";
//const char *Wifi_network_password = "";

const char*mqtt_broker = "broker.mqttdashboard.com";
const char *topic = "topicFahim";
const char *user_name = "test";
const char *user_password= "test";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

WiFiManager wifiManager;
void setup() {

  Serial.begin(115200);
  
  wifiManager.autoConnect("AutoConnectAP");
  Serial.println(WiFi.SSID());
  Serial.println(WiFi.psk());
  
  Serial.println("Connecting To network: ");
//  Serial.print(Wifi_network_ssid);
//  WiFi.begin(Wifi_network_ssid,Wifi_network_password);
  WiFi.begin(WiFi.SSID(),WiFi.psk());
  while(WiFi.status() != WL_CONNECTED){
    Serial.print("<");
    delay(1000);
    Serial.println("<con>");
    }
  Serial.println("Connected To WiFi network.");
  Serial.print("Ip: ");
  Serial.println(WiFi.localIP());


client.setServer(mqtt_broker,mqtt_port);
client.setCallback(callback);
String client_id = "ESP8266" + String(WiFi.macAddress());
client.connect(client_id.c_str(),user_name,user_password);
client.subscribe(topic);  
 

}

void loop() {
  client.loop();

}

void callback(char *topic,byte *payload,unsigned int length)

{
  Serial.println("Broker Topic");
  Serial.println(topic);
  Serial.println("Broker Message");
  for(int i=0; i<length; i++){
    Serial.print((char) payload[i]);
    }
Serial.println();   
Serial.println("Message End");
  }
