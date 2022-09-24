#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>
const char *Wifi_network_ssid = "Inam ul Rehman";
const char *Wifi_network_password = "in123456";
WiFiClient client;
HTTPClient http;
String payload;
#define GREEN_LED D0s
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

  http.begin(client,"b37q1-nodemcu.herokuapp.com",80,"/");
  http.GET();
  payload = http.getString();
  Serial.println(payload);
  if(payload == "red" || payload == "RED")
  {
    digitalWrite(RED_LED,HIGH);
    digitalWrite(ORANGE_LED,LOW);
    digitalWrite(GREEN_LED,LOW);
  }
  else if(payload == "orange" || payload == "ORANGE")
  {
    digitalWrite(ORANGE_LED, HIGH);
    digitalWrite(RED_LED,LOW);
    digitalWrite(GREEN_LED,LOW);
  }
  else if(payload == "green" || payload == "GREEN")
  {
    digitalWrite(GREEN_LED,HIGH);
    digitalWrite(ORANGE_LED,LOW);
    digitalWrite(RED_LED,LOW);
  }
  else{
    digitalWrite(GREEN_LED,LOW);
    digitalWrite(ORANGE_LED,LOW);
    digitalWrite(RED_LED,LOW);
    }
  http.end();

  delay(2000);


}
