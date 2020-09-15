#define IN1 6
#define IN2 7
#define ENB 2

#define IN3 5
#define IN4 4
#define ENA 3
#include <NewPing.h>

int MAX_SPEED = 255; 
int MIN_SPEED = 0;
int distance  = 0;

int TRIGGER_PIN = 2;
int ECHO_PIN = 3;
NewPing srf05(TRIGGER_PIN,ECHO_PIN,100);

enum State {Forward, Back, Left, Right};
enum State currentState = Forward;

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  Serial.begin (9600);
  pinMode (TRIGGER_PIN, OUTPUT);
  pinMode (ECHO_PIN, INPUT);
}
void motor2Lui(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  analogWrite(IN3, speed);
  //analogWrite(ENB, speed);
}
void motor2Dung() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void motor2Tien(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  analogWrite(IN3, speed);
}

void motor1Lui(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  analogWrite(IN1, speed);
  //analogWrite(ENA, speed);
}
void motor1Dung() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void motor1Tien(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);  
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  analogWrite(IN1, speed);
}
int measureDistance() {
  /*
  digitalWrite (TRIGGER_PIN, HIGH);
  delayMicroseconds (10);
  digitalWrite (TRIGGER_PIN, LOW);
  int time = pulseIn (ECHO_PIN, HIGH);
  int distance = (time * 0.034) / 2;  //The speed of sound in cm/us is 0.034cm/us
  */
  int distance = srf05.ping_cm();
  return distance;
}
void moveBack() {
  motor1Lui(50);
  motor2Lui(50); 
}
void moveForward() {
  motor1Tien(50);
  motor2Tien(50); 
}
void stop() {
  motor1Dung();
  motor2Dung();
}
void loop()
{     
    delay(3000);
    stop();
    moveForward();  
    distance = measureDistance();
    Serial.println(distance);
    if (distance <= 10 && distance > 0) {
      stop();      
      moveBack();
      distance = 100;
    }
    
}

/*#define inA1 5
#define inB1 3

#define inA2 11
#define inB2 10

#define inA3 9
#define inB3 6


int spd;
char data_nhan_duoc;
void setup() 
{   
   Serial.begin(9600);
   pinMode(inA1, OUTPUT); 
   pinMode(inA2, OUTPUT);
   pinMode(inB1, OUTPUT);
   pinMode(inB2, OUTPUT);
}
void tien()
{
    digitalWrite(inA1,HIGH);
    digitalWrite(inA2,HIGH);
    digitalWrite(inB1,LOW);
    digitalWrite(inB2,LOW);
}
void lui()
{
    digitalWrite(inA1,LOW);
    digitalWrite(inA2,LOW);
    digitalWrite(inB1,HIGH);
    digitalWrite(inB2,HIGH);
}
void trai()
{ 
    digitalWrite(inA1,HIGH);
    digitalWrite(inA2,LOW);
    digitalWrite(inB1,LOW);
    digitalWrite(inB2,LOW);  
}
void phai()
{ 
    digitalWrite(inA1,LOW);
    digitalWrite(inA2,HIGH);
    digitalWrite(inB1,LOW);
    digitalWrite(inB2,LOW);
}
void dung()
{
    digitalWrite(inA1,LOW);
    digitalWrite(inA2,LOW);
    digitalWrite(inB1,LOW);
    digitalWrite(inB2,LOW);
}
void bom()
{
  digitalWrite(inA3,HIGH);
}
void tat_bom()
{
  digitalWrite(inA3,LOW);
}
void den()
{
  digitalWrite(inB3,HIGH);
}
void tat_den()
{
  digitalWrite(inB3,LOW);
}
void loop()
{
  if(data_nhan_duoc=='0')
  {
    tien(); 
  }
   else if(data_nhan_duoc=='1')
  {
    lui(); 
  }
   else if(data_nhan_duoc=='2')
  {
    trai(); 
  }
   else if(data_nhan_duoc=='3')
  {
    phai(); 
  }
   else if(data_nhan_duoc=='8')
  {
    dung(); 
  }
   else if(data_nhan_duoc=='4')
  {
    bom(); 
  }
   else if(data_nhan_duoc=='5')
  {
    den(); 
  }
  else if(data_nhan_duoc=='6')
  {
    tat_bom(); 
  }
  else if(data_nhan_duoc=='7')
  {
    tat_den(); 
  }
  
}

void serialEvent(){
  if(Serial.available())
  {
  data_nhan_duoc = Serial.read();  
  Serial.print(data_nhan_duoc);
  }
}
*/
