
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <LiquidCrystal.h>
#define speed_delay 2000
#include<Timer.h>
Timer t;


char mystr[20];

#include <Wire.h>
#include <MAX30100_PulseOximeter.h>

#define REPORTING_PERIOD_MS     1000



unsigned long lastTime = 0;
unsigned long timerDelay = 30000;

float BPM, SpO2;
int count1=0;


PulseOximeter pox;
uint32_t tsLastReport = 0;


int SW=53;

int IN1=22;
int IN2=23;
int IN3=25;
int IN4=24;

int Relay=3;

int data=A0;




int MNG_2=27;
int MNG_1=26;

int LNCH_2=29;
int LNCH_1=28;

int DIN_1=31;
int DIN_2=30;
#define heart 13   

int VOICE_1=32;
int VOICE_2=33;
int VOICE_3=34;
int VOICE_4=35;
int VOICE_5=36;


char ch;
char Start_buff[70]; 

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

char CARD_1[]="0B00231FBB8C";
char CARD_2[]="0B00235D93E6";
String message=""; 


void TABLET_MORNING();
void TABLET_LUNCH();
void TABLET_DINNER();



void OPEN_1();
void OPEN_2();
void OPEN_3();

void CLOSE_1();
void CLOSE_2();
void CLOSE_3();

void DISPENSE();

void OPEN();
void CLOSE();
void OPEN_CLOSE_STOP();

int z=0;





unsigned long temp=0;
byte customChar1[8] = {0b00000,0b00000,0b00011,0b00111,0b01111,0b01111,0b01111,0b01111};
byte customChar2[8] = {0b00000,0b11000,0b11100,0b11110,0b11111,0b11111,0b11111,0b11111};
byte customChar3[8] = {0b00000,0b00011,0b00111,0b01111,0b11111,0b11111,0b11111,0b11111};
byte customChar4[8] = {0b00000,0b10000,0b11000,0b11100,0b11110,0b11110,0b11110,0b11110};
byte customChar5[8] = {0b00111,0b00011,0b00001,0b00000,0b00000,0b00000,0b00000,0b00000};
byte customChar6[8] = {0b11111,0b11111,0b11111,0b11111,0b01111,0b00111,0b00011,0b00001};
byte customChar7[8] = {0b11111,0b11111,0b11111,0b11111,0b11110,0b11100,0b11000,0b10000};
byte customChar8[8] = {0b11100,0b11000,0b10000,0b00000,0b00000,0b00000,0b00000,0b00000};

int count=0;


#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS     1000

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 52 

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float temperature;

void Init_spo2();

void onBeatDetected()
{
  Serial.println("Beat Detected!");
}

void Emergency()
{

if(digitalRead(SW)==LOW)
{
  lcd.clear();
  lcd.print("Emergency..");
   EMERGENCY();
  delay(1000);
}
  
 

}

void setup () 
{
  Serial.begin(9600);
  Serial1.begin(9600);
 Serial2.begin(9600);
  pinMode(data,INPUT);

pinMode(Relay,OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(MNG_1, OUTPUT);
  pinMode(MNG_2, OUTPUT);

  pinMode(LNCH_1, OUTPUT);
  pinMode(LNCH_2, OUTPUT);
  
  pinMode(DIN_1, OUTPUT);
  pinMode(DIN_2, OUTPUT);

  
  pinMode(VOICE_1, OUTPUT);
  pinMode(VOICE_2, OUTPUT);
  pinMode(VOICE_3, OUTPUT);
   pinMode(VOICE_4, OUTPUT);
     pinMode(VOICE_5, OUTPUT);

  digitalWrite(VOICE_1,HIGH);
  digitalWrite(VOICE_2,HIGH);
  digitalWrite(VOICE_3,HIGH);
   digitalWrite(VOICE_4,HIGH);
  digitalWrite(VOICE_5,HIGH);

  digitalWrite(Relay,LOW);
     pinMode(SW,INPUT_PULLUP);
   
   Serial1.begin(9600);
   lcd.createChar(1, customChar1);
    lcd.createChar(2, customChar2);
    lcd.createChar(3, customChar3);
    lcd.createChar(4, customChar4);
    lcd.createChar(5, customChar5);
    lcd.createChar(6, customChar6);
    lcd.createChar(7, customChar7);
    lcd.createChar(8, customChar8);
   
  lcd.begin(16,2);
  
  
 
  Serial.println("$ARTIFICIAL INTELLIGENCE BASED NURSE ROBOT#");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" NURSE ROBOT ");
 
   
  delay(2000);
}


void loop ()                      
{

START();
 
}
void START()
{
  lcd.clear();
  lcd.setCursor(0, 1);
  int count=millis() / 1000;
  lcd.print("Time:");
  lcd.print(count);
  Serial.print("Time:");
  Serial.println(count);
  delay(1000);
  if(count==20)
  {
    morning_time(); 
  }
  if(count==150)
  {
    lunch_time(); 
  
  }
   if(count==300)
  {
    dinner_time(); 
  
  }

}

void morning_time()
 {
  Serial.println("PATIENT 1....");
   lcd.clear();
    lcd.print("PATIENT 1....");
  FORWORD();
  delay(2000);

  STOP();

  
  
      digitalWrite(VOICE_1,LOW);
  delay(1000);
   digitalWrite(VOICE_1,HIGH);
  delay(2000);

    TABLET_MORNING();
     
   for(z=0;z<2;z++)
  {
    

    HEART_BEAT_MONITOR();
    TEMP_MONITOR();
    delay(500);
     
    }
    Emergency();
  
  
  Serial.println("PATIENT 2....");
    lcd.clear();
    lcd.print("PATIENT 2....");
   FORWORD();
   
  delay(2000);

  STOP();
    digitalWrite(VOICE_1,LOW);
  delay(1000);
  digitalWrite(VOICE_1,HIGH);
  delay(2000);
     
    TABLET_MORNING();
     
        
    for(z=0;z<2;z++)
  {

    HEART_BEAT_MONITOR();
    TEMP_MONITOR();
    delay(500);
     
    }  
     Emergency();
  Serial.println("RETURN....");
   REVERSE();
  delay(4000);
  STOP();
   delay(3000);
 }

 void lunch_time()
  {
     Emergency();
     Serial.println("PATIENT 1....");
        lcd.clear();
    lcd.print("PATIENT 1....");
  FORWORD();
  delay(2000);
  
  STOP();
        
     digitalWrite(VOICE_2,LOW);
  delay(1000);
  digitalWrite(VOICE_2,HIGH);
  delay(2000);

    TABLET_LUNCH();
    for(z=0;z<2;z++)
  {

    HEART_BEAT_MONITOR();
    TEMP_MONITOR();
    delay(500);
     
    }  
     Emergency();
  Serial.println("PATIENT 2....");
     lcd.clear();
    lcd.print("PATIENT 2....");
   FORWORD();
  delay(2000);
 
  STOP();
      
     digitalWrite(VOICE_2,LOW);
  delay(1000);
  digitalWrite(VOICE_2,HIGH);
  delay(2000);

    TABLET_LUNCH();
     
  for(z=0;z<2;z++)
  {

    HEART_BEAT_MONITOR();
    TEMP_MONITOR();
    delay(500);
     
    }  
  

  Serial.println("RETURN....");
   REVERSE();
  delay(4000);
  STOP();
  delay(3000);
  }

  void dinner_time()
  {
     Emergency();
    Serial.println("PATIENT 1....");
       lcd.clear();
    lcd.print("PATIENT 1....");
  FORWORD();
  delay(2000);

  STOP();
    digitalWrite(VOICE_3,LOW);
  delay(1000);
  digitalWrite(VOICE_3,HIGH);
  delay(3000); 

    TABLET_DINNER();
     
     for(z=0;z<2;z++)
  {

   HEART_BEAT_MONITOR();
    TEMP_MONITOR();
    delay(500);
     
    }  
  Emergency();
  Serial.println("PATIENT 2....");
     lcd.clear();
    lcd.print("PATIENT 2....");
   FORWORD();
  delay(2000);

  STOP();
    digitalWrite(VOICE_3,LOW);
  delay(1000);
  digitalWrite(VOICE_3,HIGH);
  delay(3000);

    TABLET_DINNER();
    
      for(z=0;z<2;z++)
  {

   HEART_BEAT_MONITOR();
    TEMP_MONITOR();
    delay(500);
     
    }  
  

  Serial.println("RETURN....");
   REVERSE();
  delay(4000);
  STOP();
  delay(3000);
  }

char Serial_read(void)
{
      char ch;
      while(Serial1.available() == 0);
      ch = Serial1.read();
      return ch;
}
void MANUAL_MODE()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   MANUAL MODE  ");
  lcd.setCursor(0,1);
  lcd.print("     SELECTED...");
  Serial1.println("$MANUAL MODE SELECTED...#");

  while(1)
  {
    if (Serial1.available() > 0)
      {
        Serial.print("hi");
          while(Serial_read()!='*');
        int  i=0;
          while((ch=Serial_read())!='#')
          {
            Start_buff[i] = ch;
             i++;
          }  
          Start_buff[i]='\0';
       }
       Serial1.println( Start_buff);
    if(strcmp(Start_buff,"FORWARD")==0)
    {
      lcd.clear();
      lcd.print("FORWARD");
      delay(1000);
      FORWORD();
      
      MANUAL_MODE();
    
    }
    else if(strcmp(Start_buff,"REVERSE")==0)
    {
      lcd.clear();
      lcd.print("REVERSE");
      delay(1000);
      REVERSE();
      MANUAL_MODE(); 
    }
     else if(strcmp(Start_buff,"LEFT")==0)
    {
      lcd.clear();
      lcd.print("LEFT");
      delay(1000);
      LEFT();
      MANUAL_MODE(); 
    }
     else if(strcmp(Start_buff,"RIGHT")==0)
    {
      lcd.clear();
      lcd.print("RIGHT");
      delay(1000);
      RIGHT();
      MANUAL_MODE(); 
    }
    else if(strcmp(Start_buff,"STOP")==0)
    {
      lcd.clear();
      lcd.print("STOP");
      delay(1000);
      STOP();
      MANUAL_MODE(); 
    }
    else if(strcmp(Start_buff,"MORNING")==0)
    {
      lcd.clear();
      lcd.print("MORNING");
      delay(1000);
      OPEN_1();
      delay(5000);
      CLOSE_1();
      MANUAL_MODE(); 
    }
    else if(strcmp(Start_buff,"AFTERNOON")==0)
    {
      lcd.clear();
      lcd.print("AFTERNOON");
      delay(1000);
      OPEN_2();
      delay(5000);
      CLOSE_2();
      MANUAL_MODE(); 
    }
    else if(strcmp(Start_buff,"NIGHT")==0)
    {
      lcd.clear();
      lcd.print("NIGHT");
      delay(1000);
      OPEN_3();
      delay(5000);
      CLOSE_3();
      MANUAL_MODE(); 
    }
  }
}

void FORWORD()
{
    Serial.println("FORWORD....");
    lcd.clear();
    lcd.print("FORWARD..");
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    delay(4000);
    STOP();
}
void REVERSE()
{
    Serial.println("REVERSE....");
    lcd.clear();
    lcd.print("REVERSE..");
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    delay(5000);
    STOP();
}
void LEFT()
{
    Serial.println("LEFT....");
    lcd.clear();
    lcd.print("LEFT..");
      digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    
}
void RIGHT()
{
    Serial.println("RIGHT....");
    lcd.clear();
    lcd.print("RIGHT..");
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  
  
  
}
void STOP()
{
    Serial.println("STOP....");
    lcd.clear();
    lcd.print("STOP..");
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);

   digitalWrite(Relay,HIGH);
   delay(1000);
    digitalWrite(Relay,LOW);
}
void TABLET_MORNING()
{
   Serial.println("MORNING TABLET PILL OPEN");
   lcd.clear();
    lcd.print("MORNING TABLET ");
    lcd.setCursor(0,1);
     lcd.print("PILL OPEN   "  );
   OPEN_1();
  
   delay(5000);
   CLOSE_1();
   Serial1.println("$MORNING TABLET DISPENSED#");
     lcd.clear();
    lcd.print("MORNING TABLET ");
     lcd.setCursor(0,1);
     lcd.print("DISPENSED   "  );
   
   delay(2000);
  
}
void TABLET_LUNCH()
{
   Serial.println("LUNCH TABLET PILL OPEN");
     lcd.clear();
    lcd.print("AFTERNOON TABLET ");
    lcd.setCursor(0,1);
     lcd.print("PILL OPEN   "  );
   OPEN_2();
   
   delay(5000);
   CLOSE_2();
   Serial1.println("$AFTERNOON TABLET DISPENSED#");
     lcd.clear();
    lcd.print("AFTERNOON TABLET  ");
        lcd.setCursor(0,1);
     lcd.print("DISPENSED   "  );
  
   delay(2000);
}
 
void TABLET_DINNER()
{
   Serial.println("DINNER TABLET PILL OPEN");
      lcd.clear();
    lcd.print("NIGHT TABLET  ");
    lcd.setCursor(0,1);
     lcd.print("PILL OPEN  "  );
   OPEN_3();
  
   delay(5000);
   CLOSE_3();
   Serial1.println("$NIGHT TABLET DISPENSED#");
     lcd.clear();
    lcd.print("NIGHT TABLET   ");
     lcd.setCursor(0,1);
     lcd.print("DISPENSED   "  );
   
   delay(2000);
} 

void RFID_CHECKING()
{
   lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SCAN YOUR HEALTH  ");
    lcd.setCursor(0,1);
    lcd.print("CARD......   ");
    Serial.println("Card read ");
  for(int x=0;x<20;x++)
  {
    if(Serial2.available()>0)
    {
     
      message=Serial2.readString();
      int str_len = message.length() + 1;
      char textmessage[12];
      message.toCharArray(textmessage,str_len);
      Serial.println(textmessage);
      textmessage[12]='\0';
      lcd.clear();
      lcd.print(textmessage);
      delay(1000);
      if((!strcmp(textmessage,CARD_1)))
      { 
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("NAME:SOWMYA");
          lcd.setCursor(0,1);
          lcd.print("DOCTOR NAME:SNEHA");
          delay(4000);
          
      }
        if(!strcmp(textmessage,CARD_2))
      { 
           lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("NAME:RAVI");
          lcd.setCursor(0,1);
          lcd.print("DOCTOR NAME:SNEHA");
          delay(4000);
    
      }
       

    }
    delay(500);
    }
    Serial.println("Card read complete");
 }


void OPEN_1()
{
    digitalWrite(MNG_1,HIGH);
    digitalWrite(MNG_2,LOW);
    delay(500);
    digitalWrite(MNG_1,LOW);
    digitalWrite(MNG_2,LOW);
  
}
void OPEN_2()
{
    digitalWrite(LNCH_1,HIGH);
    digitalWrite(LNCH_2,LOW);
    delay(500);
    digitalWrite(LNCH_1,LOW);
    digitalWrite(LNCH_2,LOW);
  
}
void OPEN_3()
{
    digitalWrite(DIN_1,HIGH);
    digitalWrite(DIN_2,LOW);
    delay(500);
    digitalWrite(DIN_1,LOW);
    digitalWrite(DIN_2,LOW);
  
}
void CLOSE_1()
{
    digitalWrite(MNG_1,LOW);
    digitalWrite(MNG_2,HIGH);
    delay(500);
    digitalWrite(MNG_1,LOW);
    digitalWrite(MNG_2,LOW);
  
}
void CLOSE_2()
{
    digitalWrite(LNCH_1,LOW);
    digitalWrite(LNCH_2,HIGH);
    delay(500);
    digitalWrite(LNCH_1,LOW);
    digitalWrite(LNCH_2,LOW);
  
}
void CLOSE_3()
{
    digitalWrite(DIN_1,LOW);
    digitalWrite(DIN_2,HIGH);
    delay(500);
    digitalWrite(DIN_1,LOW);
    digitalWrite(DIN_2,LOW);
  
}

void EMERGENCY()
{ 

  lcd.clear();
  lcd.print("EMERGENCY");
  Serial1.println("$EMERGENCY FOR PATIENT#");
  digitalWrite(VOICE_5,LOW);
  delay(1000);
  digitalWrite(VOICE_5,HIGH);
  delay(2000);

  
}
void TEMP_MONITOR()
{
    float temperature;
    temperature = random(280,400) / 10.0;

    if(temperature == -127.00){
      Serial.println("Sensor error!");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("35.00");
      return;
    }
     
      Serial.print("$Temperature: ");
      Serial.print(temperature);
      Serial.println("#");

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Temp: ");
      lcd.setCursor(0,1);
      lcd.print(temperature);
      delay(1000);
  
  if(temperature>35)
  {
     lcd.clear();
     lcd.setCursor(0,0);
    lcd.print("Temp is More");
    Serial1.println("{$More Temperature#}");
    delay(1000);
  
  }
  
}

void HEART_BEAT_MONITOR()
{
digitalWrite(VOICE_4,LOW);
  delay(2000);
   digitalWrite(VOICE_4,HIGH);
  delay(2000);
   count1=0;
    lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Place The Finger");
   lcd.setCursor(0, 1);
   lcd.print("to check HB");
   delay(2000);
  
   lcd.clear();
   temp=millis();
   
   while(millis()<(temp+5000))
   {
   
      if(analogRead(data)<100)
        {
         count1=count1+1;
         
         lcd.setCursor(6, 0);
         lcd.write(byte(1));
         lcd.setCursor(7, 0);
         lcd.write(byte(2));
         lcd.setCursor(8, 0);
         lcd.write(byte(3));
         lcd.setCursor(9, 0);
         lcd.write(byte(4));

         lcd.setCursor(6, 1);
         lcd.write(byte(5));
         lcd.setCursor(7, 1);
         lcd.write(byte(6));
         lcd.setCursor(8, 1);
         lcd.write(byte(7));
         lcd.setCursor(9, 1);
         lcd.write(byte(8));
         
         while(analogRead(data)<100);
         lcd.clear();
        }
   }
   
         lcd.clear();
         lcd.setCursor(0, 0);
         count1=count1*5;
         lcd.setCursor(2, 0);
         lcd.write(byte(1));
         lcd.setCursor(3, 0);
         lcd.write(byte(2));
         lcd.setCursor(4, 0);
         lcd.write(byte(3));
         lcd.setCursor(5, 0);
         lcd.write(byte(4));

         lcd.setCursor(2, 1);
         lcd.write(byte(5));
         lcd.setCursor(3, 1);
         lcd.write(byte(6));
         lcd.setCursor(4, 1);
         lcd.write(byte(7));
         lcd.setCursor(5, 1);
         lcd.write(byte(8));
         lcd.setCursor(7, 1);
         lcd.print(count1);
         lcd.print(" BPM");
         temp=0;
       sprintf(mystr, "HB:%d", count1);
       Serial1.print("$");
      Serial1.print(mystr);
      Serial1.print("#");
      Serial1.println("");

    
      delay(1000);
      
      
      if(count1>120)
{
        lcd.clear();
        lcd.print("More Heartbeat.");
        Serial1.println("$More Heartbeat..#");
        delay(1000);
      }

         
}