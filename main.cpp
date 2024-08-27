#include "Lib_Led/ControlLed.h"
#include "Lib_Button/ControlButton.h"

int main() {
    setupLedPins();
    setupButtonPin();

    while (1) {
        normalTrafficLightCycle();
    }

    return 0;
}
