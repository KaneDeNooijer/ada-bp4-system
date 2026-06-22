const int LEFT_LED = 11;
const int MIDDLE_BUTTON = 8;
const int RIGHT_LED = 5;

void setup() {
  // Zet alle pins aan
  pinMode(LEFT_LED, OUTPUT);
  pinMode(MIDDLE_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_LED, OUTPUT);

  // Zet LEFT_LED aan
  digitalWrite(LEFT_LED, HIGH);
}

void loop() {
  // Als er op de knop word geklikt, voer een methode uit
  if (digitalRead(MIDDLE_BUTTON)) {
    toggleLeds();

    // Stop het programma terwijl de knop ingedrukt blijft
    while (digitalRead(MIDDLE_BUTTON));
  }
}

void toggleLeds() {
  // Lees de linker en rechter pins uit
  int leftState = digitalRead(LEFT_LED);
  int rightState = digitalRead(RIGHT_LED);

  // Verwissel de waarden met elkaar
  digitalWrite(LEFT_LED, rightState);
  digitalWrite(RIGHT_LED, leftState);
}
