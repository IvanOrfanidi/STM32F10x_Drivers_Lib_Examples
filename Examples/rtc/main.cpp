/* Standart lib */
#include <iostream>
#include <time.h>

/* Driver lib */
#include "rtc.hpp"

constexpr auto ALARM_TIME = 5U;

bool isAlarm = false;

/// Alarms Handler Interrupt
void SubscriberFirst();
void SubscriberSecond();

/**
 * @brief Class subject with SubjectObserver basic class 
*/
class SubjectsFirst : public SubjectObserver {
  public:
    /// Constructor default
    SubjectsFirst() = default;

    /// Virtual function
    virtual void update()
    {
        /*   Subjects First code   */
        /* ----------------------- */
        /***************************/

        isAlarm = true;
    }
};

/**
 * @brief Class subject with SubjectObserver basic class 
*/
class SubjectsSecond : public SubjectObserver {
  public:
    /// Constructor default
    SubjectsSecond() = default;

    /// Virtual function
    virtual void update()
    {
        /*   Subjects Second code   */
        /* ------------------------ */
        /****************************/

        isAlarm = true;
    }
};

/**
 * @brief main
 */
int main()
{
    // Initialisation RTC
    auto& rtc = Rtc::getInstance();

    // Time structure
    RTC_t time;
    rtc.getTime(&time);

    // Create and enable interrupt
    rtc.createInterrupt();

    if(time.year == 2070) {
        time.year = 2019;
        time.month = 1;
        time.mday = 1;
        time.hour = 12;
        time.min = 0;
        time.sec = 0;
        rtc.setTime(time);
    }

    // Print various components of tm structure.
    std::cout << "Year " << time.year << std::endl;
    std::cout << "Month: " << time.month << std::endl;
    std::cout << "Day: " << time.mday << std::endl;
    std::cout << "Time: " << time.hour << ":";
    std::cout << time.min << ":";
    std::cout << time.sec << std::endl;

    /// Get time in unix format
    auto unixTimestamp = rtc.getTime();
    std::cout << "Unix Timestamp " << unixTimestamp << std::endl;

    // Register subjects
    SubjectsFirst subjectFirst;
    rtc.attach(&subjectFirst, Observer::Priority::HIGH);

    SubjectsSecond subjectsSecond;
    rtc.attach(&subjectsSecond);

    // Set alarm time
    unixTimestamp += ALARM_TIME;
    rtc.setAlarm(unixTimestamp);

    while(true) {
        /*   Loop  code   */
        /* -------------- */
        /******************/

        if(isAlarm) {
            isAlarm = false;
            const auto alarmTime = rtc.getTime();
            rtc.setAlarm(alarmTime + ALARM_TIME);
        }
    }
}