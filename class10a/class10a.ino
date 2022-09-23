#define GREEN_LED D0
#define ORANGE_LED D1
#define RED_LED D2  
void setup() {
  pinMode(GREEN_LED,OUTPUT);
  pinMode(ORANGE_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
  digitalWrite(GREEN_LED,LOW);
  digitalWrite(ORANGE_LED,LOW);
  digitalWrite(RED_LED,LOW);
  Serial.begin(115200);

}

void loop() {
  digitalWrite(GREEN_LED,HIGH);
//  Serial.println("GREEN LED ON");
  delay(3000);
  digitalWrite(GREEN_LED,LOW);
  digitalWrite(ORANGE_LED, HIGH);
  delay(500);
  digitalWrite(ORANGE_LED, LOW);
  digitalWrite(RED_LED,HIGH);
  delay(3000);
  digitalWrite(RED_LED,LOW);
  
  
  

}
