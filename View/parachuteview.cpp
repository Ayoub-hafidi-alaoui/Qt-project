#include "parachuteview.h"
#include <QPainter>
#include <QPainterPath>
#include <QPolygon>
#include <math.h>
#include <QDebug>

ParachuteView::ParachuteView(QWidget *parent) : QWidget(parent)
{

}
void ParachuteView::setPresenter(Presenter *p) {
    ParachuteView::_presenter=p;
}
void ParachuteView::setVector() {
    ParachuteView::_vector=ParachuteView::_presenter->getVector();
}
QVector<int> ParachuteView::getVector() {
    return ParachuteView::_vector;
}

void ParachuteView::paintEvent(QPaintEvent *) {
    //
    QVector<int> v=ParachuteView::_vector;
    int size=v.size();
    int _nbsectors=ParachuteView::_nbsectors;
    int _nbtracks=ParachuteView::_nbtracks;
    int radius = width()/3 ;
    float sectorangle = (2.0 * M_PI / _nbsectors);
    float thicknesstrack = radius/_nbtracks;
    int sectornumber;
    float firstAngle;
    float secondAngle;
    int tracknumber;
    float interradius;
    float exteradius;
    int x1, x2, x3, x4, y1 , y2 , y3, y4 ;
    //int sieze1=size/7;
    int i=0;
    int k=(7*(i+1))-1;
    for(int j = 0; j <_nbsectors*_nbtracks ; j++) {
        sectornumber = j%_nbsectors;
        firstAngle = sectornumber * sectorangle;
        secondAngle = (sectornumber + 1) * sectorangle;
        tracknumber = j / _nbsectors;
        interradius =  tracknumber * thicknesstrack;
        exteradius = (tracknumber + 1) * thicknesstrack;

        // Coordinates determination
        x1 = interradius * cos(firstAngle) + width()/2;
        y1 = interradius * sin(firstAngle) +  radius + 30;
        x2 = interradius * cos(secondAngle) +  width()/2;
        y2 = interradius * sin(secondAngle) +  radius + 30;
        x3 = exteradius * cos(firstAngle) +  width()/2;
        y3 = exteradius * sin(firstAngle) +  radius + 30;
        x4 = exteradius * cos(secondAngle) +  width()/2;
        y4 = exteradius * sin(secondAngle) +  radius + 30;
        QPainterPath path;
        QPolygon poly;
        QPainter painter(this);
        painter.setPen(QPen(Qt::black));
        poly<<QPoint(x2,y2);
        poly<<QPoint(x1,y1);
        poly<<QPoint(x3,y3);
        poly<<QPoint(x4,y4);
        painter.drawPolygon(poly);
        path.addPolygon(poly);
        if(v.empty()){
        painter.fillPath(path,QBrush(Qt::white));
        }
       else {

            //int indice;
            if( j<size && v[k] ) {
            painter.fillPath(path,QBrush(Qt::red));
            }
            else {
                painter.fillPath(path,QBrush(Qt::white));
            }
            //qWarning()<<k;
            k--;
        }
        if(k<7*i) {
            ++i;
            k=7*(i+1)-1;
        }
    }
}
void ParachuteView::updateNBSectors(int sector) {
    ParachuteView::_nbsectors=sector;
    repaint();
}
void ParachuteView::updateNbPiste(int piste) {
    ParachuteView::_nbtracks=piste;
    repaint();
}
int ParachuteView::getNbSector() {
    return ParachuteView::_nbsectors;
}
int ParachuteView::getNbTrack() {
    return ParachuteView::_nbtracks;
}

