#include <fstream>
#include <string>

#include <sys/mman.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>

#include "io_mem.h"
#include "defines.h"
#include "exceptions.h"
#include "utils.h"

using namespace std;


namespace BCM2837
{

///
/// Get virtual memory pointer
///
volatile void* IO_mem::get()
{
    return this->_io_memory;
}


///
/// Get IO memory size
///
uint64_t IO_mem::size()
{
    return this->_size;
}

IO_mem& IO_mem::instance()
{
    static IO_mem inst;
    return inst;
}


IO_mem::~IO_mem()
{
    munmap( (void*) _io_memory, _size);
}

///
///	Map IO-memory to virtual memory
///
IO_mem::IO_mem()
{
    uint64_t base{};
    int memfd = -1;

    base = read_io_base_and_size(&_size, DEVICE_TREE_FILENAME);
    memfd = open(MEMORY_DEVICE_FILENAME, O_RDWR | O_SYNC);
    if(memfd < 0)
        throw bcm2837_error{"Cannot open MEMORY_DEVICE_FILENAME: ", true};

    _io_memory = mmap(NULL, _size, (PROT_READ | PROT_WRITE), MAP_SHARED, memfd, base);
    if(_io_memory == MAP_FAILED)
        throw bcm2837_error{"mmap failed: ", true};
    close(memfd);
}




///
/// Read data from device-tree (/proc) about IO. 
///
uint64_t IO_mem::read_io_base_and_size(uint64_t* out_size, const char* filename)
{
    uint64_t io_base{};

    char buff[IO_ADDR_LEN];
    ifstream io_file(filename);

    if (!io_file)
        throw bcm2837_error{"Cannot open device-tree file: ", true};

    if(out_size != nullptr)
    {
        io_file.seekg(IO_MEM_SIZE_OFFSET, ios::beg);
        io_file.read(buff, IO_ADDR_LEN);
        *out_size = convert_endian<uint64_t>(buff, IO_ADDR_LEN);
    }

    io_file.seekg(IO_ADDR_OFFSET, ios::beg);
    io_file.read(buff, IO_ADDR_LEN);
    io_base = convert_endian<uint64_t>(buff, IO_ADDR_LEN);

    return io_base;
}






}