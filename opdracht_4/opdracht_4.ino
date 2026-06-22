const int LEDS[] = {0, 1, 2, 3, 4, 5};
const int LEDS_LENGTH = sizeof(LEDS) / sizeof(LEDS[0]);
const int POT_METER = A0;

void setup() {
  // Stel alle LED-pinnen in als uitgang
  for (int i = 0; i < LEDS_LENGTH; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  // Gebruik de waarde van de potentiometer om te bepalen hoeveel LEDs branden 
  setLeds(map(analogRead(POT_METER), 0, 1023, LEDS_LENGTH, 0));
}

void setLeds(int ledsOn) {
  // Schakel het opgegeven aantal LEDs in en de rest uit
  for (int i = 0; i < LEDS_LENGTH; i++) {    
    digitalWrite(LEDS[i], i < ledsOn ? LOW : HIGH);
  }
}
