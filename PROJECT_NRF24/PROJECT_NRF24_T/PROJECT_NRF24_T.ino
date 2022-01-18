#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int pir=4;
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  pinMode(pir,INPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  digitalWrite(2,HIGH);
}
void loop() {
  while(digitalRead(pir)== HIGH)
  {
      const char text[] = "1";
      radio.write(&text, sizeof(text));
      Serial.println(text);
      delay(2000);
  }

      const char text[] = "0";
      radio.write(&text, sizeof(text));
      Serial.println(text);
  delay(1000);
}
