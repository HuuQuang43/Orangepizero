#ifndef CONTROL_LED_H
#define CONTROL_LED_H

void setupLedPins();
void turnOnRedLed();
void turnOnGreenLed();
void turnOnYellowLed();
void turnOffAllLeds();
void normalTrafficLightCycle();
void handleButtonPressDuringGreen(int &greenTime);

#endif
