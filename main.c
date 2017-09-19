#include <stdio.h> //printf
#include "utils.h"

int main(const char* argv[], int argc)
{
	int i = 0; // idiot <c99
	
	vector v;
	
	//vector_init(&v, sizeof(int));
	VECTOR_INIT(v, int);
	
	printf("init: data_size: %u, capacity: %u, size: %u\n", v.data_size, v.capacity, v.count);
	
	int max = 17;
	
	for(i=0; i<max; ++i)
	{
		//vector_push(&v, &i);
		VECTOR_PUSH(v, i, int);
		
		printf("after push: capacity: %u, size: %u\n", v.capacity, v.count);
	}
	
	VECTOR_PUSH(v, 128, int);
	printf("after push: capacity: %u, size: %u\n", v.capacity, v.count);
	
	for(i=0; i<max+1; ++i)
	{
		//printf("v[%i] = %i\n", i, *(int*)vector_get(&v, i));
		printf("v[%i] = %i\n", i, VECTOR_GET(v, i, int));
	}
	
	//vector_free(&v);
	VECTOR_FREE(v);
}