#include <LiquidCrystal_I2C.h>
#include<ESP8266WiFi.h>
int col = 16;
int row = 2;


const char* ssid = "Inam ul Rehman";
const char* password = "in123456";
WiFiClient client;
LiquidCrystal_I2C lcd(0x27,col,row);
void setup() {
  lcd.init();
  lcd.backlight();

  Serial.println("Connecting to Wifi");
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
//  lcd.setCursor(0,0);
//  lcd.print("Hello World");
//  delay(1000);
//  lcd.clear();//clear before setting cursor
//  lcd.setCursor(0,1);
//  lcd.print("Hello World");
//  delay(1000);
//  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print(WiFi.localIP());

}
