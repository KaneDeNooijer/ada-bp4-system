const int LEFT_LED = 11;
const int MIDDLE_BUTTON = 8;
const int RIGHT_LED = 5;

void setup()
{
  pinMode(LEFT_LED, OUTPUT);
  pinMode(MIDDLE_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_LED, OUTPUT);

  digitalWrite(LEFT_LED, HIGH);
}

void loop()
{
  if (digitalRead(MIDDLE_BUTTON)) {
    toggleLeds();

    while (digitalRead(MIDDLE_BUTTON));
  }
}

void toggleLeds() {
  int leftState = digitalRead(LEFT_LED);
  int rightState = digitalRead(RIGHT_LED);

  digitalWrite(LEFT_LED, rightState);
  digitalWrite(RIGHT_LED, leftState);
}
