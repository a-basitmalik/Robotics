
#define sensor A3


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorValue = analogRead(sensor);
Serial.println(sensorValue);
if (sensorValue > 200){
  Serial.println("It's Raining take necessary Action");
}
else{
  Serial.println("Normal weather Condition");
}
delay(1000);
}
