#include "model.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
using namespace std;

Model::Model()
{
    //_message=message;

}
QStringList Model::ConversionStringToAscii( ) {
    QStringList numberString;
        for(const auto character: Model::_message){
            numberString << QString::number(character.unicode(), 10);
        }
        //QString HexStrData= numberString.join(" ");
        return numberString;
    }
QVector<int> Model::getKbit(QStringList s) {
    QVector<int>vectorInt;
        bool ok;
        int temp;
        for(int i=0;i<s.length();i++) {
         temp=(s[i].toInt(&ok))-64;
         for(int j=0;j<7;j++) {
             vectorInt.append(temp%2);
             temp=temp/2;
         }
         int temp1;
         for(int j=7*(i+1);j>7*(i);j--) {
             vectorInt;
         }
        }
        return vectorInt;
}
int Model::getLenMessage() {
    return (Model::_message).length();
}
void Model::updateMessage( QString message) {
    Model::_message=message;
}
void Model::stockMessage(int nbSecteur,int nbPiste) {
    //QString fileName=QFileDialog::getSaveFileName("../file.txt");
    QFile file("../Project/file.txt");
    /*if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning()<<111111111111111111;
    }*/
    //else {
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream out(&file);
        //file.seek(50);
        out<<(Model::_message)<<Qt::endl;
        out<<"("<<"Nombre de secteurs : "<<nbSecteur<<","<<"Nombre de pistes "<<nbPiste<<")";
        file.flush();
        file.close();
    //}
}

