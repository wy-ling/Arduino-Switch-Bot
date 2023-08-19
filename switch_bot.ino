#include <Servo.h>
#define buzzerPin 5

int servoPin = 12;
Servo Servo1;
int btn5Pin = 8;
int btn10Pin = 7;
// int buzzerPin = 5;
int buttonState = 0;
unsigned long startMillis;
unsigned long currentMillis;
unsigned long period;

void setup() {
  
  Servo1.attach(servoPin);
  startMillis = millis();

  pinMode(btn5Pin, INPUT);
  pinMode(btn10Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {

  int buttonFive = digitalRead(btn5Pin);  // read pushbutton value
  int buttonTen = digitalRead(btn10Pin);

  currentMillis = millis();

  if (buttonFive == HIGH) {  //"Five minutes" button is pressed, buzzer will beep once, timer start
    period = 300000;
    startMillis = currentMillis;
    buttonState = 1;
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(100);

  } 
  if (buttonTen == HIGH) {  //"Ten minutes" button is pressed, buzzer will beep 2 times, timer start

    period = 600000;
    startMillis = currentMillis;
    buttonState = 1;
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(100);
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(100);
    
  }
  if (currentMillis - startMillis >= period && buttonState == 1){  //After period has passed, the servo motor will move and turn off the heater switch (and buzzer will beep once)
    Servo1.write(0);
    delay(500);
    Servo1.write(90);
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(100);
    buttonState = 0;
    startMillis = currentMillis;
  }

}
