/*
 * Nguyen Duc Hoang - Programming tutorial channel
 * https://www.youtube.com/c/nguyenduchoang
 * Create push button to turn on/off a LED
*/
//Define constants
const int BUTTON_PIN = 2;//Pin2 connected to Button
const int LED_PIN = 13;//Pin3 connected to a LED
int currentButtonState = 0;//HIGH / LOW
int previousButtonState = 0;//HIGH / LOW
int numberOfTurnOn = 0;
void setup() {
  //run once  
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);  
  Serial.begin(9600);
}

void loop() {   
  //Run repeatedly   
  currentButtonState = digitalRead(BUTTON_PIN);
  if(currentButtonState != previousButtonState) {
      if(currentButtonState == HIGH) {
      numberOfTurnOn = numberOfTurnOn + 1;
      Serial.print("Number of button pushes: ");
      Serial.println(numberOfTurnOn);
      digitalWrite(LED_PIN, HIGH);    
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  }
  
  previousButtonState = currentButtonState;
}
