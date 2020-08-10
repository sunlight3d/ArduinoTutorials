#include <TM1637Display.h>

// Define the connections pins:
#define CLK 2
#define DIO 3
int sensorPin = A0;// chân analog kết nối tới cảm biến LM35

// Create display object of type TM1637Display:
TM1637Display display = TM1637Display(CLK, DIO);
// Create degree Celsius symbol:
const uint8_t celsius[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_D | SEG_E | SEG_F   // C
};
void setup() {
  Serial.begin(9600);
  // Clear the display:
  display.clear();
  delay(1000);
}
void loop() {
  // Set the brightness:
  display.setBrightness(0x0a);    
  int step = 0;
  for(step = 5; step > 0; step--)  //Interrate NumStep
  {
    display.showNumberDec(step); //Display the Variable value;
    delay(500);  //A half second delay between steps.
  }
//  display.setSegments(celsius, 2, 2);//const uint8_t segments[], uint8_t length, uint8_t pos  
  int temperature = getTemperature();
  display.showNumberDec(temperature,true, 2, 0);
  delay(5000);
  //display.clear();  
}
int getTemperature() {
  float voltage = 0.0;
  float temp = 0.0;  
  while(temp < 10.0) {
    int reading = analogRead(sensorPin); 
    voltage = reading * 5.0 / 1024.0; 
    temp = voltage * 100.0;    
  }  
  return (int)temp;
}
