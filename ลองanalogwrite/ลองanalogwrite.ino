#define PWM_Pin 11 // Look at '~' pins 11,10,9,6,5,3 
#define PWM_off LOW
int duty = 100; 
void setup() 
{ 
  pinMode(PWM_Pin,OUTPUT); 
  digitalWrite(PWM_Pin,PWM_off); 
}
void loop() 
{ 
  for(int i=1;i<=5;i++)
  {
  analogWrite(PWM_Pin,duty);
  duty-=20;
  delay(3000);
  }
}
