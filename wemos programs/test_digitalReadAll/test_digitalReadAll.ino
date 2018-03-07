// use first channel of 16 channels (started from zero)
#define C_CHANNEL_left     0
#define C_CHANNEL_right     1

// use 13 bit precission for LEDC timer
#define C_TIMER_8_BIT  8

// use 5000 Hz as a LEDC base frequency
#define C_BASE_FREQ     5000


//int ledPin = 15;
int analogPin = 34;
int motorPinLeft = 5;
int motorPinRight = 17;
int dutyCycleLeft = 0;
int dutyCycleRight = 0;
bool qtr[8] = {false,false,false,false,false,false,false,false};


void setup()
{
  pinMode(motorPinLeft, OUTPUT);
  pinMode(motorPinRight, OUTPUT);
  pinMode(analogPin, INPUT);

  pinMode(35, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(14, INPUT);
  pinMode(12, INPUT);

  ledcSetup(C_CHANNEL_left, C_BASE_FREQ, C_TIMER_8_BIT);
  ledcSetup(C_CHANNEL_right, C_BASE_FREQ, C_TIMER_8_BIT);
  ledcAttachPin(motorPinLeft, C_CHANNEL_left);
  ledcAttachPin(motorPinRight, C_CHANNEL_right);

  Serial.begin(115200);
  Serial.println("Hello ESP32!");
}
void updateQTR() {

  qtr[0] = bool(digitalRead(35));
  qtr[1] = bool(digitalRead(32));
  qtr[2] = bool(digitalRead(33));
  qtr[3] = bool(digitalRead(25));
  qtr[4] = bool(digitalRead(26));
  qtr[5] = bool(digitalRead(27));
  qtr[6] = bool(digitalRead(14));
  qtr[7] = bool(digitalRead(12));

}
void loop()
{

  long input = analogRead(analogPin);
  updateQTR();
  for (int i = 0; i <= 7; i++) {
    Serial.print(qtr[i]);
  }
  Serial.println("");
  Serial.println(input);

  dutyCycleLeft = map(input, 0, 4095, 0, 255);

  ledcWrite(C_CHANNEL_left, dutyCycleLeft);
  ledcWrite(C_CHANNEL_right, dutyCycleLeft);
  delay(20);
}

void rechtdoor() {
  dutyCycleLeft = 255;
  dutyCycleRight = 255;
}
void rechts1() {
  dutyCycleLeft = 255;
  dutyCycleRight = 200;
}
void rechts2() {
  dutyCycleLeft = 255;
  dutyCycleRight = 150;
}
void rechts3() {
  dutyCycleLeft = 255;
  dutyCycleLeft = 100;
}
void links1() {
  dutyCycleRight = 255;
  dutyCycleLeft = 200;
}
void links2() {
  dutyCycleRight = 255;
  dutyCycleLeft = 150;
}
void links3() {
  dutyCycleRight = 255;
  dutyCycleLeft = 100;
}


