#ifndef TRACE_H_
#include "trace.h"
#endif

extern "C"
{

    TraceLevel get_trace_level()
    {
        char *env = getenv(BUNGET_TRACE_ENV_VAR);
        TraceLevel level = kTraceNone;
        if(env) {
            level = (TraceLevel) atoi(env);
        }
        return(level);
    }

    int is_tracing(TraceLevel level)
    {
        TraceLevel t = get_trace_level();
        return(t & level);
    }

};
