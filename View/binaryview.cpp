#include "binaryview.h"
#include <QPainter>
#include <QDebug>
BinaryView::BinaryView(QWidget *parent) : QWidget(parent)
{
}

void BinaryView::setPresenter(Presenter *p) {
    BinaryView::_presenter=p;
}
void BinaryView::setVector() {
    BinaryView::vector=BinaryView::_presenter->getVector();
}
void BinaryView::paintEvent(QPaintEvent *) {
    //_presenter->setVectorInt();
    //QVector<int> v=BinaryView::_presenter->getVector();
           QVector<int> v=BinaryView::vector;
           for(int i=0;i<v.size();i++) {
               qWarning()<<v[i];
           }
          int range=v.size()/7;
          QPainter painter(this);
          painter.setPen(QPen(Qt::black));
          int x=0;
          for(int i=0;i<range;i++) {
              for(int j=(7*(i+1))-1;j>=7*i;j--) {
                  if(v[j]){
                  QBrush brush (Qt::red);
                  painter.setBrush(brush);
                  painter.drawEllipse(QPoint(10+25*i,10+25*x),7,7);
                  }
                  else {
                      QBrush brush1=(Qt::white);
                      painter.setBrush(brush1);
                      painter.drawEllipse(QPoint(10+25*i,10+25*x),7,7);
                  }
                  x++;
                }
              x=0;
          }
        }
