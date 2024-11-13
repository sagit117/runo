#include "headers/logger.h"
#include "headers/params.h"

Logger logger = {.level = ALL};

int main(int argc, char *argv[]) {
    if (check_params(argc, argv) == 0) return 0;

    return 0;
}