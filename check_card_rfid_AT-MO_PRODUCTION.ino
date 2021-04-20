#include <SPI.h>
#include <RFID.h>
#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN,RST_PIN);

//183 154 242 216 white card
//140 178 95 34 blue key



void setup() {
  Serial.begin(9600);                       
  SPI.begin();
  rfid.init();
}

void loop() {
  
   if(rfid.isCard()){
        if(rfid.readCardSerial()){
            Serial.print(rfid.serNum[0]);
            Serial.print(" ");
            Serial.print(rfid.serNum[1]);
            Serial.print(" ");
            Serial.print(rfid.serNum[2]);
            Serial.print(" ");
            Serial.println(rfid.serNum[3]);
        }
    rfid.halt();
   } 
}
