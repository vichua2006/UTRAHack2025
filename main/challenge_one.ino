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

int centerTime = 0;

color currentColor;



ChallengeOneState challengeOneState = ChallengeOneState::TARGET_SEARCH;

void challengeOne()
{
  switch (challengeOneState)
  {
    case (ChallengeOneState::TARGET_SEARCH):
      driveMotor(10, 10);

      if(isColorFound())
      {
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

      while(colorChanges < 3) {
        driveMotor(5, -5);
        while(getColor() == currentColor) {}

        if(colorChanges == 1) {
          timestampOne = millis() - startTime;
        } else if(colorChanges == 2) {
          timestampTwo = millis() - startTime;
        }

        currentColor = getColor();
        colorChanges++;
      }

      driveMotor(0, 0);

      // Calculate the center angle
      centerTime = (timestampTwo - timestampOne) / 2;
      
      startTime = millis();

      while(millis() - startTime < centerTime) {
        driveMotor(-5, 5);
      }

      driveMotor(0, 0);

      challengeOneState = ChallengeOneState::MOVE_TO_CENTER;
      break;
    case (ChallengeOneState::MOVE_TO_CENTER):
      // Move towards and stop at the center
      driveMotor(10, 10);

      colorChanges = 0;

      currentColor = getColor();

      while(colorChanges < 4) {
        while(getColor() == currentColor) {}

        currentColor = getColor();
        colorChanges++;
      }

      driveMotor(0, 0);

      challengeOneState = ChallengeOneState::DONE;
      break;
    case ChallengeOneState::DONE:
      // Stop the robot
      driveMotor(0, 0);
      break;
  }
}
