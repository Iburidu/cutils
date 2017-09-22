#include <string.h> // memset
#include <stdlib.h> // malloc, free
#include <stddef.h> // size_t

#include "utils.h"

void vector_create(vector* v, size_t data_size)
{
    v->data_size = data_size;
    v->capacity = MIN_CAPACITY;
    v->size = 0;
    
    v->data = malloc(v->data_size * v->capacity);
    
    D(("%s: data_size: %u, capacity: %u, size: %u, data: 0x%p", __func__, v->data_size, v->capacity, v->size, v->data));
}

void vector_push(vector* v, const void* item)
{
    vector_insert(v, item, v->size);
}

void* vector_get(vector* v, size_t index)
{
    return (index<=v->size) ? (char*)v->data + (index * v->data_size) : NULL;
}

size_t vector_size(const vector* v)
{
    return v->size;
}

bool vector_empty(const vector* v)
{
    return v->size == 0;
}

void vector_reserve(vector* v, size_t new_size)
{
    if (new_size > v->capacity)
    {
        v->capacity = new_size;
        v->data = realloc(v->data, v->data_size * v->capacity);
        
        D(("%s: new capacity: %u, new data: 0x%p", __func__, v->capacity, v->data));
    }
}

size_t vector_capacity(const vector* v)
{
    return v->capacity;
}

void vector_shrink_to_fit(vector* v)
{
    if (v->capacity > v->size)
    {
        v->capacity = (v->size < MIN_CAPACITY) ? MIN_CAPACITY : v->size;
        v->data = realloc(v->data, v->data_size * v->capacity);
        
        D(("%s: new capacity: %u, new data: 0x%p", __func__, v->capacity, v->data));
    }
}

void vector_clear(vector* v)
{
    v->size = 0;
}

void* vector_insert(vector* v, const void* item, size_t index)
{
    // v->size is acceptable, because it will work as push_back ;)
    if (index > v->size)
    {
        D(("%s: Failed: index > vectorsize (%u > %u)", __func__, index, v->size));
        return NULL;
    }
    
    if (v->size == v->capacity)
    {
        vector_reserve(v, v->capacity * ALLOC_MULTIPLIER);
    }
    
    void* new_item = (char*)v->data + v->data_size * index;
    if (index != v->size)
    {
        void* shifted_place = new_item + v->data_size;
        size_t distance = (v->size - index) * v->data_size;
        
        memcpy(shifted_place, new_item, distance); // shift everything after the newly inserted element
    }
    
    memcpy(new_item, item, v->data_size);
    ++v->size;
    
    D(("%s: New item added - index: %u, new size: %u", __func__, index, v->size));
    
    return new_item;
}

void* vector_erase(vector* v, size_t index)
{
    if (index > v->size - 1)
    {
        D(("%s: Failed: index > vectorsize (%u > %u)", __func__, index, v->size));
        return NULL;
    }
    
    void* erase_item = (char*)v->data + v->data_size * index;
    void* next_item = (char*)erase_item + v->data_size;
    size_t distance = (--v->size - index) * v->data_size;
    
    memcpy(erase_item, next_item, distance);
    
    D(("%s: Item removed - index: %u", __func__, index));
    
    return erase_item;
}
void vector_resize(vector* v, size_t count, const void* item)
{
    if (count > v->size)
    {
        vector_reserve(v, count);
        
        size_t i = v->size; // idiot <c99
        for(; i < count; ++i)
        {
            void* new_item = v->data + i * v->data_size;
            
            if (item)
            {
                memcpy(new_item, item, v->data_size);
            }
            else
            {
                memset(new_item, 0, v->data_size);
            }
        }
    }
    
    v->size = count; // this will cut off the elements if count < v->size
}

void vector_destroy(vector* v)
{
    free(v->data);
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
    
    D(("%s: Vector destroyed", __func__));
}