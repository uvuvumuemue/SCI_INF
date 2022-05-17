#ifndef BAZA_DANYCH_H
#define BAZA_DANYCH_H
#include <QObject>
#include <QString>
#include <vector>
#include <string>
using namespace std;
class Baza_danych : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void update();
    Q_INVOKABLE void addusr(const QString l,const QString p);
    Q_INVOKABLE bool validate(const QString l);
    explicit Baza_danych(QObject *parent = nullptr);
     ~Baza_danych();
    Q_INVOKABLE bool findusr(const QString l,const QString p);
private:

    vector<Baza_danych*> baza;
    string login;
    string password;
signals:

};

#endif // BAZA_DANYCH_H
