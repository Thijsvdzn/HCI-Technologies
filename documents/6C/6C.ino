int greenLedPin = 10;
int yellowLedPin = 9;
float sensorValue = 0;
int sensorPin = A0;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, 0, 1023, 0 ,255);
  analogWrite(greenLedPin, sensorValue);
  analogWrite(yellowLedPin, 255 - sensorValue);
  delay(20);
}
