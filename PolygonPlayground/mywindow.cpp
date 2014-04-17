#include "mywindow.h"

MyWindow::MyWindow()
{
    exitButton = new QPushButton("exit");
    saveButton = new QPushButton("save");
    loadButton = new QPushButton("load");

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(loadButton);
    buttonLayout->addWidget(canvas);

    setLayout(buttonLayout);

    connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(saveButton,SIGNAL(clicked()),this,SLOT(close()));
}

void MyWindow::Save()
{
    emit saveSignal();
    cout << "I'm saving" << endl;
}

