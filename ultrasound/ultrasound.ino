const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 8; // Echo Pin of Ultrasonic Sensor
const int buttonPin = 2;
int buttonState = 0;
const int buzzPin = 3;
const int ledR = 4;
const int ledG = 5;
const int ledV = 6;



void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(buttonPin, INPUT);
   pinMode(ledR, OUTPUT);
   pinMode(ledG, OUTPUT);
   pinMode(ledV, OUTPUT);
   pinMode(buzzPin, OUTPUT);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   buttonState = digitalRead(buttonPin);
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
  if(cm >= 10 || cm < 5){
    digitalWrite(ledR, HIGH);
    digitalWrite(buzzPin, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledV, LOW);
  }
  else if (cm < 10 && cm > 7 ){
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledV, LOW);
  }

  else if (cm <= 7 && cm >= 5 ){
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledV, HIGH);
  }
  else if (cm < 5){
    digitalWrite(ledR, HIGH);
    digitalWrite(buzzPin, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledV, LOW);
  }
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    digitalWrite(buzzPin, LOW);
    
  }
   delay(100);
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
