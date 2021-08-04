#define notec 2
#define noted 3
#define notee 4 
#define notef 5
#define noteg 6
#define notea 7
#define noteb 8
#define notechigh 9
#define replay 10
#define speaker 13
#define led 11

int piano[100];
int i=0;
int x=0;
void setup() 
{
  pinMode(notec,INPUT);
  pinMode(noted,INPUT);
  pinMode(notee,INPUT);
  pinMode(notef,INPUT);
  pinMode(noteg,INPUT);
  pinMode(notea,INPUT);
  pinMode(noteb,INPUT);
  pinMode(replay,INPUT);
  pinMode(speaker,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
void loop() 
{
  //รับค่าว่ากดโน๊ตตัวไหนแล้วแสดงเสียงโน๊ตนั้น
 
  if(digitalRead(notec)==HIGH){tone(speaker,262);delay(200);noTone(speaker);piano[i]=1;i++;}
  else if(digitalRead(noted)==HIGH){tone(speaker,294);delay(200);digitalWrite(led,HIGH);delay(100);digitalWrite(led,LOW);delay(100);noTone(speaker);piano[i]=2;i++;}
  else if(digitalRead(notee)==HIGH){tone(speaker,330);delay(200);digitalWrite(led,HIGH);delay(100);digitalWrite(led,LOW);delay(100);noTone(speaker);piano[i]=3;i++;}
  else if(digitalRead(notef)==HIGH){tone(speaker,349);delay(200);digitalWrite(led,HIGH);delay(100);digitalWrite(led,LOW);delay(100);noTone(speaker);piano[i]=4;i++;}
  else if(digitalRead(noteg)==HIGH){tone(speaker,392);delay(200);digitalWrite(led,HIGH);delay(100);digitalWrite(led,LOW);delay(100);noTone(speaker);piano[i]=5;i++;}
  else if(digitalRead(notea)==HIGH){tone(speaker,440);delay(200);digitalWrite(led,HIGH);delay(100);digitalWrite(led,LOW);delay(100);noTone(speaker);piano[i]=6;i++;}
  else if(digitalRead(noteb)==HIGH){tone(speaker,494);delay(200);digitalWrite(led,HIGH);delay(100);digitalWrite(led,LOW);delay(100);noTone(speaker);piano[i]=7;i++;}
  else if(digitalRead(notechigh)==HIGH){tone(speaker,523);delay(200);digitalWrite(led,HIGH);delay(100);digitalWrite(led,LOW);delay(100);noTone(speaker);piano[i]=8;i++;}
  else {piano[i]=9;noTone(speaker);delay(100);i++;}
    
  if(digitalRead(replay)==HIGH)
  { 
    x=1;
  }
  
  if(x==1)
  {
    for(int Round =0;Round<=i;Round++)
    {
      if(piano[Round]==1){tone(speaker,262);delay(200);noTone(speaker);}
      else if(piano[Round]==2){tone(speaker,294);delay(200);noTone(speaker);}
      else if(piano[Round]==3){tone(speaker,330);delay(200);noTone(speaker);}
      else if(piano[Round]==4){tone(speaker,349);delay(200);noTone(speaker);}
      else if(piano[Round]==5){tone(speaker,392);delay(200);noTone(speaker);}
      else if(piano[Round]==6){tone(speaker,440);delay(200);noTone(speaker);}
      else if(piano[Round]==7){tone(speaker,494);delay(200);noTone(speaker);}
      else if(piano[Round]==8){tone(speaker,523);delay(200);noTone(speaker);}
      else if(piano[Round]==9){noTone(speaker);delay(200);}
      digitalWrite(led,HIGH);delay(100);
      digitalWrite(led,LOW);delay(100);
    }
    i=0;
    x=0;
  }
  delay(200);
}
