/*
 * Nguyen Duc Hoang - Programming tutorial channel
 * https://www.youtube.com/c/nguyenduchoang
*/

void setup() {
  //run once  
  pinMode(LED_BUILTIN, OUTPUT); //make LED_BUILTIN(pin 13) as "OUTPUT"
}

void loop() {
  
  //Run repeatedly
  blinkLed(500);//100 miliseconds
}
void blinkLed(int miliseconds) {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(miliseconds);               // delay 1 second = 1000 ms
  digitalWrite(LED_BUILTIN, LOW);    // voltage LOW => turn off led
  delay(miliseconds);   
}
