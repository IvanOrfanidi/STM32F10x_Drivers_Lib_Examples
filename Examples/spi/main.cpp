

/* Standart lib */
#include <iostream>
#include <time.h>

/* Driver lib */
#include "spi.hpp"

/**
 * 
 */
class AccelWithInterrupt {
  public:
    explicit AccelWithInterrupt(VirtualPort* port) :
        _port(port), _isError(false)
    {
        initGpioCs();

        constexpr uint8_t DEVICE_ID = 0;
        const uint8_t chipType = read(DEVICE_ID);

        constexpr uint8_t CHIP_ID = 0xE5;
        if(CHIP_ID != chipType) {
            _isError = true;
            return;
        }
    }

    bool isError() const
    {
        return _isError;
    }

  private:
    void initGpioCs() const
    {
        GPIOA->CRL &= ~GPIO_CRL_CNF4;
        GPIOA->CRL |= GPIO_CRL_MODE4_0;
        GPIOA->BSRR = GPIO_BSRR_BS4;
    }

    uint8_t read(uint8_t address) const
    {
        uint16_t data[1];
        data[0] = (address | 0x80) << 8;

        enable();
        _port->transmit(data, 1);

        waitData();

        _port->receive(data, 1);
        disable();

        return data[0];
    }

    void waitData() const
    {
        while(_port->isEmpty()) {
        }
    }

    void enable() const
    {
        GPIOA->BSRR = GPIO_BSRR_BR4;
        for(volatile int i = 0; i < 100; i++) {
        }
    }

    void disable() const
    {
        for(volatile int i = 0; i < 100; i++) {
        }
        GPIOA->BSRR = GPIO_BSRR_BS4;
    }

    VirtualPort* _port;
    bool _isError;
};

class AccelWithoutInterrupt {
  public:
    AccelWithoutInterrupt(Spi* spi) : _spi(spi), _isError(false)
    {
        initGpioCs();

        constexpr uint8_t DEVICE_ID = 0;
        const uint8_t chipType = read(DEVICE_ID);

        constexpr uint8_t CHIP_ID = 0xE5;
        if(CHIP_ID != chipType) {
            _isError = true;
            return;
        }
    }

    bool isError() const
    {
        return _isError;
    }

  private:
    void initGpioCs() const
    {
        GPIOB->CRH &= ~GPIO_CRH_CNF12;
        GPIOB->CRH |= GPIO_CRH_MODE12_0;
        GPIOB->BSRR = GPIO_BSRR_BS12;
    }

    void enable() const
    {
        GPIOB->BSRR = GPIO_BSRR_BR12;
        for(volatile int i = 0; i < 100; i++) {
        }
    }

    void disable() const
    {
        for(volatile int i = 0; i < 100; i++) {
        }
        GPIOB->BSRR = GPIO_BSRR_BS12;
    }

    uint8_t read(uint8_t address) const
    {
        enable();
        _spi->write(((address << 1) & 0x7E) | 0x80);

        waitData();

        const auto data = _spi->read();
        disable();
        return data;
    }

    void waitData() const
    {
        _spi->waitingCompleteTransfer();
        while(!_spi->isSetStatusFlag(SPI_SR_RXNE)) {
        }
    }

    Spi* _spi;
    bool _isError;
};

int main()
{
    Spi::Config spiConfig;
    spiConfig.mode = Spi::Mode::MASTER;
    spiConfig.prescaler = Spi::Prescaler::_64P;
    spiConfig.direction = Spi::Direction::TWO_LINE_FULL_DUPLEX;
    spiConfig.size = Spi::Size::_16B;
    spiConfig.polarity = Spi::Polarity::HIGH;
    spiConfig.phase = Spi::Phase::_2E;
    spiConfig.firstBit = Spi::FirstBit::MSB;

    Spi* spi1 = Spi::getInstance(SPI1);
    spi1->init(&spiConfig);
    spi1->createInterrupt();

    AccelWithInterrupt accelWithInterrupt(spi1);
    if(accelWithInterrupt.isError()) {
        // Error Accel
    }

    Spi* spi2 = Spi::getInstance(SPI2);
    spi2->init(&spiConfig);

    AccelWithoutInterrupt accelWithoutInterrupt(spi2);
    if(accelWithoutInterrupt.isError()) {
        // Error Accel
    }

    while(true) {
    }
}
