#include "../../headers/config.h"
#include "../../headers/logger.h"
#include "../../headers/common.h"

#include <sys/socket.h> // socket
// #include <sys/types.h>
#include <netinet/in.h> // sockaddr_in
#include <unistd.h> // close
#include <string.h>
#include <ctype.h>

void processing_message(unsigned char *s, int n) {
    log_debug("processing message...\n");
    unsigned char *p;
    for (p=s; p < s + n; p++)
    {
        if (islower(*p))
        {
            *p += 13;
            if(*p > 'z') *p -= 26;
        }
    }
}

BOOL runo_http_server(Server *config_server) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0); // AF_INET - ip4

    if (server_socket == -1) {
        log_error("Ошибка открытия сокета");
        return FALSE;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(config_server->port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    struct sockaddr_in client_address;
    socklen_t client_address_len;

    int rc = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    if (rc < 0) {
        log_error("Ошибка открытия вызова команды bind server_address");
        return FALSE;
    }

    listen(server_socket, config_server->max_connections);

    log_info("Сервер ожидает подключения...");
    
    // ACCEPT connections
    int keep_socket = 1;
    while (keep_socket) {
        client_address_len = sizeof(client_address);

        int client_socket;
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);

        log_debug("Подключен клиент с адресом %d", client_address.sin_addr.s_addr);

        // send the message
        log_debug("processing message service...");
        log_debug("fd is: %f", client_socket);
        unsigned char buf[1024]; // Pre-allocated buffer
        int count;

        while ((count = read(client_socket, buf, 1024)) > 0) {
            log_debug("%p\n",count);
            log_debug("reading...");
            processing_message(buf, count);
            //send(out, buf, count, 0);
            write(client_socket, buf, count);
        }

        // close the socket
        close(client_socket);
    }
    
	return TRUE;
}