#include<ESP8266WiFi.h>
#define led LED_BUILTIN 
unsigned char led_status = 0;
const char* ssid = "Inam ul Rehman";
const char* password = "in123456";

WiFiServer server(80);

//WiFiClient client;
void setup() {
  
  Serial.begin(115200);
  pinMode(led,OUTPUT);
  digitalWrite(led,HIGH);
  Serial.println();
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid); 
  WiFi.begin(ssid,password);
  while(WiFi.status()!=  WL_CONNECTED){
      delay(500);
      Serial.print("<");
      Serial.println("<connecting>");
    }
    
  Serial.println("Connected to WiFi Network");
  Serial.print("IP:");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
    WiFiClient client = server.available();
    if(!client){
//      Serial.println("no client");
      return;
      }
    Serial.println("new client");
   
   while(!client.available()){
     delay(1);
        }
      String request = client.readStringUntil('\r');
      Serial.println(request);
      client.flush();

      if(request.indexOf("/ledoff") != -1){
        led_status = 0;
        digitalWrite(led,HIGH);
        Serial.println("LED OFF");
        }
        else if (request.indexOf("/ledon") != -1){
          led_status = 1;
          digitalWrite(led,LOW);
          Serial.println("LED ON");
          }

      client.println("<h1>hi this is WebServer</h1>");
      client.println("<a href = \"/ledon\"\"> LED ON</button>");
      client.println("<a href = \"/ledoff\"\"> LED OFF</button>");
     
    
    }
  
