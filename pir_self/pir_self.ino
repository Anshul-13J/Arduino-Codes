int pirPin=3, ledPin=5;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW); //give the sensor some time to calibrate 
  Serial.print("calibrating sensor ");
  for(int i = 0; i < 30; i++){
    Serial.print("."); delay(1000);
  }
  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);

}

void loop() {
  if(digitalRead(pirPin) == HIGH){
    digitalWrite(ledPin,HIGH);
    Serial.println("Motion Detected!");
    delay(1000);
  }
  else{
    digitalWrite(ledPin,LOW);
    Serial.println("Motion not detected.");
    delay(1000);
  }
  
}
