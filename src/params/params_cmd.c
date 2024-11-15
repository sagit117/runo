#include "../headers/logger.h"
#include "../headers/common.h"

#include <string.h> // strcmp

BOOL check_params_cmd(int argc, char *argv[]) {
    if (argc == 1) {
        log_error("Укажите параметр конфигурации и путь до файла конфигурации, пример: -c ./cfg");
        return FALSE;
    } 

    if (strcmp(PARAM_CMD_CONFIG, argv[1]) != 0 && strcmp(PARAM_CMD_HELP, argv[1]) != 0) {
        log_error("Не известный параметр");
        return FALSE;
    }

    if (strcmp(PARAM_CMD_HELP, argv[1]) == 0) {
        log_info("\nПараметры приложения: \n\t-c: параметр конфигурации и путь до файла конфигурации, пример: -c ./cfg");
        return FALSE;
    }

    return TRUE;
}

/** 
 * Получает значение параметра приложения по его имени.
 * @return занчение параметра, либо NULL если такого параметра нет.
 */
char *get_params_cmd_by_name(const char *name, int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], name) == 0) {
            return argv[i + 1];
            break;
        }
    }

    return NULL;
} 