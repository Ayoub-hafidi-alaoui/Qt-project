#ifndef PARACHUTEVIEW_H
#define PARACHUTEVIEW_H

#include <QWidget>
#include "Presenter/presenter.h"
class Presenter;
class ParachuteView : public QWidget
{
    Q_OBJECT
public:
    explicit ParachuteView(QWidget *parent = nullptr);
    void setVector();
    void setPresenter(Presenter *);
    QVector<int> getVector();
    void updateNBSectors(int);
    void updateNbPiste(int);
    int getNbSector();
    int getNbTrack();
protected:
    void paintEvent(QPaintEvent *e) override;
private:
    Presenter *_presenter;
    QVector<int> _vector;
    //int NbSectors;
    int _nbsectors=21;
    int _nbtracks=5;
signals:

};

#endif // PARACHUTEVIEW_H
