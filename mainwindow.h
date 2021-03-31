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
    void changerSpinBox2Value(int);
    void changerSpinBox1Value(int);
    void changeSliderValue(int);
    void changeSlider2Value(int);

private slots:
    void on_action_About_us_triggered();
    void on_action_spanish_triggered();
    void on_action_open_triggered();
};
#endif // MAINWINDOW_H
