#include <SoftwareSerial.h>
SoftwareSerial myserial(2, 3);
SoftwareSerial myserial2(4, 5);
int relayPin = 6,input;
int flag=0;
void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  myserial.begin(9600);
}

void loop() {
 if(myserial.available()>1){
  input=myserial.read();
  delay(20);
}
  if(input=='3'){
    digitalWrite(relayPin, HIGH);
    while (input=='3' && flag==0){
    myserial.end();
    myserial2.begin(9600);
    myserial2.println("ATD8802327251;");
    Serial.println("callining1");
    delay(10000);
    myserial2.println("ATH");
    myserial2.end();
    flag=1;
    myserial.begin(9600);
    }
    }
  if(input=='1'){
    digitalWrite(relayPin, LOW);
    while(input=='1' && flag==1){
    myserial.end();
    myserial2.begin(9600);
    myserial2.println("ATD88023227251;");
    Serial.println("callining2");
    delay(10000);
    myserial2.println("ATH");  
    myserial2.end();
    flag=0;  
    myserial.begin(9600);
    }
  }
delay(20);
}
