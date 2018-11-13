const int buzzer = 9; //buzzer to arduino pin 9
const int trigPin = 10;
const int echoPin = 11;

long duration;
int distance;
int toneOutput;

void setup() {
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  toneOutput = distance*10;

  tone(buzzer, toneOutput ); // Send 1KHz sound signal...
  delay(100);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(100);        // ...for 1sec

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.print(" \n ");
  
}
