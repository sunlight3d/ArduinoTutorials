#include <TM1637Display.h>
#include "DHT.h"

// Define the connections pins:
#define CLK 2
#define DIO 3
DHT dht(4, DHT11); //pin 4 connect to 
TM1637Display display = TM1637Display(CLK, DIO);
void setup() {
  Serial.begin(9600);
  dht.begin();
  // Clear the display:
  display.clear();  
}
void loop() {
  // Set the brightness:
  display.setBrightness(0x0a);    
  int step = 0;
  for(step = 2; step > 0; step--)  //Interrate NumStep
  {
    display.showNumberDec(step); //Display the Variable value;
    delay(500);  //A half second delay between steps.
  }  
  measure();
  delay(5000);
  //display.clear();  
}
void measure() {
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

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
