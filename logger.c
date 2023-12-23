#include "logger.h"
#include <stdio.h>
#include <stdarg.h>

void super_log_any (u8 severity, const char* file, const char* func, u32 line, const char* fmt, ...)
{
    /* 
        TODO, calling this much fprintfs is not efficient, concant then call one fprintf
     */
    static const char* fmt_lvl[] = {"[DBG]","[WRN]", "[INF]", "[ERR]"};
    fprintf(stderr, "%s [ %s %s:%d ]: ", fmt_lvl[severity], file, func, line);
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args); 
    va_end(args);
    fprintf(stderr, "\n");
}