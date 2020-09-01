//pwm = pulse - width modulation
const int pwm = 10 ;  //initializing pin 2 as pwm
const int in_1 = 8 ;
const int in_2 = 9 ;

void setup() {
  pinMode(pwm,OUTPUT) ;    //we have to set PWM pin as output
  pinMode(in_1,OUTPUT) ;  //Logic pins are also set as output
  pinMode(in_2,OUTPUT) ;
}

void loop() {
  // put your main code here, to run repeatedly:
  //quay thuan
  digitalWrite(in_2,HIGH) ;
  digitalWrite(in_1,LOW) ;
  analogWrite(pwm,0);  
  
  delay(50000);
//  digitalWrite(in_2,LOW) ;
//  digitalWrite(in_1,LOW) ;
//  delay(3000);
//  digitalWrite(in_2,LOW) ;
//  digitalWrite(in_1,HIGH) ;
//  delay(3000);
}
