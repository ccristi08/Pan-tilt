#include <Servo.h>

Servo servo1;
Servo servo2;

int pos1 = 90; // initial position of servo 1
int pos2 = 90; // initial position of servo 2

void setup() {
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'a') {
      pos1 = pos1 + 30;
      servo1.write(pos1);
    } else if (c == 'd') {
      pos1 = pos1 - 30;
      servo1.write(pos1);
    } else if (c == 'w') {
      servo2.write(0);
    } else if (c == 's') {
      servo2.write(180);
    }
  }
}
