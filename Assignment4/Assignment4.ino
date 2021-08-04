#define PIN_ANALOG_X A0
#include "LedControl.h"
#define up 2
#define right 3
#define down 4
#define left 5

void game();
void star();
void start();
void win();
void lose();

int colship=3;
int direct=0;
int Open=0;
int Shoot=0;
int bulletx;
int bullety;
int Time;
int colum;
int Timebullet1;
int coltime=8;
int collooptime=0;
int colsecond=0;
int Timey;
int score=0;
int row[8];
int col[8];
int canPlay=1;
int Timeship;

LedControl lc=LedControl(11,13,10,4); 
void setup() 
{ 
  Serial.begin(9600);
  int devices=lc.getDeviceCount();   
  
  for(int address=0;address<devices;address++) 
  {  
    lc.shutdown(address,false); 
    lc.setIntensity(address,8); 
    lc.clearDisplay(address); 
  }
  
  randomSeed(analogRead(0));
  start();
  //การวาดดาว                 
  for (int i = 0;i<5;i++)
  {   
    row[i] = random(1,6);
    col[i] = random(1,3);
    while(row[i-1] == row[i] && col[i-1] == col[i])
    {
      row[i] = random(1,6);
      col[i] = random(1,3);
    }
    lc.setLed(0,row[i],col[i],true);
  }
}
void loop() 
{ 
   if(canPlay==1)
   {
     game();   
   }
   else if(canPlay==2)
   {
     win(); 
     canPlay=1;
     setup(); 
   }
   else if(canPlay==0)
   {
     lose();
     canPlay=1;
     setup();
   }
}

void start()
{
  int wind[3][8][8]={{{1,0,0,0,1,1,1,1},
                      {1,1,0,0,1,1,1,0},
                      {1,1,1,0,1,1,0,0},
                      {1,1,1,1,1,0,0,0},
                      {0,0,0,1,1,1,1,1},
                      {0,0,1,1,0,1,1,1},
                      {0,1,1,1,0,0,1,1},
                      {1,1,1,1,0,0,0,1}},
                     {{1,1,1,1,0,0,0,1},
                      {0,1,1,1,0,0,1,1},
                      {0,0,1,1,0,1,1,1},
                      {0,0,0,1,1,1,1,1},
                      {1,1,1,1,1,0,0,0},
                      {1,1,1,0,1,1,0,0},
                      {1,1,0,0,1,1,1,0},
                      {1,0,0,0,1,1,1,1}}};
  int square[4][8][8]={{{1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1},
                        {1,1,1,0,0,1,1,1},
                        {1,1,1,0,0,1,1,1},
                        {1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1}},
                       {{1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1},
                        {1,1,0,0,0,0,1,1},
                        {1,1,0,0,0,0,1,1},
                        {1,1,0,0,0,0,1,1},
                        {1,1,0,0,0,0,1,1},
                        {1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1}},
                       {{1,1,1,1,1,1,1,1},
                        {1,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,1},
                        {1,1,1,1,1,1,1,1}},
                       {{0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0}}};
  int j = 0,k=0,i=0,m=0;
  for(m=0;m<=4;m++)
  {
    for(k = 0;k<=1;k++)
    {
      for(i=0;i<=7;i++)
      {
        for(j=0;j<=7;j++)
        {
          lc.setLed(0,j,i,wind[k][i][j]);
        }
      }
      delay(50);  
     }
   }
  if(m==5)
  {
    for(i=0;i<=7;i++)
    {
       for(j=0;j<=7;j++)
       {
          lc.setLed(0,j,i,1);
       }
    }
    delay(500);
  }
  j = 0,k=0,i=0,m=0;
  for(k=0;k<4;k++)
  {
    for(i=0;i<=7;i++)
    {
        for(j=0;j<=7;j++)
        {
          lc.setLed(0,j,i,square[k][i][j]);
        }
    }
    delay(100);
  }
  delay(100);
}

void game()
{
    if(colsecond==0)
    {
      while(collooptime<=coltime)
      {
       lc.setLed(0,collooptime,0,true); 
       collooptime++;
      }
    }
    //นับเวลาโดยให้จุดลดลงทีละจุด
    Timey=millis(); 
    if (Timey%100==0 && colsecond<=7)
    {
      lc.setLed(0,colsecond,0,false); 
      colsecond++;
    }
    if(colsecond==8)
    {
      lc.clearDisplay(0);
      canPlay=0;
      collooptime=0;
      colsecond=0;
      score=0;
    }

    //วาดเรือ
    if(canPlay==1)
    {
      lc.setLed(0,colship-1,7,true);
      lc.setLed(0,colship,6,true);
      lc.setLed(0,colship,7,false);
      lc.setLed(0,colship+1,7,true); 
    }
  int x=analogRead(PIN_ANALOG_X);
      lc.setLed(0,colship-1,7,true);
      lc.setLed(0,colship,6,true);
      lc.setLed(0,colship+1,7,true);
     if(x >= 1000 &&colship>1)
      {
        
        if(millis()-Timeship>0)
        {
          Timeship = millis();
        lc.setLed(0,colship-1,7,false);
        lc.setLed(0,colship,6,false);
        lc.setLed(0,colship+1,7,false);
        colship--;
        }
      }
      if(x <= 50 && colship<6)
      {
       
        if(millis()-Timeship>1000)
        {
          Timeship = millis();
        lc.setLed(0,colship-1,7,false);
        lc.setLed(0,colship,6,false);
        lc.setLed(0,colship+1,7,false);
        colship++;
        }
      }

    //รับค่าปุ่มยิงกระสุน
    if ( digitalRead(up) == LOW)
    {
      Shoot=1;
    }
    //วาดกระสุน
    if(Shoot==1)
    {
      bullety=5;
      while(bullety>=1)
      {
        if(bullety<5)
        {
        lc.setLed(0,bulletx,bullety+1,false);
        }
        Time = millis();
        bulletx=colship;
        lc.setLed(0,bulletx,bullety,true);
        for (int x = 0;x<5;x++)
        {
            if(row[x]==bulletx && col[x]==bullety)
            {
              score++;
              row[x]+=10;
              col[x]+=10;             
            }
        }
        if(Time-Timebullet1>50)
        {
          Timebullet1=millis();
          bullety--;
        }
      }    
    lc.setLed(0,bulletx,1,false);
    Shoot=0;
    }

    //ตรวจสอบว่าชนะ
    Serial.println(score);
    if(score==5)
    {
      canPlay=2;
      collooptime=0;
      colsecond=0;
      score=0;
    }
}

void win()
{
  int Win[8][8]={{0,0,0,0,0,0,0,0},
                 {0,0,1,0,0,1,0,0},
                 {0,0,1,0,0,1,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,1,0,0,0,0,1,0},
                 {0,0,1,1,1,1,0,0},
                 {0,0,0,0,0,0,0,0}};
   int i , j ;
   for(i=0;i<8;i++)
   {
    for(j=0;j<8;j++)
    {
      lc.setLed(0,i,j,Win[j][i]);
    }
   }
   delay(1500);
}
void lose()
{
  int Lose[8][8]={{0,0,0,0,0,0,0,0},
                 {0,0,1,0,0,1,0,0},
                 {0,0,1,0,0,1,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,1,1,1,1,0,0},
                 {0,1,0,0,0,0,1,0},
                 {0,0,0,0,0,0,0,0}};
   int i , j ;
   for(i=0;i<8;i++)
   {
    for(j=0;j<8;j++)
    {
      lc.setLed(0,i,j,Lose[j][i]);
    }
   }
   delay(1500);
}
