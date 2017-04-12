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
#define GPIO_BASE 0x200000

}


#endif // !_DEFINES_H_