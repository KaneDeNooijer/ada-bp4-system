#include <Servo.h>

const int SERVO_PIN = A5;
const int SENSOR_TRIG_PIN = 10;
const int SENSOR_ECHO_PIN = 9;

Servo servo;

void setup() {
  // Koppel de servo en stel de sensorpinnen in
  servo.attach(SERVO_PIN);
  pinMode(SENSOR_TRIG_PIN, OUTPUT); 
  pinMode(SENSOR_ECHO_PIN, INPUT);
}

void loop() {
  // Lees de afstand en zet deze om naar een servohoek
  servo.write(map(getDistanceCm(), 10, 4, 0, 180));

  // Kleine delay zodat de servo niet spastisch gaat doen
  delay(350);
}

long getDistanceCm() {
  // Stuur een puls naar de ultrasone sensor
  digitalWrite(SENSOR_TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(SENSOR_TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(SENSOR_TRIG_PIN, LOW);

  // Bereken de afstand op basis van de teruggekomen puls
  long duration = pulseIn(SENSOR_ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;

  // Beperk de afstand tot het bereik dat gebruikt word
  if (distance > 10) distance = 10;
  if (distance < 4) distance = 4;

  return distance;
}
