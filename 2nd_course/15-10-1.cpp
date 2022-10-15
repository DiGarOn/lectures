// for server

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(27910);

    bind(sock, (sockaddr*)&server, sizeof(server));

    listen(sock, 10);

    int new_sock;
    sockaddr_in client;
    while((new_sock=accept(sock, (sockaddr*)&client, (socklen_t*)sizeof(client))) != -1) {
        //smth to do
    }
}