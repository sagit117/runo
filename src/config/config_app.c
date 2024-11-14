#include "../headers/config.h"
#include "../headers/logger.h"
#include "../headers/common.h"

#include <stdio.h>  // FILE
#include <string.h> // strlen

/** 
 * Заполняет config из файла.
 * @return 0 - ошибка, 1 - выполнено.
 */
bool load_config_from_file(const char *filePath, Config *config) {
    FILE* fileConfig = fopen(filePath, "r");

    if (fileConfig == NULL) {
        log_error("Не могу открыть файл %s", filePath);

        return false;
    }

    fclose(fileConfig);

    return true;
}