#ifndef CONTROL_LED_HPP
#define CONTROL_LED_HPP

void setupLedPins();
void turnOnRedLed();
void turnOnGreenLed();
void turnOnYellowLed();
void turnOffAllLeds();
void normalTrafficLightCycle();
void handleButtonPressDuringGreen(int &greenTime);

#endif
