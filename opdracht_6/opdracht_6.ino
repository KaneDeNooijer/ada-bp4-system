#include <Servo.h>

const int SERVO_PIN = A5;
const int SENSOR_TRIG_PIN = 10;
const int SENSOR_ECHO_PIN = 9;

Servo servo;

void setup() {
  Serial.begin(9600);

  servo.attach(SERVO_PIN);
  pinMode(SENSOR_TRIG_PIN, OUTPUT); 
  pinMode(SENSOR_ECHO_PIN, INPUT);
}

void loop() {
  long distance = getDistanceCm();
  int angle = map(distance, 10, 4, 0, 180);

  servo.write(angle);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm\tAngle: ");
  Serial.println(angle);

  delay(350);
}

long getDistanceCm() {
  digitalWrite(SENSOR_TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(SENSOR_TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(SENSOR_TRIG_PIN, LOW);

  long duration = pulseIn(SENSOR_ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;

  if (distance > 10) distance = 10;
  if (distance < 4) distance = 4;

  return distance;
}
