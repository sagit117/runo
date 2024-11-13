#include "headers/logger.h"
#include "headers/params.h"
#include "headers/config.h"

/**
 * Объекты(тип) - с заглавной буквы.
 * Имена функций - snake_case.
 * Имена переменных - camelCase.
 */

Logger logger = {.level = ALL};
Config config;

int main(int argc, char *argv[]) {
    if (check_params_cmd(argc, argv) == 0) return 0;

    char *filePath = get_params_cmd_by_name("-c", argc, argv);

    load_config_from_file(filePath, &config);

    return 0;
}