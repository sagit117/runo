#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    int port;
    int max_connections;
} Server;

typedef struct {
    Server server;
} Config;

int load_config_from_file(const char *filePath, Config *config);

#endif
