#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <cstring>

int main(int argc, char **argv)
{
    // Создание сокета
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Привязка сокета к IP-адресу и порту
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    bind(server_socket, reinterpret_cast<sockaddr *>(&server_address), sizeof(server_address));

    // Прослушивание
    listen(server_socket, 5);

    // Ожидание подключения
    int client_socket = accept(server_socket, nullptr, nullptr);

    // Прием данных
    char buffer[1024]{0};
    recv(client_socket, buffer, sizeof(buffer), 0);
    std::cout << "Message from client: " << buffer << std::endl;

    // Отправка даных
    const char *message{"Hello, client!"};
    send(client_socket, message, std::strlen(message), 0);

    // Закрытие
    close(server_socket);
    close(client_socket);

    // TODO: add test instead of `telnet 127.0.0.1 8080`
    return 0;
}
