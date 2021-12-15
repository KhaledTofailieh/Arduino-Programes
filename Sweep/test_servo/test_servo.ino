#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position
 
void setup() {
  digitalWrite(10,HIGH
  );
  myservo.attach(9);
  int pos=0;// attaches the servo on pin 9 to the servo object
}
 
void loop() {
  if(pos<=180){
    myservo.write(pos);
  }
    pos+=3;// tell servo to go to position in variable 'pos'
    delay(5000);                       // waits 15ms for the servo to reach the position
  
}
