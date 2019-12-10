
/* Driver lib */
#include "gpio.hpp"
#include "exti.hpp"

/**
 * @brief main
 */
int main()
{
    Gpio::Config config;

    // Config led
    config.mode = Gpio::Mode::OUTPUT_PUSH_PULL;
    config.speed = Gpio::Speed::_2mhz;
    Gpio led(GPIOC, 13, config);
    led.reset();

    // Config button
    config.mode = Gpio::Mode::INPUT_FLOATING;
    Gpio button(GPIOB, 6);
    button.init(config);

    while(true) {
        // Read status button
        if(button.get()) {
            led.set();
        }
        else {
            led.reset();
        }

        /*   Loop  code   */
        /* -------------- */
        /* -------------- */
        /* -------------- */
        /******************/
    }
}