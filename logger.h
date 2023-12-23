#pragma once
#include "super_defines.h"
#include <string.h>

enum {
        SUPER_LOG_LVL_DBG = 0,
        SUPER_LOG_LVL_INF = 1,
        SUPER_LOG_LVL_WRN = 2,
        SUPER_LOG_LVL_ERR = 3
};


void super_log_any(u8 severity, const char* file, const char* func, u32 line, const char* fmt, ...);

#define SUPER_LOG(severity, format, ...) super_log_any(severity, __FILE__, __func__, __LINE__, format, __VA_ARGS__);


#define SUPER_LOG_DBG(...) SUPER_LOG(SUPER_LOG_LVL_DBG, "%s", __VA_ARGS__);
#define SUPER_LOG_FMT_DBG(format, ...) SUPER_LOG(SUPER_LOG_LVL_DBG, format, __VA_ARGS__);

#define SUPER_LOG_INF(...) SUPER_LOG(SUPER_LOG_LVL_INF, "%s", __VA_ARGS__);
#define SUPER_LOG_FMT_INF(format, ...) SUPER_LOG(SUPER_LOG_LVL_INF, format, __VA_ARGS__);

#define SUPER_LOG_WRN(...) SUPER_LOG(SUPER_LOG_LVL_WRN, "%s", __VA_ARGS__);
#define SUPER_LOG_FMT_WRN(format, ...) SUPER_LOG(SUPER_LOG_LVL_WRN, format, __VA_ARGS__);

#define SUPER_LOG_ERR(...) SUPER_LOG(SUPER_LOG_LVL_ERR, "%s", __VA_ARGS__);
#define SUPER_LOG_FMT_ERR(format, ...) SUPER_LOG(SUPER_LOG_LVL_ERR, format, __VA_ARGS__);
