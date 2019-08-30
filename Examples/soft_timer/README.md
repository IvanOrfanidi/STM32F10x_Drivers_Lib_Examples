This is a small Software Timer example project.
----------------------------------------
**Support Software Timer**
>
---
***Сonstructor***
>**SoftTimer::SoftTimer()**

***Сonstructor***
* @param [in] callback - function for get clock
>**SoftTimer::SoftTimer(std::function<std::time_t()> callback)**

***Сonstructor***
* @param [in] value - time timer 
* @param [in] callback - function for get clock
>**SoftTimer::SoftTimer(std::time_t value, std::function<std::time_t()> callback)**

***Stopped timer***
* @retval true - timer is stop
>**bool isStopped() const**

***Started timer***
* @retval true - timer is starting
>**bool isStarted() const**

***Start timer***
* @param [in] value - time timer 
>**void start(std::time_t value)**

***Stop timer***
>**void stop()**

***Match timer***
* @retval true - match timer 
>**bool isMatch() const**

***Get over time timer***
* @retval over time
>**std::time_t overTime() const**

***Remaining Time**
* @retval remaining time
>**std::time_t remainingTime() const**
