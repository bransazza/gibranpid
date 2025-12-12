#include "gibranpid.h"

#define POT_PIN  A0
#define PWM_PIN  5
#define DIR_PIN  4

gibranpid PID(POT_PIN, PWM_PIN, DIR_PIN, 3.0, 0.1, 0.2, 90);

void setup() {
  Serial.begin(115200);  
}

void loop() {
  PID.run();
  PID.debug();
  delay(10);
}
