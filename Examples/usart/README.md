This is a small USART example project
>
----------------------------------------
**Supported USART1 USART2 and USART3 interface**
>
---
***Get instance class***
* @param [in] uart - number object USART
* @retval instance class
>**const Uart* getInstance(USART_TypeDef* const uart)**
---
***Returns the status of class creation***
* @retval true -  success, false - fail
>**bool isCreateClass()**
---
***Initialization UART and interrupt this.***
* @param [in] config - config USART
>**void init(Config* const config)**
---
***Set Baud Rate***
* @param [in] baudRate - baud rate
>**void setBaudRate(uint32_t baudRate)**
---
***Initialization Nested Vectored Interrupt Controller (NVIC)***
* @param [in] preemption - preemption priority
* @param [in] sub- sub priority
>**void initNvic(uint8_t preemption, uint8_t sub)**
---
***Enable USART***
>**void enable() const()**
---
***Disable USART***
>**void disable() const()**
---
***Get length data buffer***
* @retval length data
>**size_t getLength()**
---
***Get is empty data buffer***
* @retval true - empty, false - no empty
>**bool isEmpty()**
---
***Wait complete transfer data***
>**void waitingCompleteTransfer()**
---
***Transmit data***
* @param [in] data - pointer to buffer data
* @param [in] len - length data
>**void transmit(const uint8_t* data, size_t len)**
---
***Write data***
* @param [in] data - pointer to buffer data
>**void write(uint16_t data) const**
---
***Receive data***
* @param [out] data - pointer to buffer data
* @param [in] len - length buffer for data
>**size_t receive(uint8_t* data, size_t len)**
---
***Read data***
* @retval data
>**uint16_t read() const**
---
***Clean transmiter***
>**void cleanTransmit()**
---
***Clean receive***
>**void cleanReceive()**
---
***Get overflow rx buffer***
* @retval true - empty, false - no empty
>**bool isOverflow() const**
---
***Get is error to interface***
* @retval true - error, false - so OK
>**bool isError() const**
---
***Clean error***
>**void cleanError()**
---
