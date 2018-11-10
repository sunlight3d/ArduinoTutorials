/*
 * Nguyen Duc Hoang - Programming tutorial channel
 * https://www.youtube.com/c/nguyenduchoang
 * Create push button to turn on/off a LED
*/
const int BUTTON_PIN = 2;//Pin2 connected to Button
const int LED_PIN = 13;//Pin13 connected to a LED
int currentButtonState = 0;

void setup() {
  //run once  
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);  
}

void loop() {  
  //Run repeatedly 
  currentButtonState = digitalRead(BUTTON_PIN);
  if(currentButtonState == HIGH) {
  	digitalWrite(LED_PIN, HIGH);    
  } else {
  	digitalWrite(LED_PIN, LOW);
  }
}
