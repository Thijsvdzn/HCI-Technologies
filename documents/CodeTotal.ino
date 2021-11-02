#define RELAY 3 // the number of the relay pin
const int echoPin = 12;
const int trigPin = 13;
int ledPinRed = 9; 
int ledPinGreen = 10;

bool distanceCheck = false;
bool waterCheck = false;
bool tempCheck = false;

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(RELAY, OUTPUT);
}

void loop() {
  /***************ECHO SENSOR****************/
  // send a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  // wait for the echo
  
  long duration = pulseIn(echoPin, HIGH);
  // convert the time into a distance, the speed of sound is 29 microseconds per centimeter,
  //the pulse traveled forth and back, so we divided the distance by 2
  int cm = duration / 29 / 2;
  //Serial.println(cm);
  delay(200);
  
  //if the measured distance is lower than 10 cm, turn on LED
  //als er iets te dichtbij is, dan zijn het roofdieren, dan blijft de kikker nog even in winterslaap
  
  if(cm<10){
     distanceCheck = false;
  }
  
  //else turn off LED
  else{
    distanceCheck = true;
  }
  
  /*************ECHO SENSOR END********************/

  /************WATER SENSOR***********************/
  
  //minder dan 300 water betekent dat de kikker kan ademen  
  if (analogRead(A0) <= 300) {
    waterCheck = true;
    } else {
    waterCheck = false;
    }

  

  
  /***********EINDE WATER SENSOR******************/


  /***********TEMP SENSOR*********/
  
  if (analogRead(A1)>= 575) {
    tempCheck = true;
    } else {
    tempCheck = false;
  }
  
  /**************EINDE TEMP SENSOR************/
  
  /**********CONDITIONCHECK**************/
  Serial.println("        ");
  Serial.println((String)"tempCheck: " + (analogRead(A1))); //tempCheck
  Serial.println((String)"waterCheck: " + (analogRead(A0))); //waterCheck
  Serial.println((String)"distanceCheck: " + cm); //distanceCheck

  if(distanceCheck==true && waterCheck==true && tempCheck==true){
    digitalWrite(ledPinGreen, 255);
    digitalWrite(ledPinRed, 0);
    Serial.println("De kikker ontwaakt");
    delay(10);
    digitalWrite(RELAY, HIGH);
    delay(300);
    digitalWrite(RELAY, LOW);
    delay(300);
  }
  
  //else turn off LED
  else{
    digitalWrite(ledPinGreen, 0);
    digitalWrite(ledPinRed, 255);
    Serial.println("De kikker blijft slapen");
    delay(10);
    digitalWrite(RELAY, LOW);
    delay(300);
  }
  
  /*********EINDE CONDITIONCHECK***************/

  
delay(1000);
}
