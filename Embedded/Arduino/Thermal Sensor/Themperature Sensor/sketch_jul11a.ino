const int PIN_BACA_SUHU = A0;

void setup() {
  analogReference(INTERNAL);
  Serial.begin(9600);
  Serial.println("Tes Sensor Suhu");
  Serial.println("dengan Arduino Uno");
}

void loop() {
  float suhu = analogRead(PIN_BACA_SUHU)/9.31;
  Serial.println(suhu);
  delay(1000);
}
