import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import Baza_danych 1.0
import "LoginScreen"
import "List"
Window {
    id:okno
    width: 640
    height: 480
    visible: true
    title: qsTr("logowanie")
    LoginScreen{
        anchors.fill: parent
        onIsclickedChanged: {
            opcje.visible=true
        }
    }
    Lista_ogolna{
        id:opcje
        visible:false
        anchors.fill: parent
    }
}
