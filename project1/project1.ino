#include <InverseK.h>
#include<Servo.h>

struct position {
  float x, y, z;
};
Link base, upperarm, forearm, hand;
float a0, a1, a2, a3;

Servo baseServo, upperServo, foreServo, handServo;
int base_pos = 0, upper_pos = 90 , fore_pos = 0, hand_pos = 0;
int base_pin = 9, upper_pin = 10 , fore_pin = 11 , hand_pin = 12;
void setup() {
  digitalWrite(90, HIGH);
  baseServo.attach(base_pin);
  upperServo.attach(upper_pin);
  foreServo.attach(fore_pin);
  handServo.attach(hand_pin);

  position XO[9];
  XO[0].x = 30;
  XO[0].y = 50;
  XO[0].z = 100;

  Serial.begin(9600);
  base.init(0, b2a(0.0), b2a(180.0));
  upperarm.init(200, b2a(90.0), b2a(180.0));
  forearm.init(200, b2a(0.0), b2a(65.0));
  hand.init(270, b2a(0.0), b2a(270.0));

//  upperServo.write(upper_pos);
  // Attach the links to the inverse kinematic model
  InverseK.attach(base, upperarm, forearm,hand);


  if (InverseK.solve(XO[0].x, XO[0].y, XO[0].z, a0, a1, a2, a3)) {
    Serial.println("ok");
    Serial.print(a2b(a0)); Serial.print(',');
    Serial.print(a2b(a1)); Serial.print(',');
    Serial.print(a2b(a2)); Serial.print(',');
  }else{
     Serial.println("noooooot ok");
    Serial.print(a2b(a0)); Serial.print(',');
    Serial.print(a2b(a1)); Serial.print(',');
    Serial.print(a2b(a2)); Serial.print(',');
  }
  Serial.print("khaled44444"); Serial.print(',');
}

void loop() {
  // put your main code here, to run repeatedly:
  if (upper_pos < a2b(a1)) {
    upper_pos += 2;
    upperServo.write(upper_pos);
     Serial.print("upper "); Serial.print(a2b(a1));
  }

  if (fore_pos < a2b(a2)) {
    fore_pos += 2;
    foreServo.write(fore_pos);
     Serial.print("fore "); Serial.print(fore_pos);
  }

  delay(50);
}

void get_stone(position pos) {

}
void put_stone(position pos) {

}

float b2a(float b) {
  return b / 180.0 * PI - HALF_PI;
}

float a2b(float a) {
  return (a + HALF_PI) * 180 / PI;
}
