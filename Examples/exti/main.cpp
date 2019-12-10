
/* Driver lib */
#include "exti.hpp"

/// External Handler Interrupt
class ExternalHandler : public SubjectObserver {
  public:
    ExternalHandler() = default;

    /// Virtual function update
    virtual void update()
    {
        __NOP();
    }
};

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
    Exti exti(GPIOC, 2, config);

    // Create interrupt
    exti.createInterrupt();

    // Enable interrupt
    exti.enable();

    ExternalHandler externalHandler;
    exti.attach(&externalHandler);

    while(true) {
        /*   Loop  code   */
        /* -------------- */
        /* -------------- */
        /* -------------- */
        /******************/
    }
}