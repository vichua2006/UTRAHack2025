
void driveMotor(int speedA, int speedB) {
    speedA = constrain(speedA, -100, 100);
    speedB = constrain(speedB, -100, 100);

    int pwmA = map(abs(speedA), 0, 100, 0, 255);
    int pwmB = map(abs(speedB), 0, 100, 0, 255);
    //direction of motor A
    if (speedA > 0) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    } else if (speedA < 0) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
    } else {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
    }
    // direction of motor B
    if (speedB > 0) {
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    } else if (speedB < 0) {
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
    } else {
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
    }

    analogWrite(enL, pwmA*modifierL);
    analogWrite(enR, pwmB*modifierR);
}

void turnRight(){

    int turnSpeed = 50;
    driveMotor(turnSpeed, -1 * (turnSpeed));
    // around how long it takes to turn 90 degrees
    delay(quarterPiTime);
    driveMotor(0, 0);
}

void turnLeft(){

    int turnSpeed = -50;
    driveMotor(turnSpeed, -1 * (turnSpeed));
    // around how long it takes to turn 90 degrees
    delay(quarterPiTime);
    driveMotor(0, 0);
}

void drive(){
    driveMotor(SET_SPEED, SET_SPEED);
}

void stop(){
    driveMotor(0, 0);
}

// example usage:
// void loop() {
//    // put your main code here, to run repeatedly:
//     driveMotor(50,50);
//     delay(2000);
// }
