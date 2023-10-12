// Sensors
int RR = 13;
int R = 12;
int M = 10;
int L = 8;
int LL = 9; 
// Variables (sensors)
int rr;
int r;
int m;
int l;
int ll;
// Mototrs
int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;
int enable = 6;
// Other variables
int x;
int count = 0;


void setup()
{
  pinMode(RR, INPUT);
  pinMode(R, INPUT);
  pinMode(M, INPUT);
  pinMode(L, INPUT);
  pinMode(LL, INPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  Read(); 
    
  if (m==0)
  {
    straight();
  }
  else if (ll==0) 
  { 
    turnrr();
    Serial.println("RR");
  }
  else if (l==0) 
  { 
     turnr();
     Serial.println("R");
  }
  else if (r==0) 
  { 
     turnl();
     Serial.println("L");
  }
  else if (rr==0) 
  { 
    turnll(); 
    Serial.println("LL");
  }
  else 
  { 
     Serial.println("undefined condition");
  }
  
  //counter();                                                                    //COUNTER
  
  if (count==4) 
  { 
    straight();
    delay(400);
    left();
    delay(250);
    lft();
  }
  else if (count==8) 
  { 
    straight();
    delay(400);
    right(); 
    delay(250);
    rht();
  } 
  else if (count==15) 
  { 
    yametekudasai();
  }
  
}


void turnll() 
{ 
  Serial.println("turnLL");
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);  
  digitalWrite(motor2pin2, HIGH);
  delay(105);

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW); 
  delay(95);
}

void turnl() 
{ 
  Serial.println("turnL");
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);  
  digitalWrite(motor2pin2, HIGH);
  delay(75);

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW); 
  delay(60);
}

void straight() 
{ 
   Serial.println("straight");
   analogWrite(enable, 255);
   digitalWrite(motor1pin1, HIGH);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1, LOW);  
   digitalWrite(motor2pin2, HIGH);
}

void turnr() 
{ 
  Serial.println("turnr");  
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor1pin1, LOW);  
  digitalWrite(motor1pin2, HIGH);
  delay(75);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW); 
  delay(60);
}

void turnrr() 
{ 
  Serial.println("turnrr");
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor1pin1, LOW);  
  digitalWrite(motor1pin2, HIGH);
  delay(105);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW); 
  delay(95);
} 

void Read() 
{ 
  rr = digitalRead(RR);
  r = digitalRead(R);
  m = digitalRead(M);
  l = digitalRead(L);
  ll = digitalRead(LL);
  
  Serial.print(ll);
  Serial.print(" ");
  Serial.print(l);
  Serial.print(" ");
  Serial.print(m);
  Serial.print(" ");
  Serial.print(r);
  Serial.print(" ");
  Serial.println(rr); 
  delay(3000);
}

void counter() 
{ 
   x = rr + r + m + l + ll;
   if (x<=2) 
   { 
      count = count + 1;
   }
}  
void left()
{ 
  digitalWrite(motor2pin1, LOW);  
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}
  
void right()
 { 
   digitalWrite(motor2pin1, HIGH);  
   digitalWrite(motor2pin2, LOW);

   digitalWrite(motor2pin1, HIGH);
   digitalWrite(motor2pin2, LOW);
 }

void lft() 
{ 
  while(x==1) 
  { 
   digitalWrite(motor1pin1, LOW);  
   digitalWrite(motor1pin2, HIGH);

   digitalWrite(motor2pin1, LOW);
   digitalWrite(motor2pin2, HIGH);
  }
}

void rht() 
{ 
  while(x==1) 
  { 
   digitalWrite(motor1pin1, HIGH);  
   digitalWrite(motor1pin2, LOW);

   digitalWrite(motor2pin1, HIGH);
   digitalWrite(motor2pin2, LOW);
  }
}

void yametekudasai() 
{ 
   Serial.println("yamataykuradasai");
   digitalWrite(motor1pin1, LOW);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1, LOW);  
   digitalWrite(motor2pin2, LOW);
}
