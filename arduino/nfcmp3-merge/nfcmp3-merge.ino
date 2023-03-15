#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

SoftwareSerial mySoftwareSerial(13, 12); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
String tagId = "None";
byte nuidPICC[4];
int LEDpin = D4;
int bright = 100;    // initial value of LED brightness
int off = 0; 
void printDetail(uint8_t type, int value);

void setup(void)
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  pinMode(LEDpin, OUTPUT); 
  Serial.println("System initialized");
  nfc.begin();
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.volume(20);  //Set volume value. From 0 to 30
  myDFPlayer.play(1);  //Play the first mp3
}

void loop()
{
  readNFC();
  static unsigned long timer = millis();

//  if (millis() - timer > 3000) {
//    timer = millis();
//    myDFPlayer.next();  //Play next mp3 every 3 second.
//  }

  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
}

void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

void readNFC() 
{
 if (nfc.tagPresent())
 {
   NfcTag tag = nfc.read();
//   tag.print();
   tagId = tag.getUidString();
//   Serial.println(tagId);
 if (tag.hasNdefMessage())
    {
      
      NdefMessage message = tag.getNdefMessage();
      
      // If you have more than 1 Message then it wil cycle through them
      int recordCount = message.getRecordCount();
      for (int i = 0; i < recordCount; i++)
      {
        
        NdefRecord record = message.getRecord(i);

        int payloadLength = record.getPayloadLength();
        byte payload[payloadLength];
        record.getPayload(payload);


        String payloadAsString = ""; // Processes the message as a string vs as a HEX value
        for (int c = 0; c < payloadLength; c++) 
        {
          payloadAsString += (char)payload[c];
        }
              
        //Tag Content Shown Below      
        //Original String
        //Serial.println(payloadAsString);       
        //By Manually removing the first 3 characters
        String cleanString = payloadAsString;
        cleanString.remove(0,3);     
        Serial.print("");
        Serial.println(cleanString);
        
        if (cleanString == "audio")
            {
              analogWrite(LEDpin, off);  // set LED brightness as PWM signal
              delay(1000);
              analogWrite(LEDpin, bright); 
              delay(1000);
              analogWrite(LEDpin, off); 
              myDFPlayer.play(1);
            }

            if (cleanString == "level")
            { 
              analogWrite(LEDpin, off);  // set LED brightness as PWM signal
              delay(100);
              analogWrite(LEDpin, bright); 
              delay(100);
              analogWrite(LEDpin, off); 
              delay(100);
              analogWrite(LEDpin, bright); 
              delay(100);
              analogWrite(LEDpin, off); 
              myDFPlayer.play(2);
            }

                    if (cleanString == "1")
            {
              analogWrite(LEDpin, off);  // set LED brightness as PWM signal
              delay(1000);
              analogWrite(LEDpin, bright); 
              delay(1000);
              analogWrite(LEDpin, off); 
              myDFPlayer.play(1);
            }

                    if (cleanString == "2")
            {
              analogWrite(LEDpin, off);  // set LED brightness as PWM signal
              delay(1000);
              analogWrite(LEDpin, bright); 
              delay(1000);
              analogWrite(LEDpin, off); 
              myDFPlayer.play(2);
            }

                    if (cleanString == "3")
            {
              analogWrite(LEDpin, off);  // set LED brightness as PWM signal
              delay(1000);
              analogWrite(LEDpin, bright); 
              delay(1000);
              analogWrite(LEDpin, off); 
              myDFPlayer.play(3);
            }

                    if (cleanString == "4")
            {
              analogWrite(LEDpin, off);  // set LED brightness as PWM signal
              delay(1000);
              analogWrite(LEDpin, bright); 
              delay(1000);
              analogWrite(LEDpin, off); 
              myDFPlayer.play(4);
            }

                    if (cleanString == "5")
            {
              analogWrite(LEDpin, off);  // set LED brightness as PWM signal
              delay(1000);
              analogWrite(LEDpin, bright); 
              delay(1000);
              analogWrite(LEDpin, off); 
              myDFPlayer.play(5);
            }
        String uid = record.getId();
        if (uid != "") 
        {
          Serial.print("  ID: ");
          Serial.println(uid);
        }
      }

 delay(2000);
}}
}
