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

const int LED_PIN = 16; // connect the LED to pin 9

char sequence[] = {'e', '5', '0', '#'};
int sequence_index = 0;
unsigned long sequence_start_time = 0;

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT); // Set the LED pin as output
}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY) {
    if (key == sequence[sequence_index]) {
      if (sequence_index == 0) {
        sequence_start_time = millis();
      }
      sequence_index++;

      if (sequence_index == sizeof(sequence)/sizeof(sequence[0])) { // end of sequence
        Serial.println("Sequence detected");
        digitalWrite(LED_PIN, HIGH); // turn the LED on
        delay(60000); // wait for one minute
        digitalWrite(LED_PIN, LOW); // turn the LED off
        sequence_index = 0;
      }
    } else {
      sequence_index = 0;
    }
  }

  if (millis() - sequence_start_time > 10000) { // reset sequence if more than 1 second has passed since the last key press
    sequence_index = 0;
  }

  Serial.println(key); // Log the current key
}
