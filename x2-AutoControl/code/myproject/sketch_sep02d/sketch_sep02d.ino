
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
#define IN1 6
#define IN2 7
#define ENB 2

#define IN3 5
#define IN4 4
#define ENA 3

int MAX_SPEED = 255; 
int MIN_SPEED = 0;
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}
void motor_2_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  //analogWrite(IN3, speed);
  analogWrite(ENB, speed);
}
void motor_2_Dung() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void motor_2_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  analogWrite(IN3, 255 - speed);
}

void motor_1_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  //analogWrite(IN1, speed);
  analogWrite(ENA, speed);
}
void motor_1_Dung() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void motor_1_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);  
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  analogWrite(IN1, speed);
}

void loop()
{     
    //delay(5000);
    motor_1_Tien(150);
    motor_2_Tien(150); 
  delay(5000);//tiến 5 s
//  motor_2_Dung();
  //motor_1_Dung();
//  delay(2000);
//  motor_2_Lui(MAX_SPEED / 5); 
 //motor_1_Lui(MAX_SPEED / 5); 
//  delay(5000);
}
