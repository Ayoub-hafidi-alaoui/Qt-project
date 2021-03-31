#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QWidget>
#include <iostream>
#include<fstream>
class Model
{
public:
    explicit Model();
    QStringList ConversionStringToAscii( );
    QVector<int> getKbit(QStringList s);
    int getLenMessage();
    void stockMessage(int,int);

public slots:
    void updateMessage(QString message);
private:
    QString _message;
    QString _convertion;
    QVector<int>vectorInt;
    std::ofstream file;
    std::ofstream binaryFile;
};

#endif // MODEL_H
