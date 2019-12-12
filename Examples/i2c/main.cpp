
/* Driver lib */
#include "i2c.hpp"

/**
 * @brief Class sensor type BME280. Pressure and temperature.
 */
class Bme {
  public:
    explicit AccelWithInterrupt(I2c* port) : _port(port), _isError(false)
    {
        constexpr uint8_t BME280_CHIP_ID_REG = 0xD0;    ///< Chip ID register
        const uint8_t chipId = readReg(BME280_CHIP_ID_REG);
    }

  private:
    /**
    * BME280 or BME280 address is 0x77 if SDO pin is high, and is 0x76 if
    * SDO pin is low.
    */
    enum BmeDefines_t : uint8_t {
        BME280_ADDR = 0xEE,      ///< BME280 address
        BME280_CHIP_ID = 0x60    ///< Chip-id. This value is fixed to 0x55.
    };

    uint8_t readReg(uint8_t reg)
    {
        bool res = _port->isSetStart();
        if(!res) {
            _isError = false;
            return 0;
        }

        res = _port->isSetAddress(

        return res;
    }

    I2c* _port;
    bool _isError;
}

/**
 * @brief main
 */
int main()
{
    I2c::Config config;
    config.address = 0xAA;
    config.acknowledgedAddress = I2c::AcknowledgedAddress::_7B;
    config.dutyCycle = I2c::DutyCycle::_2tt;
    config.isAck = true;
    config.frequency = 200000;
    config.sysClock = SystemCoreClock;

    I2c* i2c1 = I2c::getInstance(I2C1);
    i2c1->init(config);

    while(true) {
        /*   Loop  code   */
        /* -------------- */
        /* -------------- */
        /* -------------- */
        /******************/
    }
}