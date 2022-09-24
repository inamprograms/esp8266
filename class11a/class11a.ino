const int trigPin = 12; // D5
const int echoPin = 14; //D6

#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);

}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin , HIGH);
  distanceCm =  duration * SOUND_VELOCITY/2;
  distanceInch =  distanceCm * CM_TO_INCH;

  Serial.print("Distance: (cm) ");
  Serial.println(distanceCm);
  Serial.print("Distance: (Inch) ");
  Serial.println(distanceInch);

  delay(2000);

}
