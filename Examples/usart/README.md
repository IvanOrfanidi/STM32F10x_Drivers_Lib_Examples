This is a small USART example project.
---
**Supported USART1 USART2 and USART3 interface.**

***Get instance class***
* @param [in] uart - number object USART
* @retval instance class
>**const Uart* Uart::getInstance(USART_TypeDef* const uart)**


***Get length data buffer***
* @retval length data
>**size_t Uart::getLength()**


***Get is empty data buffer***
* @retval true - empty, false - no empty
>**bool Uart::isEmpty()**

