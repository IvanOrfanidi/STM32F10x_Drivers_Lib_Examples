
/* Standart lib */
#include <stdio.h>
#include <iostream>
#include <string>

/* Driver lib */
#include "uart.hpp"

/* Driver MCU */
#include "stm32f10x.h"

/**
 * MAIN
 */
int main()
{
    // Update System clock Core
    SystemCoreClockUpdate();

    Uart::Config config;
    config.wordLength = Uart::WordLength::_8B;
    config.stopBits = Uart::StopBits::_1;
    config.parity = Uart::Parity::NO;
    config.mode = Uart::Mode::TX_RX;
    config.hardFlowControl = Uart::HardwareFlowControl::NONE;
    config.baudRate = 115200;
    config.sysClock = SystemCoreClock;

    auto uart1 = Uart::getInstance(USART1);
    uart1->init(&config);

    constexpr size_t SIZE = 256;
    Uart uart2(USART2, &config, SIZE, SIZE);

    uart2.transmit("Hello", 5);
    uart1->transmit("Hello", 5);

    uint8_t buffer[SIZE];
    size_t len = 0;

    while(true) {
        len = uart1->getLength();
        if(len > 0) {
            uart1->receive(buffer, len);
            uart1->transmit(buffer, len);
        }

        len = uart2.getLength();
        if(len > 0) {
            uart2.receive(buffer, len);
            uart2.transmit(buffer, len);
        }
    }
}
