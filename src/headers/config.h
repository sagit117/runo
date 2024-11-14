#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    int port;
} Server;

typedef struct {
    Server server;
} Config;

int load_config_from_file(const char *filePath, Config *config);

#endif
