
int RightForward = 2;
int RightBackward = 3;
int LeftForward = 4;
int LeftBackward = 5;


void setup() {
  // put your setup code here, to run once:
pinMode(RightForward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);
 
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
straight();
}

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
