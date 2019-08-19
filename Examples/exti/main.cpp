
/* Standart lib */
#include <iostream>
#include <time.h>

/* Driver lib */
#include "exti.hpp"

/// External Handler Interrupt
void externalHandler(void);

/**
 * MAIN
 */
int main()
{
    // Update System clock Core
    SystemCoreClockUpdate();

    // Config EXT Interrupt
    Exti::Config config;
    config.gpioPuPd = Exti::GpioPuPd::UP;
    config.mode = Exti::Mode::INTERRUPT;
    config.trigger = Exti::Trigger::RISING_FALLING;

    // Initialisation EXT Interrupt
    Exti exti(GPIOC, 2, &config);
    exti.setInterruptHandler(externalHandler);
    exti.enable();

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
void externalHandler(void)
{
    __NOP();

    /*   Alarm  code   */
    /* --------------- */
    /* --------------- */
    /* --------------- */
    /*******************/
}