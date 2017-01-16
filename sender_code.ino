#include <SoftwareSerial.h>
SoftwareSerial myserial(2, 3); //RX and TX of HC-12 module
int trigPin = 5;
int echoPin = 6;
int tank_height; //place the height of the tank here 
int tankTop_level; //distance of the water in tank from the ultrasonic sensor after which you want to turn of the motor 
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
  if(distance == tank_height){ // send '3' to receiver end when the tank gets empty
    myserial.println("3");
    Serial.println("message sent");
  }
  if(distance == tankTop_level){ // send '1' when the water reaches topmost level in tank
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
