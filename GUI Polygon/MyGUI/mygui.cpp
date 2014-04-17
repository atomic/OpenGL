#include "mygui.h"


MyGui::MyGui()
{
    exitButton = new QPushButton("Exit");
    saveButton = new QPushButton("Save");
    loadButton = new QPushButton("Load");
    glwidget = new glWidget;
//    textArea = new QTextEdit;

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(loadButton);

    QVBoxLayout* overall = new QVBoxLayout;
    overall->addWidget(glwidget);
    overall->addLayout(buttonLayout);

    setLayout(overall);

    connect(exitButton, SIGNAL(clicked()),
            this, SLOT(close()));

    connect(loadButton, SIGNAL(clicked()),
            this, SLOT(Load()));

    connect(saveButton, SIGNAL(clicked()),
            this, SLOT(Save()));

    connect(this, SIGNAL(actionSignal()),
            this, SLOT(Action()));

    glwidget->setMinimumSize(640, 480);
}

void MyGui::Load()
{
    cout << "\n\nLOADING...\n\n";

    emit actionSignal();
}

void MyGui::Save()
{
    cout << "\n\nSAVING...\n\n";

    emit actionSignal();
}

void MyGui::Action()
{
    cout << "\n\nTAKING ACTION...\n\n";
}
