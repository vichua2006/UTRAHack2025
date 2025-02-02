
float getDistance()
{

  float totalDistance = 0.0;
  for (int i = 0; i < ULTRA_SAMPLE_SIZE; i++)
  {
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    float duration = pulseIn(ECHO_PIN, HIGH); // measures how long the ECHO_PIN is set to high for (the duration of the)
    float distance = (duration / 58);         // miliseconds * 1000 * speed of sound in air

    totalDistance += distance;
    delay(ULTRA_SAMPLE_DELAY);
  }

  return totalDistance / ULTRA_SAMPLE_SIZE;
  // digitalWrite(TRIGGER_PIN, LOW);
  // delayMicroseconds(2);
  // digitalWrite(TRIGGER_PIN, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(TRIGGER_PIN, LOW);
  // float duration =  pulseIn(ECHO_PIN, HIGH); // measures how long the ECHO_PIN is set to high for (the duration of the)
  // float distance = (duration / 58);         // miliseconds * 1000 * speed of sound in air
  // delay(10);

  // return distance;
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
  for (int i = 0; i < 10; i++) {
    if (!getting_closer(direction)) {
      if (direction == 'L') direction = 'R';
      else direction = 'L';
    }
  }
}

float sweep() {
  drive_sweep('L');
  float min_dist = getDistance();
  for (int i = 0; i < 12; i++) {
    drive_slow('R');
    float temp = getDistance();
    if (temp < min_dist) {
      min_dist = temp;
    }
  }
  return min_dist;
}

char swap_direction(char direction) {
  if (direction == 'R') return 'L';
  else return 'R';
}

void sweep_calibrate() {
  float target_dist = sweep() + 0.20;
  float prev = getDistance();
  float current;
  char direction = 'L';
  for (int i = 0; i < 10; i++) {
    drive_slow(direction);
    current = getDistance();
    if (current < target_dist) {
      break;
    }
    else if (current - prev > 0) {
      direction = swap_direction(direction);
    }
    prev - current;
  }
}


