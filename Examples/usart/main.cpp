
/* Driver lib */
#include "uart.hpp"

/**
 * @brief main
 */
int main()
{
    // Config for USART
    Uart::Config config;
    config.mode = Uart::Mode::TX_RX;
    config.baudRate = 115200;
    config.wordLength = Uart::WordLength::_8B;
    config.parity = Uart::Parity::NO;
    config.stopBits = Uart::StopBits::_1B;
    config.hardFlowControl = Uart::HardwareFlowControl::NONE;
    config.sysClock = SystemCoreClock;

    // Create classes USARTs
    auto uart1 = Uart::getInstance(USART1);
    uart1->init(&config);
    uart1->createInterrupt();

    auto uart2 = Uart::getInstance(USART2);
    uart2->init(&config);
    uart2->createInterrupt();

    config.hardFlowControl = Uart::HardwareFlowControl::RTS_CTS;
    auto uart3 = Uart::getInstance(USART3);
    uart3->init(&config);
    uart3->createInterrupt();

    constexpr char msg1[] = "USART #1\r\n";
    uart1->transmit(msg1, strlen(msg1));

    constexpr char msg2[] = "USART #2\r\n";
    uart2->transmit(msg2, strlen(msg2));

    constexpr char msg3[] = "USART #3\r\n";
    uart3->transmit(msg3, strlen(msg3));

    uint8_t buffer[256];
    size_t len = 0;

    while(true) {
        len = uart1->getLength();
        if(len > 0) {
            uart1->receive(buffer, len);
            uart2->transmit(buffer, len);
        }

        len = uart2->getLength();
        if(len > 0) {
            uart2->receive(buffer, len);
            uart1->transmit(buffer, len);
        }

        len = uart3->getLength();
        if(len > 0) {
            uart3->receive(buffer, len);
            uart3->transmit(buffer, len);
        }
    }
}
