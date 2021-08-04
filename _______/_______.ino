#include "LedControl.h"

int timer1_counter;
unsigned long t1 = 0;
int m1,m10,h1,h10;


LedControl lc = LedControl(13,11,12,4);  // DIN,CLK,CS,Number of LED Module

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


void setup() {

  Serial.begin(9600);
  for (int i = 0; i < 4; i++)
  {
    lc.shutdown(i, false);
    lc.setIntensity(i, 8);
    lc.clearDisplay(i);
  }

  printByte_h10(zero);
  printByte_h1(zero);
  printByte_m10(zero);
  printByte_m1(zero);
  
  noInterrupts(); 
  TCCR1A = 0;
  TCCR1B = 0;
  timer1_counter = 3036; 
  TCNT1 = timer1_counter;
  TCCR1B |= (1 << CS12); 
  TIMSK1 |= (1 << TOIE1); 
  interrupts(); 
}
ISR(TIMER1_OVF_vect) 
{
  TCNT1 = timer1_counter; 

  Serial.println(t1++);
}

void loop() {
  
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

      if(t1 == 0 )
      {
        h10 = 0;
        h1 = 0;
        m10 = 0;
        m1 = 0;
      }
      else if(t1 > 0 && t1 < 3600)
      {
        h10 = t1/600;
        h1 = (t1/60)%10;
        m10 = (t1-(h1*60))/10;
        m1 = (t1-(h1*60))%10;
      }

       
      if (m1 == 1) {printByte_m1(one);}
      else if (m1 == 2) {printByte_m1(two);}
      else if (m1 == 3) {printByte_m1(three);}
      else if (m1 == 4) {printByte_m1(four);}
      else if (m1 == 5) {printByte_m1(five);}
      else if (m1 == 6) {printByte_m1(six);}
      else if (m1 == 7) {printByte_m1(seven);}
      else if (m1 == 8) {printByte_m1(eight);}
      else if (m1 == 9) {printByte_m1(nine);}
      else if (m1 == 0) {printByte_m1(zero);}

      if (m10 == 1) {printByte_m10(one);}
      else if (m10 == 2) {printByte_m10(two);}
      else if (m10 == 3) {printByte_m10(three);}
      else if (m10 == 4) {printByte_m10(four);}
      else if (m10 == 5) {printByte_m10(five);}
      else if (m10 == 6) {printByte_m10(six);}
      else if (m10 == 7) {printByte_m10(seven);}
      else if (m10 == 8) {printByte_m10(eight);}
      else if (m10 == 9) {printByte_m10(nine);}
      else if (m10 == 0) {printByte_m10(zero);}

      if (h1 == 1) {printByte_h1(one);}
      else if (h1 == 2) {printByte_h1(two);}
      else if (h1 == 3) {printByte_h1(three);}
      else if (h1 == 4) {printByte_h1(four);}
      else if (h1 == 5) {printByte_h1(five);}
      else if (h1 == 6) {printByte_h1(six);}
      else if (h1 == 7) {printByte_h1(seven);}
      else if (h1 == 8) {printByte_h1(eight);}
      else if (h1 == 9) {printByte_h1(nine);}
      else if (h1 == 0) {printByte_h1(zero);}

      if (h10 == 1) {printByte_h10(one);}
      else if (h10 == 2) {printByte_h10(two);}
      else if (h10 == 3) {printByte_h10(three);}
      else if (h10 == 4) {printByte_h10(four);}
      else if (h10 == 5) {printByte_h10(five);}
      else if (h10 == 6) {printByte_h10(six);}
      else if (h10 == 7) {printByte_h10(seven);}
      else if (h10 == 8) {printByte_h10(eight);}
      else if (h10 == 9) {printByte_h10(nine);}
      else if (h10 == 0) {printByte_h10(zero);}
      
      if(t1 == 86400){t1=0;}

}

void plot (uint8_t x, uint8_t y, uint8_t value) {

  //select which matrix depending on the x coord
  uint8_t address;
  if (x >= 0 && x <= 7)   { address = 3; }
  if (x >= 8 && x <= 15)  { address = 2; x = x - 8; }
  if (x >= 16 && x <= 23) { address = 1; x = x - 16;}
  if (x >= 24 && x <= 31) { address = 0; x = x - 24;}

  if (value == 1) {
    lc.setLed(address, y, x, true);
  } else {
    lc.setLed(address, y, x, false);
  }
}

void printByte_h10(byte character[]) {
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(0, i, character[i]);
  }
}

void printByte_h1(byte character[]) {
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(1, i, character[i]);
  }
}

void printByte_m10(byte character[]) {
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(2, i, character[i]);
  }
}

void printByte_m1(byte character[]) {
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(3, i, character[i]);
  }
}
