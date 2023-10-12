#include<LiquidCrystal.h>
//LiquidCrystal lcd(RS,EN,D4,D5,D7,D6);
LiquidCrystal lcd(13,12,11,10,9,8);


#include<Servo.h>
int i=0;
int hh,mm,ss;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.setCursor(2,1);// col, rows, it sets the position
lcd.print("Ambulance X");
delay(5000);
lcd.clear();// clear the screen

}

void loop() {
  // put your main code here, to run repeatedly:
i++;
ss=i;
delay(1000);
if(ss==60){
  i=0;
  mm++;
}
  
lcd.setCursor(2,0);
lcd.print("HH : MM : SS");
lcd.setCursor(3,1);
lcd.print(hh);
lcd.print(" : ");
lcd.print(mm);
lcd.print(" : ");
lcd.print(ss);








//lcd.setCursor(0,0);// col, rows
//  
//lcd.print("LGS JT");
//
//i++;
//lcd.setCursor(0,1);
//lcd.print(i);
//delay(1000);
//
//

}
