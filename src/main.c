#include "headers/logger.h"
#include "headers/params.h"

Logger logger = {.level = ALL};

int main(int argc, char *argv[]) {
    if (check_params_cmd(argc, argv) == 0) return 0;

    log_info(get_params_cmd_by_name("-c", argc, argv));

    return 0;
}