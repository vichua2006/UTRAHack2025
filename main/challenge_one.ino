bool isColorFound()
{
  // Return true if a color is found
  return true;
}

Color getColor()
{
  // Return the color that is found
  return Color::RED;
}

void driveMotor(int leftSpeed, int rightSpeed)
{
  // Drive the robot
}

enum class Color {
  RED,
  GREEN,
  BLUE,
  NONE
};

enum class ChallengeOneState
{
  SPIRAL_SEARCH,
  FIND_CENTER_ANGLE,
  MOVE_TO_CENTER,
};

int radius = 1;
int angle = 0;
const int baseSpiralSpeed = 10;

ChallengeOneState challengeOneState = ChallengeOneState::SPIRAL_SEARCH;

void challengeOne()
{
  switch (challengeOneState)
  {
    case ChallengeOneState::SPIRAL_SEARCH:
      // Increase the radius every full rotation
      if (angle >= 360)
      {
        radius += 5;
        angle = 0;
      }

      // Drive the robot in a spiral pattern
      driveMotor(baseSpiralSpeed - (baseSpiralSpeed / radius), baseSpiralSpeed);

      // Increment the angle for the next iteration
      angle += 10;

      delay(100);

      if(isColorFound())
      {
        challengeOneState = ChallengeOneState::FIND_CENTER_ANGLE;
      }
      break;
    case ChallengeOneState::FIND_CENTER_ANGLE:
      // Rotate around the robot's axis and record where the edges of the circle are
      // to find out where the center of the circle is
      unsigned long startTime = millis();

      unsigned long timestampOne = 0;
      unsigned long timestampTwo = 0;

      int colorChanges = 0;

      Color currentColor = getColor();

      while(colorChanges < 3) {
        while(getColor() == currentColor) {
          driveMotor(5, -5);
        }

        if(colorChanges == 0) {
          timestampOne = millis();
        } else if(colorChanges == 1) {
          timestampTwo = millis();
        }

        colorChanges++;
      }

      // Calculate the center angle
      int centerAngle = (timestampOne - timestampTwo) / 2;

      // Move to face the center
      break;
    case ChallengeOneState::MOVE_TO_CENTER:
      // Move towards and stop at the center
      // TODO: Implement this state
      break;
  }
}
