import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        anchors.centerIn: parent;
        Row{
            id: row;
            spacing: 10;
            anchors.centerIn: parent;
            TextField{
                id: filePath;
                width: 300;
                readOnly: true;
            }
            Button{
                id: selectSource
                text: qsTr("Select");
                onClicked: {
                    fileDialog.open();
                }
            }
            Button{
                id: convertToBMP
                text:qsTr("Convert");
                onClicked: {
                    operateImage.saveNewImage(filePath.text);
                }
            }
        }
    }
    FileDialog{
        id:fileDialog;
        title: qsTr("Please choose a file");
        folder: shortcuts.home
        onAccepted: {
            filePath.text = fileDialog.fileUrl.toString().substring(8,fileDialog.fileUrl.length);
        }
        onRejected: {
            console.log("you have been rejected.");
        }
    }
}
