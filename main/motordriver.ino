
#ifndef MOTORDRIVER_h

#define MOTORDRIVER_h
#define modifierL 0.886
#define modifierR 1
int enL= 8;
int in1= 5;
int in2 = 6;
int enR= 12;
int in3=11;
int in4=7;

const tenRotationtime = 

void setupMotorPins() {
  // put your setup code here, to run once:
  pinMode(enL, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
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
    delay(660);
    driveMotor(0, 0);
}

void turnLeft(){

    int turnSpeed = -50;
    driveMotor(turnSpeed, -1 * (turnSpeed));
    // around how long it takes to turn 90 degrees
    delay(660);
    driveMotor(0, 0);
}

// example usage:
// void loop() {
//    // put your main code here, to run repeatedly:
//     driveMotor(50,50);
//     delay(2000);
// }


#endif