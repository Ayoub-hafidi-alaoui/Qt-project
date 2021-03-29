#ifndef PRESENTER_H
#define PRESENTER_H
#include "Model/model.h"
#include "View/binaryview.h"
#include "View/parachuteview.h"
class ParachuteView;
class BinaryView;
class Presenter
{
public:
    Presenter();
    void setModel(Model * model);
    void setView1(BinaryView *v1);
    void setView2(ParachuteView *v2);
    void setMessage(QString message);
    void setVectorInt();
    QVector<int> getVector();
private :
    QString _message;
    Model *_model;
    BinaryView *_v1;
    ParachuteView *_v2;
    QVector<int> _vectorInt;
public slots:
    QString getMessageFromView();
};

#endif // PRESENTER_H
