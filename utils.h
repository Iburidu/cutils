#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdarg.h>
#include <stdio.h> // vprintf

#ifndef bool
#define bool int
#endif // bool

#ifndef false
#define false 0
#endif // false

#ifndef true
#define true 1
#endif // true

#ifndef NULL
#define NULL ((void*)0)
#endif //NULL

#ifndef UNUSED
#define UNUSED(variable) \
	do { \
		(void)variable; \
	} while(false) 
#endif // UNUSED

#define MIN_CAPACITY 2
#define ALLOC_MULTIPLIER 2

#ifdef DEBUG
#define D(...) \
    do { \
        printf(__VA_ARGS__); \
        printf("\n"); \
    } while(false)
#else
#define D(...)
#endif // DEBUG

#endif // __UTILS_H__