

// ultrosonic controls 
#define trig A1
#define echo A0


//Car motors control
#define RF 2
#define RB 3
#define LB 4
#define LF 5
#define enable 6
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);//Baud Rate

pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

pinMode(RF,OUTPUT);
pinMode(RB,OUTPUT);
pinMode(LB,OUTPUT);
pinMode(LF,OUTPUT);
pinMode(enable,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


digitalWrite(trig,HIGH);
delay(10);// producing ultrasounds
digitalWrite(trig,LOW);


double pulse=pulseIn(echo,HIGH);
float distance=pulse/58.4;

Serial.print("Distance = ");
Serial.print(distance);
Serial.println(" cm");

if(distance<30){
  digitalWrite(RF,LOW);
digitalWrite(LF,LOW);
digitalWrite(RB,LOW);
digitalWrite(LB,LOW);
}

else{

  digitalWrite(RF,HIGH);
digitalWrite(LF,HIGH);
digitalWrite(RB,LOW);
digitalWrite(LB,LOW); 

}
}
