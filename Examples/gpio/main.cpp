
/* Driver lib */
#include "gpio.hpp"
#include "exti.hpp"

/**
 * @brief main
 */
int main()
{
    Gpio::Config config;

    // Config leds
    config.mode = Gpio::Mode::OUTPUT_PUSH_PULL;
    config.speed = Gpio::Speed::_10mhz;
    Gpio ledD1(GPIOB, 9, config);
    ledD1.reset();

    Gpio ledD2(GPIOB, 7, config);
    ledD2.reset();

    // Config buttons
    config.mode = Gpio::Mode::INPUT_FLOATING;
    Gpio buttonS1(GPIOC, 0);
    buttonS1.init(config);

    Gpio buttonS2(GPIOC, 1);
    buttonS2.init(config);

    while(true) {
        // Read status buttons
        if(buttonS1.get()) {
            ledD1.set();
        }
        else {
            ledD1.reset();
        }

        if(buttonS2.get()) {
            ledD2.reset();
        }
        else {
            ledD2.set();
        }

        /*   Loop  code   */
        /* -------------- */
        /* -------------- */
        /* -------------- */
        /******************/
    }
}