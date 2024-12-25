const int D_PIN = 8;
const int A_PIN = A1;

void setup() {
  pinMode(A_PIN, INPUT);
  pinMode(D_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  float a_input;
  int d_input;

  a_input = analogRead(A_PIN);
  Serial.print(a_input);
  Serial.print('\n');
  delay(100);
}
