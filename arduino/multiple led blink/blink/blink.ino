#include "pitches.h"

// melody 1:
int melody1[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, 0, NOTE_B3, NOTE_C4
};
int noteDurations1[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

// melody 2:
int melody2[] = {
  NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, 0, NOTE_E4, NOTE_E4
};
int noteDurations2[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

//// melody 3:
//int melody3[] = {
//  NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, 0, NOTE_E4, NOTE_E4
//};
//int noteDurations2[] = {
//  4, 8, 8, 4, 4, 4, 4, 4
//};
//
//// melody 4:
//int melody2[] = {
//  NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, 0, NOTE_E4, NOTE_E4
//};
//int noteDurations2[] = {
//  4, 8, 8, 4, 4, 4, 4, 4
//};

// melody 5:
int melody5[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4,
  NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4
};

int melody6[] = {
  NOTE_A3, NOTE_A3, NOTE_D4, NOTE_D4, NOTE_G4, NOTE_G4,
  NOTE_FS4, NOTE_FS4, NOTE_D4, NOTE_D4, NOTE_A3, NOTE_A3,
  NOTE_E4, NOTE_E4, NOTE_FS4, NOTE_FS4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_C5,
  NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_FS4,
  NOTE_D4, NOTE_D4, NOTE_A3, NOTE_A3, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_FS4, NOTE_D4, NOTE_D4,
  NOTE_A3, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_FS4, NOTE_FS4,
  NOTE_D4, NOTE_D4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4,
  NOTE_C5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4,
  NOTE_FS4, NOTE_FS4, NOTE_D4, NOTE_D4, NOTE_A3, NOTE_A3
};

int noteDurations6[] = {
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8
};

int noteDurations5[] = {
  4, 4, 8, 8, 4, 8,
  4, 4, 8, 8, 4, 8,
  4, 4, 4, 4, 4, 2, 2,
  4, 4, 8, 8, 4, 8
};

int melody3[] = {
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_E5, 0, 
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_E5, 0,
  NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, 
  NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5
};

int noteDurations3[] = {
  4, 4, 2, 2, 4, 4, 2, 2, 
  4, 4, 2, 2, 4, 4, 2, 2,
  4, 4, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
};

int melody4[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_D4, NOTE_C4
};

int noteDurations4[] = {
  4, 4, 4, 4, 4, 4, 2
};

int melody9[] = {
  NOTE_A1, NOTE_G1, NOTE_E1, NOTE_F1, NOTE_A1, NOTE_C1, NOTE_D1, NOTE_C1,
  NOTE_A2, NOTE_G2, NOTE_E2, NOTE_F2, NOTE_A2, NOTE_C2, NOTE_D2, NOTE_C2,
  NOTE_A1, NOTE_G1, NOTE_E1, NOTE_F1, NOTE_A1, NOTE_C1, NOTE_D1, NOTE_C1,
  NOTE_A4, NOTE_G4, NOTE_E4, NOTE_F4, NOTE_A4, NOTE_C4, NOTE_D4, NOTE_C4,

};

int noteDurations9[] = {
  8, 8, 8, 8, 8, 8, 4, 4,
  8, 8, 8, 8, 8, 8, 4, 4,
  8, 8, 8, 8, 8, 8, 4, 4,
  8, 8, 8, 8, 8, 8, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4
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
