int enA = 10;
int in1 = 9;
int in2 = 8;
int enB = 5;
int in3 = 7;
int in4 = 6;
#define sensor1 A1
#define sensor2 A2
#define sensor3 A3
#define sensor4 A4
#define sensor5 A5

#define black 0
#define white 1

#define a1 960
#define a2 960
#define a3 960
#define a4 960
#define a5 920

#define LED_A1 13
#define LED_A2 12
#define LED_A3 11
#define LED_A4 4
#define LED_A5 3

int Sen1=black;
int Sen2=black;
int Sen3=black;
int Sen4=black;
int Sen5=black;

int SensorRead1 = analogRead(sensor1);
int SensorRead2 = analogRead(sensor2);
int SensorRead3 = analogRead(sensor3);
int SensorRead4 = analogRead(sensor4);
int SensorRead5 = analogRead(sensor5);

void tr()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in4, LOW);
  delay(150);
}
void tl()
{1
  digitalWrite(in1, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, LOW); 
  digitalWrite(in4, LOW);
  delay(150);
}
void fw()
{
  digitalWrite(in1, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, LOW); 
  digitalWrite(in4, LOW);
  delay(10);
}
void st()
{
  digitalWrite(in1, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in4, LOW);
  delay(10);
}
void setup()
{
    Serial.begin(9600);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    pinMode(A4, INPUT);
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT); 
    pinMode(in2, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    
    pinMode(LED_A1,OUTPUT);
    pinMode(LED_A2,OUTPUT);
    pinMode(LED_A3,OUTPUT);
    pinMode(LED_A4,OUTPUT);
    pinMode(LED_A5,OUTPUT);
    
    pinMode(sensor1,INPUT);
    pinMode(sensor2,INPUT);
    pinMode(sensor3,INPUT);
    pinMode(sensor4,INPUT);
    pinMode(sensor5,INPUT);
}
void loop()
{
    showsensor();
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    if(SensorRead1 >= a1)
    {
      Sen1=white;
    }
    if(SensorRead1 < a1)
    {
      Sen1=black;
    }
    if(SensorRead2 >= a2 )
    {
      Sen2=white;
    }
    if(SensorRead2 < a2)
    {
      Sen2=black;
    }
    if(SensorRead3 >= a3 )
    {
      Sen3=white;
    }
    if(SensorRead3 < a3)
    {
      Sen3=black;
    }
    if(SensorRead4 >= a4 )
    {
      Sen4=white;
    }
    if(SensorRead4 < a4)
    {
      Sen4=black;
    }
    if(SensorRead5 >= a5)
    {
      Sen5=white;
    }
    if(SensorRead5 < a5)
    {
      Sen5=black;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////
    if(Sen1==white)
    {
      digitalWrite(LED_A1,HIGH); 
      delay(10);
    }
    if(Sen1==black)
    {
      digitalWrite(LED_A1,LOW); 
      delay(10);
    }
    if(Sen2==white)
    {
      digitalWrite(LED_A2,HIGH); 
      delay(10);
    }
    if(Sen2==black)
    {
      digitalWrite(LED_A2,LOW);
      delay(10);
    }
    if(Sen3==white)
    {
      digitalWrite(LED_A3,HIGH); 
      delay(10);
    }
    if(Sen3==black)
    {
      digitalWrite(LED_A3,LOW);
      delay(10);
    }
    if(Sen4==white)
    {
      digitalWrite(LED_A4,HIGH);
      delay(10);
    }
    if(Sen4==black)
    {
      digitalWrite(LED_A4,LOW);
    }
    if(Sen5==white)
    {
      digitalWrite(LED_A5,HIGH);
      delay(10);
    }
    if(Sen5==black)
    {
      digitalWrite(LED_A5,LOW);
      delay(10);
    }
    analogWrite(enA, 150);
    analogWrite(enB, 184.05);
    if(Sen1==white)
    {
      tl();
    }
    if(Sen2==white)
    {
      tl();
    }
    if(Sen3==white)
    {
      fw();
    }
    if(Sen3==black)
    {
      st();
    }
    if(Sen4==white)
    {
      tr();
    }
    if(Sen5==white)
    {
      tr();
    }
}
void light()
{
    if(Sen1==white)
    {
      digitalWrite(LED_A1,HIGH); 
      delay(10);
    }
    if(Sen1==black)
    {
      digitalWrite(LED_A1,LOW); 
      delay(10);
    }
    if(Sen2==white)
    {
      digitalWrite(LED_A2,HIGH); 
      delay(10);
    }
    if(Sen2==black)
    {
      digitalWrite(LED_A2,LOW);
      delay(10);
    }
    if(Sen3==white)
    {
      digitalWrite(LED_A3,HIGH); 
      delay(10);
    }
    if(Sen3==black)
    {
      digitalWrite(LED_A3,LOW);
      delay(10);
    }
    if(Sen4==white)
    {
      digitalWrite(LED_A4,HIGH);
      delay(10);
    }
    if(Sen4==black)
    {
      digitalWrite(LED_A4,LOW);
    }
    if(Sen5==white)
    {
      digitalWrite(LED_A5,HIGH);
      delay(10);
    }
    if(Sen5==black)
    {
      digitalWrite(LED_A5,LOW);
      delay(10);
    }
}
void showsensor()
{
    Serial.print("a1= ");
    Serial.print(analogRead(A1));
    Serial.print(" ");
    Serial.print("a2= ");
    Serial.print(analogRead(A2));
    Serial.print(" ");
    Serial.print("a3= ");
    Serial.print(analogRead(A3));
    Serial.print(" ");
    Serial.print("a4= ");
    Serial.print(analogRead(A4));
    Serial.print(" ");
    Serial.print("a5= ");
    Serial.println(analogRead(A5));
}
