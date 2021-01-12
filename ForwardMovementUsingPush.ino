#include "LedControl.h"
#include <binary.h>

#define fwdButton 12
#define DIN 8
#define CLK 9
#define CS 10

boolean newSwitchState1 = HIGH;
boolean newSwitchState2 = HIGH;
boolean newSwitchState3 = HIGH;
boolean oldSwitchState = HIGH;

int row = 0;
int column = 0;

LedControl lc = LedControl(DIN, CLK, CS, 1);

void setup() {
  // put your setup code here, to run once:
  pinMode(fwdButton, INPUT);

  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);

  lc.setLed(0, row, column, true);
}

void loop() {
  // put your main code here, to run repeatedly:
  newSwitchState1 = digitalRead(fwdButton);
  delay(1);
  newSwitchState2 = digitalRead(fwdButton);
  delay(1);
  newSwitchState3 = digitalRead(fwdButton);

  // if all 3 values are the same we can continue
  if (  (newSwitchState1 == newSwitchState2) && (newSwitchState1 == newSwitchState3) ) {


    if ( newSwitchState1 != oldSwitchState ) {

      // has the button switch been closed?
      if ( newSwitchState1 == HIGH ) {
        lc.setLed(0, row, column, false);
        row += 1;
        lc.setLed(0, row, column, true);  
      }
    }
  }
}
