#include <Servo.h>

enum CycleState {
  IDLE,
  LEFT_CYCLE,
  RIGHT_CYCLE,
  BOTH_CYCLE
};

enum CycleStep {
  FORWARD,
  WAITING,
  BACKWARD
};

const int LEFT_BUTTON_PIN = 10;
const int RIGHT_BUTTON_PIN = 7;
const int SERVO_PIN = A5;

const int MIN_ANGLE = 0;
const int MAX_ANGLE = 120;

Servo servo;
int currentAngle = 0;
CycleState cycleState = IDLE;
CycleStep cycleStep = WAITING;

long waitStartTime = 0;

void setup() {
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);

  servo.attach(SERVO_PIN);
  servo.write(currentAngle);
}

void loop() {
  bool leftPressed = digitalRead(LEFT_BUTTON_PIN) == LOW;
  bool rightPressed = digitalRead(RIGHT_BUTTON_PIN) == LOW;

  updateCycleState(leftPressed, rightPressed);
  executeCycle(leftPressed, rightPressed);
}

void updateCycleState(bool leftPressed, bool rightPressed) {
  CycleState newCycleState = cycleState;

  if (leftPressed && rightPressed) {
    newCycleState = BOTH_CYCLE;
  } else if (leftPressed) {
    newCycleState = LEFT_CYCLE;
  } else if (rightPressed) {
    newCycleState = RIGHT_CYCLE;
  }

  if (newCycleState != cycleState) {
    cycleState = newCycleState;
    cycleStep = FORWARD;
    waitStartTime = 0;
  }
}

void executeCycle(bool leftPressed, bool rightPressed) {
  switch (cycleState) {
    case IDLE:
      break;

    case LEFT_CYCLE:
      if (leftPressed) executeTwoStepCycle(3000);
      break;

    case RIGHT_CYCLE:
      if (rightPressed) executeTwoStepCycle(500);
      break;

    case BOTH_CYCLE:
      if (leftPressed && rightPressed) executeComboCycle();
      break;
  }
}

void executeTwoStepCycle(int durationMs) {
  switch (cycleStep) {
    case FORWARD:
      moveServo(MAX_ANGLE, durationMs);
      if (currentAngle == MAX_ANGLE) cycleStep = BACKWARD;
      break;

    case BACKWARD:
      moveServo(MIN_ANGLE, durationMs);
      if (currentAngle == MIN_ANGLE) cycleStep = FORWARD;
      break;

    case WAITING:
      break;
  }
}

void executeComboCycle() {
  switch (cycleStep) {
    case FORWARD:
      moveServo(MAX_ANGLE, 3000);
      if (currentAngle == MAX_ANGLE) {
        waitStartTime = millis();
        cycleStep = WAITING;
      }
      break;

    case WAITING:
      if (millis() - waitStartTime >= 5000) cycleStep = BACKWARD;
      break;

    case BACKWARD:
      moveServo(MIN_ANGLE, 500);
      if (currentAngle == MIN_ANGLE) cycleStep = FORWARD;
      break;
  }
}

void moveServo(int targetAngle, int durationMs) {
  if (currentAngle == targetAngle) return;

  currentAngle += currentAngle < targetAngle ? 1 : -1;
  
  servo.write(currentAngle);
  delay(durationMs / MAX_ANGLE);
}
