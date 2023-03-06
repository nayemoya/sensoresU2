#include <Stepper.h>

int LB = 3;
int val;
double stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);  // Pin inversion to make the library work

void setup() {
  pinMode (LB, INPUT);
  myStepper.setSpeed(10);
  Serial.begin(9600);
}

void loop(){
  val = digitalRead (LB);
  if (val == HIGH) {
  Serial.println("Está bloqueando luz");
  myStepper.step(stepsPerRevolution);
  }else{
  Serial.println("No está bloqueando luz");
  myStepper.step(-stepsPerRevolution);
  }
}