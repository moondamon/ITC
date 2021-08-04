#define a 13
#define b 12
#define c 11
#define d 10
#define e 9
#define f 8
#define g 7
#define buttonA 3
#define buttonB 2
#define Led1 6
#define Led2 5
#define Led3 4
int shownumber[8][7]={{0,0,0,0,0,0,1},
                      {1,0,0,1,1,1,1},
                      {0,0,1,0,0,1,0},
                      {0,0,0,0,1,1,0},
                      {1,0,0,1,1,0,0},
                      {0,1,0,0,1,0,0},
                      {0,1,0,0,0,0,0},
                      {1,1,1,1,1,1,1}};
int numberA,numberB;
void setup() 
{
  Serial.begin(9600);
  pinMode(buttonA,INPUT_PULLUP);
  pinMode(buttonB,INPUT_PULLUP);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(Led1,OUTPUT);
  pinMode(Led2,OUTPUT);
  pinMode(Led3,OUTPUT);
  long int randomseed();
  int pin = 13;
  for(int i = 0;i<7;i++)
  {
    digitalWrite(pin,shownumber[7][i]);
    pin--;
  }
}
void loop() 
{
 if(digitalRead(buttonA)==LOW && numberA <=6)
 {
  numberA++;
  pressA(numberA);
 }
 if(numberA == 6 )
 {
  numberA = 0;
 }
 if(digitalRead(buttonB)==LOW)
 {
  repeat();
  pressB(numberB);
 }
 
}
void pressA(int number)
{
  int pin = 13;
  for(int i = 0;i<7;i++)
  {
    
    digitalWrite(pin,shownumber[number][i]);
    pin--;
    
  }
  delay(200);
}
void pressB(int x)
{
  
  x = random(1,6);
  int pin = 13;
  for(int i = 0;i<7;i++)
  {
    
    digitalWrite(pin,shownumber[x][i]);
    pin--;
    
  }
  
  if(numberA!=x)
 {
  Lose();
 }
 else if (numberA==x)
 {
  Win();
 }
 delay(200);
}
void repeat()
{
  int pin = 13;
  for(int i = 0;i<7;i++)
  {
    digitalWrite(pin,shownumber[7][i]);
    pin--;
  }
  delay(100);
  pin = 13;
  
  for(int i = 0;i<7;i++)
  {
    digitalWrite(pin,shownumber[0][i]);
    delay(100);
    pin--;
  }
  pin = 13;
  for(int i = 0;i<7;i++)
  {
    digitalWrite(pin,shownumber[7][i]);
    delay(100);
    pin--;
  }
  delay(10);
}
void Win()
{
  delay(200);
  for(int u=0;u<7;u++)
  {
    digitalWrite(Led1,HIGH);
    delay(50);
    digitalWrite(Led1,LOW);
    delay(50);
    digitalWrite(Led2,HIGH);
    delay(50);
    digitalWrite(Led2,LOW);
    delay(50);
    digitalWrite(Led3,HIGH);
    delay(50);
    digitalWrite(Led3,LOW);
    delay(50);
  }
  numberA = 0;
  setup();
  
}
void Lose()
{
  for(int h = 0;h<=7;h++)
  {
    digitalWrite(Led1,HIGH);
    delay(100);
    digitalWrite(Led1,LOW);
    delay(100);
  }
  numberA = 0;
  setup();
