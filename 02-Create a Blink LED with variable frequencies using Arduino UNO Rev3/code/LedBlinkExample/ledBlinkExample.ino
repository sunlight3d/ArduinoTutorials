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
  blinkLed(10); //10 miliseconds = 0.01 second => cannot see "blink"
}
void blinkLed(int miliseconds) {
  //This is a function
  digitalWrite(LED_BUILTIN, HIGH); //HIGH => Logic 1
  delay(miliseconds);
  digitalWrite(LED_BUILTIN, LOW);//LOW => Logic 0
  delay(miliseconds);
}
