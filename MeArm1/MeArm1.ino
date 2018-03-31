/*
 * Playing with a MeArm robot.
 * With various adjustments and runs it's produced this in 2017:
 * https://youtu.be/s_XU93Ue0BA
 * 
 * Player: Todor
 */
#include<Servo.h>
Servo servoX;
Servo servoY;
Servo servoClamp; //6
Servo servoH; //9

void setup(){
  servoX.attach(3);
  servoY.attach(5);
  servoClamp.attach(6);
  servoH.attach(9);
  Serial.begin(9600);
  }

void loop(){

  servoClamp.write(90);
  delay(500);
  servoClamp.write(90);
  delay(500);
  servoClamp.write(30);
  delay(500);

  int i=0;
  int deg = servoH.read();

  int clamp = servoClamp.read();
  int j;
  for (j=clamp; j<90; j+=5) { servoClamp.write(j); delay(200); }

  servoClamp.write(90);

  delay(500);

  if (deg!=0)
  for(i=deg; i>0; i--){
     servoH.write(i);
     Serial.print("Deg"); Serial.println(i);
     delay(60);
     servoClamp.write(i);
 }

 Serial.println("A::");
  for(i=0; i<90; i+=5){
      servoH.write(i);
      Serial.println(i);
      delay(100);
   }
  Serial.println("B::");
  
   for( i=89; i>1; i-=3){
    servoH.write(i);
      Serial.println(i);
    delay(200);
   }
}
   /*
  servoH.write(45);
  delay(2000);
  servoH.write(60);
  delay(3000);
  servoH.write(70);
  delay(1000);
  servoH.write(80);
  delay(1000);
  for(int i=75; i>0; i-=5){
  servoH.write(i);
  delay(250);
 
  servoH.write(40);
  delay(2000);
  /*
   for(int i=0; i<90; i+4){
    servoH.write(i);
    delay(100);
   }

   for(int i=89; i>1; i-=3){
    servoH.write(i);
    delay(120);
   }
   
   delay(3000);
   */
   
  /*
  servoH.write(55);
  servoX.write(70);
  servoY.write(100);
  servoV.write(30);
delay(2500);
  servoH.write(20);
delay(2500);
  servoH.write(20);
  servoX.write(90);
  servoY.write(90);
  servoV.write(90);
delay(2500);
  servoH.write(40);
delay(4000);
*/


