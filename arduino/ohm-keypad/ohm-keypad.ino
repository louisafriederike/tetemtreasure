/*


  Melody


  Plays a melody


  circuit:


  - 8 ohm speaker on digital pin 8


  created 21 Jan 2010


  modified 30 Aug 2011


  by Tom Igoe


  This example code is in the public domain.


  http://www.arduino.cchttps://www.arduino.cc/en/Tutorial/Tone


*/


#include "pitches.h"
#include <Keypad.h>

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'h','e','l', 'p'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {5, 4, 0, 2}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {14, 12, 13, 15}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

// notes in the melody:

int melody[] = {


  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, 0, NOTE_B3, NOTE_C4

};


// note durations: 4 = quarter note, 8 = eighth note, etc.:

int noteDurations[] = {


  4, 8, 8, 4, 4, 4, 4, 4

};


void setup() {
  Serial.begin(9600);

  // iterate over the notes of the melody:


  for (int thisNote = 0; thisNote < 8; thisNote++) {


    // to calculate the note duration, take one second divided by the note type.


    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.


    int noteDuration = 1000 / noteDurations[thisNote];


    tone(16, melody[thisNote], noteDuration);


    // to distinguish the notes, set a minimum time between them.


    // the note's duration + 30% seems to work well:


    int pauseBetweenNotes = noteDuration * 1.30;


    delay(pauseBetweenNotes);


    // stop the tone playing:


    noTone(16);


  }

}


void loop() {


   char key = keypad.getKey();

  if (key == h){
    Serial.println(key);
      for (int thisNote = 0; thisNote < 8; thisNote++) {


    // to calculate the note duration, take one second divided by the note type.


    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.


    int noteDuration = 1000 / noteDurations[thisNote];


    tone(16, melody[thisNote], noteDuration);


    // to distinguish the notes, set a minimum time between them.


    // the note's duration + 30% seems to work well:


    int pauseBetweenNotes = noteDuration * 1.30;


    delay(pauseBetweenNotes);


    // stop the tone playing:


    noTone(16);


  }
  }

}
