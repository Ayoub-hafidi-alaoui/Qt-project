#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Presenter/presenter.h"
#include "View/binaryview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setPresenter(Presenter *p);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    Presenter *_p;
public slots:
    void updateMessage();
    void updateNbSectors(int);
    void updateNbPiste(int);
private slots:
    void on_action_About_us_triggered();
};
#endif // MAINWINDOW_H