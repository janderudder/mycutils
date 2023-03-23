#include "string-view/StringView.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


StringView sv_create(char const* const string, size_t const start, size_t const length)
{
    return (StringView){string, start, length};
}


size_t sv_length(StringView const sv)
{
    return sv.length;
}


size_t sv_start_index(StringView const sv)
{
    return sv.start;
}


char const* sv_referenced_string(StringView const sv)
{
    return sv.string;
}


char* sv_copy_to(StringView const sv, char* dest)
{
    memcpy(dest, &sv.string[sv.start], sv.length);
    dest[sv.length] = '\0';
    return dest;
}


char* sv_to_string(StringView const sv)
{
    char* string = malloc(sv.length+1);
    return (string) ?
        sv_copy_to(sv, string):
        string;
}


void sv_print(StringView const sv)
{
    for (size_t i=0; i<sv.length; ++i) {
        printf("%c", sv.string[sv.start+i]);
    }
}


void sv_println(StringView const sv)
{
    sv_print(sv);
    printf("\n");
}
