#include <IRremote.h>
# define ldr A0
#define Relay1 2 //PIR
#define Relay2 3 //LDR
#define Relay3 4 //IR
#define Relay4 5 //IR


int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;
int count;
int pir = 7;
int Check;
int ldr_value;
long number;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(pir,INPUT);
pinMode(Relay1,OUTPUT);
pinMode(Relay2,OUTPUT);
pinMode(Relay3,OUTPUT);
pinMode(Relay4,OUTPUT);
digitalWrite(pir,HIGH);


Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
//  // put your main code here, to run repeatedly:
long timer=millis();
long t=timer/1000;

t=t%10;
if(t == 0) {
Check=digitalRead(pir);
Serial.println(Check);
}
if (Check == 0){
  
  digitalWrite(Relay1,HIGH);
Check=digitalRead(pir);
}
else {
  digitalWrite(Relay1,LOW);

}
ldr_value=analogRead(ldr);
Serial.println(ldr_value);
if (ldr_value < 100){
  Serial.println("Too Dark turn on Light");
  digitalWrite(Relay2,LOW);
  
}
else{
  Serial.println("Turning off light");
  digitalWrite(Relay2,HIGH);
  
}
if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    number= results.value, HEX;
    irrecv.resume(); // Receive the next value
 delay(260); 
  }
  

if (number == 16 ){
    count++;
    digitalWrite(Relay3,HIGH);
    Serial.println("Relay 3 Off");
  }
  if (number == 16 && count==1){
    digitalWrite(Relay3,LOW);
    Serial.println("Relay 3 On");
  count=0;
  }
if (number == 2064){
    count++;
    digitalWrite(Relay3,LOW);
    Serial.println("Relay 3 On");
  }
  if (number == 2064 && count==1){
    digitalWrite(Relay3,LOW);
    Serial.println("Relay 3 On");
  count=0;
  }
//if (number == 528 ){
  //  digitalWrite(Relay4,HIGH);
    //Serial.println("Relay 4 Off");
  //}
//if (number == 3088){
  //  digitalWrite(Relay4,LOW);
    //Serial.println("Relay 4 On");
  //}
//if (number == 1040){
  //  digitalWrite(Relay3,HIGH);
    //digitalWrite(Relay4,HIGH);
  //  Serial.println("Everything Shuttdown");
  //}
  


}
