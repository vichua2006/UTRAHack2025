const float MIN_WALL_WIDTH = 100.0;
const float COURSE_SIZE = 1500.0;

void challengeThree(color path[], int size) {
  int pathIndex = 0;
  
  while(pathIndex < size) {
    color currentColor = getColor();
    if(currentColor == path[pathIndex]) {
      driveMotor(0, 0);
      delay(200);
      ledBlink();
      delay(200);
      pathIndex++;
    }
    
    float frontDist = getDistance();
    
    if(frontDist < MIN_SONIC_DISTANCE) {
      driveMotor(0, 0);
      
      turnRight();
      float rightDist = getDistance();
      
      if(rightDist > MIN_SONIC_DISTANCE + MIN_WALL_WIDTH) {
        driveMotor(DRIVE_SPEED, DRIVE_SPEED);
        continue;
      }
      
      turnLeft();
      turnLeft();
      float leftDist = getDistance();
      
      if(leftDist > MIN_SONIC_DISTANCE + MIN_WALL_WIDTH) {
        driveMotor(DRIVE_SPEED, DRIVE_SPEED);
        continue;
      }
      turnLeft();
      
    } else {
      driveMotor(DRIVE_SPEED, DRIVE_SPEED);
    }
  }
  
  driveMotor(0, 0);
}
