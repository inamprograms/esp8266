#include <DHT.h>



#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include<Wire.h>

#include<ESP8266WiFi.h>

const char* ssid = "Inam ul Rehman";
const char* password = "in123456";
WiFiClient client;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
float temp, hum;
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

void setup() {
  //task 1: set temp , hum on oled display
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC,0x3c);
//  display.clearDisplay();
//  display.setTextSize(1);
//  display.setTextColor(WHITE);
//  display.setCursor(10,15);
//  display.println("Hello world");
//  display.display();

  pinMode(DHTPIN,INPUT);
  dht.begin();

   Serial.println("Connection to Wifi");
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
      delay(1000);
      Serial.print("*");    
    }
  Serial.println();
  Serial.println("Wifi Connected");
  Serial.println(WiFi.localIP());
  
  
}

void loop() {
//  for(int x=0 ; x<64;x++)
//{
//  display.clearDisplay();
//  display.setTextSize(1);
//  display.setTextColor(WHITE);
//  display.setCursor(x,32);
//  display.println("Hello world");
//  display.display();
//  }
  
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20,0);
  display.print("Temp: ");
  display.println(temp);
  display.setCursor(40,20);
  display.print("hum: ");
  display.println(hum);
    display.setCursor(20,30);
  display.print("IP: ");
  display.println(WiFi.localIP());
display.display();
Serial.print(temp);


}
