#ifndef _UTILS_H_
#define _UTILS_H_


template<typename Ret>
Ret convert_endian(const char* buff, unsigned int buff_size)
{
    Ret res{};

    for(unsigned int x=0; x < buff_size; ++x)
    {
        unsigned shift = (buff_size-x-1)*8;
        res |= ( buff[x] << shift );
    }

    return res;
}


#endif // !_UTILS_H_