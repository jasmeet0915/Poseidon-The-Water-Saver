#include <SoftwareSerial.h>
SoftwareSerial myserial(2, 3);
int trigPin = 5;
int echoPin = 6;
long duration;
int distance;
void setup() {
  Serial.begin(9600);
  myserial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  Serial.println("distance:");
  Serial.print(distance);
  delay(1000);
  if(distance==10){
    myserial.println("3");
    Serial.println("message sent");
  }
  if(distance==5){
    myserial.println("1");
    Serial.println("message sent");
  }
  if(Serial.available()>0){
    String input=Serial.readString();
    myserial.println(input);
  }
if(myserial.available()>1){
  String input=myserial.readString();
  Serial.println(input);
  }
delay(20);
}
