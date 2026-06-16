const int FIRST_PIN = 13;
const int LAST_PIN = 6;
const int DELAY = 100;

/*
 * Loop door all pins heen en zet ze naar OUTPUT
 */
void setup()
{
  for (int i = FIRST_PIN; i >= LAST_PIN; i--) {
    pinMode(i, OUTPUT);
  }
}

/*
 * Loop heen en weer door alle pins
 * en laat telkens 1 pin oplichten
 */
void loop()
{
  // Links naar rechts
  for (int i = FIRST_PIN; i >= LAST_PIN; i--) {
    digitalWrite(i, HIGH);
    delay(DELAY);
    digitalWrite(i, LOW);
  }
  
  // Rechts naar links
  for (int i = LAST_PIN; i <= FIRST_PIN; i++) {
    digitalWrite(i, HIGH);
    delay(DELAY);
    digitalWrite(i, LOW);
  }
}
