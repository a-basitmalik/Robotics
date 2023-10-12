//Motor driver pins

#define MotorForward 2
#define MotorBackward 3
#define enable 4

int temperature = 0;
int FanSpeed = 255;


void setup() {



pinMode(MotorForward, OUTPUT);
pinMode(MotorBackward, OUTPUT);


}

void loop() {
  if (temperature >= 40){
  FanSpeed=255;
  analogWrite(enable, FanSpeed);
  digitalWrite(MotorForward, HIGH);
  digitalWrite(MotorBackward, LOW);
  
  }
if (temperature >= 38 && temperature < 40){
  
  FanSpeed=235;
  analogWrite(enable, FanSpeed);
  digitalWrite(MotorForward, HIGH);
  digitalWrite(MotorBackward, LOW);
  
}

if (temperature >= 36 && temperature < 38){
  
  FanSpeed=215;
  analogWrite(enable, FanSpeed);
  digitalWrite(MotorForward, HIGH);
  digitalWrite(MotorBackward, LOW);
  
}

if (temperature >= 34 && temperature < 36){
  
  FanSpeed=195;
  analogWrite(enable, FanSpeed);
  digitalWrite(MotorForward, HIGH);
  digitalWrite(MotorBackward, LOW);
  
}

if (temperature >= 32 && temperature < 34){
  
  FanSpeed=175;
  analogWrite(enable, FanSpeed);
  digitalWrite(MotorForward, HIGH);
  digitalWrite(MotorBackward, LOW);
  
}


if (temperature >= 30 && temperature < 32){
  
  FanSpeed=155;
  analogWrite(enable, FanSpeed);
  digitalWrite(MotorForward, HIGH);
  digitalWrite(MotorBackward, LOW);
  
}

if (temperature >= 28 && temperature < 30){
  
  FanSpeed=135;
  analogWrite(enable, FanSpeed);
  digitalWrite(MotorForward, HIGH);
  digitalWrite(MotorBackward, LOW);
  
}

if (temperature >= 26 && temperature < 28){
  
  FanSpeed=115;
  analogWrite(enable, FanSpeed);
  digitalWrite(MotorForward, HIGH);
  digitalWrite(MotorBackward, LOW);
  
}

if (temperature >= 24 && temperature < 26){
  
  FanSpeed=95;
  analogWrite(enable, FanSpeed);
  digitalWrite(MotorForward, HIGH);
  digitalWrite(MotorBackward, LOW);
  
}

if (temperature >= 22 && temperature < 24){
  
  FanSpeed=75;
  analogWrite(enable, FanSpeed);
  digitalWrite(MotorForward, HIGH);
  digitalWrite(MotorBackward, LOW);
  
}


if (temperature < 20){
  
  FanSpeed=55;
  analogWrite(enable, FanSpeed);
  digitalWrite(MotorForward, HIGH);
  digitalWrite(MotorBackward, LOW);
  
}


}
