#ifndef STRING_VIEW_H_INCLUDED
#define STRING_VIEW_H_INCLUDED

#include <stddef.h>


typedef char const* StringRORef;

typedef struct StringView
{
    StringRORef string;
    size_t start, length;

} StringView;


/**
 *  Create a view on a string, by specifying starting index and length of the view.
 */
StringView sv_create(StringRORef const string, size_t const start, size_t const length);

/**
 *  Retrieve the length of the focused string.
 */
size_t sv_length(StringView const sv);

/**
 *  Retrieve the starting index of the view into the string.
 */
size_t sv_start_index(StringView const sv);

/**
 *  Retrieve the entire underlying string.
 */
StringRORef sv_referenced_string(StringView const sv);

/**
 *  Copy the focused string to an existing memory location.
 */
char* sv_copy_to(StringView const sv, char* dest);

/**
 *  Allocate a new memory location and copy the focused string into it.
 */
char* sv_to_string(StringView const sv);

/**
 *  Print the focused string to stdout.
 */
void sv_print(StringView const sv);

/**
 *  Print the focused string to stdout followed by a new line character.
 */
void sv_println(StringView const sv);



#endif // STRING_VIEW_H_INCLUDED
