
/* Standart lib */
#include <iostream>
#include <time.h>

/* Driver lib */
#include "utils\soft_timer.hpp"

// The general counter
volatile std::time_t counter = 0;

// Two counters
volatile int counter_1 = 0;
volatile int counter_2 = 0;

/**
 * @brief Get clock
 */
std::time_t getClock()
{
    return counter;
}

/**
 * @brief main
 */
int main()
{
    // Periods
    constexpr auto TIMER1_PERIOD = 10000U;
    constexpr auto TIMER2_PERIOD = 20000U;

    // Soft Timer #1
    SoftTimer softTimer_1(TIMER1_PERIOD, getClock);

    // Soft Timer #2
    SoftTimer softTimer_2(getClock);
    softTimer_2.start(TIMER2_PERIOD);

    SoftTimer softTimer_3();

    while(true) {
        ++counter;    // Increment

        if(softTimer_1.isMatch()) {
            ++counter_1;
            softTimer_1.start(TIMER1_PERIOD);
        }

        if(softTimer_2.isMatch()) {
            ++counter_2;
            softTimer_2.start(TIMER2_PERIOD);
        }
    }
}
