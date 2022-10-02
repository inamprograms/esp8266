#include <Wire.h>
byte error,address;
int nDevices;
void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Scanner");
}

void loop() {

  Serial.println("Scan start...");
  nDevices = 0;
  for(address =1; address<127; address++){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if(error == 0){
      Serial.println("Device found");
      Serial.println(address,HEX);
      nDevices++;
      }
    }
    delay(5000);
}
