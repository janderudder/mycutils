#ifndef BYTES_H_INCLUDED
#define BYTES_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


bool is_little_endian_system();

uint8_t* reverse_bytes(uint8_t* dest, void const* const src, size_t const size);
void* to_little_endian(uint8_t* dest, void const* const src, size_t const size);
void* to_big_endian(uint8_t* dest, void const* const src, size_t const size);

char* bytes_to_string(uint8_t const* const bytes, size_t const size, char* separator);


#endif // BYTES_H_INCLUDED
