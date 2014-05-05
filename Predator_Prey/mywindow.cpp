#include "mywindow.h"

MyWindow::MyWindow()
{
    exitButton = new QPushButton("exit");
    nextButton = new QPushButton("Next");
    runButton = new QPushButton("Run");
    stopButton = new QPushButton("Stop");
    spawnMTKButton = new QPushButton("Spawn Mutalisk");

    iPosButton = new QSpinBox();
    jPosButton = new QSpinBox();
    iPosButton->setValue(25);
    jPosButton->setValue(25);
    iPosButton->setMinimum(10);
    jPosButton->setMinimum(10);
    iPosButton->setMaximum(35);
    jPosButton->setMaximum(35);
    ptSizeDisplay = new QLabel(" Pt. ");
    ptSizeSlider = new QSlider(Qt::Horizontal);
    ptSizeSlider->setMinimum(200);
    ptSizeSlider->setMaximum(500);
    ptSizeSlider->setValue(POINTSIZE);

    canvas = new glWidget;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(nextButton);
    buttonLayout->addWidget(runButton);
    buttonLayout->addWidget(stopButton);
    buttonLayout->addWidget(spawnMTKButton);
    buttonLayout->addWidget(iPosButton);
    buttonLayout->addWidget(jPosButton);
    buttonLayout->addWidget(ptSizeSlider);
    buttonLayout->addWidget(ptSizeDisplay);


    QVBoxLayout* overall = new QVBoxLayout;
    overall->addWidget(canvas);
    overall->addLayout(buttonLayout);

    connect(exitButton, SIGNAL(clicked()),
            this, SLOT(close()));
    connect(nextButton, SIGNAL(clicked()),
            canvas, SLOT(Next()));
    connect(runButton, SIGNAL(clicked()),
            canvas, SLOT(Run()));
    connect(stopButton, SIGNAL(clicked()),
            canvas, SLOT(Stop()));

    connect(iPosButton, SIGNAL(valueChanged(int)),
            canvas, SLOT(set_i_Pos(int)));
    connect(jPosButton, SIGNAL(valueChanged(int)),
            canvas, SLOT(set_j_Pos(int)));
    connect(spawnMTKButton, SIGNAL(clicked()),
            canvas, SLOT(spawnRandomMutalisk()));
    connect(ptSizeSlider, SIGNAL(valueChanged(int)),
            canvas, SLOT(setPtSize(int)));
    connect(ptSizeSlider, SIGNAL(valueChanged(int)),
            this, SLOT(updateptSizeText(int)));

    setLayout(overall);
    canvas->setMinimumSize(SCREENX,SCREENY);
}
