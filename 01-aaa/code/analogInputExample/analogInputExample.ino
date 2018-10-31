/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

// the setup routine runs once when you press reset:
void setup() {
  //Serial port = COM through USB
  Serial.begin(9600);
}

// loop forever:
void loop() {
  // A0 = "Input analog 0":
  int digitalOutput = analogRead(A0);
  // print out the value you read:
  //DAC = Digital to Analog Converter 
  //10 bit => 0 to 1023
  //Power = 5V
  float analogValue = (5.00 / 1024) * digitalOutput;
  //Serial.println(digitalOutput);  
  Serial.print("digitalOutput = ");  
  Serial.print(analogValue, 3);
  Serial.println("V");  
  delay(1000);        // delay in betwelnen reads for stability
}
