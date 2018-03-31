/*
 * Playing with a MeArm robot.
 * With various adjustments and runs it's produced this in 2017:
 * https://youtu.be/s_XU93Ue0BA
 * 
 * Player: Todor
 */
 
#include<Servo.h>
Servo servoX11;
Servo servoY6;
//Servo servoClamp; //6
Servo servoH; //9

Servo motor[4];


void init(int m1, int m2, int m3, int m4, int dl){
  motor[0].write(m1);
  delay(dl);
  motor[1].write(m2);
  delay(dl);
  motor[2].write(m3);
  delay(dl);
  motor[3].write(m4);
  delay(dl);
  
}

void setup(){
  /*
  servoX11.attach(11);
  servoY6.attach(6);
  //servoClamp.attach(6);
  servoH.attach(9);
  */
  Serial.begin(9600);
  motor[0].attach(5); //6 ? not working?
  motor[1].attach(9);
  motor[2].attach(10);
  motor[3].attach(11);

  init(0, 0, 0, 0, 600);

  
  
  }
  int k =0;
void loop(){
  if (k<10)
  {
   
   motor[0].write(30);
   delay(1000);
   motor[0].write(60);
   delay(500);
   motor[0].write(90);
   delay(500);
   motor[0].write(45);
   delay(300);
   motor[0].write(30);
   delay(2000);
  }
  //delay(2000);
   k++;
   if (k>10) goto end;
  int i;
  for(i=0; i<4; i++){
    //int d = motor[i].read();
    int d = 0;
    Serial.print("M"); Serial.print(i);
    while(d < 90) {
      d+=10;
      motor[i].write(d);
      delay(1400);
      Serial.println(d);
    }
    while(d>90){
       d-=10;
      motor[i].write(d);
      Serial.println(d);
      delay(1200);
    }
    delay(1400);
  }  
  end: ; 
}
/*

servoY6.write(45);

delay(1500);
servoH.write(60);

delay(1500);

servoH.write(30);

delay(1500);
int s = servoX11.read();
int step = 30;
if (s > 59) step=-step;
//if (s >= 85) s =-70;
servoX11.write(s+step);
delay(500);
servoY6.write(69);
delay(1000);
}
*/
/*
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
*/
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

