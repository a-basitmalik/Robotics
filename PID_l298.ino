#include <QTRSensors.h>


// Mototrs
int RightForward = 2;
int RightBackward = 5;
int LeftForward = 3;
int LeftBackward = 4;
int enable_Left = 6;
int enable_Right = 7;

// Other variables
int count = 0;
int y;
int junction=0;
int leftMotorSpeed=0;
int rightMotorSpeed=0;

const double KP = 0.72;
const double  KD =  0.0;
int Goal = 3500;

int M1_minimum_speed = 150;
int M2_minimum_speed = 150;
int M1_maximum_speed = 255;
int M2_maximum_speed = 255;


#define NUM_SENSORS 8
#define TIMEOUT 2500
#define EMITTER_PIN 2
#define DEBUG 0


QTRSensorsRC qtrrc((unsigned char[]) { A7,A6,A5,A4,A3,A2,A1,A0} ,NUM_SENSORS, TIMEOUT, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];




void setup() {
  // put your setup code here, to run once:

pinMode(RightForward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);


delay(1500);
manual_calibration();
set_motors(0,0);


}


int lastError = 0;
int last_proportional = 0;
int integral = 0;



void loop() {
  // put your main code here, to run repeatedly:


unsigned int sensors[8];
int position = qtrrc.readLine(sensors);
int error = position - Goal;


int motorSpeed = KP * error + KD * (error - lastError);
lastError = error;


int leftMotorSpeed = M1_minimum_speed + motorSpeed;
int rightMotorSpeed = M2_minimum_speed - motorSpeed;


set_motors(leftMotorSpeed, rightMotorSpeed);


}



void set_motors(int motor1speed, int motor2speed)
{
if (motor1speed > M1_maximum_speed ) motor1speed = M1_maximum_speed;
if (motor2speed > M2_maximum_speed ) motor2speed = M2_maximum_speed;
if (motor1speed < 0) motor1speed = 0; 
if (motor2speed < 0) motor2speed = 0; 

analogWrite(enable_Right, motor1speed);
  analogWrite(enable_Left, motor2speed);
  digitalWrite(RightForward, HIGH);
  digitalWrite(RightBackward, LOW);

  digitalWrite(LeftForward, HIGH);  
  digitalWrite(LeftBackward, LOW);
  
}



void manual_calibration() {
  


int i;
for (i = 0; i < 250; i++)
{
qtrrc.calibrate(QTR_EMITTERS_ON);
delay(20);
}
  

delay(500);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);    
  for (int i = 0; i < 400; i++)
  {
    qtrrc.calibrate();
  }
  digitalWrite(13, LOW);
}


void Drive()
{
  analogWrite(enable_Right, 255);
  analogWrite(enable_Left, 255);
  digitalWrite(RightForward, HIGH);
  digitalWrite(RightBackward, LOW);

  digitalWrite(LeftForward, HIGH);  
  digitalWrite(LeftBackward, LOW);
  

}
void Reverse()
{
  analogWrite(enable_Right, 255);
  analogWrite(enable_Left, 255);
  digitalWrite(RightForward, LOW);
  digitalWrite(RightBackward, HIGH);

  digitalWrite(LeftForward, LOW);  
  digitalWrite(LeftBackward, HIGH);
  

}
