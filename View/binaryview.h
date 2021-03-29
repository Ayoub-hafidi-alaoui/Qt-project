#ifndef BINARYVIEW_H
#define BINARYVIEW_H

#include <QObject>
#include <QWidget>
#include "Presenter/presenter.h"

class Presenter;
class BinaryView : public QWidget
{
    Q_OBJECT
public:
    explicit BinaryView(QWidget *parent = nullptr);
     void setVector();
     void setPresenter(Presenter *);
protected:
    void paintEvent(QPaintEvent *e) override ;
private:
    Presenter *_presenter;
    QVector<int> vector;
signals:

};

#endif // BINARYVIEW_H
