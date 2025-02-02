const int speed = 35;

enum class ChallengeOneState
{
  TARGET_SEARCH,
  FIND_CENTER_ANGLE,
  MOVE_TO_CENTER,
  DONE
};

unsigned long startTime = 0;

unsigned long timestampOne = 0;
unsigned long timestampTwo = 0;

int colorChanges = 0;

unsigned long centerTime = 0;

color currentColor;

ChallengeOneState challengeOneState = ChallengeOneState::TARGET_SEARCH;

void challengeOne()
{
  switch (challengeOneState)
  {
  case (ChallengeOneState::TARGET_SEARCH):
    driveMotor(speed, speed);

    if (isColorFound())
    {
      Serial.println("Found Circle\n");
      driveMotor(0, 0);
      delay(500);
      driveMotor(-speed, -speed);
      delay(200);
      driveMotor(0, 0);
      challengeOneState = ChallengeOneState::FIND_CENTER_ANGLE;
    }
    break;
  case (ChallengeOneState::FIND_CENTER_ANGLE):
    // Rotate around the robot's axis and record where the edges of the circle are
    // to find out where the center of the circle is
    startTime = millis();

    timestampOne = 0;
    timestampTwo = 0;

    colorChanges = 0;

    currentColor = getColor();

    while (colorChanges < 3)
    {
      driveMotor(speed, -speed);
      while (getColor() == currentColor)
      {
      }

      if (colorChanges == 1)
      {
        timestampOne = millis() - startTime;
      }
      else if (colorChanges == 2)
      {
        timestampTwo = millis() - startTime;
      }

      currentColor = getColor();
      colorChanges++;
    }

    driveMotor(0, 0);

    // Calculate the center angle
    startTime = millis();

    centerTime = (timestampOne - timestampTwo) / 2;

    while (millis() - startTime < centerTime)
    {
      driveMotor(-speed, speed);
    }

    driveMotor(0, 0);

    Serial.println("Found Center Angle\n");
    challengeOneState = ChallengeOneState::MOVE_TO_CENTER;
    break;
  case (ChallengeOneState::MOVE_TO_CENTER):
    // Move towards and stop at the center
    driveMotor(speed, speed);

    colorChanges = 0;

    currentColor = getColor();

    while (colorChanges < 6)
    {
      while (getColor() == currentColor)
      {
      }

      Serial.println("Color changes: ");
      Serial.println(colorChanges);
      Serial.println("\n");
      currentColor = getColor();
      colorChanges++;
    }

    driveMotor(0, 0);

    Serial.println("Found Center\n");
    challengeOneState = ChallengeOneState::DONE;
    break;
  case ChallengeOneState::DONE:
    // Stop the robot
    driveMotor(0, 0);
    break;
  }
}
