v#define buttonC 2
#define buttonD 3
#define buttonE 4
#define buttonF 5
#define buttonG 6
#define buttonA 7
#define buttonB 11
#define buttonC1 9
#define buttonReplay 10
#define speaker 13
int Pitch[8] = {262,294,330,349,392,440,494,523};
int i = 0,c=0,d=0,e=0,f=0,g=0,a=0,b=0,c1=0,play=0;
int REPLAY[100];
int HoldTime[100];
int SpaceTime[100];
int Pressbutton = 0;
int Stopbutton = 0;
void setup()
{
  int Pitch[8] = {262,294,330,349,392,440,494,523};
  int i = 0,c=0,d=0,e=0,f=0,g=0,a=0,b=0,c1=0,play=0;
  int REPLAY[100];
  int HoldTime[100];
  int SpaceTime[100];
  int Pressbutton = 0;
  int Stopbutton = 0;
  Serial.begin(9600);
  pinMode(buttonC,INPUT);
  pinMode(buttonD,INPUT);
  pinMode(buttonE,INPUT);
  pinMode(buttonF,INPUT);
  pinMode(buttonG,INPUT);
  pinMode(buttonA,INPUT);
  pinMode(buttonB,INPUT);
  pinMode(buttonC1,INPUT);
  pinMode(buttonReplay,INPUT);
  pinMode(speaker,OUTPUT);
}
void loop()
{
  if(digitalRead(buttonC)==HIGH&&c==0)
  {
    Pressbutton = millis();
    c = 1;
    i++;
  }
  else
  {
    c = 0;
  }
  while(digitalRead(buttonC)==HIGH)
  {
    tone(speaker,Pitch[0]);
    Stopbutton = millis();
    HoldTime[i-1] = Stopbutton - Pressbutton;
    REPLAY[i-1]=0;
  }
  noTone(speaker);
  if(digitalRead(buttonD)==HIGH&&d==0)
  {
    Pressbutton = millis();
    
    d = 1;
    i++;
  }
  else
  {
    d = 0;
  }
  while(digitalRead(buttonD)==HIGH)
  {
    tone(speaker,Pitch[1]);
    Stopbutton = millis();
    HoldTime[i-1] = Stopbutton - Pressbutton;
    REPLAY[i-1]=1;
  }
  noTone(speaker);
  if(digitalRead(buttonE)==HIGH&&e==0)
  {
    Pressbutton = millis();
    e = 1;
    i++;
  }
  else
  {
    e = 0;
  }
  while(digitalRead(buttonE)==HIGH)
  {
    tone(speaker,Pitch[2]);
    Stopbutton = millis();
    HoldTime[i-1] = Stopbutton - Pressbutton;
    REPLAY[i-1]=2;
  }
  noTone(speaker);
  if(digitalRead(buttonF)==HIGH&&f==0)
  {
    Pressbutton = millis();
    
    f = 1;
    i++;
  }
  else
  {
    f = 0;
  }
  while(digitalRead(buttonF)==HIGH)
  {
    tone(speaker,Pitch[3]);
    Stopbutton = millis();
    HoldTime[i-1] = Stopbutton - Pressbutton;
    REPLAY[i-1]=3;
  }
  noTone(speaker);
  if(digitalRead(buttonG)==HIGH&&g==0)
  {
    Pressbutton = millis();
    g = 1;
    i++;
  }
  else
  {
    g = 0;
  }
  while(digitalRead(buttonG)==HIGH)
  {
    tone(speaker,Pitch[4]);
    Stopbutton = millis();
    HoldTime[i-1] = Stopbutton - Pressbutton;
    REPLAY[i-1]=4;
  }
  noTone(speaker);
  if(digitalRead(buttonA)==HIGH&&a==0)
  {
    Pressbutton = millis();
    a = 1;
    i++;
  }
  else
  {
    a = 0;
  }
  while(digitalRead(buttonA)==HIGH)
  {
    tone(speaker,Pitch[5]);
    Stopbutton = millis();
    HoldTime[i-1] = Stopbutton - Pressbutton;
    REPLAY[i-1]=5;
  }
  noTone(speaker);
  if(digitalRead(buttonB)==HIGH&&b==0)
  {
    Pressbutton = millis();
    b = 1;
    i++;
  }
  else
  {
    b = 0;
  }
  while(digitalRead(buttonD)==HIGH)
  {
    tone(speaker,Pitch[6]);
    Stopbutton = millis();
    HoldTime[i-1] = Stopbutton - Pressbutton;
    REPLAY[i-1]=6;
  }
  noTone(speaker);
  if(digitalRead(buttonC1)==HIGH&&c1==0)
  {
    Pressbutton = millis();
    c1 = 1;
    i++;
  }
  else
  {
    c1 = 0;
  }
  while(digitalRead(buttonC1)==HIGH)
  {
    tone(speaker,Pitch[7]);
    Stopbutton = millis();
    HoldTime[i-1] = Stopbutton - Pressbutton;
    REPLAY[i-1]=7;
  }
  noTone(speaker);
  if(digitalRead(buttonReplay)==HIGH)
  {
    replay(i);
  }
  noTone(speaker);
}
void replay(int i)
{
  Serial.println("loop");
  int k = 0;
  while(k<=i)
  {
    Serial.println(k);
    tone(speaker,Pitch[REPLAY[k]]);
    delay(HoldTime[k]);   
    noTone(speaker);
    delay(SpaceTime[k]);
    k++;
    Serial.println(k);
  }  
  noTone(speaker);
  i = 0;
  Pressbutton = 0;
  Stopbutton = 0;
  setup();
  
  
}
