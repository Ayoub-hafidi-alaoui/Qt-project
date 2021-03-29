#include "presenter.h"
#include <iostream>
#include <QDebug>

Presenter::Presenter()
{


}
void Presenter::setModel(Model *model) {
    _model=model;
}

void Presenter::setView1(BinaryView *v1) {
    Presenter::_v1=v1;
}
void Presenter::setView2(ParachuteView *v2) {
    Presenter::_v2=v2;
}
void Presenter::setVectorInt() {
    Presenter::_vectorInt=_model->getKbit(_model->ConversionStringToAscii());
    _model->stockMessage();
    //std::cout<<_vectorInt.at(0);
}
void Presenter::setMessage(QString message) {
    _message=message;
    _model->updateMessage(message);
    Presenter::setVectorInt();
    Presenter::_v1->setVector();
    Presenter::_v2->setVector();
    qWarning()<<Presenter::_model->getLenMessage();

}
QVector<int> Presenter::getVector() {
    if(_vectorInt.empty()) {
        return QVector<int>(120,0);
    }
    return Presenter::_vectorInt;
}
//Presenter::
/*
int Presenter::getKBitsFromModel(int k) {
    QStringList list=_model->ConversionStringToAscii(_message);
    /*
    QVector<int> v
    for(int i=0;i<7;i++) {
        for(int j=0;j<20;j++) {
            _v1->set
        }
    }*/
    //return _model->getKbit(list,k);
//}

