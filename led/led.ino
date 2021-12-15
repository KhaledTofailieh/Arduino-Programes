int greenPin1= 22;
int redPin1 = 23;

int greenPin2= 24;
int redPin2 = 25;

int greenPin3= 26;
int redPin3 = 27;

int greenPin4= 28;
int redPin4 = 29;


int greenPin5= 30;
int redPin5 = 31;


int greenPin6= 32;
int redPin6 = 33;

int greenPin7= 34;
int redPin7 = 35;

int greenPin8= 36;
int redPin8 = 37;

int greenPin9= 38;
int redPin9 = 39;
void setup() {
  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  
   pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);

   pinMode(redPin3, OUTPUT);
  pinMode(greenPin3, OUTPUT);

   pinMode(redPin4, OUTPUT);
  pinMode(greenPin4, OUTPUT);

   pinMode(redPin5, OUTPUT);
  pinMode(greenPin5, OUTPUT);
  
}
void loop() {
  setColor(0, 255); // Red Color
  delay(3000);
  setColor(100, 100); // Green Color
  delay(3000);
    setColor(135, 100); // Green Color
  delay(3000);
}
void setColor(int redValue, int greenValue) {
  analogWrite(redPin1, redValue);
  analogWrite(greenPin1, greenValue);

   analogWrite(redPin2, redValue);
  analogWrite(greenPin2, greenValue);

   analogWrite(redPin3, redValue);
  analogWrite(greenPin3, greenValue);

   analogWrite(redPin4, redValue);
  analogWrite(greenPin4, greenValue);
  
   analogWrite(redPin5, redValue);
  analogWrite(greenPin5, greenValue);

  analogWrite(redPin6, redValue);
  analogWrite(greenPin6, greenValue);


analogWrite(redPin7, redValue);
  analogWrite(greenPin7, greenValue);


analogWrite(redPin8, redValue);
  analogWrite(greenPin8, greenValue);


analogWrite(redPin9, redValue);
  analogWrite(greenPin9, greenValue); 
}
