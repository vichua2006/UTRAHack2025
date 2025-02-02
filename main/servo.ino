Servo servo;

void setupServo() {
  servo.attach(SERVO_PIN);
}

void openGripper() {
    servo.write(0); // 20
}

void closeGripper() {
    servo.write(55); // 45
}

void defaultGripper() {
    servo.write(40);
}
