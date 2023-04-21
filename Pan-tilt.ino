#include <Servo.h>

Servo servo1; // Paning servo, to move left and right
Servo servo2; // Tilting servo, to move up and down

int pos1 = 90; // initial position of servo 1
int pos2 = 90; // initial position of servo 2
// pos start/end are used to make the movement smoother
int pos_start;
int pos_end;

void setup() {
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'a') {
      pos_start = pos1;
      pos_end = pos1 + 30;
      for (int i = pos_start; i <= pos_end; i++) {
        servo1.write(i);
        delay(15); // small delay between each iteration. It determines how "slow" it moves
      }
      pos1 = pos_end; // update current position of servo 1
    } else if (c == 'd') {
      pos_start = pos1;
      pos_end = pos1 - 30;
      for (int i = pos_start; i >= pos_end; i--) {
        servo1.write(i);
        delay(15); // small delay between each iteration. It determines how "slow" it moves
      }
      pos1 = pos_end; // update current position of servo 1
    } else if (c == 'w') {
      pos_start = pos2;
      pos_end = pos2 + 30;
      for (int i = pos_start; i <= pos_end; i++) {
        servo2.write(i);
        delay(15); // small delay between each iteration. It determines how "slow" it moves
      }
      pos2 = pos_end; // update current position of servo 2
    } else if (c == 's') {
      pos_start = pos2;
      pos_end = pos2 - 30;
      for (int i = pos_start; i >= pos_end; i--) {
        servo2.write(i);
        delay(15); // small delay between each iteration. It determines how "slow" it moves
      }
      pos2 = pos_end; // update current position of servo 2
    }
  }
}
