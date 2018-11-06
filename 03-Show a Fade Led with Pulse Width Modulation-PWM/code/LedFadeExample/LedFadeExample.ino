/*
 * Nguyen Duc Hoang - Programming tutorial channel
 * https://www.youtube.com/c/nguyenduchoang
 * Fade LED using Pulse Width Modulation - PWM 
*/
int PWM_PIN10 = 10;//make pin10 as OUTPUT
//value from 0 -> 255
int step = 5;
int brightness = 255;

void setup() {
  //run once  
  pinMode(PWM_PIN10, OUTPUT);
}

void loop() {  
  //Run repeatedly 
  //ledTurnOnFade(PWM_PIN10, 300); //300 miliseconds / step
  ledTurnOffFade(PWM_PIN10, 100);
}
void ledTurnOnFade(int pinNumber, int delayMiliseconds) {
  brightness = (brightness < 255) ? brightness + step : brightness;
  analogWrite(pinNumber, brightness);//brightness = 0,5,10, 15,...255
  delay(delayMiliseconds);
}
void ledTurnOffFade(int pinNumber, int delayMiliseconds) {
  brightness = (brightness > 0) ? brightness - step : brightness;
  analogWrite(pinNumber, brightness);//brightness = 255, 250, 245,...10, 5, 0
  delay(delayMiliseconds);
}
