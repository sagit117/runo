#include "../../headers/config.h"
#include "../../headers/logger.h"
#include "../../headers/common.h"

#include <sys/socket.h> // socket accept
#include <netinet/in.h> // sockaddr_in
#include <unistd.h> // close

BOOL runo_http_server(Server *config_server) {
    // Создание сокета
    int server_socket = socket(AF_INET, SOCK_STREAM, 0); // AF_INET - ip4

    if (server_socket == -1) {
        log_error("Ошибка открытия сокета");
        return FALSE;
    }

    // Опичание структуры адреса сокета
    struct sockaddr_in server_address = {
        .sin_family = AF_INET, // AF_INET - ip4
        .sin_port = htons(config_server->port),
        .sin_addr.s_addr = htonl(INADDR_ANY)
    };

    // Связать сокет с адресом в выбранном домене
    int rc = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    if (rc < 0) {
        log_error("Ошибка связки сокета с адресом");
        return FALSE;
    }

    listen(server_socket, config_server->max_connections); // max_connections - количетсво в очереде ожидающих запросов
    log_info("Сервер ожидает подключения, порт: %d", config_server->port);
    
    // Прием соединений
    struct sockaddr_in client_address;
    socklen_t client_address_len;

    int keep_socket = 1;

    while (keep_socket) {
        client_address_len = sizeof(client_address);

        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);
        if (client_socket < 0) {
            log_error("Ошибка принятия запроса");
            perror("accept");

            continue;
        } else {
            log_debug("Подключен клиент с адресом: %d, порт: %d", client_address.sin_addr.s_addr, client_address.sin_port);

            char buf[1024];
            int recieve_bytes = recv(client_socket, buf, sizeof(&buf), 0);

            log_debug("Прочитано %d байт", recieve_bytes);
            log_debug("Прочитано %s", buf);

            // send the message
            int send_bytes = send(client_socket, "HTTP/1.1 200 OK\nContent-Type: text/html", sizeof("HTTP/1.1 200 OK\nContent-Type: text/html"), 0);

            log_debug("Отправлено %d байт", send_bytes);
        }

        // close the socket
        close(client_socket);
    }
    
	return TRUE;
}