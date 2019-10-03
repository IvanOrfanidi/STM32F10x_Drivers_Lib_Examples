
/* Driver lib */
#include "exti.hpp"

/// External Handler Interrupt
void externalHandler();

/**
 * @brief main
 */
int main()
{
    // Config EXT Interrupt
    Exti::Config config;
    config.gpioPuPd = Exti::GpioPuPd::NOPULL;
    config.mode = Exti::Mode::INTERRUPT;
    config.trigger = Exti::Trigger::RISING_FALLING;

    // Initialisation EXT Interrupt
    Exti exti(GPIOC, 2, &config);

    // Create interrupt
    exti.createInterrupt();

    // Enable interrupt
    exti.enable();

    exti.addSubscriber(externalHandler);

    while(true) {
        /*   Loop  code   */
        /* -------------- */
        /* -------------- */
        /* -------------- */
        /******************/
    }
}

/**
 * External Handler Interrupt
 */
void externalHandler()
{
    __NOP();

    /*   Alarm  code   */
    /* --------------- */
    /* --------------- */
    /* --------------- */
    /*******************/
}