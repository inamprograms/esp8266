#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>
const char *Wifi_network_ssid = "Inam ul Rehman";
const char *Wifi_network_password = "in123456";
WiFiClient client;
HTTPClient http;
String payload;

#define GREEN_LED D0
#define ORANGE_LED D1
#define RED_LED D2 
 
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
  
  pinMode(GREEN_LED,OUTPUT);
  pinMode(ORANGE_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
  
  digitalWrite(GREEN_LED,LOW);
  digitalWrite(ORANGE_LED,LOW);
  digitalWrite(RED_LED,LOW);
  
 

}

void loop() {
  digitalWrite(GREEN_LED,HIGH);
//  Serial.println("GREEN LED ON");
  http.begin(client,"b37q1-nodemcu.herokuapp.com",80,"/change/green/");
  http.GET();
  payload = http.getString();
  Serial.println(payload);
  http.end();
  delay(10000);
  
  digitalWrite(GREEN_LED,LOW);
  digitalWrite(ORANGE_LED, HIGH);
  http.begin(client,"b37q1-nodemcu.herokuapp.com",80,"/change/orange/");
  http.GET();
  payload = http.getString();
  Serial.println(payload);
  https.end();
  delay(3000);
  
  digitalWrite(ORANGE_LED, LOW);
  digitalWrite(RED_LED,HIGH);
  http.begin(client,"b37q1-nodemcu.herokuapp.com",80,"/change/red/");
  http.GET();
  payload = http.getString();
  Serial.println(payload);
  http.end();
  delay(10000);
  digitalWrite(RED_LED,LOW);
  

}
