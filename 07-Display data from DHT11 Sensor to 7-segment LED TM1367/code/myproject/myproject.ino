#include <TM1637Display.h>
#include "DHT.h"
//define the connection pins
#define CLK 2
#define DIO 3
#define DHT_SENSOR 4 //connect DHT to pin 4

TM1637Display display = TM1637Display(CLK, DIO);
DHT dhtSensor(DHT_SENSOR, DHT11);

void setup() {
  // put your setup code here, to run once:
  display.clear();
  display.setBrightness(7);//max light    
  dhtSensor.begin();
}

void loop() {
  /*
  for(int step = 10; step >= 1; step--) {
    display.showNumberDec(step);  
    delay(500);//0.5 second
  } 
  */
  measure();  
  delay(2000);  
}
void measure() {
  float humidity = dhtSensor.readHumidity();
  float temperature = dhtSensor.readTemperature();  
  //display.showNumberDec(temperature);  
  display.showNumberDec(humidity);  
}
