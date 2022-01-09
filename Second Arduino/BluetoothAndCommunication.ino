#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int forward=11;
int backward=12;
int grab=13;
int projon=10;
union BtoF{
  byte b[16];
  float fval;
  }u;

const int buffer_size= 16;
byte buf[buffer_size];
float myval;

char Incoming_value = 0;
int enter=0;             
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);         
  pinMode(projon, OUTPUT);
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
  pinMode(grab, OUTPUT); 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Project is OFF");      
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");        
    if(Incoming_value == '1'){             
      digitalWrite(projon, HIGH); 
      enter=1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Project is ON");  
      while(enter==1){
      digitalWrite(grab, LOW); 
      digitalWrite(backward, LOW);
      digitalWrite(forward, LOW);
      Incoming_value = Serial.read();      
      Serial.print(Incoming_value);   
      if(Incoming_value == '0'){      
      digitalWrite(projon, LOW);
      enter=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Project is OFF"); 
      }
      if(Incoming_value == '2'){
      digitalWrite(forward, HIGH);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Project is ON"); 
        lcd.setCursor(0,1);
        lcd.print("Forward State");
      while(1){
      Incoming_value = Serial.read();
      //Serial.print(Incoming_value);
      if(Incoming_value == '5'){
      digitalWrite(forward, LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Project is ON");
        break;
        } 
      }
      }
      if(Incoming_value == '3'){
      digitalWrite(backward, HIGH);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Project is ON"); 
        lcd.setCursor(0,1);
        lcd.print("Backward State");
      while(1){
       Incoming_value = Serial.read();
        if(Incoming_value == '5'){
      digitalWrite(backward, LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Project is ON");
        break;
        } 
      //Serial.print(Incoming_value); 
      }
      }
      if(Incoming_value == '4'){
      digitalWrite(grab, HIGH);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Project is ON"); 
        lcd.setCursor(0,1);
        lcd.print("Grabbing...");
      while(1){
       Incoming_value = Serial.read();
       if(Incoming_value == '6'||Incoming_value == '7'){
      digitalWrite(grab, LOW); 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Project is ON");
        break;
        } 
      //Serial.print(Incoming_value); 
      }
      }
      }
      } 
  }                            
}
