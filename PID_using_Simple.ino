//initial motors pin
int RightForward = 9;
int RightBackward = 8;
int LeftForward = 5;
int LeftBackward = 10;
int enableRight = 6;
int enableLeft = 7;
//Configure
const int offsetA = 1;
const int offsetB = 1;
//PID Constants
int P, D, I, previousError, PIDvalue, error;
int MotorLeftSpeed, MotorRightSpeed;
int minSpeed = 200;
float Kp = 0;
float Kd = 0;
float Ki = 0 ;
int minValues[6], maxValues[6], threshold[6];


void setup() {
  // put your setup code here, to run once:
//MotorsSetup
  pinMode(RightForward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);
//Buttons Setup
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

while (digitalRead(12)) {}
  delay(1000);
 calibrate();
  while (digitalRead(13)) {}
  delay(1000);

  while (1)
  {
    if (analogRead(0) > threshold[1] && analogRead(4) < threshold[5] )
    {
      turnRightmost();
    }

    else if (analogRead(4) > threshold[5] && analogRead(0) < threshold[1])
    { 
      turnLeftmost();
    }
    else if (analogRead(2) > threshold[3])
    {
      Kp = 0.0006 * (1000 - analogRead(2));
      Kd = 10 * Kp;
      //Ki = 0.0001;
      linefollow();
    }
  }
}




void turnRightmost()
{
  Serial.println("turnRightmost");
  
  digitalWrite(RightForward, HIGH);
  digitalWrite(RightBackward, LOW);

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

void linefollow()
{
  int error = (analogRead(1) - analogRead(3));

  P = error;
  I = I + error;
  D = error - previousError;

  PIDvalue = (Kp * P) + (Ki * I) + (Kd * D);
  previousError = error;

  MotorLeftSpeed = minSpeed - PIDvalue;
  MotorRightSpeed = minSpeed + PIDvalue;

  if (MotorLeftSpeed > 255) {
    MotorLeftSpeed = 255;
  }
  if (MotorLeftSpeed < 0) {
    MotorLeftSpeed = 0;
  }
  if (MotorRightSpeed > 255) {
    MotorRightSpeed = 255;
  }
  if (MotorRightSpeed < 0) {
    MotorRightSpeed = 0;
  }

analogWrite(enableRight,MotorRightSpeed);
analogWrite(enableLeft,MotorLeftSpeed);
digitalWrite(RightForward,HIGH);
digitalWrite(LeftForward,HIGH);

}

void calibrate()
{
  for ( int i = 0; i < 5; i++)
  {
    minValues[i] = analogRead(i);
    maxValues[i] = analogRead(i);
  }
  
  for (int i = 0; i < 3000; i++)
  {
    analogWrite(enableRight,-50);
analogWrite(enableLeft,50);
digitalWrite(RightForward,HIGH);
digitalWrite(LeftForward,HIGH);

    for ( int i = 1; i < 6; i++)
    {
      if (analogRead(i) < minValues[i])
      {
        minValues[i] = analogRead(i);
      }
      if (analogRead(i) > maxValues[i])
      {
        maxValues[i] = analogRead(i);
      }
    }
  }

  for ( int i = 1; i < 6; i++)
  {
    threshold[i] = (minValues[i] + maxValues[i]) / 2;
    Serial.print(threshold[i]);
    Serial.print("   ");
  }
  Serial.println();
  
analogWrite(enableRight,0);
analogWrite(enableLeft,0);
digitalWrite(RightForward,HIGH);
digitalWrite(LeftForward,HIGH);
}
