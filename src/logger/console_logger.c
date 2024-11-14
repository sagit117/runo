#include "../headers/logger.h"

#include <stdio.h>  // printf
#include <time.h>   // time_t
#include <stdarg.h> // va

static char *level_str(int level) {
    switch (level) {
        case DEBUG:     return "DEBUG";
        case INFO:      return "INFO";
        case WARNING:   return "WARNING";
        case ERROR:     return "ERROR";

        default: return "UNKNOWN";
    };
}

void log_format(const int level, const char *message, va_list vl) {
    extern Logger logger;

    if (level >= logger.level) {
        time_t nowtime = time(NULL);
        struct tm *now = localtime(&nowtime);

        char datestr[20];
        strftime(datestr, sizeof(datestr), "%Y-%m-%d %T", now);

        printf("%s [%7s]: ", datestr, level_str(level));

        vprintf(message, vl);

        printf("\n");
    }
}

void log_error(const char *message, ...) {
    va_list vl;   
    va_start(vl, message); 

    log_format(ERROR, message, vl);

    va_end(vl);
}

void log_warning(const char *message, ...) {
    va_list vl;   
    va_start(vl, message);

    log_format(WARNING, message, vl);

    va_end(vl);
}

void log_info(const char *message, ...) {
    va_list vl;   
    va_start(vl, message);

    log_format(INFO, message, vl);

    va_end(vl);
}

void log_debug(const char *message, ...) {
    va_list vl;   
    va_start(vl, message);

    log_format(DEBUG, message, vl);

    va_end(vl);
}

void log_message(const int level, const char *fmt, ...) {
    va_list vl;
    va_start(vl, fmt);

    log_format(level, fmt, vl);

    va_end(vl);
}