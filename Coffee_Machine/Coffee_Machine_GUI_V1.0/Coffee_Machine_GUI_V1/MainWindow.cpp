/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QColor>
#include <QLabel>
#include <QPixmap>

#include <unistd.h>

#include <iostream>
#include <fstream>
using namespace std;

#include "AppInfo.h"
#include "MainWindow.h"

MainWindow::MainWindow()
{
    pStateMachine = new StateMachine(this);

    createMenu();
    createHorizontalGroupBoxes();
    createGridGroupBox();

    // buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
    //                                 | QDialogButtonBox::Close);
    // connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    // connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(horizontalGroupBox2);
    mainLayout->addWidget(gridGroupBox);
    mainLayout->addWidget(horizontalGroupBox1);
    mainLayout->addWidget(horizontalGroupBox3);
    mainLayout->addWidget(horizontalGroupBox4);
    //mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);
    setWindowTitle(APPNAME_VERSION);
    pStateMachine->handleEvent(E_INIT);
}

void MainWindow::Loging(){
    this->hide();
    sleep(5);
    this->show();
}

void MainWindow::ToggleLogger(){
    static int Mem = 1;

    if (Mem == 1){
        horizontalGroupBox2->hide();
        Mem = 0;
    } else {
        horizontalGroupBox2->show();
        Mem = 1;
    }

}

void MainWindow::ToggleExtra(){
    static int Mem = 1;

    if (Mem == 1){
        horizontalGroupBox4->hide();
        Mem = 0;
    } else {
        horizontalGroupBox4->show();
        Mem = 1;
    }

}

void MainWindow::enableCentButtons(bool enable) {
    for (int i = 0; i < NumButtons; i++) {
        buttons[i]->setEnabled(enable);
    }
}

void MainWindow::setDisplay(const QString &text) {
    display->setText(text);
    display->update();
}

void MainWindow::setLogger(const QString &text) {
    logDisplay->moveCursor(QTextCursor::End);
    logDisplay->insertPlainText(text);
    logDisplay->moveCursor(QTextCursor::End);

    file1.open ("testing.txt", ios::out | ios::app);
    file1 << text.toStdString();
    file1.close();
}

void MainWindow::setbuttonss(bool disable){
    if(disable){
        buttonss[0]->setEnabled(true);
        buttonss[1]->setEnabled(true);
        buttonss[2]->setEnabled(true);
        buttonss[3]->setEnabled(true);

        buttons[0]->setEnabled(true);
        buttons[1]->setEnabled(true);
        buttons[2]->setEnabled(true);
        buttons[3]->setEnabled(true);
    } else {
        buttonss[0]->setEnabled(false);
        buttonss[1]->setEnabled(false);
        buttonss[2]->setEnabled(false);
        buttonss[3]->setEnabled(false);

        buttons[0]->setEnabled(false);
        buttons[1]->setEnabled(false);
        buttons[2]->setEnabled(false);
        buttons[3]->setEnabled(false);
    }
}

void MainWindow::createMenu()
{
    menuBar = new QMenuBar;//(1)
    fileMenu = new QMenu("&File", this);//(2)
    menuBar->addMenu(fileMenu);//(3)

    exitAction = fileMenu->addAction("E&xit");//(4)
    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
    exitAction2 = fileMenu->addAction("Log-in(WIP");//(4)
    connect(exitAction2, SIGNAL(triggered()), this, SLOT(Loging()));
    exitAction3 = fileMenu->addAction("Toggle Logger(WIP");//(4)
    connect(exitAction3, SIGNAL(triggered()), this, SLOT(ToggleLogger()));
    exitAction4 = fileMenu->addAction("Toggle Extra Buttons (WIP");//(4)
    connect(exitAction4, SIGNAL(triggered()), this, SLOT(ToggleExtra()));
}

void MainWindow::createHorizontalGroupBoxes()
{
    // HorizontalGroupBox 1 -----------------------------------------------------

    buttons[0] = new QPushButton("10C");
    buttons[1] = new QPushButton("20C");
    buttons[2] = new QPushButton("50C");
    buttons[3] = new QPushButton("100C");

    QVBoxLayout *layout1 = new QVBoxLayout;

    buttons[0]->setFixedWidth(200);

    layout1->addWidget(buttons[0]);
    layout1->addWidget(buttons[1]);
    layout1->addWidget(buttons[2]);
    layout1->addWidget(buttons[3]);

    connect(buttons[0], SIGNAL(released()), this, SLOT(coin10C()));
    connect(buttons[1], SIGNAL(released()), this, SLOT(coin20C()));
    connect(buttons[2], SIGNAL(released()), this, SLOT(coin50C()));
    connect(buttons[3], SIGNAL(released()), this, SLOT(coin100C()));

    enableCentButtons(false);
    buttons[3]->setDisabled(true);
    buttons[3]->setEnabled(false);
    QApplication::processEvents();


    horizontalGroupBox1 = new QGroupBox("Input cents");
    horizontalGroupBox1->setLayout(layout1);

    // HorizontalGroupBox 3 -----------------------------------------------------

    buttonss[0] = new QPushButton("Drink 1");
    buttonss[1] = new QPushButton("Drink 2");
    buttonss[2] = new QPushButton("Drink 3");
    buttonss[3] = new QPushButton("Cancel");

    QVBoxLayout *layout3 = new QVBoxLayout;

    buttonss[0]->setFixedWidth(200);

    layout3->addWidget(buttonss[0]);
    layout3->addWidget(buttonss[1]);
    layout3->addWidget(buttonss[2]);
    layout3->addWidget(buttonss[3]);

    connect(buttonss[0], SIGNAL(released()), this, SLOT(Drink1()));
    connect(buttonss[1], SIGNAL(released()), this, SLOT(Drink2()));
    connect(buttonss[2], SIGNAL(released()), this, SLOT(Drink3()));
    connect(buttonss[3], SIGNAL(released()), this, SLOT(Cancel()));

    enableCentButtons(false);

    horizontalGroupBox3 = new QGroupBox("Input drink type");
    horizontalGroupBox3->setLayout(layout3);

    // HorizontalGroupBox 4 -----------------------------------------------------

    buttonsss[0] = new QPushButton("Fake coins");
    buttonsss[1] = new QPushButton("Placeholder");
    buttonsss[2] = new QPushButton("Placeholder");
    buttonsss[3] = new QPushButton("Placeholder");

    QVBoxLayout *layout4 = new QVBoxLayout;

    buttonsss[0]->setFixedWidth(200);
    buttonsss[0]->setStyleSheet("background-color: red; color: blue");

    layout4->addWidget(buttonsss[0]);
    layout4->addWidget(buttonsss[1]);
    layout4->addWidget(buttonsss[2]);
    layout4->addWidget(buttonsss[3]);

    connect(buttonsss[0], SIGNAL(released()), this, SLOT(coinWrong()));
    //connect(buttonsss[1], SIGNAL(released()), this, SLOT(Cancel()));
    //connect(buttonsss[2], SIGNAL(released()), this, SLOT(Cancel()));
    //connect(buttonsss[3], SIGNAL(released()), this, SLOT(Cancel()));

    buttonsss[1]->setEnabled(false);
    buttonsss[2]->setEnabled(false);
    buttonsss[3]->setEnabled(false);
    enableCentButtons(false);

    horizontalGroupBox4 = new QGroupBox("Extra buttons");
    horizontalGroupBox4->setLayout(layout4);

    // HorizontalGroupBox 2 -----------------------------------------------------

    logDisplay = new QTextEdit("Logging started", this);
    logDisplay->setOverwriteMode(false);
    logDisplay->setReadOnly(true);
    logDisplay->setFixedWidth(400);
    logDisplay->setFixedHeight(400);

    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(logDisplay);

    horizontalGroupBox2 = new QGroupBox("Logging");
    horizontalGroupBox2->setLayout(layout2);

}

void MainWindow::createGridGroupBox()
{
    QPixmap *image = new QPixmap(":/icons/Cola.ico");  // in CVMresources.qrc
    QLabel *label = new QLabel;
    label->setPixmap(*image);

    display = new QTextEdit(this);
    display->setReadOnly(true);
    display->setTextColor(QColor(0,0,0));
    display->setFontPointSize(10);
    //display->setFixedSize(500, 50);
    display->setFixedWidth(400);
    display->setOverwriteMode(true);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label, 0, 0);
    layout->addWidget(display, 0, 1, 1, 5);

    // layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 10);

    gridGroupBox = new QGroupBox("Display");
    gridGroupBox->setLayout(layout);
}

//----------------------------------------------------------- GUI event handlers
void MainWindow::coin5C()
{
    pStateMachine->handleEvent(E_IN10C);
}


void MainWindow::coin10C()
{
    pStateMachine->handleEvent(E_IN10C);
}

void MainWindow::coin20C()
{
    pStateMachine->handleEvent(E_IN20C);
}

void MainWindow::coin50C()
{
    pStateMachine->handleEvent(E_IN50C);
}

void MainWindow::coin100C()
{
    pStateMachine->handleEvent(E_IN100C);
}

void MainWindow::Drink1()
{
    pStateMachine->handleEvent(E_Drink1);
}

void MainWindow::Drink2()
{
    pStateMachine->handleEvent(E_Drink2);
}

void MainWindow::Drink3()
{
    pStateMachine->handleEvent(E_Drink3);
}

void MainWindow::Cancel()
{
    pStateMachine->handleEvent(E_Cancel);
}

void MainWindow::coinWrong()
{
    pStateMachine->handleEvent(E_coinWrong);
}
