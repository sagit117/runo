#include "headers/logger.h"
#include "headers/config.h"
#include "headers/common.h"

#include <stdlib.h> // exit
#include <unistd.h>

/**
 * Объекты(тип) -       PascalCase.
 * Имена функций -      snake_case.
 * Имена переменных -   camelCase.
 * const -              UPPER_CASE
 */

Logger logger = { .level = ALL };
Config config = { .server.port = 8080 };

int main(int argc, char *argv[]) {
    int res = 0;
    extern char *optarg;

    while ((res = getopt(argc, argv, "hc:")) != -1) {
		switch (res) {
            case 'h': log_info("\nПараметры приложения: \n\t-c: параметр конфигурации и путь до файла конфигурации, пример: -c ./cfg"); exit(EXIT_SUCCESS); break;
            case 'c': if (load_config_from_file(optarg, &config) == FALSE) exit(EXIT_ERROR); break;
            case '?': break;
		} 
	}

    return 0;
}