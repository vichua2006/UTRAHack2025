Servo servo;

void setupServo() {
  servo.attach(SERVO_PIN);
}

void openGripper() {
    servo.write(20);
}

void closeGripper() {
    servo.write(45);
}
