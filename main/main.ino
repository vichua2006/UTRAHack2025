#define COLOR_S0 5
#define COLOR_S1 6
#define COLOR_S2 2
#define COLOR_S3 3

#define COLOR_PWM 4

// #define RED_MIN 15
// #define RED_MAX 110
// #define RED_THRESHOLD 

// #define GREEN_MIN 20
// #define GREEN_MAX 130
// #define GREEN_THRESHHOLD 

// #define BLUE_MIN 20
// #define BLUE_MAX 130
// #define BLUE_THRESHHOLD 

void setup()
{
    Serial.begin(115200);

    pinMode(COLOR_S0, OUTPUT);
    pinMode(COLOR_S1, OUTPUT);
    pinMode(COLOR_S2, OUTPUT);
    pinMode(COLOR_S3, OUTPUT);

    pinMode(COLOR_PWM, INPUT);

    digitalWrite(COLOR_S0, HIGH);
	  digitalWrite(COLOR_S1, HIGH);
}

void loop()
{
  Serial.print("Red: ");
  Serial.print(readRed());
  Serial.print(" - ");
  Serial.print("Green: ");
  Serial.print(readGreen());
  Serial.print(" - ");
  Serial.print("Blue: ");
  Serial.print(readBlue());
  Serial.print("\n");
  delay(200);
}

int readRed() {
  digitalWrite(COLOR_S2, LOW);
  digitalWrite(COLOR_S3, LOW);

  int pw = pulseIn(COLOR_PWM, LOW);

  // pw = map(pw, RED_MIN, RED_MAX, 255, 0);

  return pw;
}

int readGreen() {
  digitalWrite(COLOR_S2, HIGH);
  digitalWrite(COLOR_S3, HIGH);

  int pw = pulseIn(COLOR_PWM, LOW);

  // pw = map(pw, GREEN_MIN, GREEN_MAX, 255, 0);

  return pw;
}

int readBlue() {
  digitalWrite(COLOR_S2, LOW);
  digitalWrite(COLOR_S3, HIGH);

  int pw = pulseIn(COLOR_PWM, LOW);

  // pw = map(pw, BLUE_MIN, BLUE_MAX, 255, 0);

  return pw;
}
