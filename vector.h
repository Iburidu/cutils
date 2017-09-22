#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stddef.h> // size_t
#include <stdio.h> // printf
#include "utils.h"

// Initialize the struct - This works as a constructor in C++
#define VECTOR_CREATE(type, vec) \
    vector_create(&vec, sizeof(type))
    
// Automatically copies the original value to a local variable (for constants) and converts from other types.
// This behaviour causes double copying in those unfortunate cases, when you do not use constants and other types
// In these cases you should use the underlying function instead.
#define VECTOR_PUSH(type, vec, item) \
    do { \
        type e = (type)item; \
        vector_push(&vec, &e); \
    } while(false)

// Gets the value of the item on the given index
// No bound checking -> undefined behaviour on overindexing
#define VECTOR_GET(type, vec, index) \
    *(type*)vector_get(&vec, index)
    
// Returns the current size of the vector    
#define VECTOR_SIZE(vec) \
    vector_size(&vec)
    
// Return true if the vector is empty, false otherwise
#define VECTOR_EMPTY(vec) \
    vector_empty(&vec)
    
// Allocates more space if the requested capacity is higher than the current
#define VECTOR_RESERVE(vec, capacity) \
    vector_reserve(&vec, capacity)
    
// Get the current allocated item numbers of the vector
#define VECTOR_CAPACITY(vec) \
    vector_capacity(&vec)
    
// Deallocates memory above size of the vector
#define VECTOR_SHRINK(vec) \
    vector_shrink_to_fit(&vec)
    
// Invalidates all elements from the container
#define VECTOR_CLEAR(vec) \
    vector_clear(&vec)
    
// Inserts a new element to the given place
// Return value will not work this way - use the underlying function instead if you need the return value
#define VECTOR_INSERT(type, vec, item, index) \
    do { \
        type e = (type)item; \
        vector_insert(&vec, &e, index); \
    } while(false)
    
// Removes an item from the given space
#define VECTOR_ERASE(vec, index) \
    vector_erase(&vec, index)
    
// Resizes the vector
// Truncate if the requested size is smaller than the actual size
// This will not work with NULL - use the underlying function instead if you need NULL
#define VECTOR_RESIZE(type, vec, count, item) \
    do { \
        type e = (type)item; \
        vector_resize(&vec, count, &e); \
    } while(false)
    
// Gives the allocated memory space back to the OS - This works as a destructor in C++
#define VECTOR_DESTROY(vec) \
    vector_destroy(&vec)

typedef struct
{
    void* data;
    size_t data_size;
    size_t capacity;
    size_t size;
} vector;

void    vector_create(vector* v, size_t data_size);
void    vector_push(vector* v, const void* item);
void*   vector_get(vector* v, size_t index);
size_t  vector_size(const vector* v);
bool    vector_empty(const vector* v);
void    vector_reserve(vector* v, size_t new_size);
size_t  vector_capacity(const vector* v);
void    vector_shrink_to_fit(vector* v);
void    vector_clear(vector* v);
void*   vector_insert(vector* v, const void* item, size_t index);
void*   vector_erase(vector* v, size_t index);
void    vector_resize(vector* v, size_t count, const void* item);
void    vector_destroy(vector* v);

#endif // __VECTOR_H_