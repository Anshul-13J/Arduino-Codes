const int led[]={13,12,11,10,9,8,7,6};
const int trigpin=4, echopin=3;
float distance,duration;
int i,j;

void setup()
{
  for(i=0;i<8;i++)
    pinMode(led[i],OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigpin,LOW);
  delay(10);
  digitalWrite(trigpin,HIGH);
  delay(10);
  digitalWrite(trigpin,LOW);
  duration= pulseIn(echopin,HIGH);
  distance= duration* 0.0343/2;
  if(distance>=2 && distance<=330)
    Serial.println(distance);
  if(distance<=3)
  {
    for(i=0;i<8;i++)
      digitalWrite(led[i],HIGH);
    return;
  }
  if(distance>=320)
  {
    for(i=0;i<8;i++)
      digitalWrite(led[i],HIGH);
    return;
  }
    
    
  for(i=0;i<8;i++)
  {
    if(distance>=(40*i) && distance<=(40*(i+1)))
    {
      for(j=0;j<=i;j++)
        digitalWrite(led[j],HIGH);
      for(j=i+1;j<8;j++)
        digitalWrite(led[j],LOW);
    }
  }
  
  
  
  
}

      
      
      
