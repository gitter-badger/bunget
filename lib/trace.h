#ifndef TRACE_H_
#define TRACE_H_

#include <stdlib.h>

typedef enum trace_level {
    kTraceNone          = 0x0000,
    kTraceCallback      = 0x0001,
    kTraceGory          = 0x0002
} TraceLevel;

#define BUNGET_TRACE_ENV_VAR "BUNGET_TRACE"

extern "C" {
    TraceLevel get_trace_level();
    int is_tracing(TraceLevel level);
};

#endif
