#include <Servo.h>

// PINS:

// COLOR SENSOR:
#define COLOR_S0 8
#define COLOR_S1 9
#define COLOR_S2 10
#define COLOR_S3 11
#define COLOR_OUT 12

// MOTOR DRIVER:

#define modifierL 0.886
#define modifierR 1
#define enL 7  // 8
#define in1 4  // 5
#define in2 2  // 6
#define enR 13 // 12
#define in3 A0 // 11
#define in4 A1 // 7

// ULTRASONIC CENTIMETER
#define TRIGGER_PIN 5
#define ECHO_PIN 10

/****************************************************** PINS CONFIG END *************************************************************/

// COLOR SENSOR CONFIG

// Sample count is the amount of samples to be averaged per sensor reading (used in getColor)
#define SAMPLE_COUNT 5

// Confidence threshold is the minimum confidence to categorize into a color
#define CONFIDENCE_THRESHOLD 75

// Sample delay is the delay between samples
#define SAMPLE_DELAY 1

// Minimum brightness is to set a minimum brightness colour
#define MINIMUM_BRIGHTNESS 500

// MOTOR MOTION CONFIG

#define SET_SPEED 40

// time it takes to turn 90 degrees
#define quarterPiTime 820

// ULTRASONIC SENSOR

#define MIN_SONIC_DISTANCE 20.0

// Sample count to be averaged per ultrasonic sensor reading
#define ULTRA_SAMPLE_SIZE 5

#define ULTRA_SAMPLE_DELAY 10

enum Challenge
{
  ONE,
  TWO,
  THREE
};

const Challenge currentChallenge = TWO;

enum color
{
  red,
  green,
  blue,
  error
};

Servo myservo;

void setup()
{
  pinMode(enL, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(COLOR_S0, OUTPUT); // pin modes
  pinMode(COLOR_S1, OUTPUT);
  pinMode(COLOR_S2, OUTPUT);
  pinMode(COLOR_S3, OUTPUT);
  pinMode(COLOR_OUT, INPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);

  Serial.begin(115200); // intialize the serial monitor baud rate

  digitalWrite(COLOR_S0, HIGH); // Putting S0/S1 on HIGH/HIGH levels means the output frequency scalling is at 100%  (recommended)
  digitalWrite(COLOR_S1, LOW);  // LOW/LOW is off HIGH/LOW is 20% and  LOW/HIGH is  2%

  delay(3000);

  myservo.attach(6);
}

void loop()
{
  // Serial.println(getEnumColor(getColor()));

  // switch (currentChallenge)
  // {
  // case Challenge::ONE:
  //   challengeOne();
  //   break;
  // case Challenge::TWO:
  //   challengeTwo();
  //   break;
  // case Challenge::THREE:
  //   // challengeThree();
  //   break;
  // }

  for (int pos = 180; pos >= 0; pos -= 1)
  {                     // goes from 180 degrees to 0 degrees
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15);          // waits 15ms for the servo to reach the position
  }

  // Serial.println(getDistance());
}
