#include <LedControl.h>


LedControl lc=LedControl(3,7,5,1);



void setup() {
  // put your setup code here, to run once:
lc.shutdown(0,false);
lc.setIntensity(0,10);
  
}

void loop() {
  // put your main code here, to run repeatedly:
//lc.setRow(0,0,B11111111);
//lc.setRow(0,1,B00000010);
//lc.setRow(0,2,B00000100);
//lc.setRow(0,3,B00001000);
//lc.setRow(0,4,B00010000);
//lc.setRow(0,5,B00100000);
//lc.setRow(0,6,B01000000);
//lc.setRow(0,7,B11111111);
//A
lc.setRow(0,0,B11111111);
lc.setRow(0,1,B10000001);
lc.setRow(0,2,B10000001);
lc.setRow(0,3,B11111111);
lc.setRow(0,4,B11111111);
lc.setRow(0,5,B10000001);
lc.setRow(0,6,B10000001);
lc.setRow(0,7,B10000001);

delay(1000);
//.
lc.clearDisplay(0);
lc.setRow(0,0,B00000000);
lc.setRow(0,1,B00000000);
lc.setRow(0,2,B00000000);
lc.setRow(0,3,B00011000);
lc.setRow(0,4,B00011000);
lc.setRow(0,5,B00000000);
lc.setRow(0,6,B00000000);
lc.setRow(0,7,B00000000);

delay(1000);

//B
lc.clearDisplay(0);
lc.setRow(0,0,B11111110);
lc.setRow(0,1,B10000011);
lc.setRow(0,2,B10000011);
lc.setRow(0,3,B11111110);
lc.setRow(0,4,B11111110);
lc.setRow(0,5,B10000011);
lc.setRow(0,6,B10000011);
lc.setRow(0,7,B11111111);
delay(1000);
//A
lc.clearDisplay(0);
lc.setRow(0,0,B11111111);
lc.setRow(0,1,B10000001);
lc.setRow(0,2,B10000001);
lc.setRow(0,3,B11111111);
lc.setRow(0,4,B11111111);
lc.setRow(0,5,B10000001);
lc.setRow(0,6,B10000001);
lc.setRow(0,7,B10000001);

delay(1000);
//s
lc.clearDisplay(0);
lc.setRow(0,0,B11111111);
lc.setRow(0,1,B10000000);
lc.setRow(0,2,B10000000);
lc.setRow(0,3,B11111111);
lc.setRow(0,4,B11111111);
lc.setRow(0,5,B00000001);
lc.setRow(0,6,B00000001);
lc.setRow(0,7,B11111111);

delay(1000);
//I
lc.clearDisplay(0);
lc.setRow(0,0,B11111111);
lc.setRow(0,1,B00011000);
lc.setRow(0,2,B00011000);
lc.setRow(0,3,B00011000);
lc.setRow(0,4,B00011000);
lc.setRow(0,5,B00011000);
lc.setRow(0,6,B00011000);
lc.setRow(0,7,B11111111);

delay(1000);

//T
lc.clearDisplay(0);
lc.setRow(0,0,B11111111);
lc.setRow(0,1,B00011000);
lc.setRow(0,2,B00011000);
lc.setRow(0,3,B00011000);
lc.setRow(0,4,B00011000);
lc.setRow(0,5,B00011000);
lc.setRow(0,6,B00011000);
lc.setRow(0,7,B00011000);

delay(1000);

}
