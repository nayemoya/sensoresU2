#include <TM1637Display.h>

#define CLK 4
#define DIO 5
#define encoderPinA 2
#define encoderPinB 15

int encoderPos = 0;
int lastPos = -1;
volatile bool encoderASet = false;
volatile bool encoderBSet = false;

TM1637Display display(CLK, DIO);

void ICACHE_RAM_ATTR encoder() {
  encoderASet = digitalRead(encoderPinA);
  encoderBSet = digitalRead(encoderPinB);
  if (encoderASet != encoderBSet) {
    if (digitalRead(encoderPinB) == HIGH) {
      encoderPos++;
    } else {
      encoderPos--;
    }
  } else {
    if (digitalRead(encoderPinA) == HIGH) {
      encoderPos++;
    } else {
      encoderPos--;
    }
  }
}

void setup() {
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPinA), encoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), encoder, CHANGE);

  display.setBrightness(0x0f);
}

void loop() {
  if (encoderPos != lastPos) {
    display.showNumberDec(encoderPos);
    lastPos = encoderPos;
  }
}