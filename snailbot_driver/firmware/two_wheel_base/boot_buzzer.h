
#ifndef _BOOT_BUZZER_H_
#define _BOOT_BUZZER_H_

#include <Arduino.h>

void start_tune (int pin) //Start Up Tune
{
  int melody[] = {262,196,196,229,196,0,247,262};  //Notes
  int note_durations[] = {4,8,8,4,4,4,4,4};
  for (byte note = 0; note < 8; note++)       
  {
    int note_duration = 1000/note_durations[note];
    tone(pin,melody[note],note_duration);
    int pause_between_notes = note_duration * 1.30;
    delay(pause_between_notes);
  }  
}

#endif












