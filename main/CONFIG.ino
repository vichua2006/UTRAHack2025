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

const int trigPin = 5;
const int echoPin = 6;

//

/****************************************************** PINS CONFIG END *************************************************************/

// COLOR SENSOR CONFIG

// Sample count is the amount of samples to be averaged per sensor reading (used in getColor)
#define SAMPLE_COUNT 10

// Confidence threshold is the minimum confidence to categorize into a color
#define CONFIDENCE_THRESHOLD 30

// Sample delay is the delay between samples
#define SAMPLE_DELAY 3

