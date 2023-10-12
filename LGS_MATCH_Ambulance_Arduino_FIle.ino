#include <Servo.h>// servo library
#include <SoftwareSerial.h>//bluetooth library

SoftwareSerial bluetoothSerial(11, 12); // RX, TX
//servo
Servo myservoX;//servo 1 object
Servo myservoY;//servo 2 object
int pos1 = 10;
int pos2 = 170;


//Other Sensors
int buzzer= 10;
int heartsensor = A5; 
int temperaturesensor= A6;

//Joystick
int joystickX= A0;
int joystickY= A1;
int joystickpush=11;
int xValue = 0 ;
int yValue = 0 ; 
int bValue = 0 ;


//initial motors pin
int RightForward = 3;
int RightBackward = 2;
int LeftForward = 5;
int LeftBackward = 4;

char command;

//SirenLed
const int ledPin =  1;
int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup()
{
  bluetoothSerial.begin(9600);  //Set the baud rate to your Bluetooth module.
Serial.begin(9600);
pinMode(joystickpush,INPUT); 
  digitalWrite(joystickpush,HIGH); 
  pinMode(buzzer,OUTPUT);
  pinMode(ledPin, OUTPUT);

pinMode(RightForward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);

myservoX.attach(1);
myservoY.attach(3);

}

void loop() {
  //Readings
unsigned long currentMillis = millis();
int long Heartbeat=analogRead(heartsensor);
int long temperature=analogRead(temperature);



      
//joystick code
Readjoystick();

if(xValue>=522 && xValue<=524 && yValue>=532 && yValue<=534)
{
  
  
  }
else if (xValue>=700){
straight();
}

else if (xValue <= 300){
Reverse();
}
else if(xValue <= 700 && xValue >=525 && yValue >= 535){
  turnRight();
}

else if(xValue <= 700 && xValue >=300 && yValue <= 500){
  turnLeft();
  
}
if (bValue == 1){
  digitalWrite(buzzer,HIGH);

if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }
}

//bluetooth code

  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();

    Stop(); //initialize with motors stoped
    if(command == 'F'){
      straight();
    }
    
    if(command == 'B'){
      Reverse();
    }
    
    if(command == 'L'){
      turnLeftmost();
    }
    
    if(command == 'R'){
      turnRightmost();
    }
    if(command == 'I'){
      turnRight();
    }
    if(command == 'G'){
      turnLeft();
    }
    if(command == 'J'){
      turnRightbackward();
    }
    if(command == 'H'){
      turnLeftbackward();
    }
  }
  
  //Heart control

if (Heartbeat<10){
  digitalWrite(buzzer,HIGH);
  myservoX.write(pos2);
  
}
else{
  myservoX.write(pos1);
}

//Temperature Control

if (temperature > 97){
  digitalWrite(buzzer,HIGH);
  myservoY.write(pos1);
  
}
else{
  myservoY.write(pos2);
}

  
  }


//car driving functions

void turnRight()
{
  Serial.println("turnLeft");
  
  digitalWrite(RightForward, HIGH);
  digitalWrite(RightBackward, LOW);

  digitalWrite(LeftForward, LOW);  
  digitalWrite(LeftBackward, LOW);
}

void straight()
{
   Serial.println("straight");
   
   digitalWrite(RightForward, HIGH);
   digitalWrite(RightBackward, LOW);
   digitalWrite(LeftForward, HIGH);  
   digitalWrite(LeftBackward, LOW);
}

void turnLeft()
{
Serial.println("turnR");
  
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, LOW);

  digitalWrite(LeftForward, HIGH);  
  digitalWrite(LeftBackward, LOW);
}

void turnRightmost()
{
  Serial.println("turnRightmost");
  
  digitalWrite(RightForward, HIGH);
  digitalWrite(RightBackward, LOW);

  digitalWrite(LeftForward, LOW);  
  digitalWrite(LeftBackward, HIGH);
 
}
void Reverse()
{

  digitalWrite(RightForward, LOW);  
  digitalWrite(RightBackward, HIGH);

  digitalWrite(LeftForward, LOW);
  digitalWrite(LeftBackward, HIGH);  
}

void turnLeftmost()
{
  
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, HIGH);

  digitalWrite(LeftForward, HIGH);  
  digitalWrite(LeftBackward, LOW);
  
}

void Stop()
{
  
  
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, LOW);

  digitalWrite(LeftForward, LOW);  
  digitalWrite(LeftBackward, LOW);
 
}

void turnRightbackward()
{
  
  
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, HIGH);

  digitalWrite(LeftForward, LOW);  
  digitalWrite(LeftBackward, LOW);
 
}

void turnLeftbackward()
{
  
  
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, LOW);

  digitalWrite(LeftForward, LOW);  
  digitalWrite(LeftBackward, HIGH);
 
}

// Joystick reading function
void Readjoystick(){
 
  xValue = analogRead(joystickX);  
  yValue = analogRead(joystickY);  
  bValue = digitalRead(joystickpush);  
  Serial.print(xValue,DEC);
  Serial.print(",");
  Serial.print(yValue,DEC);
  Serial.print(",");
  Serial.print(!bValue);
  Serial.print("\n");

 
}
