#include <Servo.h>
#include <RTClib.h> // for the RTC

RTC_DS1307 rtc;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

const int TurnONHour1 = 07;
const int TurnONMinute1 =30;

int CurrentHour;
int CurrentMinute;

const int startsystem = 2;


char fba;      
int pos1 = 0;    
int pos2 = 0;
int pos3 = 0;    
int pos4 = 0;
int po5 = 0;    
int ONbutton = 0;
int OFFbutton = 0;
#define ONbuttonPin 4
#define OFFbuttonPin 3

void setup() {
  servo1.attach(9);
  servo2.attach(8);
  servo3.attach(7);
  servo4.attach(6);
  servo5.attach(5);
  Serial.begin(9600);

  rtc.begin();
  pinMode(startsystem, OUTPUT);
}

void TurnOnGrpservo4(){

servo4.write(75);
delay(1000);
servo4.write(1);
delay(100);

 }
 void TurnOnGrpservo2(){

servo2.write(100);
delay(3000);
servo2.write(1);
delay(100);

 }
 void TurnOnGrpservo1(){

servo1.write(50);
delay(1000);
servo1.write(1);
delay(100);

 }

void TurnOffGrpservo3(){

servo3.write(75);
delay(3000);
servo3.write(1);
delay(100);

}

void TurnOffGrpservo5(){

servo5.write(75);
delay(1000);

servo5.write(1);
delay(100);

}

void loop() {
  ONbutton = digitalRead(ONbuttonPin);
  OFFbutton = digitalRead(ONbuttonPin);
  
  fba = Serial.read();
  if (fba == '1'){
    TurnOnGrpservo4();  
    delay(15000);
    TurnOnGrpservo2();
    delay(4000);
    TurnOnGrpservo1();
  }

  if (fba == '2'){
    TurnOnGrpservo1();
    delay(20000);
    TurnOffGrpservo3();
    delay(4000);
    TurnOffGrpservo5();
    delay(1000);

  }
    if (ONbutton == HIGH) {
    TurnOnGrpservo4();  
    delay(15000);
    TurnOnGrpservo2();
    delay(4000);
    TurnOnGrpservo1();
  } 
  
    if (OFFbutton == HIGH) {
    TurnOnGrpservo1();
    delay(20000);
    TurnOffGrpservo3();
    delay(4000);
    TurnOffGrpservo5();
    delay(1000);
  } 
  
    DateTime now = rtc.now();
    CurrentHour = now.hour();
    CurrentMinute = now.minute();
  Serial.println(CurrentHour);
  Serial.println(CurrentMinute);
  if((CurrentHour==TurnONHour1) && (CurrentMinute == TurnONMinute1)){
    digitalWrite(startsystem,HIGH);
    Serial.println("PC ON");
    }
    
  

}
