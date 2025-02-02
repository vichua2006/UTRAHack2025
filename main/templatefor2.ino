const int turnMod = 900;

// #define SET_SPEED 75

// //import stuff?

// void setup() {
//   // put your setup code here, to run once:

// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   while(distance != 5//?cm idk how this variable works){
//   //keep going straight
//   driveMotor(SET_SPEED,SET_SPEED)
// }

// if (getColor()==red){
//   //turn and shit
// }
// else if(getColor()==blue){
//   // does some more turning shit
// }
// else if(getColor()==green){
//   // does whatever green does
// }

// }

void reorient(){
  // Reorients robot to 90 degrees

  driveMotor(0, 0);
  delay(500);
  driveMotor(-speed, -speed);
  delay(200);
  driveMotor(0, 0);

  startTime = millis();

  unsigned long timestampOne;
  unsigned long timestampTwo;

  int colorChanges = 0;

  color currentColor = getColor();

  while(getColor() == currentColor) driveMotor(speed, -speed);
  timestampOne = millis();
  currentColor = getColor();
  driveMotor(0, 0);

  while(getColor() == currentColor) driveMotor(-speed, speed);
  timestampTwo = millis();
  driveMotor(0, 0);

  // Calculate the center angle
  startTime = millis();

  centerTime = (timestampTwo - timestampOne) / 2;

  while ((millis() - startTime) < centerTime + turnBackTimeOffset)
  {
    driveMotor(speed, -speed);
  }

  driveMotor(0, 0);
  
  return;
}
