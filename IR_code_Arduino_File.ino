#include <IRremote.h>
int Relay3 = 4; 
int RECV_PIN = 13;
int Relay4 = 5;
long number;
int count3;
int count4;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
pinMode(Relay3,OUTPUT);
pinMode(Relay4,OUTPUT);
}
int relay3_count;
int relay4_count;

void loop() {
  //Serial.println(count);
  if (irrecv.decode(&results)) {
     (results.value, HEX);
   number= results.value, HEX;
    Serial.println(number);
//      Receive the next value
 delay(300);
irrecv.resume();

if(number==1785214238) {
  relay4_count++;
  count4=relay4_count%2;
 Serial.println(count4);
 }
 count4==0 ? digitalWrite(Relay3,HIGH):digitalWrite(Relay3,LOW);
 if(number==-1830824929) {
  relay3_count++;
  count3=relay3_count%2;
 Serial.println(count3);
 }
  count3==0 ? digitalWrite(Relay4,HIGH):digitalWrite(Relay4,LOW);

 
// OR
//if(count==1) digitalWrite(Relay4,HIGH);
//if(count==0) digitalWrite(Relay4,LOW);


  number=0;
  }



}
