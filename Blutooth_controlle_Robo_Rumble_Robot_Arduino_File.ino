#include <SoftwareSerial.h>//bluetooth library
SoftwareSerial bluetoothSerial(11, 12); // RX, 

int RightForward = 3;
int RightBackward = 2;
int LeftForward = 5;
int LeftBackward = 4;

void setup() {
  // put your setup code here, to run once:
bluetoothSerial.begin(9600);  //Set the baud rate to your Bluetooth module.
Serial.begin(9600);
pinMode(RightForward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (bluetoothSerial.available() > 0) {
    int command = bluetoothSerial.read();

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
