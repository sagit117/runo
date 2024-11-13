#include <stdio.h>
#include <time.h>
#include "../headers/logger.h"

static char *level_str(int level) {
    switch (level) {
        case DEBUG:     return "DEBUG";
        case INFO:      return "INFO";
        case WARNING:   return "WARNING";
        case ERROR:     return "ERROR";

        default: return "UNKNOWN";
    };
}

void log_format(const int level, const char *message) {
    extern Logger logger;

    if (level >= logger.level) {
        time_t nowtime = time(NULL);
        struct tm *now = localtime(&nowtime);

        char datestr[20];
        strftime(datestr, sizeof(datestr), "%Y-%m-%d %T", now);

        printf("%s [%7s]: %s\n", datestr, level_str(level), message);
    }
}

void log_error(const char *message) {
    log_format(ERROR, message);
}

void log_warning(const char *message) {
    log_format(WARNING, message);
}

void log_info(const char *message) {
    log_format(INFO, message);
}

void log_debug(const char *message) {
    log_format(DEBUG, message);
}