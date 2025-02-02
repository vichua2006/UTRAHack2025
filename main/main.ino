// PINS:

// COLOR SENSOR:
#define  COLOR_S0 8 
#define COLOR_S1 9
#define COLOR_S2 10
#define COLOR_S3 11 
#define  COLOR_OUT 12

// MOTOR DRIVER:

#define modifierL 0.886
#define modifierR 1
const int enL= 7; //8
const int in1= 4; //5
const int in2 = 2; //6
const int enR= 13; //12
const int in3= A0; //11
const int in4= A1; //7

// ULTRASONIC CENTIMETER


#define TRIGGER_PIN 5
#define ECHO_PIN 6

//

/****************************************************** PINS CONFIG END *************************************************************/

// COLOR SENSOR CONFIG

// Sample count is the amount of samples to be averaged per sensor reading (used in getColor)
#define SAMPLE_COUNT 10

// Confidence threshold is the minimum confidence to categorize into a color
#define CONFIDENCE_THRESHOLD 30

// Sample delay is the delay between samples
#define SAMPLE_DELAY 3

enum color
{
  red,
  green,
  blue,
  error
};


void setup() {
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
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600); // intialize the serial monitor baud rate

  digitalWrite(COLOR_S0, HIGH); // Putting S0/S1 on HIGH/HIGH levels means the output frequency scalling is at 100%  (recommended)
  digitalWrite(COLOR_S1, LOW);  // LOW/LOW is off HIGH/LOW is 20% and  LOW/HIGH is  2%
    Serial.begin(9600);
}



void loop() {
    Serial.println(getEnumColor(getColor()));
    delay(10);
}