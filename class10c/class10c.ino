#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>
const char *Wifi_network_ssid = "CAS-SMART";
const char *Wifi_network_password = "agriculture";
WiFiClient client;
WiFiServer server(80);
HTTPClient http;
String payload;
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

  server.begin();

  http.begin(client,"api.openweathermap.org",80,"/data/2.5/weather?q=alaska&appid=93dd6a284d80c18e9331856dd558177f");
  http.GET();
  payload = http.getString();
  Serial.println(payload);
  http.end();

}

void loop() {

  client = server.available();
  if(!client){
    return;
    }
  while(!client.available()){
    delay(1);
    }
  Serial.println("New client");
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.println(payload);
  client.flush();
  delay(10000);  

}
