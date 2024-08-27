#include "ControlButton.h"
#include <wiringPi.h>

#define BUTTON_PIN 3

void setupButtonPin() {
    wiringPiSetup();
    pinMode(BUTTON_PIN, INPUT);
    pullUpDnControl(BUTTON_PIN, PUD_UP);
}

bool isButtonPressed() {
    return digitalRead(BUTTON_PIN) == LOW;
}
