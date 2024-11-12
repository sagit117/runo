#include "headers/logger.h"

Logger logger = {.level = ALL};

int main(void) {
    log_error("test");
    log_debug("test");
    log_info("test");
    log_warning("test");
    return 0;
}