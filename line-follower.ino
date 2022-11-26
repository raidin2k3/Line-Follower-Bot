#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int a=13;
int b=10;
int c=9;
int d=8;
int e=6;
int f=7;
int sensor=14;
int steps=0;
int trig=16;
int echo=15;
int buzzer=17;
long duration;
int distance;
int led=A5; 
void setup(){
  lcd.begin(16,2);
  lcd.print("Speed: ");
  lcd.setCursor(0,1);
  lcd.print("Distance: ");
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT); 
  pinMode(e,INPUT);
  pinMode(f,INPUT);
  pinMode(sensor,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600); 
}
void loop(){
  if(digitalRead(sensor)){
    steps=steps+1;
    while(digitalRead(sensor));
  }
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  double distance=duration*0.034/2;
  lcd.setCursor(11,0);
  lcd.print(steps/5);
  lcd.setCursor(9,1);
  lcd.print(distance+1.0);
  Serial.println(distance);
  lcd.setCursor(14,1);
  lcd.print("cm");
  delay(50);
  int s1=digitalRead(e); 
  int s2=digitalRead(f);
  if (distance<=20){
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    tone(buzzer,500);
    digitalWrite(led,LOW);
  }
  else{
    noTone(buzzer);
    digitalWrite(led,HIGH);
    if(s1==HIGH){ 
      digitalWrite(a,LOW); 
      digitalWrite(b,HIGH);
    }
    else{
      digitalWrite(b,LOW); 
      digitalWrite(a,LOW);
      digitalWrite(led,LOW); 
    }
    if(s2==HIGH){ 
      digitalWrite(d,LOW); 
      digitalWrite(c,HIGH);
    }
    else{ 
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(led,LOW);
    }
  }
}