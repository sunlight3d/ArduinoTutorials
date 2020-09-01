#include <TM1637Display.h>
#include "DHT.h"

// Define the connections pins:
#define CLK 2
#define DIO 3
DHT dhtSensor(4, DHT11); //pin 4 connect to 
TM1637Display display = TM1637Display(CLK, DIO);
void setup() {
  Serial.begin(9600);
  dhtSensor.begin();
  // Clear the display:
  display.clear();  
}
void loop() {
  // Set the brightness:
  display.setBrightness(10);    
//  int step = 0;
  for(int step = 0; step < 10 ; step++) 
  {
    display.showNumberDec(step);
    delay(1000);  //A half second delay between steps.
  }  
  measure();
//  delay(5000);
  //display.clear();  
}
void measure() {
  float h = dhtSensor.readHumidity();  
  float t = dhtSensor.readTemperature();  
  float f = dhtSensor.readTemperature(true);
  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Ko doc duoc thong so");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dhtSensor.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dhtSensor.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %t");
  Serial.print("Temperature: ");
  display.showNumberDec(t,true, 2, 0);
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *Ft");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
}
