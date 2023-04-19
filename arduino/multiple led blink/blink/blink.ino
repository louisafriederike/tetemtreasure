#include "pitches.h"



int melody2[] = {
NOTE_E2, NOTE_E2, NOTE_E2, NOTE_E2, NOTE_E2, NOTE_E2, NOTE_E2, NOTE_E2
};
int noteDurations2[] = {
2, 2, 2, 2, 2, 2, 2, 2,
};


int melody4[] = {
NOTE_A2, NOTE_A2, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4
};
int noteDurations4[] = {
2, 2, 4, 4, 4, 4, 4, 2, 2
};


int melody1[] = {
NOTE_B4, NOTE_B4, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C6, NOTE_C6
};
int noteDurations1[] = {
2, 2, 4, 4, 4, 4, 4, 2, 2
};


int melody6[] = {
NOTE_E2, NOTE_E2, NOTE_E2, NOTE_E2, NOTE_E2, NOTE_E2, NOTE_E2, NOTE_E2
};
int noteDurations6[] = {
2, 2, 4, 4, 4, 4, 4, 2, 2
};


int melody3[] = {
NOTE_D3, NOTE_D3, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_E5
};
int noteDurations3[] = {
2, 2, 4, 4, 4, 4, 4, 2, 2
};


int melody5[] = {
NOTE_E5, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_E2, NOTE_E2
};
int noteDurations5[] = {
2, 2, 4, 4, 4, 4, 4, 2, 2
};

// speaker pins
const int speakerPin1 = 16;
const int speakerPin2 = 14;
const int speakerPin3 = 12;
const int speakerPin4 = 13;
const int speakerPin5 = 15;
const int speakerPin6 = 1;


void playMelody(int speakerPin, int *melody, int *noteDurations, int melodyLength) {
  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(speakerPin, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(speakerPin);
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  // play the first melody on speaker connected to digital pin 8
//  playMelody(speakerPin1, melody7, noteDurations7, sizeof(melody7)/sizeof(melody1[0]));
//  // play the second melody on speaker connected to digital pin 9
  playMelody(speakerPin1, melody1, noteDurations1, sizeof(melody1)/sizeof(melody1[0]));
  playMelody(speakerPin2, melody2, noteDurations2, sizeof(melody2)/sizeof(melody2[0]));
   playMelody(speakerPin3, melody3, noteDurations3, sizeof(melody3)/sizeof(melody3[0]));
  playMelody(speakerPin4, melody4, noteDurations4, sizeof(melody4)/sizeof(melody4[0]));
   playMelody(speakerPin5, melody5, noteDurations5, sizeof(melody5)/sizeof(melody5[0]));
  playMelody(speakerPin6, melody6, noteDurations6, sizeof(melody6)/sizeof(melody6[0]));
}
