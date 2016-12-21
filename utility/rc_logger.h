
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>



#define LEVEL_OFF 0
#define LEVEL_ERR 1
#define LEVEL_WRN 2
#define LEVEL_INF 3
#define LEVEL_DBG 4
#define LEVEL_ALL 5

#define LOGGER_LEVEL LEVEL_ALL

#define EOL {fprintf(stderr, "\n");}
#define CP(x) {fprintf(stderr, "check point %d\n", x);}


#include <assert.h>
/*-----------------------------------------------------------------------------
 * Debug Macro (for debug version)
 *---------------------------------------------------------------------------*/
#define DFLAG_SHORT 1
#define DFLAG_LONG  2
#if LEVEL_DBG <= LOGGER_LEVEL
    #define LOGGER_DBG(msg, ...)                                                \
    do {                                                                              \
        fprintf(stderr, "TRACE: " __FILE__ ":%d %s()\n", __LINE__, __FUNCTION__); \
        fprintf(stderr, msg);                                            \
        fprintf(stderr, "\n");                                                        \
    } while(0)
#else
    #define LOGGER_DBG(msg, ...)
#endif

#if LEVEL_DBG <= LOGGER_LEVEL
    #define LOGGER_TRACE(line, msg)                                                \
    do {                                                                              \
        fprintf(stderr, "TRACE: %d --> ", line ); \
        fprintf(stderr, msg);                                            \
        fprintf(stderr, "\n");                                                        \
    } while(0)
#else
    #define LOGGER_TRACE(line, msg)
#endif

/*-----------------------------------------------------------------------------
 * Tips Information Macro (for released version)
 *---------------------------------------------------------------------------*/
#if LEVEL_INF <= LOGGER_LEVEL
    #define LOGGER_INF(msg, ...)           \
    do {                                   \
        fprintf(stderr, msg); \
        fprintf(stderr, "\n");             \
    } while(0)
#else
    #define LOGGER_INF(msg, ...)
#endif