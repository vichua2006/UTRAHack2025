
// enum direction{
//   up,
//   down,
//   left,
//   right
// };


// char path[30][30];
// direction previous = down;

// bool detectWall(){
//   float repetitions = 5.0;
//   int threshhold = 15;
//   float average = 0;

//   for(int i = 0; i < repetitions; i++) average += getDistance() / repetitions;
//   if(average < threshhold) return true;

//   return false;
// }

// // vvv FOR SOME REASON THIS IS NECESSARY vvv
// char getCurrentNode(enum direction last);
// char getCurrentNode(enum direction last){
//   char ans = 0;
//   switch(getColor()){
//     case red: 
//       ans += 192;
//       break;
//     case green: 
//       ans += 128;
//       break;
//     case blue: 
//       ans += 64;
//       break;
//   }

//   switch(last){
//     case up:
//       ans += 48;
//       break;
//     case right:
//       ans += 32;
//       break;
//     case down:
//       ans += 16;
//       break;
//   }

//   for(int i = 1; i <= 8; i << 1){
//     if(detectWall) ans += i;
//     //turn90() **********
//   }

//   return ans;
// }

// void challengeThree(){
//   return;
// }

void challengeThree(color path[], int size){
  while(getDistance() < MIN_SONIC_DISTANCE) turnLeft();

  for(int i = 0; i < size; i++){
    while(getColor() != path[i]){
      driveMotor(DRIVE_SPEED, DRIVE_SPEED);
      if(getDistance() < MIN_SONIC_DISTANCE){
        turnLeft(); turnLeft();
      }
    }

    driveMotor(0,0);
    delay(500);
    ledBlink();
    delay(500);
  }
}
