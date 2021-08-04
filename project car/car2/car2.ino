#define a1 950
#define a2 950
#define a3 950
#define a4 950
#define a5 900

int enA = 10; // Left
int in1 = 9;
int in2 = 8;
int enB = 5;
int in3 = 7;
int in4 = 6;

int count =0;

#define LED_A1 13
#define LED_A2 12
#define LED_A3 11
#define LED_A4 4
#define LED_A5 3

bool isstop = false;
int left[] = {1, 0, 1, 0, 2, 2, 0, 1, 1, 1, 0, 0, 0, 1,0,1,0, 3};
int indicator = 0;

bool A1_ontrack() 
{
  int r = analogRead(A1);
  if(r > a1) 
  {
    digitalWrite(LED_A1,HIGH); 
    return true; 
  }
  digitalWrite(LED_A1,LOW); 
  return false;
}

bool A2_ontrack() 
{
  int r = analogRead(A2);
  if(r > a2)
  {
        digitalWrite(LED_A2,HIGH); 
    return true;
  }
  digitalWrite(LED_A2,LOW); 
  return false;
}

bool A3_ontrack() 
{
  int r = analogRead(A3);
  if(r > a3) 
  {
     digitalWrite(LED_A3,HIGH); 
    return true; 
  }
  digitalWrite(LED_A3,LOW); 
  return false;
}

bool A4_ontrack() 
{
  int r = analogRead(A4);
  if(r > a4) 
  {
    digitalWrite(LED_A4,HIGH);
    return true;  
  }
  digitalWrite(LED_A4,LOW); 
  return false;
}

bool A5_ontrack() 
{
  int r = analogRead(A5);
  if(r > a5) 
  {
    digitalWrite(LED_A5,HIGH);
    return true;  
  }
  digitalWrite(LED_A5,LOW); 
  return false;
}

void setup() 
{
  Serial.begin(9600);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  pinMode(LED_A1,OUTPUT);
  pinMode(LED_A2,OUTPUT);
  pinMode(LED_A3,OUTPUT);
  pinMode(LED_A4,OUTPUT);
  pinMode(LED_A5,OUTPUT);
    
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void fwd() {
  analogWrite(enA, 163);
  analogWrite(enB, 200);
  digitalWrite(in1, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, LOW); 
  digitalWrite(in4, LOW);
}

void tl() {
  analogWrite(enA, 163);
  analogWrite(enB, 200);
  digitalWrite(in1, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, LOW); 
  digitalWrite(in4, LOW); 
}

void tr() {
  analogWrite(enA, 163);
  analogWrite(enB, 200);
  digitalWrite(in1, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in4, LOW);  
}

void loop() {

  showsensor();
  A1_ontrack();
  A2_ontrack();
  A3_ontrack();
  A4_ontrack();
  A5_ontrack();
  
  if(isstop) return;
  if(A1_ontrack() && A2_ontrack() && A3_ontrack() && A4_ontrack() && A5_ontrack() && left[indicator] == 3) {
    fwd();
    delay(100);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);   
    isstop = true;
  }else if(A1_ontrack() && A2_ontrack() && A3_ontrack() && A4_ontrack() && A5_ontrack() && left[indicator] == 1) {
    fwd();
    delay(200);
    tl();
    delay(770);
    indicator++;
  }else if(A1_ontrack() && A2_ontrack() && A3_ontrack() && A4_ontrack() && A5_ontrack() && left[indicator] == 0) {
    fwd();
    delay(300);
    tr();
    delay(400);
    indicator++;
  }else if(A1_ontrack() && A2_ontrack() && A3_ontrack() && A4_ontrack() && A5_ontrack() && left[indicator] == 2) {
    fwd();
    delay(9000);
    indicator++;
  }else if(A1_ontrack() && !A5_ontrack()) {
    tl();  
  }else if(!A1_ontrack() && A5_ontrack()) {
    tr();
  }else {
    fwd();  
  }
  delay(1);
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
