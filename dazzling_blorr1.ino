const int redLedPin = 9;
const int yellowLedPin = 10;
const int greenLedPin = 11;
const int buttonPin = 2;


const int greenLightDuration = 5000;  
const int yellowLightDuration = 2000; 
const int redLightDuration = 5000;    

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
 
  if (digitalRead(buttonPin) == HIGH) {
    PedestrianCrossing();
  } else {
    NormalTrafficCycle();
    
  }
}

void NormalTrafficCycle() {
  // Green light
  Serial.println("Green light ON");
  digitalWrite(greenLedPin, HIGH);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, LOW);
  delay(greenLightDuration);
  if (digitalRead(buttonPin) == HIGH) {
    PedestrianCrossing();
  }

  // Yellow light
  Serial.println("Yellow light ON");
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, HIGH);
  digitalWrite(redLedPin, LOW);
  delay(yellowLightDuration);
  if (digitalRead(buttonPin) == HIGH) {
    PedestrianCrossing();
  }

  // Red light
  Serial.println("Red light ON");
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, HIGH);
  delay(redLightDuration);
  if (digitalRead(buttonPin) == HIGH) {
    PedestrianCrossing();
  }
}

void PedestrianCrossing() {
  // Immediately turn red light on
  Serial.println("Pedestrian Mode:Red light ON");
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, HIGH);

  delay(redLightDuration); 
}