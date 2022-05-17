import QtQuick 2.0
import QtQml.Models 2.15
Item {
    ListView{

        width: 100
        height: 100
        model:model_listy
        z:20
        y:70
        delegate: Row{
        Text{font.pointSize: 16
              text:index+". " + name}//index dla cyferek
        }
    }
    ListModel{
        id:model_listy
        ListElement{
            name:"test"
        }
        ListElement{
            name:"alan"
        }
        ListElement{
            name:"lubi"
        }
        ListElement{
            name:"w"
        }
    }
}

