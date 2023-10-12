

#define trig A1// output
#define echo A0// input
#define line1 9
#define line2 10
#define line3 11

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//Baud Rate
Carpin(2,3,4,5,6);

pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(line1,INPUT);
pinMode(line2,INPUT);
pinMode(line3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(10);// producing ultrasounds
digitalWrite(trig,LOW);
double pulse=pulseIn(echo,HIGH);
float distance=pulse/58.4;

Serial.print("Distance = ");
Serial.print(distance);
Serial.println(" cm");
delay(500);

if(distance==10){
  digitalWrite(2,LOW);
digitalWrite(3,LOW);
}
else{
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
}


}
