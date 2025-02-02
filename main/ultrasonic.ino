
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
  int switch_dir = 0;
  for (int i = 0; i < 10; i++) {
    if (!getting_closer(direction)) {
      if (direction == 'L') direction = 'R';
      else direction = 'L';
    }
  }
}


