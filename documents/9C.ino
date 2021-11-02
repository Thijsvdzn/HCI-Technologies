int speakerPin = 8; 
void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {   
  for(int i = 262; i < 523; i++){
    tone(speakerPin, i, 200);
    delay(20);
  }               
}
