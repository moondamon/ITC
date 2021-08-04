#define buttongreen 8
#define buttonyellow 9
#define buttonred 10
#define greenLED 4
#define yellowLED 3
#define redLED 2
unsigned long previousMillisgreen = 0;
unsigned long previousMillisyellow = 0;
unsigned long previousMillisred = 0;
int green = 0;
int red = 0;
int yellow;

void setup()
{
   pinMode(buttongreen,INPUT);
   pinMode(buttonyellow,INPUT);
   pinMode(buttonred,INPUT_PULLUP);
   pinMode(greenLED,OUTPUT);
   pinMode(yellowLED,OUTPUT);
   pinMode(redLED,OUTPUT);
   Serial.begin(9600);
}
void loop()
{
   unsigned long counttime = millis();
   int ButtonGreen = digitalRead(buttongreen);
   int ButtonYellow = digitalRead(buttonyellow);
   int ButtonRed = digitalRead(buttonred);
   if(red==0)
   {
      if (ButtonGreen == HIGH)
      {
        previousMillisgreen = counttime;
        delay(250);
        green++;
      }
   }
   if(green==1)
   {
      digitalWrite(greenLED,HIGH);
   }
   if(counttime - previousMillisgreen >= 3000)
   {
      digitalWrite(greenLED,LOW);
      green = 0;

   }
   if(green==2)
   {
      digitalWrite(greenLED,LOW);
      green =0;
   }
   if(green==0 && red==0)
   {
      if (ButtonYellow == LOW)
      {
        previousMillisyellow = counttime;
        delay(200);
        yellow=1;
      }
   }
   if(yellow==1)
   {
    if(counttime - previousMillisyellow >= 0 && counttime - previousMillisyellow <= 500)
    {
      digitalWrite(yellowLED,HIGH);
    }
    if(counttime - previousMillisyellow >= 500 && counttime - previousMillisyellow <= 1000)
    {
      digitalWrite(yellowLED,LOW);
    }
    if(counttime - previousMillisyellow >= 1000 && counttime - previousMillisyellow <= 1500)
    {
      digitalWrite(yellowLED,HIGH);
    }
    if(counttime - previousMillisyellow >= 1500 )
    {
      digitalWrite(yellowLED,LOW);
    }
    
   }
   if (ButtonRed == LOW)
   {
      delay(250);
      previousMillisred = counttime;
      red++;
   }
 if(red==1)
   {
      digitalWrite(redLED,HIGH);
      if(green==1)
      {
      if (ButtonGreen == HIGH)
        {
           digitalWrite(greenLED,LOW);
           red=0;
        }
      }
      
   }
   if (counttime - previousMillisred >= 3000)
   {
      digitalWrite(greenLED,LOW);
      digitalWrite(redLED,LOW);
      red = 0;
   }
   if(red==2)
   {
    digitalWrite(redLED,LOW);
    red = 0;
    green = 0;
   }
}
     
