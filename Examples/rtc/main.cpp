
/* Standart lib */
#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>

/* Driver lib */
#include "rtc.hpp"

constexpr auto ALARM_TIME = 5U;

/// Alarm Handler Interrupt
void alarmHandler(void);

/**
 * MAIN
 */
int main()
{
    // Update System clock Core
    SystemCoreClockUpdate();

    // Initialisation RTC
    const auto& rtc = Rtc::getInstance();

    ///
    RTC_t time;
    rtc->getTime(&time);

    if(time.year == 2070) {
        time.year = 2019;
        time.month = 1;
        time.mday = 1;
        time.hour = 12;
        time.min = 0;
        time.sec = 0;
        rtc->setTime(time);
    }

    // Print various components of tm structure.
    std::cout << "Year " << time.year << std::endl;
    std::cout << "Month: " << time.month << std::endl;
    std::cout << "Day: " << time.mday << std::endl;
    std::cout << "Time: " << time.hour << ":";
    std::cout << time.min << ":";
    std::cout << time.sec << std::endl;

    /// Get time in unix format
    auto unixTimestamp = rtc->getTime();
    std::cout << "Unix Timestamp " << unixTimestamp << std::endl;

    /// Set alarm handler
    rtc->setInterruptHandler(alarmHandler);

    /// Set alarm time
    unixTimestamp += ALARM_TIME;
    rtc->setAlarm(unixTimestamp);

    while(true) {
        /*   Loop  code   */
        /* -------------- */
        /* -------------- */
        /* -------------- */
        /******************/
    }
}

/**
 * Alarm Handler Interrupt
 */
void alarmHandler(void)
{
    const auto rtc = Rtc::getInstance();
    const auto alarmTime = rtc->getTime();
    rtc->setAlarm(alarmTime + ALARM_TIME);

    /*   Alarm  code   */
    /* --------------- */
    /* --------------- */
    /* --------------- */
    /*******************/
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *   where the assert_param error has occurred.
 * @param file: pointer to the source file name
 * @param line: assert_param error line source number
 * @retval : None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
      ex: ("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while(1) {
    }
}
#endif