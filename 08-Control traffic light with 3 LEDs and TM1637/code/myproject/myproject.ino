#include <TM1637Display.h>
#include "DHT.h"
//define the connection pins
#define CLK 2
#define DIO 3

TM1637Display display = TM1637Display(CLK, DIO);
int RED = 4; //pin 4 in Arduino
int YELLOW = 5;
int GREEN = 6;

void setup() {
  // put your setup code here, to run once:
  display.clear();
  display.setBrightness(7);//max light     
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}
void turnOffAll() {
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
}
void loop() {      
  //turn on RED 5 seconds
  turnOffAll();
  digitalWrite(RED, HIGH);
  for(int step = 1; step <= 5; step++){
    display.showNumberDec(step);
    delay(1000);
  }  
  //turn on Yellow 2 seconds
  turnOffAll();
  digitalWrite(YELLOW, HIGH);
  for(int step = 1; step <= 2; step++){
    display.showNumberDec(step);
    delay(1000);
  }
  //turn on GREEN 6 seconds
  turnOffAll();
  digitalWrite(GREEN, HIGH);
  for(int step = 1; step <= 6; step++){
    display.showNumberDec(step);
    delay(1000);
  }
}
