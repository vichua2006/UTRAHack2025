// Gets the raw sensor data. Samples is the amount of samples to be averaged per reading.
int getData(int samples)
{
  int data = -1;
  for (int i = 0; i < samples; i++)
  {
    delay(SAMPLE_DELAY);
    data += pulseIn(COLOR_OUT, HIGH); // here  we wait until "out" go LOW, we start measuring the duration and stops when "out"  is HIGH again
  };
  return data / samples;
}

// Produces the color detected as a color enum.
enum color getColor()
{
  digitalWrite(COLOR_S2, LOW); // S2/S3  levels define which set of photodiodes we are using LOW/LOW is for RED LOW/HIGH  is for Blue and HIGH/HIGH is for green
  digitalWrite(COLOR_S3, LOW);
  int redVal = getData(SAMPLE_COUNT); // Executing GetData function to  get the value

  digitalWrite(COLOR_S2, LOW);
  digitalWrite(COLOR_S3, HIGH);
  int blueVal = getData(SAMPLE_COUNT);

  digitalWrite(COLOR_S2, HIGH);
  digitalWrite(COLOR_S3, HIGH);
  int greenVal = getData(SAMPLE_COUNT);

  if (redVal < greenVal && redVal < blueVal)
  {
    int confidence = min(abs(greenVal - redVal), abs(blueVal - redVal));
    if (confidence >= CONFIDENCE_THRESHOLD && redVal <= MINIMUM_BRIGHTNESS)
      return red;
    else
      return error;
  }
  else if (greenVal < redVal && greenVal < blueVal)
  {
    int confidence = min(abs(redVal - greenVal), abs(blueVal - greenVal));
    if (confidence >= CONFIDENCE_THRESHOLD && greenVal <= MINIMUM_BRIGHTNESS)
      return green;
    else
      return error;
  }
  else if (blueVal < greenVal && blueVal < redVal)
  {
    int confidence = min(abs(redVal - blueVal), abs(greenVal - blueVal));
    if (confidence >= CONFIDENCE_THRESHOLD && blueVal <= MINIMUM_BRIGHTNESS)
      return blue;
    else
      return error;
  }
  else
    return error;
}

// Given a color enum, it produces the corresponding string equivalent of the color.
String getEnumColor(enum color c)
{
  switch (c)
  {
  case red:
    return "red";
  case blue:
    return "blue";
  case green:
    return "green";
  case error:
    return "error";
  }
}

// Returns true if Red|Green|Blue has been detected.
bool isColorFound()
{
  enum color result = getColor();
  return (result == red || result == green || result == blue);
}