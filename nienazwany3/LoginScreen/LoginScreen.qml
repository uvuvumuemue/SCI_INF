import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import Baza_danych 1.0
Item {
    id:logowanie
    property bool isclicked:false
    Column {
        Rectangle{
            x:200
            color:"red"
            height: 400
            width: 250
            TextField{
                id:log
                y:100
                width:250
                placeholderText: qsTr("podaj login")
            }
            TextField{
                echoMode: "Password"
                id:pass
                y:200
                width:250
                placeholderText: qsTr("podaj haslo")
            }
            Text{
                font.pixelSize:25
                x:10
                y:70
                id:wiadomosc
                visible: false
                text:"zostales zalogowany"
            }
            Text{
                text:"błędne dane logowania"
                visible:false
                id:blad
                font.pixelSize:24
                y:40
            }
            Button{
                id:zalogowanie
                text: "login"
                y:300
                height:50
                width:250
                onClicked: {
                    if(Baza_danych.findusr(log.text,pass.text)){
                        wiadomosc.visible=true
                        logowanie.visible=false
                        isclicked=true
                        blad.visible=false
                    }
                    else{
                        wiadomosc.visible=false
                        blad.visible=true
                    }
                }
            }
            Button{
                id:rejestracja
                text: "sign up"
                y:351
                height:50
                width:250
                onClicked: {
                    Baza_danych.addusr(log.text,pass.text);
                    blad.visible=false
                }
            }
        }
    }
}
