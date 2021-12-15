#include <Servo.h>
#include<stdio.h>

Servo myservo1; 
Servo myservo2; // create servo object to control a servo
// twelve servo objects can be created on most boards
 
int pos1 = 0;
int pos2 = 90; // variable to store the servo position
int y=0;
bool positive= true, positive2 = true; 
void setup() {
  digitalWrite(0,HIGH);
  myservo1.attach(10);
  myservo2.attach(9);
  Serial.begin(9600);
  y+=0;
   pos1 =-20;// attaches the servo on pin 9 to the servo object
  bool positive = true;
  myservo1.write(pos1);
   myservo2.write(pos2);
}
 
void loop() {
  if(positive){
    myservo1.write(pos1);
    myservo2.write(pos2);
    pos1+=2;
  
    if((((y*pos1)%22)==0)||(y==0)){
      
      Serial.println(y);
      y+=1;
//      Serial.println("pos:%d",pos1);
      delay(500);
      if(y==4){
        y=0;
        } 
      }
    if(pos2<160){
       pos2+=2;
      }  
  }
  if(!positive){
    pos1-=2;
    if(pos2>90){
       pos2-=2;
      } 
   myservo1.write(pos1); 
   myservo2.write(pos2);
  }
  
  if(pos1>=65){
    positive = false;
    delay(2000);
  }
  if(pos1<=-1){
    positive = true;
    delay(50);
  }
// second servo
//  if(positive2){
//    myservo2.write(pos2);
//    pos2+=2;
//  }
//  if(!positive2){
//    pos2-=2; 
//   myservo2.write(pos2); 
//  }
//  
//  if(pos2>=140){
//    positive2 = false;
//    delay(2000);
//  }
//  if(pos2<=90){
//    positive2 = true;
//    delay(50);
//  }
    // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position

  
}
