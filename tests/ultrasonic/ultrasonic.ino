const int trigPin = 9;
const int echoPin = 10;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  

  float duration = pulseIn(echoPin, HIGH);  // measures how long the echopin is set to high for (the duration of the)
  float distance = (duration / 58); // miliseconds * 1000 * speed of sound in air

  Serial.println(distance);

  delay(100);
}

