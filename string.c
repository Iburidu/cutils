#include <string.h>
#include <stddef.h> // size_t
#include "string.h"

void string_create(string* s)
{
	vector_create((vector*)&s, sizeof(char));
}

char* string_concat(string* s, const char* str)
{
	const size_t len	 = strlen(str);
	const size_t current = vector_size((vector*)&s);
	const size_t total   = current + len + 1;
	
	vector_reserve((vector*)&s, total);
	memcpy(s->data + current, str, len);
	
	((char*)s->data)[total - 1] = '\0';
	s->size = total;
	
	return s->data;
}

char* string_assign(string* s, const char* str)
{
	vector_clear((vector*)&s);
	string_concat(s, str);
	
	return s->data;
}