int greenLedPin = 10; 
int redLedPin = 9; 
 
void setup() {           
        
  pinMode(greenLedPin, OUTPUT);   
  pinMode(redLedPin, OUTPUT);      
} 
 
void loop() { 
  analogWrite(greenLedPin, HIGH);   
  analogWrite(redLedPin, LOW); 
  delay(1000);                    
  analogWrite(greenLedPin, LOW);    
  analogWrite(redLedPin, HIGH); 
  delay(1000);                     
}
