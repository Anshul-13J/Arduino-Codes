#include <cvzone.h>

SerialData serialData(1, 3); //(numOfValsRec,digitsPerValRec)
int valsRec[2]; // array of int with size numOfValsRec 

const int led = 6;

void setup()
{
  pinMode(led,OUTPUT);
  serialData.begin();
}
void loop()
{
  serialData.Get(valsRec);
  analogWrite(led,valsRec[0]);
  
  delay(10);
}
