


/* Standart lib */
#include <iostream>
#include <time.h>

/* Driver lib */
#include "spi.hpp"

#define SPI_USE_INTERRUPT

/**
 * 
 */
class Accel
{
  public:
    explicit Accel(Spi* spi) : _spi(spi), _isError(false)
    {
        initGpioCs();
    
        static constexpr uint8_t DEVICE_ID = 0;
        static constexpr uint8_t ID = 0xE5;
        
        const uint8_t chipID = read(DEVICE_ID);
        if(ID != chipID) {
            _isError = true;
            return;
        }
    }
  
    bool isError() const {
        return _isError;
    }

  private:
    Accel() = delete;
    
    void initGpioCs() const
    {
        GPIOA->CRL &= ~GPIO_CRL_CNF4;
        GPIOA->CRL |= GPIO_CRL_MODE4_0;
    }
        
    uint8_t read(uint8_t address) const
    {
        
        
#ifdef SPI_USE_INTERRUPT
         uint16_t data[1];
         data[0] = (address | 0x80) << 8 | 0x00;
        _spi->transmit(data, 1);
#else
        enable();
        _spi->write((address | 0x80) << 8 | 0x00);
#endif

        waitData();

#ifdef SPI_USE_INTERRUPT
        _spi->receive(data, 1);
        data[0] = (address | 0x80) << 8 | 0x00;
        _spi->transmit(data, 1);
        return data[0];
#else
        const auto data = _spi->read();
        _spi->write((address | 0x80) << 8 | 0x00);
        disable();
        return data;
#endif  
    }
    
    /**
    */
    uint8_t write(uint8_t address, uint8_t value) const
    {
        enable();
        
        _spi->write((address | 0x80) << 8 | value);
        
        waitData();
        
        const auto data = _spi->read();
        
        disable();
        
        return data;
    }
    
    void waitData() const
    {
#ifndef SPI_USE_INTERRUPT
        while(!_spi->isSetStatusFlag(SPI_SR_TXE)) {
        }
        while(!_spi->isSetStatusFlag(SPI_SR_RXNE)) {
        }
#endif
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
    
#ifdef SPI_USE_INTERRUPT
    spiConfig.useInterrupt = true;
    spiConfig.management = Spi::Management::HARD;
    spiConfig.ssOutput = true;
#else
    spiConfig.useInterrupt = false;
    spiConfig.management = Spi::Management::SOFT;
    spiConfig.ssOutput = false ;
#endif
    
    auto spi = Spi::getInstance(SPI1);
    spi->init(&spiConfig);
    
    Accel accel(spi);
    
    while(true)
    {
        
    }
    
    return 0;
}
