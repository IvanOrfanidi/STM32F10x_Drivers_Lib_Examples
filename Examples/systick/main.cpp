
/* Standart lib */
#include <iostream>
#include <time.h>

/* Driver lib */
#include "systick.hpp"

/**
 * @brief main
 */
int main()
{
    // Get Instance
    auto& systick = Systick::getInstance();

    // Configure 1 tick - 1 msec
    systick.init(SystemCoreClock, 1000);

    uint32_t count = 0U;
    while(true) {
        // Delay 1 Sec
        systick.delay(1000);

        // Out info
        std::cout << ++count << std::endl;
    }
}
