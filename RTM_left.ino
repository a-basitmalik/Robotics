// Sensors
int RR = 9;
int R = 10;
int M = 11;
int L = 12;
int LL = 13;
// Variables (sensors)
int Rightmost;
int Right;
int Mid;
int Left;
int Leftmost;
// Mototrs
int RightForward = 2;
int RightBackward = 5;
int LeftForward = 3;
int LeftBackward = 4;
int enable = 6;
// Other variables
int count = 0;
int y;
int junction=0;


void setup()
{
  pinMode(RR, INPUT);
  pinMode(R, INPUT);
  pinMode(M, INPUT);
  pinMode(L, INPUT);
  pinMode(LL, INPUT);
  pinMode(RightForward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);
}

void loop()
{
 
 
  Read();
  
 if (y<2)
  {
  count++;
  }   
 if (count==1)
 {
  junction++;
 }
 if (y>3)
 {
  count=0;
 }

// Start RTM

straight();
 delay(500);
 turnLeftmost();
 delay(300);
 straight();
 delay(2000);
 turnLeftmost();
 delay(300);
 straight();
 delay(800);
 turnLeftmost();
 delay(300);
 
 
 ///start Modular

 
 straight();
 delay(600);
 turnLeftmost();
  delay(290);
 straight();
 delay(510);
  turnRightmost();
  delay(300);
  straight();
  delay(1200);
  turnRightmost();
  delay(310);
  straight();
  delay(300);
  turnLeftmost();
  delay(300);
  
  straight();
  delay(200);
  Stop();
  delay(100000);
  }


void turnRightmost()
{
  analogWrite(enable, 255);
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, HIGH);

  digitalWrite(LeftForward, HIGH);  
  digitalWrite(LeftBackward, LOW);
  

}

void turnRight()
{
  analogWrite(enable, 255);
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, LOW);

  digitalWrite(LeftForward, HIGH);  
  digitalWrite(LeftBackward, LOW);
}

void straight()
{
   analogWrite(enable, 255);
   digitalWrite(RightForward, HIGH);
   digitalWrite(RightBackward, LOW);
   
   digitalWrite(LeftForward, HIGH);  
   digitalWrite(LeftBackward, LOW);

}

void turnLeft()
{
  analogWrite(enable, 255);
  digitalWrite(RightForward, HIGH);
  digitalWrite(RightBackward, LOW);

  digitalWrite(LeftForward, LOW);  
  digitalWrite(LeftBackward, LOW);
}

void turnLeftmost()
{
  analogWrite(enable, 255);
  digitalWrite(RightForward, HIGH);
  digitalWrite(RightBackward, LOW);

  digitalWrite(LeftForward, LOW);  
  digitalWrite(LeftBackward, HIGH);
  
}
void Reverse()
{
analogWrite(enable, 255);
  digitalWrite(RightForward, LOW);  
  digitalWrite(RightBackward, HIGH);

  digitalWrite(LeftForward, LOW);
  digitalWrite(LeftBackward, HIGH);  
}

void Read()
{
  Rightmost = digitalRead(RR);
  Right = digitalRead(R);
  Mid = digitalRead(M);
  Left = digitalRead(L);
  Leftmost = digitalRead(LL);
 y = Rightmost + Right + Mid + Left + Leftmost; 
  
}
void Stop()
{
   digitalWrite(RightForward, LOW);
   digitalWrite(RightBackward, LOW);
   
   digitalWrite(LeftForward, LOW);  
   digitalWrite(LeftBackward, LOW);
}
