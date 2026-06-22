const int FIRST_PIN = 13;
const int LAST_PIN = 6;
const int DELAY = 100;

void setup() {
  // Loop door all pins heen en zet ze naar OUTPUT
  for (int i = FIRST_PIN; i >= LAST_PIN; i--) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // Loop heen en weer door alle pins, van links naar rechts
  // en laat telkens 1 pin oplichten
  for (int i = FIRST_PIN; i >= LAST_PIN; i--) {
    digitalWrite(i, HIGH);
    delay(DELAY);
    digitalWrite(i, LOW);
  }
  
  // Hetzelfde, maar dan van rechts naar links
  for (int i = LAST_PIN; i <= FIRST_PIN; i++) {
    digitalWrite(i, HIGH);
    delay(DELAY);
    digitalWrite(i, LOW);
  }
}
