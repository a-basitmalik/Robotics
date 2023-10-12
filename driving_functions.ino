#include <SoftwareSerial.h>//bluetooth library
SoftwareSerial bluetoothSerial(7, 6); // RX, TX

//initial motors pin
int RightForward = 5;
int RightBackward = 4;
int LeftForward = 3;
int LeftBackward = 2;
int Renable= 7;
int Lenable = 6;
char command;

void setup() {
  // put your setup code here, to run once:
  bluetoothSerial.begin(9600);  //Set the baud rate to your Bluetooth module.

Serial.begin(9600);
pinMode(RightForward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);
pinMode(Lenable, OUTPUT);
pinMode(Renable, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 turnRight();
}



void turnRight()
{
  Serial.println("turnLeft");
  analogWrite(Renable,-50);
  analogWrite(Lenable,70);
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
