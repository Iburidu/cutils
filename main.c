#include <stdio.h> //printf
#include "vector.h"

void print_vector(vector* v)
{
    printf("--------------- VECTOR ITEMS ---------------\n");
    size_t i=0;
    for(i=0; i<VECTOR_SIZE(*v); ++i)
    {
        printf("v[%u] = %u\n", i, VECTOR_GET(int, *v, i));
    }
    printf("--------------------------------------------\n");
}

int main()
{
	vector v;
    size_t i=0; // idiot <c99
    
    VECTOR_CREATE(int, v);
    VECTOR_RESIZE(int, v, 10, 0);
    
    print_vector(&v);
    
    for(i=0; i<5; ++i)
    {
        VECTOR_PUSH(int, v, i);
    }
    
    print_vector(&v);
    
    printf("capacity: %u, size: %u, empty: %u\n", VECTOR_CAPACITY(v), VECTOR_SIZE(v), VECTOR_EMPTY(v));
    
    VECTOR_SHRINK(v);
    
    printf("after shrink: capacity: %u, size: %u, empty: %u\n", VECTOR_CAPACITY(v), VECTOR_SIZE(v), VECTOR_EMPTY(v));
    
    for(i=0; i<10; ++i)
    {
        VECTOR_INSERT(int, v, (i+1)*11, i*2);
    }
    
    print_vector(&v);
    
    for(i=0; i<10; ++i)
    {
        VECTOR_ERASE(v, i+1);
    }
    
    print_vector(&v);
    
    VECTOR_RESIZE(int, v, 0, 0);
    VECTOR_SHRINK(v);
    
    printf("capacity: %u, size: %u, empty: %u\n", VECTOR_CAPACITY(v), VECTOR_SIZE(v), VECTOR_EMPTY(v));
    
    VECTOR_PUSH(int, v, 100);
    
    printf("capacity: %u, size: %u, empty: %u\n", VECTOR_CAPACITY(v), VECTOR_SIZE(v), VECTOR_EMPTY(v));
    
    VECTOR_DESTROY(v);
    
    printf("capacity: %u, size: %u, empty: %u\n", VECTOR_CAPACITY(v), VECTOR_SIZE(v), VECTOR_EMPTY(v));
	
	VECTOR_CREATE(int, v);
	
	printf("capacity: %u, size: %u, empty: %u\n", VECTOR_CAPACITY(v), VECTOR_SIZE(v), VECTOR_EMPTY(v));
    
    VECTOR_DESTROY(v);
    
    printf("capacity: %u, size: %u, empty: %u\n", VECTOR_CAPACITY(v), VECTOR_SIZE(v), VECTOR_EMPTY(v));
    
    return 0;
}