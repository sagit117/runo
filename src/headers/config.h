#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    Server server;
} Config;

typedef struct {
    int port;
} Server;

void load_config_from_file(const char *filePath, Config *config);

#endif
