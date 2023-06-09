#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StringView.h"

/**
 *  sample program
 */
int main(void)
{
    char* input = "some input string";

    // make an immutable view object
    StringView const sv = sv_create(input, 5, 5);

    // check what the view sees
    printf("|");
    sv_print(sv);
    printf("|\n");

    // copy it to a newly allocated string
    char* const output = sv_to_string(sv);
    printf("|%s|\n", output);
    output[0] = 'I';
    printf("|%s|\n", output);

    // free the allocated string
    free(output);

    // we can retrieve the underlying string
    char const* str = sv_referenced_string(sv);
    printf("referenced string: \"%s\" (length = %lu)\n", str, strlen(str));

    // but not modify it
    // str[0] = 'S'; // compile error

    // make a non constant string view object (not really recommended)
    StringView msv = sv_create(input, 11, 6);
    msv.string = "mutable view";                // change pointed to string
    msv.start = 0;                              // update range
    msv.length = strlen(msv.string);            // same ^
    sv_println(msv);

    return 0;
}
