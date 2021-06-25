#include "LedControl.h"
LedControl lc = LedControl(12,11,10,1);

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);

}

void loop() {
  lc.setRow(0,0,B00111100); 
  lc.setRow(0,1,B01000010); 
  lc.setRow(0,2,B10100101); 
  lc.setRow(0,3,B10000001);
  lc.setRow(0,4,B10100101);
  lc.setRow(0,5,B10011001);
  lc.setRow(0,6,B01000010);
  lc.setRow(0,7,B00111100);
  delay(1000);
  
  lc.setRow(0,0,B00111100);
  lc.setRow(0,1,B01000010);
  lc.setRow(0,2,B10100101);
  lc.setRow(0,3,B10000001);
  lc.setRow(0,4,B10011001);
  lc.setRow(0,5,B10100101);
  lc.setRow(0,6,B01000010);
  lc.setRow(0,7,B00111100);
  delay(1000);

}
