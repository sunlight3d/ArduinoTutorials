void setup() {
  // Setup baudrate,bit rate
  Serial.begin(9600); //9600 bits per second
}

void loop() {
  //Run forever !
  // A0 = "Input analog 0"
  int digitalOutput = analogRead(A0);
//  Serial.print("digital output = ");
//  Serial.println(digitalOutput);
  //10 bit => 0 to 1023
  float analogValue = (5.00 / 1024) * digitalOutput;//Power = 5V
  Serial.print("digitalOutput = ");  
  Serial.print(analogValue, 3);//Eg: 2.123
  Serial.println("V");
  //Delay 1 second
  delay(1000);//1000 miliseconds
}
