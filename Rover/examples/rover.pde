#include <Rover.h>

//  0   - bluetooth-module
//  1   - bluetooth-module
//  2   - right motor - direction
//  3   - right motor - speed
//  4   - left motor - direction
//  5   - left motor - direction
Rover rover(2, 3, 4, 5);

void setup() {
}

void loop() {
  rover.forward();
  delay(1000);
  rover.stop();
  delay(1000);
  rover.back();
  delay(1000);
  rover.stop();
  delay(2000);
}
