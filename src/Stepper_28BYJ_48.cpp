#include "Stepper_28BYJ_48.h"



Stepper_28BYJ_48::Stepper_28BYJ_48(int _pin_1n1, int _pin_1n2, int _pin_1n3, int _pin_1n4) {
  bStop = true;
  
  pin_1n1 = _pin_1n1;
  pin_1n2 = _pin_1n2;
  pin_1n3 = _pin_1n3;
  pin_1n4 = _pin_1n4;

  pinMode(pin_1n1, OUTPUT);
  pinMode(pin_1n2 , OUTPUT);
  pinMode(pin_1n3, OUTPUT);
  pinMode(pin_1n4, OUTPUT);
};

void Stepper_28BYJ_48::step( int count) {
  while ( count > 0 ) {
    for (int i = 0; i < 8; i++)
    {
      setOutput(i);
      delayMicroseconds(motorSpeed);
    }
    count--;
  }
  
  while ( count < 0 ) {
    for (int i = 7; i >= 0; i--)
    {
      setOutput(i);
      delayMicroseconds(motorSpeed);
    }
    count++;
  }
  bStop = false;
};

void Stepper_28BYJ_48::stop(){
    if(!bStop){
      digitalWrite(pin_1n1, LOW);
      digitalWrite(pin_1n2, LOW);
      digitalWrite(pin_1n3, LOW);
      digitalWrite(pin_1n4, LOW);
      bStop = true;
    }
};

 void Stepper_28BYJ_48::setOutput(int out) {
  digitalWrite(pin_1n1, bitRead(lookup[out], 0));
  digitalWrite(pin_1n2, bitRead(lookup[out], 1));
  digitalWrite(pin_1n3, bitRead(lookup[out], 2));
  digitalWrite(pin_1n4, bitRead(lookup[out], 3));
};
