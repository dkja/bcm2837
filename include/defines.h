#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <cstdint>

namespace BMC2837
{

/// Memory device filename
#define MEMORY_DEVICE_FILENAME "/dev/mem"
/// BCM2837 on Linux  the base of the peripherals is read from a /proc file
#define DEVICE_TREE_FILENAME "/proc/device-tree/soc/ranges"
/// Offset in DEVICE_TREE_FILENAME for io base address
#define IO_ADDR_OFFSET 0x04
/// IO address lenght in DEVICE_TREE_FILENAME
#define IO_ADDR_LEN 0x04
/// IO memory size offset
#define IO_MEM_SIZE_OFFSET 0x08



/// Base Address of GPIO registers
#define GPIO_BASE       0x200000  
#define GPIO_REG_SIZE   0x32


/// GPIO registers:
#define GPFSEL      0x0000
    #define FSEL_SIZE   3
    #define PINS_PER_REG (GPIO_REG_SIZE / FSEL_SIZE)
#define GPSET       0x001C
#define GPCLR       0x0028
#define GPLEV       0x0034
#define GPEDS       0x0040
#define GPREN       0x004c
#define GPFEN       0x0058
#define GPHEN       0x0064
#define GPLEN       0x0070
#define GPAREN      0x007C
#define GPAFEN      0x0088
#define GPPUD       0x0094
#define GPPUDCLK    0x0098

}


#endif // !_DEFINES_H_