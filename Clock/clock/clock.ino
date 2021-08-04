#include "LedControl.h"
#define buttonmode 9
#define button1 6
#define button2 5
#define button3 10
#define button4 3
#define speaker 7

int timer_counter;
unsigned long time_clock = 17480;
unsigned long time_timer = 0;
int Position4; 
int Position3; 
int Position2;   
int Position1;  
int openchangenum=0;
int changenum=0;
int mode =0;
int time_getup =17500;
int timer_open=0;
int timerstop=0;
int time_stop;

LedControl lc = LedControl(12,13,11,4);  // DIN,CLK,CS,Number of LED Module

byte zero[8] = {0x18,0x24,0x24,0x24,0x24,0x24,0x24,0x18,};
byte one[8] = {0x3C,0x10,0x10,0x10,0x10,0x14,0x18,0x10,};
byte two[8] = {0x3C,0x04,0x08,0x10,0x20,0x24,0x24,0x18,};
byte three[8] = {0x18,0x24,0x20,0x20,0x18,0x20,0x24,0x18,};
byte four[8] = {0x10,0x10,0x10,0x10,0x3C,0x14,0x18,0x10};
byte five[8] = {0x18,0x24,0x20,0x20,0x3C,0x04,0x04,0x3C,};
byte six[8] = {0x18,0x24,0x24,0x24,0x1C,0x04,0x24,0x18,};
byte seven[8] = {0x08,0x08,0x08,0x08,0x10,0x20,0x20,0x3C,};
byte eight[8] = {0x18,0x24,0x24,0x24,0x18,0x24,0x24,0x18,};
byte nine[8] = {0x18,0x24,0x20,0x38,0x24,0x24,0x24,0x18,};
byte point[8] = {0x00, 0x00, 0x00, 0x00, 0x0E, 0x0A, 0x0E, 0x00,};

void setup() 
{
  Serial.begin(9600);
  for (int i = 0; i < 4; i++)
  {
    lc.shutdown(i, false);
    lc.setIntensity(i, 8);
    lc.clearDisplay(i);
  }
  
  pinMode(speaker,OUTPUT);
  pinMode(buttonmode, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  
  printByte_Position1(zero);
  printByte_Position2(zero);
  printByte_Position3(zero);
  printByte_Position4(zero);
  
  noInterrupts(); 
  TCCR1A = 0;
  TCCR1B = 0;
  timer_counter = 3036; 
  TCNT1 = timer_counter;
  TCCR1B |= (1 << CS12); 
  TIMSK1 |= (1 << TOIE1); 
  interrupts(); 
}

ISR(TIMER1_OVF_vect) 
{
  TCNT1 = timer_counter; 
  Serial.println(time_timer++);
  Serial.println(time_clock++);
}

void loop() 
{
      bright();
      if(digitalRead(buttonmode) == LOW ) 
      {
        delay(500);
        time_timer=0;
        printByte_Position1(zero);
        printByte_Position2(zero);
        printByte_Position3(zero);
        printByte_Position4(zero);
        openchangenum=0;
        changenum=0;
        timerstop=0;
        mode++;
      }
      if(digitalRead(button1) == LOW && timer_open==0) 
      {
        if(changenum==0)
        {
          time_clock+=60;
          shownum();
        }
        if(changenum==1)
        {
          time_clock+=600;
          shownum();
        }
        if(changenum==2)
        {
          time_clock+=3600;
          shownum();
        }
        if(changenum==3)
        {
          time_clock+=36000;
          shownum();
        }
        Serial.println(time_clock);
        Serial.println(changenum);
      }
      if(digitalRead(button2) == LOW && timer_open==0) 
      {
        changenum++;
        if(changenum==4)
        {
          changenum=0;
        }
        Serial.println(changenum);
      }
      if(digitalRead(button3) == LOW) 
      {
        if(timer_open==0)
        {
          time_getup=time_clock;
          Serial.println(time_getup);
        }
        if(timer_open==1)
        {
          time_stop=time_timer;
          shownum();
          timerstop=1;
          tone(speaker,262);delay(2000);
          noTone(speaker);
        }
      }
      if(digitalRead(button4) == LOW) 
      {
        noTone(speaker);
      }
      if(mode==0)
      {
        modeclock();
        if(time_clock==time_getup)
        {
          tone(speaker,262);delay(500);
        }
        Serial.println(time_getup);
        Serial.println(time_clock);
        timer_open==0;
      }
      else if(mode==1)
      {
        if(timerstop==0)
        {
          timer();
          timer_open=1;
        }
        
      }
      else if(mode==2)
      {
        mode=0;
      }
      //Serial.println(mode);
}

void plot (uint8_t x, uint8_t y, uint8_t value) 
{
  //select which matrix depending on the x coord
  uint8_t address;
  if (x >= 0 && x <= 7)   { address = 3; }
  if (x >= 8 && x <= 15)  { address = 2; x = x - 8; }
  if (x >= 16 && x <= 23) { address = 1; x = x - 16;}
  if (x >= 24 && x <= 31) { address = 0; x = x - 24;}

  if (value == 1) 
  {
    lc.setLed(address, y, x, true);
  } 
  else 
  {
    lc.setLed(address, y, x, false);
  }
}

void dotcenter()
{
  plot (16,1,1);
  plot (15,1,1);
  plot (16,2,1);
  plot (15,2,1);
  plot (16,5,1);
  plot (15,5,1);
  plot (16,6,1);
  plot (15,6,1);
  delay(500);
  plot (16,1,0);
  plot (15,1,0);
  plot (16,2,0);
  plot (15,2,0);
  plot (16,5,0);
  plot (15,5,0);
  plot (16,6,0);
  plot (15,6,0);
  delay(500);
}

void bright()
{
    int val = analogRead(A3);
    Serial.print("val ");
    Serial.println(val);
   if(val>100&&val<200)
    {
      lc.setIntensity(0, 14);
      lc.setIntensity(1, 14);
      lc.setIntensity(2, 14);
      lc.setIntensity(3, 14);
    }
    if(val>200&&val<300)
    {
      lc.setIntensity(0, 12);
      lc.setIntensity(1, 12);
      lc.setIntensity(2, 12);
      lc.setIntensity(3, 12);
    }
    if(val>300&&val<400)
    {
      lc.setIntensity(0, 10);
      lc.setIntensity(1, 10);
      lc.setIntensity(2, 10);
      lc.setIntensity(3, 10);
    }
    if(val>400&&val<500)
    {
      lc.setIntensity(0, 8);
      lc.setIntensity(1, 8);
      lc.setIntensity(2, 8);
      lc.setIntensity(3, 8);
    }
     if(val>500&&val<600)
    {
      lc.setIntensity(0, 6);
      lc.setIntensity(1, 6);
      lc.setIntensity(2, 6);
      lc.setIntensity(3, 6);
    }
     if(val>600&&val<700)
    {
      lc.setIntensity(0, 4);
      lc.setIntensity(1, 4);
      lc.setIntensity(2, 4);
      lc.setIntensity(3, 4);
    }
    if(val>700&&val<800)
    {
      lc.setIntensity(0, 1);
      lc.setIntensity(1, 1);
      lc.setIntensity(2, 1);
      lc.setIntensity(3, 1);
    }
}
void printByte_Position4(byte character[])
{
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(0, i, character[i]);
  }
}

void printByte_Position3(byte character[]) 
{
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(1, i, character[i]);
  }
}

void printByte_Position2(byte character[]) 
{
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(2, i, character[i]);
  }
}

void printByte_Position1(byte character[]) 
{
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(3, i, character[i]);
  }
}

void shownum()
{
      if (Position1 == 1) {printByte_Position1(one);}
      else if (Position1 == 2) {printByte_Position1(two);}
      else if (Position1 == 3) {printByte_Position1(three);}
      else if (Position1 == 4) {printByte_Position1(four);}
      else if (Position1 == 5) {printByte_Position1(five);}
      else if (Position1 == 6) {printByte_Position1(six);}
      else if (Position1 == 7) {printByte_Position1(seven);}
      else if (Position1 == 8) {printByte_Position1(eight);}
      else if (Position1 == 9) {printByte_Position1(nine);}
      else if (Position1 == 0) {printByte_Position1(zero);}

      if (Position2 == 1) {printByte_Position2(one);}
      else if (Position2 == 2) {printByte_Position2(two);}
      else if (Position2 == 3) {printByte_Position2(three);}
      else if (Position2 == 4) {printByte_Position2(four);}
      else if (Position2 == 5) {printByte_Position2(five);}
      else if (Position2 == 6) {printByte_Position2(six);}
      else if (Position2 == 7) {printByte_Position2(seven);}
      else if (Position2 == 8) {printByte_Position2(eight);}
      else if (Position2 == 9) {printByte_Position2(nine);}
      else if (Position2 == 0) {printByte_Position2(zero);}

      if (Position3 == 1) {printByte_Position3(one);}
      else if (Position3 == 2) {printByte_Position3(two);}
      else if (Position3 == 3) {printByte_Position3(three);}
      else if (Position3 == 4) {printByte_Position3(four);}
      else if (Position3 == 5) {printByte_Position3(five);}
      else if (Position3 == 6) {printByte_Position3(six);}
      else if (Position3 == 7) {printByte_Position3(seven);}
      else if (Position3 == 8) {printByte_Position3(eight);}
      else if (Position3 == 9) {printByte_Position3(nine);}
      else if (Position3 == 0) {printByte_Position3(zero);}

      if (Position4 == 1) {printByte_Position4(one);}
      else if (Position4 == 2) {printByte_Position4(two);}
      else if (Position4 == 3) {printByte_Position4(three);}
      else if (Position4 == 4) {printByte_Position4(four);}
      else if (Position4 == 5) {printByte_Position4(five);}
      else if (Position4 == 6) {printByte_Position4(six);}
      else if (Position4 == 7) {printByte_Position4(seven);}
      else if (Position4 == 8) {printByte_Position4(eight);}
      else if (Position4 == 9) {printByte_Position4(nine);}
      else if (Position4 == 0) {printByte_Position4(zero);}
}
void timer()
{
      dotcenter();
      if(time_timer == 0)
      {
        Position1 = 0;
        Position2 = 0;
        Position3 = 0;
        Position4 = 0;
      }
      else if(time_timer > 0 && time_timer < 3600)
      {
        Position4 = time_timer/600;
        Position3 = (time_timer/60)%10;
        Position2 = (time_timer-(Position3*60))/10;
        Position1 = (time_timer-(Position3*60))%10;
      }
      shownum(); 
}
void modeclock()
{
      dotcenter();
      if(time_clock == 0 && time_clock < 60)
      {
        Position4 = 0;
        Position3 = 0;
        Position2 = 0;
        Position1 = 0;
      }
      else if(time_clock >= 60 && time_clock<=86400)
      {
        Position4 = (time_clock/3600)/10;
        Position3 = (time_clock/3600)%10;
        Position2 = ((time_clock%3600)/60)/10;
        Position1 = ((time_clock%3600)/60)%10;
      }
      shownum();
      if(time_clock >= 86400){time_clock=0;}
}
