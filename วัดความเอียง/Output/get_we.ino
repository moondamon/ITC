#include "LedControl.h"
#include "FontLEDClock.h" 
#include <SoftwareSerial.h>
String inputString = ""; 
SoftwareSerial mySerial(5,6); 

LedControl lc=LedControl(11,13,10,4);  // DIN,CLK,CS,Number of LED Module
uint8_t intensity = 1;

unsigned long delaytime=50;  // time to updates of the display

void setup() {
  int devices=lc.getDeviceCount();  
  Serial.begin(9600);
   mySerial.begin(9600); 
   attachInterrupt(1,SoftwareSerialEvent,FALLING);
  for(int address=0;address<devices;address++) {  // set up each device 
    lc.shutdown(address,false);
    lc.setIntensity(address,8);
    lc.clearDisplay(address);
  }
}



//plot a point on the display
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

void clear_display() {
  for (uint8_t address = 0; address < 8; address++) {
    lc.clearDisplay(address);
  }
  
}
void print_tiny_char(uint8_t x, uint8_t y, char c)
{
  uint8_t dots;
  if (c >= 'A' && c <= 'Z' || (c >= 'a' && c <= 'z') ) { c &= 0x1F; }  // A-Z maps to 1-26 
  else if (c >= '0' && c <= '9') { c = (c - '0') + 32; }
  else if (c == ' ') { c = 0;  } // space 
  else if (c == '.') { c = 27; } // full stop 
  else if (c == ':') { c = 28; } // colon 
  else if (c == '\''){ c = 29; } // single quote mark 
  else if (c == '!') { c = 30; } // single quote mark 
  else if (c == '?') { c = 31; } // single quote mark 

  for (uint8_t col = 0; col < 3; col++) {
    dots = pgm_read_byte_near(&mytinyfont[c][col]);
    for (uint8_t row = 0; row < 5; row++) {
      if (dots & (16 >> row))
        plot(x + col, y + row, 1);
      else
        plot(x + col, y + row, 0);
    }
  }
}



void loop() { 
  String Y,y;
  uint8_t i = 1;
  Y = mySerial.readStringUntil('\n');
  //Serial.println(mySerial.readStringUntil('\n'));
  if(y!=Y)
  {
    clear_display();
    i=1;
  }
  while (Y[i]) 
  {
    print_tiny_char((i * 6), 2, Y[i-1]);
    i++;
  }
  y=Y;
 
}
void SoftwareSerialEvent()
{
if(mySerial.available()) // test this condition by connecting pin rxsoftware with pin'0'(Rx)
{
  Serial.print((char)mySerial.read());
}
}
