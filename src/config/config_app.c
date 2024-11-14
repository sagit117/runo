#include "../headers/config.h"
#include "../headers/logger.h"
#include "../headers/common.h"

#include <stdio.h>  // FILE
#include <string.h> // strlen

void set_struct_data(const char *data) {
    extern Config config;
    
    
}

/** 
 * Заполняет config из файла.
 * @return 0 - ошибка, 1 - выполнено.
 */
BOOL load_config_from_file(const char *filePath, Config *config) {
    FILE* fileConfig = fopen(filePath, "r");

    if (fileConfig == NULL) {
        log_error("Не могу открыть файл %s", filePath);

        return FALSE;
    }

    int bufferLength = 255;
    char buffer[bufferLength];
    
    while(fgets(buffer, bufferLength, fileConfig)) {
        set_struct_data(buffer);
    }

    fclose(fileConfig);

    return TRUE;
}