#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QtWidgets>
#include <QPushButton>
#include <QHBoxLayout>
#include <iostream>

using namespace std;

class MyWindow : public QWidget
{
    Q_OBJECT
public:
    MyWindow();
signals:
    void saveSignal();
public slots:
    void Save();
private:
    QPushButton *exitButton;
    QPushButton *saveButton;
    QPushButton *loadButton;

};

#endif // MYWINDOW_H
