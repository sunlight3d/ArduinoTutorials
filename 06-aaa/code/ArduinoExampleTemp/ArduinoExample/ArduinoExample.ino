/*
 * Nguyen Duc Hoang - Programming tutorial channel
 * https://www.youtube.com/c/nguyenduchoang
 * Play a melody using tone() function 
*/
#include "pitches.h"
const int OUPUT_SPEAKER = 8;
int melodies[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G1, NOTE_C5, NOTE_F4, NOTE_GS4, NOTE_C5, NOTE_D6
};

// note durations: in miliseconds
int noteDurations[] = {
  200, 250, 200, 300, 120, 300, 200, 250, 280, 400
};

void setup() {  
  //run once  
  int arrayLength = sizeof(noteDurations)/sizeof(*noteDurations);
  for (int i = 0; i < arrayLength; i++) {
    int noteDuration = noteDurations[i]; 
    tone(OUPUT_SPEAKER, melodies[i], noteDuration);   
    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);    
    noTone(OUPUT_SPEAKER);//stop playing
  }
}

void loop() {   
  //Run repeatedly     
}
