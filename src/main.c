#include "headers/logger.h"
#include "headers/config.h"
#include "headers/common.h"
#include "headers/server.h"

#include <stdlib.h> // exit
#include <unistd.h> // getopt

/**
 * Объекты(тип) -       PascalCase.
 * Имена функций -      snake_case.
 * Имена переменных -   snake_case.
 * const -              UPPER_CASE
 */

Logger logger = { .level = ALL };
Config config = { 
    .server.port = 8080, 
    .server.max_connections = 10 
};

int main(int argc, char *argv[]) {
    int res = 0;
    extern char *optarg;
    extern int opterr;
    opterr = 0; // отключить ошибки в getopt
    
    while ((res = getopt(argc, argv, "hc:")) != -1) {
		switch (res) {
            case 'h': log_info("\nПараметры приложения: \n\t-c: параметр конфигурации и путь до файла конфигурации, пример: -c ./cfg"); exit(EXIT_SUCCESS); break;
            case 'c': if (load_config_from_file(optarg, &config) == FALSE) exit(EXIT_ERROR); break;
            case '?': break;
		} 
	}

    runo_http_server(&(config.server));

    return 0;
}