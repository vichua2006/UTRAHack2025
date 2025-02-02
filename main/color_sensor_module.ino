
// PINS:
#define  COLOR_S0 8 
#define COLOR_S1 9
#define COLOR_S2 10
#define COLOR_S3 11 
#define  COLOR_OUT 12

// Sample count is the amount of samples to be averaged per sensor reading (used in getColor)
#define SAMPLE_COUNT 10

// Confidence threshold is the minimum confidence to categorize into a color
#define CONFIDENCE_THRESHOLD 30

// Sample delay is the delay between samples
#define SAMPLE_DELAY 3

enum color{
  red, green, blue, error
};

void  setup() 
{
   pinMode(COLOR_S0,OUTPUT);    //pin modes
   pinMode(COLOR_S1,OUTPUT);
   pinMode(COLOR_S2,OUTPUT);
   pinMode(COLOR_S3,OUTPUT);
   pinMode(COLOR_OUT,INPUT);

   Serial.begin(9600);   //intialize the serial monitor baud rate
   
   digitalWrite(COLOR_S0,HIGH);  //Putting S0/S1 on HIGH/HIGH levels means the output frequency scalling is at 100%  (recommended)
   digitalWrite(COLOR_S1,LOW); //LOW/LOW is off HIGH/LOW is 20% and  LOW/HIGH is  2%
   
}

void loop()                  //Every 2s we select  a photodiodes set and read its data
{
  Serial.println(getEnumColor(getColor()));
}


// Gets the raw sensor data. Samples is the amount of samples to be averaged per reading.
int getData(int samples){
  int data = -1;
  for (int i = 0; i < samples; i++){
   delay(SAMPLE_DELAY);
   data+=pulseIn(COLOR_OUT,HIGH);       //here  we wait until "out" go LOW, we start measuring the duration and stops when "out"  is HIGH again
  };
  return data/samples;
}

// Produces the color detected as a color enum.
enum color getColor(){
   digitalWrite(COLOR_S2,LOW);        //S2/S3  levels define which set of photodiodes we are using LOW/LOW is for RED LOW/HIGH  is for Blue and HIGH/HIGH is for green
   digitalWrite(COLOR_S3,LOW);
   int redVal = getData(SAMPLE_COUNT);                   //Executing GetData function to  get the value

   digitalWrite(COLOR_S2,LOW);
   digitalWrite(COLOR_S3,HIGH);
   int blueVal = getData(SAMPLE_COUNT);

   digitalWrite(COLOR_S2,HIGH);
   digitalWrite(COLOR_S3,HIGH);
   int greenVal = getData(SAMPLE_COUNT);

   if (redVal < greenVal && redVal < blueVal){
    int confidence = min(abs(greenVal - redVal), abs(blueVal - redVal));
    if (confidence >= CONFIDENCE_THRESHOLD) return red;
    else return error;
   }
   else if (greenVal < redVal && greenVal < blueVal){
    int confidence = min(abs(redVal - greenVal), abs(blueVal - greenVal));
    if (confidence >= CONFIDENCE_THRESHOLD) return green;
    else return error;
    }
   else if (blueVal < greenVal && blueVal < redVal){
    int confidence = min(abs(redVal - blueVal), abs(greenVal - blueVal));
    if (confidence >= CONFIDENCE_THRESHOLD) return blue;
    else return error;
    }
   else return error;
}


// Given a color enum, it produces the corresponding string equivalent of the color.
String getEnumColor(enum color c) 
{
   switch (c) 
   {
      case red: return "red";
      case blue: return "blue";
      case green: return "green";
      case error: return "error";
   }
}


// Returns true if Red|Green|Blue has been detected.
bool isColorFound(){
  enum color result = getColor();
  return (result == red || result == green || result == blue);
}