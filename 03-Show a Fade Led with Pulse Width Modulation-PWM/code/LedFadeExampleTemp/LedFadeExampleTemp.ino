/*
 * Nguyen Duc Hoang - Programming tutorial channel
 * https://www.youtube.com/c/nguyenduchoang
*/
int PWM_PIN10 = 10;//make pin10 as OUTPUT
int step = 5;
int brightness = 0;

void setup() {
  //run once  
  pinMode(PWM_PIN10, OUTPUT);  
}

void loop() {
  //Run repeatedly  
  //ledTurnOnFade(PWM_PIN10, 300);
  ledTurnOffFade(PWM_PIN10, 100);
}
void ledTurnOnFade(int pinNumber, int delayMiliseconds) {
    brightness = (brightness < 255) ? brightness + step : brightness;
    analogWrite(pinNumber, brightness);
    delay(delayMiliseconds);
}
void ledTurnOffFade(int pinNumber, int delayMiliseconds) {
    brightness = (brightness > 0) ? brightness - step : brightness;
    analogWrite(pinNumber, brightness);
    delay(delayMiliseconds);
}
