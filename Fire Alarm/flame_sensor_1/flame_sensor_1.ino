// SK GROUP //
//Arduino Flame Sensor
const int buzzerPin = 12;
const int flamePin = 11;
int Flame = HIGH;
int redled = 3;
int greenled = 4;
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);

  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Flame = digitalRead(flamePin);
  if (Flame == LOW) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(greenled, LOW);
    digitalWrite(redled, HIGH);
  }
}
