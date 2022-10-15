/*
OSI (7ми уровневая) open system interaction 

1- физический

4-
TCP | UDP -> IP (v4/v6)


#include <sys/socket.h>

int main() {
    int sock = socket(AF_INET);
}

*/


#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server;
    server.sin_family = AF_INET;
    inet_aton("127.0.0.1", &(server.sin_addr));
    server.sin_port = htons(27910);

    connect(sock,(sockaddr*)&server, sizeof(server));

}

/*

QAbstractSocket -> signal readyRead()
^
|
QTcpSocket

у QAbstractSocket: 
    bind(адрес, порт)
    connectToHost(address, port, режим)

    bytesAvailable
_____________________________________________________--
class server : public QObject {
    Q_OBJECT
    QTcpSocket sock;
    QHostAddres serv;

public slots:
    void OnConnect();
    void OnReceive();
};

OnConnect() {
    qDebug() << sock.peerAddress() << " has connected";
}
OnReceive() {
    qint64 s = sock.bytesAvailable();
    char *data = new char[s+1];
    sock.readData(data, s);
    data[s]=0;
    qDebug() << data;
    delete data;
}



*/