#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo myservo; // create servo object to control a servo
void setup() {
  Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin(); // Initialize SPI bus
  mfrc522.PCD_Init(); // Initialize MFRC522 RFID reader
  Serial.println("Ready to read RFID tag");
  myservo.attach(8);
  lcd.begin(16,2);
  lcd.print("Door Security ");
  
}

void loop() {
  String id="";
  // Look for new cards
  
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Print the card ID in hex format
    Serial.print("Card ID:");
    
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      id+= String(mfrc522.uid.uidByte[i], HEX);
      
    }
     if (id == "7347132f")
     {
      lcd.clear();
      
      lcd.print("Access Granted");
      Serial.print("\nAccess Granted");
      delay(500);
      Serial.print("\nOpened");
      myservo.write(180);
      delay(5000);
      Serial.print("\nclosed");
    myservo.write(0);
    id="";
    }
  else
  {
    Serial.print("\nAccess Denied");
  
  }
  
    
    // myservo.write(0);
    // if  == RC522.serNum[73 47 13 2F];
    

    Serial.println();
    mfrc522.PICC_HaltA(); // Stop reading
  }}
