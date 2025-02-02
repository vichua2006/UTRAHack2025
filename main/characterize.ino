int tunableDriveSpeed = DRIVE_SPEED;

float tunableModifierL = modifierL;
float tunableModifierR = modifierR;

// time it takes to turn 90 degrees
int tunableQuarterPiTime = quarterPiTime;

String input;

enum DrivingState
{
    STOP,
    FORWARD,
    TURN
};

DrivingState drivingState = STOP;

void characterize()
{
    while (Serial.available())
    {
        input = Serial.readString();

        if (input[0] == 'f')
        {
            drivingState = FORWARD;

            if (input[1] == 'l')
            {
                tunableModifierL = input.substring(2).toFloat();
            }
            else if (input[1] == 'r')
            {
                tunableModifierR = input.substring(2).toFloat();
            }
            else if (input[1] == 's')
            {
                tunableDriveSpeed = input.substring(2).toInt();
            }
        }
        else if (input[0] == 's')
        {
            drivingState = STOP;
        }
        else if (input[0] == 't')
        {
            drivingState = TURN;

            if(input[1] == 't')
            {
                tunableQuarterPiTime = input.substring(2).toInt();
            }
            else if(input[1] == 's')
            {
                tunableDriveSpeed = input.substring(1).toInt();
            }
        }
    }

    switch (drivingState)
    {
    case FORWARD:
        driveMotor(tunableDriveSpeed, tunableDriveSpeed);
        break;
    case STOP:
        driveMotor(0, 0);
        break;
    case TURN:
        int turnSpeed = 50;
        driveMotor(turnSpeed, -1 * (turnSpeed));
        // around how long it takes to turn 90 degrees
        delay(tunableQuarterPiTime);
        driveMotor(0, 0);
        delay(1000);
        break;
    }
}
