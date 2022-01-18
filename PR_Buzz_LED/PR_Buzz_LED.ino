const int pr=A0, buzz=7,led=9;
int value,bright;
void setup()
{
  Serial.begin(9600);
  pinMode(pr, INPUT);
  pinMode(buzz,OUTPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  value= analogRead(pr);
  Serial.println(value);
  bright= map(value,0,570,0,255);
  if(value<=20)
  {
    digitalWrite(buzz,HIGH);  }
  else
  {
    digitalWrite(buzz,LOW);
  }
  analogWrite(led,255-bright);
  delay(2000);
}
