
/* Driver lib */
#include "i2c.hpp"

/**
 * @brief main
 */
int main()
{
    I2c::Config config;
    config.address = 0xAA;
    config.acknowledgedAddress = I2c::AcknowledgedAddress::_7B;
    config.dutyCycle = I2c::DutyCycle::_2tt;
    config.isAck = true;
    config.frequency = 200000;
    config.sysClock = SystemCoreClock;

    I2c* i2c1 = I2c::getInstance(I2C1);
    i2c1->init(&config);
    i2c1->createInterrupt();

    while(true) {
        /*   Loop  code   */
        /* -------------- */
        /* -------------- */
        /* -------------- */
        /******************/
    }
}