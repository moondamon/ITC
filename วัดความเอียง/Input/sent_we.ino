#include<math.h>
#include <SoftwareSerial.h>
#define Button 7
String inputString = ""; 
SoftwareSerial mySerial(6,5); 
const unsigned int X_AXIS_PIN = 2;
const unsigned int Y_AXIS_PIN = 1;
const unsigned int Z_AXIS_PIN = 0;
const unsigned int NUM_AXES = 3;
const unsigned int PINS[NUM_AXES] = {X_AXIS_PIN, Y_AXIS_PIN, Z_AXIS_PIN
};
const unsigned int BUFFER_SIZE = 16;
const unsigned int BAUD_RATE = 9600;
int buffer[NUM_AXES][BUFFER_SIZE];
int buffer_pos[NUM_AXES] = { 0 };

void setup() 
{ 
  Serial.begin(BAUD_RATE); 
  mySerial.begin(9600); 
  pinMode(Button,INPUT_PULLUP);
}
int get_axis(const int axis) {
delay(1);
buffer[axis][buffer_pos[axis]] = analogRead(PINS[axis]);
buffer_pos[axis] = (buffer_pos[axis] + 1) % BUFFER_SIZE;
long sum = 0;
for (unsigned int i = 0; i < BUFFER_SIZE; i++)
sum += buffer[axis][i];
return round(sum / BUFFER_SIZE);
}
int get_x() { return get_axis(0); }
int get_y() { return get_axis(1); }
int get_z() { return get_axis(2); }
float MAX = 0,MIN = 0,SUM,Time,Time1,Time2,A,Y;
int Calibrate =0,RadianY;


void loop() {
  
  mySerial.println(RadianY);
  if(digitalRead(Button)==LOW)
  {
    Time=millis();
    Calibrate++;
    delay(250);
  }
  if(Calibrate==1&&Time1 - Time < 2000)
  {
    Time1 = millis();
    MIN = get_y();
    Serial.println(Calibrate);
    Serial.print(" ");
    Serial.print(MIN);
    Serial.print(" ");
    Serial.print(MAX);
    Serial.print("\n");
  }
  else if(Calibrate==2 && Time2 - Time < 2000)
  {
    Time2 = millis();
    MAX = get_y();
    Serial.print(Calibrate);
    Serial.print(" ");
    Serial.print(MIN);
    Serial.print(" ");
    Serial.print(MAX);
    Serial.print("\n");
  }
  else if(Calibrate>=2 && Time2 - Time > 2000)
  {
    Calibrate = 0;
  }
  Y = get_y();
  SUM =(MAX-MIN)/2;
  A =(Y-MAX+SUM)/SUM;
 /* if(A > 1.00)
  {
    A = 1.00;
  }
  if(A < -1.00)
  {
    A = -1.00;
  }*/
  RadianY=asin(A)*180/3.14;
  Serial.print("RadianY = ");
  Serial.print(RadianY);
  Serial.print("\n");
  delay(100);
}

void serialEvent()
{
  
  while(Serial.available()) // recheck serial is available
  {
    char inChar=(char)Serial.read(); // get the new byte:
    inputString+=inChar; // add it to the inputString:
    if (inChar=='\r') // check received 'enter' (0x0D)
    {
      mySerial.print("TX from Software serial -> ");
      mySerial.println(inputString);
      inputString="";
    }
  }
}
void SoftwareSerialEvent()
{
if(mySerial.available()) // test this condition by connecting pin rxsoftware with pin'0'(Rx)
{
Serial.print((char)mySerial.read());
}
}
