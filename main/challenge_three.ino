const float MIN_WALL_WIDTH = 10.0;
const enum color path[] {red,green,blue,green,blue};
const int pathSize = 5;

void challengeThree() {
  int pathIndex = 0;
  timeSave();
  while(pathIndex < pathSize) {
    color currentColor = getColor();
    if(currentColor == path[pathIndex]) {
      driveMotor(0, 0);
      delay(200);
      ledBlink();
      delay(200);
      pathIndex++;
    }
    timeSave();
    
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
