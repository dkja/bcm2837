#include "gpio.h"
#include "io_mem.h"
#include "defines.h"
namespace BCM2837
{

namespace GPIO
{

    ///
    /// Select function for GPIO pin 
    /// Eg. Select "output" for "pin05"
    ///
    void GPIO_driver::set_function(GPIO_pins pin, Funct f)
    {
        auto reg = pin / PINS_PER_REG;
        auto shift = (pin % PINS_PER_REG) * FSEL_SIZE;
        auto addr = &( _gpfsel[reg] );
        set_bits(addr, (f<<shift), (Funct::mask << shift));
    }
    
    ///
    /// Set pin's value as HIGH
    ///
    void GPIO_driver::set(GPIO_pins pin)
    {
        auto reg = pin / GPIO_REG_SIZE;
        auto shift = pin % GPIO_REG_SIZE;
        _gpset[reg] = (1 << shift);
    }
    
    ///
    /// Get value from GPIO pin
    ///
    bool GPIO_driver::value(GPIO_pins pin)
    {
        auto reg = pin / GPIO_REG_SIZE;
        auto shift = pin % GPIO_REG_SIZE;
        return ((_gplev[reg] & (1 << shift)) ? true : false);
    }

    ///
    /// Set pin's value as HIGH
    ///
    void GPIO_driver::clear(GPIO_pins pin)
    {
        auto reg = pin / GPIO_REG_SIZE;
        auto shift = pin % GPIO_REG_SIZE;
        _gpclr[reg] = (1 << shift);
    }



    ///
    /// Get GPIO_driver instance.
    /// \note There is only one, shared instance GPIO_driver.
    ///
    GPIO_driver& GPIO_driver::instance()
    {
        static GPIO_driver dri{};
        return dri;
    }
    
    GPIO_driver::GPIO_driver()
    {
        uint8_t* gpio_mem = ((uint8_t*)(IO_mem::instance().get()) + GPIO_BASE); 
        _gpio_mem = (volatile uint32_t*)(gpio_mem);

        _gpfsel     = (volatile uint32_t *) (gpio_mem + GPFSEL);
        _gpset      = (volatile uint32_t *) (gpio_mem + GPSET);
        _gpclr      = (volatile uint32_t *) (gpio_mem + GPCLR);
        _gplev      = (volatile uint32_t *) (gpio_mem + GPLEV);
        _gpeds      = (volatile uint32_t *) (gpio_mem + GPEDS);
        _gpren      = (volatile uint32_t *) (gpio_mem + GPREN);
        _gpfen      = (volatile uint32_t *) (gpio_mem + GPFEN);
        _gphen      = (volatile uint32_t *) (gpio_mem + GPHEN);
        _gplen      = (volatile uint32_t *) (gpio_mem + GPLEN);
        _gparen     = (volatile uint32_t *) (gpio_mem + GPAREN);
        _gpafen     = (volatile uint32_t *) (gpio_mem + GPAFEN);
        _gppud      = (volatile uint32_t *) (gpio_mem + GPPUD);
        _gppudclk   = (volatile uint32_t *) (gpio_mem + GPPUDCLK);
    }

    GPIO_driver::~GPIO_driver()
    {
        
    }


    ///
    /// Set masked bits.
    ///
    void GPIO_driver::set_bits(volatile uint32_t* addr, uint32_t value, uint32_t mask)
    {
        uint32_t old = *addr;
        *addr = (old & ~mask) | (value & mask);
    }



}
}