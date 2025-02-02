const int speed = 45;
const int turnSpeed = 30;

const int turnBackTimeOffset = 1000;

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
      driveMotor(-30, -30);
      while(getColor() != error) {}
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
      driveMotor(turnSpeed, -turnSpeed);
      while (getColor() == currentColor)
      {
        Serial.println("Swapping colors --- on:");
        Serial.println(currentColor);
        Serial.println("\n");
        Serial.println(getEnumColor(getColor()));
      }

      if (colorChanges == 1)
      {
        timestampOne = millis();
      }
      else if (colorChanges == 2)
      {
        timestampTwo = millis();
      }

      currentColor = getColor();
      colorChanges++;
    }

    driveMotor(0, 0);

    // Calculate the center angle
    startTime = millis();

    centerTime = ((timestampTwo - timestampOne) / 2) + turnBackTimeOffset;
    Serial.print("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA ONE: ");
    Serial.print(timestampOne);
    Serial.print(" --- Two: ");
    Serial.print(timestampTwo);
    Serial.println("\n");
    delay(500);

    while ((millis() - startTime) < centerTime)
    {
      driveMotor(-turnSpeed, turnSpeed);
      Serial.print("Spinning to center + ");
      Serial.print(millis());
      Serial.print(" + StartTime: ");
      Serial.print(startTime);
      Serial.print(" --- centerTime: ");
      Serial.print(centerTime);
      Serial.print(" --- Difference: ");
      Serial.print((millis() - startTime));
      Serial.println("\n");
      Serial.println(getEnumColor(getColor()));
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
