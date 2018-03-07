
int ledPin = 15;
int analogPin = 34;
int motorPin = 5;
// use first channel of 16 channels (started from zero)
//#define LEDC_CHANNEL_0     1

// use 13 bit precission for LEDC timer
//#define LEDC_TIMER_8_BIT  8

// use 5000 Hz as a LEDC base frequency
//#define LEDC_BASE_FREQ     12000

void setup()
{
  ledcSetup(0, 5000, 8);
  ledcAttachPin(motorPin, 0);
  
  Serial.begin(115200);
}

void loop()
{
  //Serial.println("Hello ESP32!");
  //digitalWrite(ledPin, HIGH);
  long input = analogRead(analogPin);
  Serial.println(input);
  //delay(500);
  //digitalWrite(ledPin, LOW);
  //delay(500);
int dutyCycle = map(input, 0, 4095, 0, 255);
  //ledcWrite(motorPin, 200);
  //ledcAnalogWrite(0, dutyCycle);
  //analogWrite(motorPin, 100);
  ledcWrite(0, dutyCycle);
  delay(20);
}

