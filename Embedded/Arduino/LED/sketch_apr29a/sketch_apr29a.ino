const int PIN_TEST = 6;
const int PIN_SEBELAS = 11;

void setup() {
  pinMode(PIN_SEBELAS, OUTPUT);
  pinMode(PIN_TEST, OUTPUT);
}

void loop() {
  digitalWrite(PIN_TEST, HIGH);
  delay(5000);
  digitalWrite(PIN_SEBELAS, LOW);
  delay(500);
}