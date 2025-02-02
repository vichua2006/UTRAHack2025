
// // import stuff?

// int challengeTwo()
// {

//     drive();
    
//     while (1)
//     {

//         float distance = getDistance();
//         Serial.println(distance);

//         if (distance < MIN_SONIC_DISTANCE)
//         {
//             Serial.println("stopped");
//             reverse();
//             //calibrate();
//             sweep_calibrate();
//             delay(50);
//             stop();
//             delay(2000);
//             enum color currColor = getColor();
//             Serial.println(getEnumColor(currColor));
//             if (currColor == red)
//             {
//                 Serial.println("U-turn");
//                 turnRight();
//                 delay(1000);
//                 turnRight();
//                 delay(1000);
//                 drive();
//                 delay(1000);
//             }
//             else if (currColor == blue)
//             {
//                 // turns left
//                 Serial.println("turn left");
//                 turnLeft();
//                 delay(1000);
//                 drive();
//                 delay(1000);
//             }
//             else if (currColor == green)
//             {
//                 // turn right
//                 Serial.println("turn right");
//                 turnRight();
//                 delay(1000);
//                 drive();
//                 delay(1000);
//             }
//             else
//             {
//                 // continue straight
//                 Serial.println("straight");
//                 drive();
//                 delay(1000);
//             }
//         }
//     }
// }

// void reorient(){
//   // Reorients robot to 90 degrees
//   driveMotor(0, 0);
//   delay(500);
//   color currentColor = getColor();
//   driveMotor(-30, -30);
//   while(getColor() == currentColor) {}
//   driveMotor(0, 0);

//   startTime = millis();

//   unsigned long timestampOne;
//   unsigned long timestampTwo;

//   int colorChanges = 0;

//   currentColor = getColor();

//   while(getColor() == currentColor) driveMotor(speed, -speed);
//   timestampOne = millis();
//   currentColor = getColor();
//   driveMotor(0, 0);

//   while(getColor() == currentColor) driveMotor(-speed, speed);
//   timestampTwo = millis();
//   driveMotor(0, 0);

//   // Calculate the center angle
//   startTime = millis();

//   centerTime = (timestampTwo - timestampOne) / 2;

//   while ((millis() - startTime) < centerTime + turnBackTimeOffset)
//   {
//     driveMotor(speed, -speed);
//   }

//   driveMotor(0, 0);
  
//   return;
// }

