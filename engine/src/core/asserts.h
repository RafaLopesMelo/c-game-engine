#pragma once

#include "defines.h"

// Disable assertions by commenting the line below
#define KASSERTIONS_ENABLED

#ifdef KASSERTIONS_ENABLED

#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak();
#else
#define debugBreak() __builtin_trap();
#endif

KAPI void report_assertion_failure(const char *expr, const char *msg,
                                   const char *file, i32 line);

#define KASSERT(expr)                                                          \
    {                                                                          \
        if (expr) {                                                            \
        } else {                                                               \
            report_assertion_failure(#expr, "", __FILE__, __LINE__);           \
            debugBreak();                                                      \
        }                                                                      \
    }

#define KASSERT_MSG(expr, msg)                                                 \
    {                                                                          \
        if (expr) {                                                            \
        } else {                                                               \
            report_assertion_failure(#expr, msg, __FILE__, __LINE__);          \
            debugBreak();                                                      \
        }                                                                      \
    }

#ifdef _DEBUG
#define KASSERT_DEBUG(expr)                                                    \
    {                                                                          \
        if (expr) {                                                            \
        } else {                                                               \
            report_assertion_failure(#expr, "", __FILE__, __LINE__);           \
            debugBreak();                                                      \
        }                                                                      \
    }
#else
#define KASSERT_DEBUG(expr)
#endif

#else

#define KASSERT(expr)
#define KASSERT_MSG(expr, msg)
#define KASSERT_DEBUG(expr)

#endif
