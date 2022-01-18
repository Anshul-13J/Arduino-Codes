#include <cvzone.h>

SerialData serialData(3, 1); //(numOfValsRec,digitsPerValRec)
int valsRec[3]; // array of int with size numOfValsRec 

int rgb[3]={5,6,7},i,en=8;   // rgb[0]=red ,rgb[1]= green , rgb[2]= blue 

void setup()
{
  pinMode(en,OUTPUT);
  digitalWrite(en,HIGH);
  serialData.begin();
  for(i=0;i<3;i++)
  {
    pinMode(rgb[i],OUTPUT);
    digitalWrite(rgb[i],HIGH);
  }
}
void loop()
{
  // 011 for red
  // 101 for green
  // 110 for blue
  
  serialData.Get(valsRec);
  digitalWrite(rgb[0], valsRec[0]);
  digitalWrite(rgb[1], valsRec[1]);
  digitalWrite(rgb[2], valsRec[2]);
  
  delay(10);
}
