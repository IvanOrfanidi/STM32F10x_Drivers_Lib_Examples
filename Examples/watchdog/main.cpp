
/* Driver lib */
#include "watchdog.hpp"

/**
 * @brief main
 */
int main()
{
    // Initialisation
    auto iwdg = Watchdog::getInstance();
    iwdg->init(1000);
    iwdg->start();

    while(true) {
        /*   Loop  code   */
        /* -------------- */
        /* -------------- */
        /* -------------- */
        /******************/
    }
}