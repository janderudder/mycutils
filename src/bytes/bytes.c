#include "bytes/bytes.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>



bool is_little_endian_system()
{
    uint16_t const n = 1;
    return *(uint8_t*)&n;
}



uint8_t* reverse_bytes(uint8_t* dest, void const* const src, size_t const size)
{
    for (size_t i=0; i<size; ++i)
    {
        dest[i] = ((uint8_t*)src)[size-i-1];
    }
    return dest;
}



void* to_little_endian(uint8_t* dest, void const* const src, size_t const size)
{
    if (is_little_endian_system())
    {
        memcpy(dest, src, size);
        return dest;
    }
    else {
        return reverse_bytes(dest, src, size);
    }
}



void* to_big_endian(uint8_t* dest, void const* const src, size_t const size)
{
    if (is_little_endian_system())
    {
        return reverse_bytes(dest, src, size);
    }
    else {
        memcpy(dest, src, size);
        return dest;
    }
}



char* bytes_to_string(uint8_t const* const bytes, size_t const size, char* separator)
{
    if (!separator) {
        separator = "";
    }
    size_t const sep_len = strlen(separator);
    char* string = malloc(size*2 + size*sep_len + 1);

    for (size_t i=0; i<size; ++i) {
        sprintf(string+i*(2+sep_len), "%.2x%s", bytes[i], separator);
    }
    return string;
}
