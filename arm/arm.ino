#include <Keypad.h>
#include "meArm.h"
#include <Servo.h>

Servo GripperServo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int MaxGripperAngle=40,gripper_pos = 0;    // variable to store the servo position
bool open_ = false,catched_=false;


const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8,9}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//Arm:
meArm arm;

int open_gripper(int max_angle){
  int i;
  for(i = 0 ; i< max_angle ; i+=1){
    GripperServo.write(i);
    delay(15);
  }
  return i;
}
int close_gripper(int pos){
  int i;
  Serial.println(pos);
  for(i = pos ; i>=0 ; i-=1){
    GripperServo.write(i);
    delay(15);
  }
  return i; 
}

int catch_object(int pos){
  int i;
  for(i = pos ; i>10 ; i-=1){
    GripperServo.write(i);
    delay(15);
  }
  return i;
}

int throw_object(int current_pos){
  for(int i= current_pos;i<MaxGripperAngle;i++){
     GripperServo.write(i);
     delay(15);
  }
  return MaxGripperAngle;
}
bool get_X_Square(){
  arm.gotoPoint(-200,-120,0);
     delay(1500);
     int angle = 0;
     if(!open_){
      gripper_pos = open_gripper(MaxGripperAngle);
      open_= true;
     }
     arm.gotoPoint(-160,-120,0);
   
     arm.gotoPoint(-140,-120,-50);

     
     arm.gotoPoint(-145,-110,-50);
     arm.gotoPoint(-150,-110,-50);
      arm.gotoPoint(-155,-110,-50);
      arm.gotoPoint(-160,-110,-50);
     
     gripper_pos = catch_object(gripper_pos);
     delay(200);
     arm.gotoPoint(-180,100,10);
     return true;
     
}
bool get_O_Square(){
   arm.gotoPoint(200,-20,0);
   
     delay(1500);
     if(!open_){
      gripper_pos = open_gripper(MaxGripperAngle);
      open_ = true;
     }
     arm.gotoPoint(120,10,0);
     arm.gotoPoint(110,0,-50);
      
     arm.gotoPoint(110,5,-50);
     
     gripper_pos = catch_object(gripper_pos);
     delay(200);
     arm.gotoPoint(180,100,10);
     return true;
}
void go_to_init_state(){
  arm.gotoPoint(-20,100,-5);
 }

void setup() {

   arm.begin(10, 11, 12, 13);

   GripperServo.attach(14);  // attaches the servo on pin 9 to the servo object
   GripperServo.write(0);
   Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  
  char key = keypad.getKey();
  if(key == '1'){
    go_to_init_state();
  }
   if(key == '2'){
    get_O_Square();
  }
   if(key == '3'){
    get_X_Square();
  }
   if(key == '4'){
     arm.gotoPoint(-200,170,-5);
  }
   if(key == '5'){
       arm.gotoPoint(-20,170,-5);
       gripper_pos= throw_object(gripper_pos);
       delay(200);
       Serial.print("close");
       gripper_pos= close_gripper(gripper_pos);
       open_ = false;
     
  }
   if(key == '6'){
    arm.gotoPoint(-160,-100,-50);
  }
   if(key == '7'){
    arm.gotoPoint(-200,-120,0);
     delay(1500);
     int angle = 0;
     if(!open_){
      angle = open_gripper(40);
      open_ = true;
     }
     arm.gotoPoint(-160,-120,0);
   
     arm.gotoPoint(-140,-120,-50);

     
     arm.gotoPoint(-145,-110,-50);
     arm.gotoPoint(-150,-110,-50);
      arm.gotoPoint(-155,-110,-50);
      arm.gotoPoint(-160,-110,-50);
     
     int angle2 = catch_object(angle);
     delay(200);
     arm.gotoPoint(-180,100,10);
  }
   if(key == '8'){
       arm.gotoPoint(-200,-120,-50);
       //arm.goDirectlyTo(-20, 100, -10);

  }
   if(key == '9'){
    arm.gotoPoint(200,-20,0);
     delay(1500);
     int angle = 0;
     if(!open_){
      angle = open_gripper(40);
     }
     arm.gotoPoint(120,10,0);
     arm.gotoPoint(110,0,-50);
     //arm.gotoPoint(110,0,-50);

     
     arm.gotoPoint(110,5,-50);
     //arm.gotoPoint(120,5,-50);
     // arm.gotoPoint(125,10,-50);
      //arm.gotoPoint(130,10,-50);
     
     int angle2 = catch_object(angle);
     delay(200);
     arm.gotoPoint(180,100,10);
  }
  // put your main code here, to run repeatedly:

}
