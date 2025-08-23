#include <stdio.h>
#include <stdarg.h>
#include "log.h"


log_levels global_log_level = TRACE;

void trace(log_levels level, char *format, ...)
{
	if(level <= global_log_level)
	{
		va_list args;

		va_start(args, format);
		vprintf(format, args);
		putchar('\n');	
		va_end(args);
	}
}


log_levels set_log_level(log_levels level)
{
	log_levels old_level = global_log_level;
	global_log_level = level;
	return old_level;
}
