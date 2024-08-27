#include "ControlLed.hpp"
#include "Lib_Button/ControlButton.hpp"
#include <wiringPi.h>
#include <iostream>

#define RED_LED_PIN 0
#define GREEN_LED_PIN 1
#define YELLOW_LED_PIN 2
#define BUTTON_PIN 3

void setupLedPins() {
    wiringPiSetup();
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
}

void turnOnRedLed() {
    turnOffAllLeds();
    digitalWrite(RED_LED_PIN, HIGH);
    std::cout << "Đèn đỏ bật.\n";
}

void turnOnGreenLed() {
    turnOffAllLeds();
    digitalWrite(GREEN_LED_PIN, HIGH);
    std::cout << "Đèn xanh bật.\n";
}

void turnOnYellowLed() {
    turnOffAllLeds();
    digitalWrite(YELLOW_LED_PIN, HIGH);
    std::cout << "Đèn vàng bật.\n";
}

void turnOffAllLeds() {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    std::cout << "Tất cả các đèn tắt.\n";
}

void normalTrafficLightCycle() {
    turnOnRedLed();
    delay(7000);  // Đỏ 7 giây

    turnOnGreenLed();
    int greenTime = 0;
    while (greenTime < 8000) {  // Xanh 8 giây
        handleButtonPressDuringGreen(greenTime);
        delay(1000);
        greenTime += 1000;
    }

    turnOnYellowLed();
    delay(3000);  // Vàng 3 giây
}

void handleButtonPressDuringGreen(int &greenTime) {
    if (isButtonPressed() && greenTime < 6000) {
        turnOnYellowLed();
        delay(2000);  // Vàng 2 giây
        turnOnRedLed();
        std::cout << "Đèn đỏ tạm thời bật.\n";
        delay(5000);  // Đỏ 5 giây
        greenTime += 7000;  // Xanh đã dừng 7 giây
    }
}
