#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <mypanelopengl.h>
#include <QMainWindow>

#include <QtWidgets>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

private:
    MyPanelOpenGL *widget;
    QMenuBar *menuBar;
    QMenu *loadMenu;
    QAction *loadPulsar;
    Ui::MainWindow *ui;
    float colorslider;
};

#endif // MAINWINDOW_H
