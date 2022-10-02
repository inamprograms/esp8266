#include "DHT.h"
#define DHT_PIN D4 // pin 2     
#define DHTTYPE DHT11   
#include <LiquidCrystal_I2C.h>
DHT dht(DHT_PIN, DHTTYPE); //show IP at LCD also
int col = 16;
int row = 2;
LiquidCrystal_I2C lcd(0x27,col,row);
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(DHT_PIN,INPUT);
  dht.begin();

}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("## Temp:");
  lcd.print(t);
  lcd.setCursor(0,1);
  lcd.print("## Hum:");
  lcd.print(h);
  lcd.print(" ##");
  delay(1000);
  lcd.clear();

  Serial.println(t);

}
