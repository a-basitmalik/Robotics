/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>
#include <Servo.h>
#include <EEPROM.h>


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads

char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {8,7 ,6 ,5 }; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 3, 2}; //connect to the column pinouts of the keypad



//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

char password[4]={'6','8','7','2'};



int counter;
int pos = 0;

char current_password[4];

void setup(){
Serial.begin(9600);
 myservo.attach(10);


}
void loop(){

  
  
  
  
  
  char customKey = customKeypad.getKey();

  // practicing eeprom start
char passa = customKey;
char passb = customKey;
char passc = customKey;
char passd = customKey;
char format_password[4] = {passa,passb,passc,passd};
  
EEPROM.write((0,passa[0]),(1,passb[1]),(2,passc[2]),(3,passd[3]));
delay(100);
  EEPROM.read(0,1,2,3)
  Serial.println(EEPROM.read(0,1,2,3));
  ///praticing eeprom end
  
  if (customKey){
    Serial.println("Button pressed");
    Serial.println(customKey);
    Serial.println("Counter = "+ String(counter));
    
current_password[counter]=customKey;

    
    counter++;
  }
  if(counter>=4){

    Serial.println("Password Array= "+String(current_password[0])+String(current_password[1])+String(current_password[2])+String(current_password[3]));
    
if((current_password[0]==password[0])&&(current_password[1]==password[1])&&(current_password[2]==password[2])&&(current_password[3]==password[3])){
  Serial.println("correct password");
   for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
   delay(15);
   }
   delay(1000);
   Serial.println("Enter Password Again");
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);
    }
  
}
else{
  Serial.println("Wrong Password");
    
}
counter=0;    
  }



}
