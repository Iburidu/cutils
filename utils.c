#include <string.h> // memset
#include <stdlib.h> // malloc, free
#include <stddef.h> // size_t

#include "utils.h"

void vector_init(vector* v, size_t data_size)
{
	v->data_size = data_size;
	v->capacity = INIT_CAPACITY;
	v->count = 0;
	
	v->data = malloc(v->data_size * v->capacity);
}

void vector_push(vector* v, void* item)
{
	if (v->count == v->capacity)
	{
		v->capacity *= ALLOC_MULTIPLIER;
		v->data = realloc(v->data, v->data_size * v->capacity);
	}
	
	void* newitem = (char*)v->data + (v->count * v->data_size);
	memcpy(newitem, item, v->data_size);
	
	++v->count;
}

void* vector_get(vector* v, size_t index)
{
	return (char*)v->data + (index * v->data_size);
}

void vector_free(vector* v)
{
	free(v->data);
}