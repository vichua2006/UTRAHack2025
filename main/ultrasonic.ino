
int getDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIGGER_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIGGER_PIN, LOW);

  float duration = pulseIn(ECHO_PIN, HIGH);  // measures how long the ECHO_PIN is set to high for (the duration of the)
  float distance = (duration / 58); // miliseconds * 1000 * speed of sound in air

  return distance;
}