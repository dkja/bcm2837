#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <stdexcept>
#include <string>
#include <string.h>

struct bcm2837_error : public std::runtime_error
{

    bcm2837_error(const char* t, bool add_strerrno)
        : std::runtime_error{ std::string{ t }+= add_strerrno ? strerror(errno) : ""}
        {}

};

#endif // !_EXCEPTIONS_H_