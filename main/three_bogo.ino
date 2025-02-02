char rand_turn_arr[] = {2, 1, 3, 3, 1, 2, 1, 3, 1, 2, 3, 2, 3, 1, 2, 1, 3, 2, 1, 3, 2, 3, 1, 3, 2, 1, 1, 3, 2, 1, 3, 2, 3, 1, 2, 1, 3, 2, 3, 1, 1, 2, 3, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 1, 2, 3, 1, 2, 3, 1, 2, 1, 3, 1, 3, 2, 3, 1, 2, 3, 1, 2, 1, 3, 3, 1, 2, 3, 1, 3, 1, 2, 2, 1, 3, 1, 3, 2, 1, 3, 2, 3, 1, 2, 3, 1, 3, 2, 1, 2, 1, 3, 2, 1};
int turn_iter = 0;

void blink() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
  
}

void challengeThree() {
  color SEQUENCE[5] = {red, green, blue, green, red};
  int index = 0;
  color currentColor;
  while (index < 5) {
    unsigned int init_time = millis();
    if (getDistance() < MIN_SONIC_DISTANCE) drive();

    while(getDistance() < MIN_SONIC_DISTANCE || millis() - init_time < 500);
    currentColor = getColor();
    if (currentColor == SEQUENCE[index]) {
      index++;
      blink();
    }
    if (getDistance() < MIN_SONIC_DISTANCE) {
      
      if (CALIBRATION) sweep_calibrate();
      int turn = rand_turn_arr[turn_iter];
      turn_iter++;
      if (turn == 1) {
        turnRight();
      }
      else if (turn == 2) {
        turnLeft();
      }
      else if (turn == 3) {
        turnRight();
        turnRight();
      }
    }
  }

}