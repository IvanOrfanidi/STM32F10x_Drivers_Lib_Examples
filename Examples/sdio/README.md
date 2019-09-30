This is a small WatchDog Timer example project.
----------------------------------------
**Support watchdog timer**
>
---
***Get instance class***
* @retval instance class
>**Watchdog** getInstance()**

---
***Initialisation watchdog timer***
* @param [in] period in milliseconds (< 32760) from a watchdog reset until a system reset is issued
>**void init(uint32_t period)**


---
***Enable(start) watchdog***
>**void start()**


---
***Enable(start) watchdog***
>**void enable()**


---
***Reloads(reset) watchdog counter***
>**void reset()**


---
***Reloads(reset) watchdog counter***
>**void reload()**


---
***Sets watchdog reload value***
* @param [in] - reload value
>**void setReload(uint16_t reload)**


---
***Sets watchdog prescaler value***
* @param [in] - prescaler value (4...256)
>**void setPrescaler(Prescaler prescaler)**
