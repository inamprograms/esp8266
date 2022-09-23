#include<ESP8266WiFi.h>
#define GREEN_LED D0
#define ORANGE_LED D1
#define RED_LED D2 
WiFiServer server(80);
const char *Wifi_network_ssid = "Inam ul Rehman";
const char *Wifi_network_password = "in123456";
void setup() {
  pinMode(GREEN_LED,OUTPUT);
  pinMode(ORANGE_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
  digitalWrite(GREEN_LED,LOW);
  digitalWrite(ORANGE_LED,LOW);
  digitalWrite(RED_LED,LOW);
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
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if(!client){
    return;
    }
  while(!client.available()){
    delay(1);
    }
  Serial.println("New client");
  String request = client.readStringUntil('\r');


  client.println("Hi");
  digitalWrite(GREEN_LED,HIGH);
  Serial.println(request);
  client.flush();
  client.println("GREEN");
  delay(10000);
  digitalWrite(GREEN_LED,LOW);
  digitalWrite(ORANGE_LED, HIGH);
  Serial.println(request);
  client.flush();
  client.println("ORANGE");
  delay(5000);
  digitalWrite(ORANGE_LED, LOW);
  digitalWrite(RED_LED,HIGH);
  Serial.println(request);
  client.flush();
  client.println("RED");
  delay(10000);
  digitalWrite(RED_LED,LOW);

}
