/*

Основы QT
---> Объектная модель 
---> Механизм сигналов и слотов 

Версии QT 
4.8         5.18            6.

QWidget 
QObject

class Klass : public QWidget {
public slots:
    void React() {
        QMessageBox("OMG", "It's Alive");
    }

signals:
    void DoIt();
public:
    void Ahtung() const { emit DoIt(); }
};

Klass::Klaqss():QWidget(nullptr) {
    connect(this, SIGNAL(void DoIt()), this, SLOT(void React()));
}


*/