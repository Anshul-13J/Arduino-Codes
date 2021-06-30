/* This code consists of a pir sensor, a photoresistor ,a led
   and a buzzer. This System rings the buzzer and blink the
   led when some motion is detected in dark surroundings.
   This is helpful in case of homes and shops where we can
   power an alarm when some motion is detected when there is
   dark, generally at night when no one should be there in the
   shop. If motion is detected this system will trigger of it's
   own.
   This also comes equipped with a slide switch which can be
   used to turn on and off the whole machine.
   
   Coded and designed by: Anshul Nigam
   Dated: 30/06/2021
*/


const int pir=12,led=11,pResistor=A0,buzzer=7;
int value,pirValue;
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(pResistor,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(pir,INPUT);
  Serial.begin(9600);
}

void loop()
{
  pirValue=digitalRead(pir);
  value= analogRead(pResistor);
  if(pirValue == HIGH && value<=100)
  {
    digitalWrite(buzzer,HIGH);
    analogWrite(led,255);
    delay(500);
    analogWrite(led,0);
    delay(500);
  }
  else
  {
    analogWrite(led,0);
    digitalWrite(buzzer,LOW);
  }
  Serial.print("PHOTO RESISTOR:" );
  Serial.print(value);
  if(pirValue==HIGH)
    Serial.println("\nPIR SENSOR: Active");
  else
    Serial.println("\nPIR SENSOR: Disabled");
  delay(1000);
}

  