#ifndef GIBRANPID_H
#define GIBRANPID_H

#include <Arduino.h>

class gibranpid {
  private:
    int potPin, pwmPin, dirPin;

    float Kp, Ki, Kd;
    float target;     

    float error, lastError;
    float integral;

    float position;   
    int pwm;          

    unsigned long lastTime;

  public:
    gibranpid(int pot, int pwm, int dir, float kp, float ki, float kd, float sp);
    void run();
    void debug();
};

#endif
