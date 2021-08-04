// motor ne
int enA = 10;
int in1 = 9;
int in2 = 8;
int enB = 5;
int in3 = 7;
int in4 = 6;
void setup()
{
// set all the motor control pins to outputs
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
}
void loop()
{
// this function will run the motors in both directions at a fixed speed
// turn on motor A
//ตรง
digitalWrite(in1, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in4, LOW);

analogWrite(enA, 163);
analogWrite(enB, 200);// Speed Control
delay(1000);
digitalWrite(in1, LOW);
digitalWrite(in3, LOW);
digitalWrite(in2, LOW);
digitalWrite(in4, LOW);
//เลี้ยวซ้าบ-ล้อขวาหมุน
delay(3000);
digitalWrite(in1, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in4, LOW);
delay(319);
digitalWrite(in1, LOW);
digitalWrite(in3, LOW);
digitalWrite(in2, LOW);
digitalWrite(in4, LOW);
delay(3000);

}
