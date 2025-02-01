#define COLOR_S2 2
#define COLOR_S3 3

#define COLOR_PWM 4

// #define RED_MIN 
// #define RED_MAX 
// #define RED_THRESHOLD 

// #define GREEN_MIN 
// #define GREEN_MAX 
// #define GREEN_THRESHHOLD 

// #define BLUE_MIN 
// #define BLUE_MAX 
// #define BLUE_THRESHHOLD 

void setup()
{
    Serial.begin(115200);

    pinMode(COLOR_S2, OUTPUT);
    pinMode(COLOR_S3, OUTPUT);

    pinMode(COLOR_PWM, INPUT);
}

void loop()
{
  // Serial.print("Red: ");
  // Serial.print(readRed());
  // Serial.print("\n");
  // delay(100);
  Serial.print("Green: ");
  Serial.print(readGreen());
  Serial.print("\n");
  delay(100);
  // Serial.print("Blue: ");
  // Serial.print(readBlue());
  // Serial.print("\n");
  // delay(100);
}

int readRed() {
  digitalWrite(COLOR_S2, LOW);
  digitalWrite(COLOR_S3, LOW);

  int pw = pulseIn(COLOR_PWM, LOW);

  return pw;

  // return map(pw, RED_MIN, RED_MAX, 255, 0);
}

int readGreen() {
  digitalWrite(COLOR_S2, HIGH);
  digitalWrite(COLOR_S3, HIGH);

  int pw = pulseIn(COLOR_PWM, LOW);

  return pw;

  // return map(pw, GREEN_MIN, GREEN_MAX, 255, 0);
}

int readBlue() {
  digitalWrite(COLOR_S2, LOW);
  digitalWrite(COLOR_S3, HIGH);

  int pw = pulseIn(COLOR_PWM, LOW);

  return pw;

  // return map(pw, BLUE_MIN, BLUE_MAX, 255, 0);
}
