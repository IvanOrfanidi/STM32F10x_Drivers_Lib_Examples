This is a small RTC example project.
----------------------------------------
**Support Real Time Clock**
>
---
***Get instance class***
* @retval instance class
>**const Rtc* Rtc::getInstance()**


***Sets current time and date***
* @param cnt - Time UNIX
>**void setTime(time_t)**
* @param [in] rtc - Time and date in formate RTC_t
>**void setTime(RTC_t&)**
* @param [in] rtc - Time and date in formate RTC_t
>**void setTime(RTC_t*)**


***Geting current time and date***
* @param [out] rtc - current time
>**void getTime(RTC_t*)**
* @param [out] rtc - current time
>**void getTime(RTC_t&)**
* @retval current time
>**time_t getTime()**


***Initialisation alarm handler***
* @param _callback - callback function
* @param preemption - preemption priority
* @param sub - sub priority
>**void setInterruptHandler(std::function<void()>, uint8_t preemption = PREEMPTION_PRIORITY, uint8_t sub = SUB_PRIORITY)**

***Set alarm clock***
* @param [out] cnt - time alarm
>**void setAlarm(time_t cnt)**
* @param rtc - time alarm
>**void setAlarm(const RTC_t* const rtc)**

***Reset clock alarm***
>**void Rtc::resetAlarm()**


***Converting date to sec***
* @param [in] rtc - date
* @retval time
>**time_t dateToSec(const RTC_t*)**
* @param [in] rtc - date
* @retval time
>**time_t dateToSec(const RTC_t&)**
