#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>
PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
String tagId = "None";
byte nuidPICC[4];
 
void setup(void) 
{
 Serial.begin(115200);
 Serial.println("System initialized");
 nfc.begin();
}
 
void loop() 
{
 readNFC();
}
 
void readNFC() 
{
 if (nfc.tagPresent())
 {
   NfcTag tag = nfc.read();
   tag.print();
   tagId = tag.getUidString();
   Serial.println(tagId);
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
        
        
        Serial.println("\nTag Content Shown Below\n");
        
        Serial.print("Original String: ");
        Serial.println(payloadAsString);
        
        Serial.println("\nBy Manually removing the first 3 characters\n"); 
        String cleanString = payloadAsString;
        cleanString.remove(0,3);
         
        Serial.print("Cleaned String: ");
        Serial.println(cleanString);


        String uid = record.getId();
        if (uid != "") 
        {
          Serial.print("  ID: ");
          Serial.println(uid);
        }
      }
    
 delay(2000);
}
}}
//void playTrack() 
//{
// if (UID = 63 82 C0 98)
// {
//  Audio.play("1.wav");
// }
//}
