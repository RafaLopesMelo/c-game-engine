#include "kstring.h"
#include "kmemory.h"

#include <string.h>

char *string_duplicate(const char *str) {
    u64 length = string_length(str);
    char *copy = kallocate(length + 1, MEMORY_TAG_STRING);
    kcopy_memory(copy, str, length + 1);

    return copy;
}

u64 string_length(const char *str) { return strlen(str); }

b8 strings_equal(const char *str0, const char *str1) {
    return strcmp(str0, str1) == 0;
}
