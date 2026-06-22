void setup() {
  // Zet pin 10 & 13 aan
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // Zet het ledje op pin 13 uit, en op 10 aan
  digitalWrite(13, LOW);
  digitalWrite(10, HIGH);

  // Wacht 2 seconden
  delay(2000);

  // Zet het ledje op pin 13 aan, en op 10 uit
  digitalWrite(13, HIGH);
  digitalWrite(10, LOW);

  // Wacht 2 seconden
  delay(2000);
}
