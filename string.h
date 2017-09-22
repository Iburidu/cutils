#include <stddef.h> // size_t
#include "utils.h"
#include "vector.h"

#define STR_STACK_BUFFER 20

typedef vector string;

void  string_create(string* s);
char* string_concat(string* s, const char* str);
char* string_assign(string* s, const char* str);
// void*   string_get(string* s, size_t index);
// size_t  string_size(const string* s);
// bool    string_empty(const string* s);
// void    string_reserve(string* s, size_t new_size);
// size_t  string_capacity(const string* s);
// void    string_shrink_to_fit(string* s);
// void    string_clear(string* s);
// void*   string_insert(string* s, const void* item, size_t index);
// void*   string_erase(string* s, size_t index);
// void    string_resize(string* s, size_t count, const void* item);
// void    string_destroy(string* s);