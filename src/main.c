#include "headers/logger.h"
#include "headers/params.h"
#include "headers/config.h"
#include "headers/common.h"

#include <stdlib.h> // exit

/**
 * Объекты(тип) - с заглавной буквы.
 * Имена функций - snake_case.
 * Имена переменных - camelCase.
 */

Logger logger = {.level = ALL};
Config config;

int main(int argc, char *argv[]) {
    if (check_params_cmd(argc, argv) == FALSE) exit(EXIT_ERROR);

    char *filePath = get_params_cmd_by_name("-c", argc, argv);
    if (load_config_from_file(filePath, &config) == FALSE) exit(EXIT_ERROR);

    return 0;
}