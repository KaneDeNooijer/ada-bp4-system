/*
 * Zet pin 10 & 13 aan
 */
void setup() {
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

/*
 * Zet bij iedere loop om de 2 seconden de stroom aan en uit
 * op pin 13 & 10, zodat de lampjes om en om gaan branden
 */
void loop() {
  digitalWrite(13, LOW);
  digitalWrite(10, HIGH);
  delay(2000);
  digitalWrite(13, HIGH);
  digitalWrite(10, LOW);
  delay(2000);
}
