#include "gibranpid.h"

gibranpid::gibranpid(int pot, int pwm, int dir, float kp, float ki, float kd, float sp) {
    potPin = pot;
    pwmPin = pwm;
    dirPin = dir;

    pinMode(pwmPin, OUTPUT);
    pinMode(dirPin, OUTPUT);

    Kp = kp;
    Ki = ki;
    Kd = kd;

    target = sp; 
    error = lastError = 0;
    integral = 0;
    lastTime = millis();

    position = 0;
    pwm = 0;
}


void gibranpid::run() {
    unsigned long now = millis();
    float dt = (now - lastTime) / 1000.0;
    lastTime = now;

    int potValue = analogRead(potPin);
    position = map(potValue, 0, 4095, 0, 180);

    error = target - position;
    integral += error * dt;
    float derivative = (error - lastError) / dt;
    lastError = error;
    float output = Kp * error + Ki * integral + Kd * derivative;

    if (output >= 0) digitalWrite(dirPin, HIGH);
    else digitalWrite(dirPin, LOW);

    pwm = constrain(abs(output), 0, 255);
    analogWrite(pwmPin, pwm);
}

void gibranpid::debug() {
    Serial.print("Posisi: ");
    Serial.print(position);
    Serial.print("  PWM: ");
    Serial.println(pwm);
}
