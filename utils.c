#include "utils.h"

void D(const char* format, ...)
{
#ifdef DEBUG
	va_list args;
	
	va_start(args, format);
	vprintf(format, args);
	printf("\n");
    va_end(args);
#else
	UNUSED(format);
#endif // DEBUG
}