int ledPin = 15;
int analogPin = 34;
int motorPinLeft = 5;
int motorPinRight = 17;
// use first channel of 16 channels (started from zero)
#define C_CHANNEL_left     0
#define C_CHANNEL_right     1

// use 13 bit precission for LEDC timer
#define C_TIMER_8_BIT  8

// use 5000 Hz as a LEDC base frequency
#define C_BASE_FREQ     5000

void setup()
{
  ledcSetup(C_CHANNEL_left, C_BASE_FREQ, C_TIMER_8_BIT);
  ledcSetup(C_CHANNEL_right, C_BASE_FREQ, C_TIMER_8_BIT);
  ledcAttachPin(motorPinLeft, C_CHANNEL_left);
  ledcAttachPin(motorPinRight, C_CHANNEL_right);

  pinMode(35, INPUT_PULLUP);
  Serial.begin(115200);
  Serial.println("Hello ESP32!");
}

void loop()
{

  long input = analogRead(analogPin);
  int IR1 = digitalRead(35);
  Serial.println(input);
  Serial.println(IR1);
  int dutyCycle = map(input, 0, 4095, 0, 255);

  ledcWrite(C_CHANNEL_left, dutyCycle);
  ledcWrite(C_CHANNEL_right, dutyCycle);
  delay(20);
}

