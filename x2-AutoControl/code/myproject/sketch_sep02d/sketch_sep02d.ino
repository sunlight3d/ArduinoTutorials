#define IN1 6
#define IN2 7
#define ENB 10

#define IN3 5
#define IN4 4
#define ENA 9



#include <NewPing.h>
#include <L298N.h>

int MAX_SPEED = 255; 
int MIN_SPEED = 0;
int distance  = 0;

int TRIGGER_PIN = 2;
int ECHO_PIN = 3;
NewPing srf05(TRIGGER_PIN,ECHO_PIN,100);

enum State {Forward, Back, Left, Right};
enum State currentState = Forward;
L298N::Direction direction = L298N::FORWARD;

L298N motor1(ENB, IN2, IN1);
L298N motor2(ENA, IN4, IN3);
void setup()
{
  
  Serial.begin (9600);
  pinMode (TRIGGER_PIN, OUTPUT);
  pinMode (ECHO_PIN, INPUT);

  motor1.setSpeed(70);
  motor2.setSpeed(70);
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


void loop()
{     
    motor1.run(direction);
    motor2.run(direction);
    
    distance = measureDistance();
    
    if (distance <= 10 && distance > 0) {
      direction = direction == L298N::FORWARD ? L298N::BACKWARD : L298N::FORWARD;
      Serial.println(distance);
      Serial.println("direction");
      Serial.println(direction);
      motor1.runFor(2000,direction);
      motor2.runFor(2000,direction);
      delay(1000);
    } 
    //turningTime++;
    
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
