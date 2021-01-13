
#include Servo.h

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

char fba;      
int pos1 = 0;    
int pos2 = 0;
int pos3 = 0;    
int pos4 = 0;
int po5 = 0;    

void setup() {
  servo1.attach(9);
  servo2.attach(8);
  servo3.attach(7);
  servo4.attach(6);
  servo5.attach(5);
  Serial.begin(9600);
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

}
