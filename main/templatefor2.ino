
// import stuff?

int challengeTwo()
{

    drive();
    
    while (1)
    {

        float distance = getDistance();
        Serial.println(distance);

        if (distance < MIN_SONIC_DISTANCE)
        {
            Serial.println("stopped");
            reverse();
            calibrate();
            delay(50);
            stop();
            delay(2000);
            enum color currColor = getColor();
            Serial.println(getEnumColor(currColor));
            if (currColor == red)
            {
                Serial.println("U-turn");
                turnRight();
                delay(1000);
                turnRight();
                delay(1000);
                drive();
                delay(1000);
            }
            else if (currColor == blue)
            {
                // turns left
                Serial.println("turn left");
                turnLeft();
                delay(1000);
                drive();
                delay(1000);
            }
            else if (currColor == green)
            {
                // turn right
                Serial.println("turn right");
                turnRight();
                delay(1000);
                drive();
                delay(1000);
            }
            else
            {
                // continue straight
                Serial.println("straight");
                drive();
                delay(1000);
            }
        }
    }
}

bool getting_closer(char direction) {
  float previous = getDistance();
  drive_slow(direction);
  float current = getDistance();
  Serial.print(previous);
  Serial.print("   ");Serial.print(direction);Serial.print("   ");
  Serial.println(current);
  return (current - previous) < 0;
  
  
}

void calibrate() {
  char direction = 'L';
  int switch_dir = 0;
  for (int i = 0; i < 10; i++) {
    if (!getting_closer(direction)) {
      if (direction == 'L') direction = 'R';
      else direction = 'L';
    }
  }
}


