#include "headers/logger.h"
#include "headers/params.h"
#include "headers/config.h"
#include "headers/common.h"

#include <stdlib.h> // exit

/**
 * Объекты(тип) -       PascalCase.
 * Имена функций -      snake_case.
 * Имена переменных -   camelCase.
 * const -              UPPER_CASE
 */

Logger logger = { .level = ALL };
Config config = { .server.port = 8080 };

int main(int argc, char *argv[]) {
    if (check_params_cmd(argc, argv) == FALSE) exit(EXIT_ERROR);

    char *filePath = get_params_cmd_by_name("-c", argc, argv);
    if (load_config_from_file(filePath, &config) == FALSE) exit(EXIT_ERROR);

    return 0;
}