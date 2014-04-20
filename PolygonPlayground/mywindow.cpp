#include "mywindow.h"

MyWindow::MyWindow()
{
    exitButton = new QPushButton("exit");
    runButton = new QPushButton("Run");
    stopButton = new QPushButton("Stop");
    colorButton = new QPushButton("Color");
    addButton = new QPushButton("Summon");
    polygonCount = new QLabel("0");
    radiusSlider = new QSlider(Qt::Horizontal);

    canvas = new glWidget;

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(runButton);
    buttonLayout->addWidget(stopButton);
    buttonLayout->addWidget(colorButton);
    buttonLayout->addWidget(radiusSlider);
    buttonLayout->addWidget(polygonCount);

    QVBoxLayout* overall = new QVBoxLayout;
    overall->addWidget(canvas);
    overall->addLayout(buttonLayout);

    setLayout(overall);
//    connect(radiusSlider, SIGNAL(valueChanged(int)),
//                                 this, SLOT(canvas->PolyBots))
    connect(addButton, SIGNAL(clicked()),
            canvas, SLOT(addPolygon()));
    connect(addButton, SIGNAL(clicked()),
            polygonCount, SLOT(setText(canvas->PolyBots.size())));
    connect(colorButton, SIGNAL(clicked()),
            canvas, SLOT(changeAllColor()));
    connect(exitButton, SIGNAL(clicked()),
            this, SLOT(close()));
    connect(runButton, SIGNAL(clicked()),
            canvas, SLOT(Run()));
    connect(stopButton, SIGNAL(clicked()),
            canvas, SLOT(Stop()));

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

