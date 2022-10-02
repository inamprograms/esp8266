
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
const char *Wifi_network_ssid = "Inam ul Rehman";
const char *Wifi_network_password = "in123456";

const char*mqtt_broker = "broker.mqttdashboard.com";
const char *topic = "topicFahim";
const char *user_name = "test";
const char *user_password= "test";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);
void setup() {

  Serial.begin(115200);
 Serial.println("Connecting To network: ");
  Serial.print(Wifi_network_ssid);
  WiFi.begin(Wifi_network_ssid,Wifi_network_password);
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
Serial.println("Message End");
  }
