#include "mywindow.h"

MyWindow::MyWindow()
{
    exitButton = new QPushButton("exit");
    saveButton = new QPushButton("save");
    loadButton = new QPushButton("load");
    colorButton = new QPushButton("Color");
    radiusSlider = new QSlider(Qt::Horizontal);

    canvas = new glWidget;

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(loadButton);
    buttonLayout->addWidget(colorButton);
    buttonLayout->addWidget(radiusSlider);

    QVBoxLayout* overall = new QVBoxLayout;
    overall->addWidget(canvas);
    overall->addLayout(buttonLayout);

    setLayout(overall);
//    connect(radiusSlider, SIGNAL(valueChanged(int)),
//                                 this, SLOT(canvas->PolyBots))
    connect(colorButton, SIGNAL(clicked()),
            canvas, SLOT(changeColor()));
    connect(exitButton, SIGNAL(clicked()),
            this, SLOT(close()));
    connect(loadButton, SIGNAL(clicked()),
            this, SLOT(Load()));
    connect(saveButton, SIGNAL(clicked()),
            this, SLOT(Save()));
    connect(this, SIGNAL(actionSignal()),
            this, SLOT(Action()));
    canvas->setMinimumSize(640, 480);
}

void MyWindow::Load()
{
    cout << "\n\nLOADING...\n\n";
    emit actionSignal();
}

void MyWindow::Action()
{
    cout << "\n\nTAKING ACTION...\n\n";
}

void MyWindow::Save()
{
    emit saveSignal();
    cout << "I'm saving" << endl;
}

