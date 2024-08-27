#include "Lib_Led/ControlLed.hpp"
#include "Lib_Button/ControlButton.hpp"

int main() {
    setupLedPins();
    setupButtonPin();

    while (1) {
        normalTrafficLightCycle();
    }

    return 0;
}
