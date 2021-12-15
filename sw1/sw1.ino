/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo GripperServo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int gripper_pos = 0,i=0;    // variable to store the servo position
bool open_ = true;
void setup() {
  GripperServo.attach(14);  // attaches the servo on pin 9 to the servo object
  GripperServo.write(0);
}

void open_gripper(){
  for(int i = 0 ; i< 30 ; i+=1){
    GripperServo.write(i);
    delay(15);
  }
}
void close_gripper(){
  for(int i = 30 ; i>0 ; i-=1){
    GripperServo.write(i);
    delay(15);
  } 
}
void loop() {

if(open_){
 open_gripper();
 open_=false;
  delay(1000);
}

if(!open_){
 close_gripper();
  delay(1500);
  open_=true;
} 
}
