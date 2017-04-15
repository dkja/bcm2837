#ifndef _IO_MEM_H_
#define _IO_MEM_H_

#include <cstdint>

namespace BCM2837
{


///
///  Virtual memory mapped into IO registers
///
///  \note There is only one instance for app.
///
class IO_mem
{
  public:
    volatile void*  get();
    uint64_t        size();
    static IO_mem&  instance();


  protected:
    IO_mem();

    IO_mem( const IO_mem&) = delete;
    IO_mem( IO_mem&& ) = delete;
    IO_mem& operator=( const IO_mem&) = delete;
    IO_mem& operator=( IO_mem&& ) = delete;

    virtual ~IO_mem();

  private:

    static uint64_t read_io_base_and_size(uint64_t* out_size, const char* filename);

    volatile void*  _io_memory;
    uint64_t        _size; 
};



}   // namespace BCM2837

#endif // !_IO_MEM_H_