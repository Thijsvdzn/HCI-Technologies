int greenLedPin = 10;
int yellowLedPin = 9;
float sensorValue = 0;
int sensorPin = A0;

void setup(){
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
}

void loop(){
  sensorValue = analogRead(sensorPin);
  sensorValue = (sensorValue/1023)*255;
  analogWrite(greenLedPin, sensorValue);
  analogWrite(yellowLedPin, sensorValue);
  delay(20);
}
