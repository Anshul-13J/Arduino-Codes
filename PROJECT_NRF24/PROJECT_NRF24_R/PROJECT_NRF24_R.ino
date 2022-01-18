/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const int relay=4;
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  pinMode(relay,OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    if(text[0]=='1')
    {
      digitalWrite(relay,LOW);
      delay(1000);
    }
    else
    {
      digitalWrite(relay,HIGH);
      delay(1000);
    }
    
   
  }
}
