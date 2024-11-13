#include "headers/logger.h"
#include <string.h>

Logger logger = {.level = ALL};

int main(int argc, char *argv[]) {
    if (argc == 1) {
        log_error("Укажите параметр конфигурации и путь до файла конфигурации, пример: -c ./cfg");
        return 0;
    } 

    if (strcmp("-c", argv[1]) != 0 && strcmp("-h", argv[1]) != 0) {
        log_error("Не известный параметр");
        return 0;
    }

    if (strcmp("-h", argv[1]) == 0) {
        log_info("\nПараметры приложения: \n   -c: параметр конфигурации и путь до файла конфигурации, пример: -c ./cfg");
    }

    return 0;
}