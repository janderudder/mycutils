#include "bytes.h"

#include <stdio.h>
#include <stdlib.h>



void print_byte_array(uint8_t const* const array, size_t const size)
{
    for (size_t i=0; i<size; ++i)
    {
        printf("%.2x ", array[i]);
    }
    printf("\n");
}



int main(void)
{
    printf(
        "The system is %s endian.\n",
        is_little_endian_system() ? "little":"big"
    );

    uint8_t const num[] = { 0, 0xa1, 0xb2, 0xc3 };
    uint8_t* mem = malloc(sizeof num);

    char *string = bytes_to_string(num, sizeof num, " ");
    printf("bytes:    %s\n", string);
    free(string);

    reverse_bytes(mem, num, sizeof num);
    string = bytes_to_string(mem, sizeof num, " ");
    printf("reversed: %s\n", string);
    free(string);

    to_little_endian(mem, num, sizeof num);
    string = bytes_to_string(mem, sizeof num, " ");
    printf("to LE:    %s\n", string);
    free(string);

    to_big_endian(mem, num, sizeof num);
    string = bytes_to_string(mem, sizeof num, " ");
    printf("to BE:    %s\n", string);
    free(string);

    free(mem);
    return 0;
}
