#include "../headers/config.h"
#include "../headers/logger.h"
#include "../headers/common.h"
#include "../headers/utils.h"

#include <stdio.h>  // FILE fgets
#include <string.h> // strlen strcmp strtok
#include <stdlib.h> // atoi

void set_struct_data(char *data) {
    extern Config config;
    const char *SERVER_PORT_PATH = "server.port";
    const char *delim = "=";
    char *token;

    token = strtok(data, delim);
   
    while(token != NULL) {
        const char *trimToken = trimwhitespace(token);

        // Server port
        if (strcmp(SERVER_PORT_PATH, trimToken) == 0) {
            token = strtok(NULL, delim);

            int port = atoi(token);

            if (port > 0) config.server.port = port;
        }
    
        token = strtok(NULL, delim);
    }
}

/** 
 * Заполняет config из файла.
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