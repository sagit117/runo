#include "../headers/config.h"
#include "../headers/logger.h"
#include "../headers/common.h"
#include "../headers/utils.h"

#include <stdio.h>  // FILE fgets
#include <string.h> // strlen strcmp strtok
#include <stdlib.h> // atoi

void set_struct_data(char *data) {
    extern Config config;
    const char *server_port_path = "server.port";
    const char *server_max_connections_path = "server.max_connections";
    const char *delim = "=";
    char *token;

    token = strtok(data, delim);
   
    while(token != NULL) {
        const char *trim_token = trimwhitespace(token);

        // Server port
        if (strcmp(server_port_path, trim_token) == 0) { // TODO refactor
            token = strtok(NULL, delim);

            int port = atoi(token);

            if (port > 0) config.server.port = port;
        }

        // Server max_connections
        if (strcmp(server_max_connections_path, trim_token) == 0) { // TODO refactor
            token = strtok(NULL, delim);

            int max_connections = atoi(token);

            if (max_connections > 0) config.server.max_connections = max_connections;
        }
    
        token = strtok(NULL, delim);
    }
}

/** 
 * Заполняет config из файла.
 */
BOOL load_config_from_file(const char *file_path, Config *config) {
    FILE* file_config = fopen(file_path, "r");

    if (file_config == NULL) {
        log_error("Не могу открыть файл конфигурации %s", file_path);

        return FALSE;
    }

    int buffer_len = 255;
    char buffer[buffer_len];
    
    while (fgets(buffer, buffer_len, file_config)) {
        set_struct_data(buffer);
    }

    fclose(file_config);

    return TRUE;
}