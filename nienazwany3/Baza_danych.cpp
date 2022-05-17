#include <iostream>
#include <fstream>
#include <vector>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include "Baza_danych.h"
using namespace std;
Baza_danych::Baza_danych(QObject *parent)
    : QObject{parent}
{

}
Baza_danych::~Baza_danych(){
    baza.clear();
}
void Baza_danych::update(){
    QFile filelogin("logins.txt");
    QFile filepassword("passwords.txt");
    filelogin.open(QIODevice::ReadOnly);
    filepassword.open(QIODevice::ReadOnly);
    QTextStream streaml(&filelogin);
    QTextStream streamp(&filepassword);
    QString linel;
    QString linep;
    do{
        Baza_danych *n=new Baza_danych;
        linel=streaml.readLine();
        qInfo()<<linel;
        n->login=linel.toStdString();
        linep=streamp.readLine();
        qInfo()<<linep;
        n->password=linep.toStdString();
        baza.push_back(n);

    }while( !streaml.atEnd() && !streamp.atEnd() );
    filelogin.close();
    filepassword.close();
}
void Baza_danych:: addusr(QString l,QString p){
    QFile filelogin("logins.txt");
    QFile filepassword("passwords.txt");
    filelogin.open(QIODevice::WriteOnly | QIODevice::Append );
    filepassword.open(QIODevice::WriteOnly | QIODevice::Append);
    if(validate(l)){
        QTextStream streaml(&filelogin);
        QTextStream streamp(&filepassword);
        Baza_danych *n=new Baza_danych;
        n->login=l.toStdString();
        n->password=p.toStdString();
        baza.push_back(n);
        streaml<<l<<"\n";
        streamp<<p<<"\n";
        filelogin.close();
        filepassword.close();
    }
    else{
        cout<<"error 1\n";
    }
}

bool Baza_danych::validate(QString l){
    for(unsigned int i=0;i<baza.size();i++){
        if(baza[i]->login==l.toStdString()){
            return false;
        }
    }
    return true;
}
bool Baza_danych::findusr(QString l,QString p){
    for(unsigned int i=0;i<baza.size();i++){
        if(baza[i]->login==l.toStdString() && baza[i]->password==p.toStdString()){
            return true;
        }
    }
    return false;
}
