const int LEDS[] = {0, 1, 2, 3, 4, 5};
const int LEDS_LENGTH = sizeof(LEDS) / sizeof(LEDS[0]);
const int POT_METER = A0;

void setup() {
  for (int i = 0; i < LEDS_LENGTH; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  setLeds(map(analogRead(POT_METER), 0, 1023, LEDS_LENGTH, 0));
}

void setLeds(int ledsOn) {
  for (int i = 0; i < LEDS_LENGTH; i++) {    
    digitalWrite(LEDS[i], i < ledsOn ? LOW : HIGH);
  }
}
