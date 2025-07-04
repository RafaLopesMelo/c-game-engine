#include "logger.h"
#include "assert.h"
#include "platform/platform.h"

// TODO: temporary
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

b8 initialize_logging() {
    // TODO: create a log file
    return TRUE;
};

void shutdown_logging() {
    // TODO: cleanup logging
};

// Each call to `log_output` uses 64kb per call
void log_output(log_level level, const char *message, ...) {
    const char *level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ",
                                    "[INFO]: ",  "[DEBUG]: ", "[TRACE]: "};

    b8 is_error = level < 2;

    // Avoids dynamic allocation because it's slow
    char out_message[32000];
    memset(out_message, 0, sizeof(out_message));

    // Format original message.Add commentMore actions
    // NOTE: Oddly enough, MS's headers override the GCC/Clang va_list type with
    // a "typedef char* va_list" in some cases, and as a result throws a strange
    // error here. The workaround for now is to just use __builtin_va_list,
    // which is the type GCC/Clang's va_start expects.
    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, 32000, message, arg_ptr);
    va_end(arg_ptr);

    char out_message2[32000];
    sprintf(out_message2, "%s%s\n", level_strings[level], out_message);

    if (is_error) {
        platform_console_write_error(out_message2, level);
    } else {
        platform_console_write(out_message2, level);
    }
};

KAPI void report_assertion_failure(const char *expr, const char *msg,
                                   const char *file, i32 line) {
    log_output(LOG_LEVEL_FATAL,
               "Assertion failure: %s, message '%s', in file %s, line %d\n",
               expr, msg, file, line);
}
