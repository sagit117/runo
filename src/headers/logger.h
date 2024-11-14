#ifndef LOGGER_H
#define LOGGER_H

enum LogLevel {
    ALL = 0,
    DEBUG = 10, 
    INFO = 20, 
    WARNING = 30, 
    ERROR = 40
};

typedef struct {
    int level;
} Logger;

void log_error(const char *message, ...);
void log_warning(const char *message, ...);
void log_info(const char *message, ...);
void log_debug(const char *message, ...);
void log_message(const int level, const char *fmt, ...);

#endif