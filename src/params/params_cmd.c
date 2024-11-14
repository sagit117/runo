#include "../headers/logger.h"
#include "../headers/common.h"

#include <string.h> // strcmp

BOOL check_params_cmd(int argc, char *argv[]) {
    if (argc == 1) {
        log_error("Укажите параметр конфигурации и путь до файла конфигурации, пример: -c ./cfg");
        return FALSE;
    } 

    if (strcmp("-c", argv[1]) != 0 && strcmp("-h", argv[1]) != 0) {
        log_error("Не известный параметр");
        return FALSE;
    }

    if (strcmp("-h", argv[1]) == 0) {
        log_info("\nПараметры приложения: \n   -c: параметр конфигурации и путь до файла конфигурации, пример: -c ./cfg");
        return FALSE;
    }

    return TRUE;
}

/** 
 * Получает значение параметра по его имени.
 * @return занчение, либо NULL если такого параметра нет.
 */
char* get_params_cmd_by_name(const char *name, int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], name) == 0) {
            return argv[i + 1];
            break;
        }
    }

    return NULL;
} 