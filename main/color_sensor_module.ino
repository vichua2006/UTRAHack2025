// Sample count is the amount of samples to be averaged per sensor reading (used in getColor)
#define SAMPLE_COUNT 10

// Confidence threshold is the minimum confidence to categorize into a color
#define CONFIDENCE_THRESHOLD 35

enum color{
  red, green, blue, error
};

void  setup() 
{
   pinMode(s0,OUTPUT);    //pin modes
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(out,INPUT);

   Serial.begin(9600);   //intialize the serial monitor baud rate
   
   digitalWrite(s0,HIGH);  //Putting S0/S1 on HIGH/HIGH levels means the output frequency scalling is at 100%  (recommended)
   digitalWrite(s1,LOW); //LOW/LOW is off HIGH/LOW is 20% and  LOW/HIGH is  2%
   
}

void loop()                  //Every 2s we select  a photodiodes set and read its data
{
  Serial.println(getEnumColor(getColor()));
}


// Gets the raw sensor data. Samples is the amount of samples to be averaged per reading.
int getData(int samples){
  int data = -1;
  for (int i = 0; i < samples; i++){
   //delay(5);
   data+=pulseIn(out,HIGH);       //here  we wait until "out" go LOW, we start measuring the duration and stops when "out"  is HIGH again
  };
  return data/samples;
}

// Produces the color detected as a color enum.
enum color getColor(){
   digitalWrite(s2,LOW);        //S2/S3  levels define which set of photodiodes we are using LOW/LOW is for RED LOW/HIGH  is for Blue and HIGH/HIGH is for green
   digitalWrite(s3,LOW);
   int redVal = getData(SAMPLE_COUNT);                   //Executing GetData function to  get the value

   digitalWrite(s2,LOW);
   digitalWrite(s3,HIGH);
   int blueVal = getData(SAMPLE_COUNT);

   digitalWrite(s2,HIGH);
   digitalWrite(s3,HIGH);
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