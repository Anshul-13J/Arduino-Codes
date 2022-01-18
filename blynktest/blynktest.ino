#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "Ch7p40EfSZXEPand5ACEKCyanib99iaj";
char ssid[] = "AndroidAP_9786";
char pass[] = "abcd1234";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
