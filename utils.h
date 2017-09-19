#ifndef __UTILS_H__
#define __UTILS_H__

#define bool int
#define false 0
#define true 1
#ifndef NULL
#define NULL ((void*)0)
#endif //NULL

#define INIT_CAPACITY 2
#define ALLOC_MULTIPLIER 2

#define VECTOR_INIT(vec, type) vector_init(&vec, sizeof(type))
#define VECTOR_PUSH(vec, item, type) type e = item;	vector_push(&vec, &e);
#define VECTOR_GET(vec, index, type) *(type*)vector_get(&vec, index)
#define VECTOR_FREE(vec) vector_free(&vec)

typedef struct
{
	void* data;
	size_t data_size;
	size_t capacity;
	size_t count;
} vector;

void vector_init(vector* v, size_t data_size);
void vector_push(vector* v, void* item);
void* vector_get(vector* v, size_t index);
void vector_free(vector* v);

#endif // __UTILS_H__