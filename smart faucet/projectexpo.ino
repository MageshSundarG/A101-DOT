#include<LiquidCrystal.h>
#include<Servo.h>
Servo myservo;
int Contrast=120;
int pos=0;
int a=0,c=0;
int b=0,d=0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
    //lcd setup
analogWrite(6,Contrast);
lcd.begin(16, 2);

     //servo begins
myservo.attach(9);
  //left sensor
pinMode(A0,INPUT);
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);
digitalWrite(A2,HIGH);
digitalWrite(A1,LOW);

  //right sensor
pinMode(A3,INPUT);
pinMode(A4,OUTPUT);
pinMode(A5,OUTPUT);
digitalWrite(A5,HIGH);
digitalWrite(A4,LOW);

   //down sensor 
pinMode(7,INPUT);
pinMode(8,OUTPUT);
pinMode(10,OUTPUT);
digitalWrite(10,HIGH);
digitalWrite(8,LOW);

Serial.begin(9600);
}

void loop() {
 //lcd display 
  lcd.setCursor(0,0);
  lcd.print("water");
  lcd.setCursor(0,1);
  lcd.print("conservation");
  delay(5000);
  lcd.clear();


if((digitalRead(A3)==LOW)&&(digitalRead(7)==LOW))
{
 a+=1;
 c=a*41;
Serial.println("c"); 
 lcd.setCursor(0,0);
lcd.print("mist mode  ");
 while(pos<=90)
  {
    myservo.write(pos);
    delay(10);
    pos+=1;
  }delay(5000);
while(pos>=0)
  {
    myservo.write(pos);
    delay(10);
    pos-=1;
  }

lcd.setCursor(0,1);
lcd.print(c);
lcd.print("ml used");
delay(5000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("95% conserved!");
  delay(5000);
lcd.clear();
  return 0;

}  
else if((digitalRead(A0)==LOW)&&(digitalRead(7)==LOW))
{
b+=1;
d=b*250;

Serial.println(d); 
lcd.setCursor(0,0);
lcd.print("spray mode");
while(pos<=180)
{
    myservo.write(pos);
    delay(10);
    pos+=1;
  }delay(5000);
while(pos>=0)
  {
    myservo.write(pos);
    delay(10);
    pos-=1;
  }

lcd.setCursor(0,1);
lcd.print(d);
lcd.print("ml used");
delay(5000);
lcd.setCursor(0,0);
lcd.print("60% conserved");
  delay(5000);
  lcd.clear();
  return 0;
} 
else
{ 
  lcd.print("THE DOTS...");
  delay(5000);
  lcd.clear();
  return;
}
}
