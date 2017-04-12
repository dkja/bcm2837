#ifndef _GPIO_H_
#define _GPIO_H_

#include <cstdint>

namespace BCM2837
{

/// General Purpose Input Output
namespace GPIO
{

    /// Function Select Registers ( GPFSETn ) modes:
    enum Funct {
        in   = 0x00,    /// Input
        out  = 0x01,    /// Output
        alt0 = 0x04,    /// Alternate function 0
        alt1 = 0x05,    /// Alternate function 1
        alt2 = 0x06,    /// Alternate function 2 
        alt3 = 0x07,    /// Alternate function 3
        alt4 = 0x03,    /// Alternate function 4
        alt5 = 0x02,    /// Alternate function 5
        mask = 0x07     /// Function select bits mask (0b0111)
        };

    /// 40 pin GPIO header -> GPIO pins numbers
    enum GPIO_pins {
        pin03 = 2,          /// SDA1
        pin05 = 3,          /// SCL1
        pin07 = 4,          /// GPIO_GCLK
        pin08 = 14,         /// TXD0
        pin10 = 15,         /// RXD0
        pin11 = 17,         /// GPIO_GEN0
        pin12 = 18,         /// GPIO_GEN1
        pin13 = 27,         /// GPIO_GEN2
        pin15 = 22,         /// GPIO_GEN3
        pin16 = 23,         /// GPIO_GEN4
        pin18 = 24,         /// GPIO_GEN5
        pin19 = 10,         /// SPI_MOSI
        pin21 = 9,          /// SPI_MISO
        pin22 = 25,         /// GPIO_GEN6
        pin23 = 11,         /// SPI_SCLK
        pin24 = 8,          /// SPI_CE0_N
        pin26 = 7,          /// SPI_CE1_N
        pin29 = 5,          /// 
        pin31 = 6,          /// 
        pin32 = 12,         /// 
        pin33 = 13,         /// 
        pin35 = 19,         /// 
        pin36 = 16,         /// 
        pin37 = 26,         /// 
        pin38 = 20,         /// 
        pin40 = 21          /// 
    };



class GPIO_driver
{
public:
    void set_function(GPIO_pins pin, Funct fs);


    static GPIO_driver& instance();
protected:
    GPIO_driver();
    virtual ~GPIO_driver();

    static void set_bits(volatile uint32_t*addr, uint32_t val, uint32_t mask);
    

private:
    volatile uint32_t* _gpio_mem;

    /// REGS:
    volatile uint32_t* _gpfsel;
    volatile uint32_t* _gpset;
    volatile uint32_t* _gpclr;
    volatile uint32_t* _gplev;
    volatile uint32_t* _gpeds;
    volatile uint32_t* _gpren;
    volatile uint32_t* _gpfen;
    volatile uint32_t* _gphen;
    volatile uint32_t* _gplen;
    volatile uint32_t* _gparen;
    volatile uint32_t* _gpafen;
    volatile uint32_t* _gppud;
    volatile uint32_t* _gppudclk;
    
};

}   // namespace GPIO
}   // namespace BCM2837

#endif // !_GPIO_H_