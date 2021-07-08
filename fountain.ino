#define YELLOW_LED1 8
#define YELLOW_LED2 7
#define GREEN_LED1 9
#define GREEN_LED2 6
#define BLUE_LED1 10
#define BLUE_LED2 5

#define MIC1 A0
#define MIC2 A1

#define MOTOR1 1

void switchLeds(int led1, int led2, int led3, int state1, int state2, int state3) {
  digitalWrite(led1, state1);
  digitalWrite(led2, state2);
  digitalWrite(led3, state3);
}
void switchMotor(int state) {
  digitalWrite(MOTOR1, state);
}

void processLeds(int v, int led1, int led2, int led3) {
  if(v <= 60) {
    switchLeds(led1, led2, led3, LOW, LOW, LOW);
  }
  else if(v <= 100) {
    switchLeds(led1, led2, led3, HIGH, LOW, LOW);
  }
  else if(v <= 250) {
    switchLeds(led1, led2, led3, HIGH, HIGH, LOW);
  }
  else {
    switchLeds(led1, led2, led3, HIGH, HIGH, HIGH);
  }
}


void setup() {
  pinMode(YELLOW_LED1, OUTPUT); pinMode(YELLOW_LED2, OUTPUT);
  pinMode(GREEN_LED1, OUTPUT); pinMode(GREEN_LED2, OUTPUT);
  pinMode(BLUE_LED1, OUTPUT); pinMode(GREEN_LED2, OUTPUT);

  pinMode(MOTOR1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int volume1 = analogRead(MIC1);
  int volume2 = analogRead(MIC2);
  processLeds(volume1, YELLOW_LED1, GREEN_LED1, BLUE_LED1);
  processLeds(volume2, YELLOW_LED2, GREEN_LED2, BLUE_LED2);
}
