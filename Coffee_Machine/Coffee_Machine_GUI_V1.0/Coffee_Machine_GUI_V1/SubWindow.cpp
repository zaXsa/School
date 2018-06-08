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
******************************************************************************/

#include "SubWindow.h"

#include <QtWidgets>
#include <QColor>
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>

#include <unistd.h>

#include <iostream>
#include <fstream>
using namespace std;

#include "AppInfo.h"
#include "MainWindow.h"

extern int AvailableAmount1;
extern int AvailableAmount2;
extern int AvailableAmount3;

SubWindow::SubWindow(){
    Name = new QLineEdit();
    Pass = new QLineEdit();
    Name->setFixedWidth(100);
    Name->setPlaceholderText("Enter Name");
    Pass->setFixedWidth(100);
    Pass->setPlaceholderText("Enter Pass");
    Pass->setEchoMode(QLineEdit::Password);

    LogInButton = new QPushButton("LogIn");
    LogInButton->setFixedWidth(50);

    connect(LogInButton, SIGNAL(released()), this, SLOT(CheckName()));

    Logdisplay = new QTextEdit("Please enter name and password");
    Logdisplay->setReadOnly(true);
    Logdisplay->setTextColor(QColor(0,0,0));
    Logdisplay->setFontPointSize(10);
    Logdisplay->setFixedSize(250,30);
    Logdisplay->setOverwriteMode(true);

    //  Later Use
    //  QString XMAX=ui->lineEdit->text();
    //  xMax=XMAX.toDouble();
    //  std::stod(ui->lineEdit->text().toStdString());

    subsubWindow();
    QGridLayout *layout = new QGridLayout();

    layout->addWidget(Logdisplay, 0, 0);
    layout->addWidget(Name, 1, 0);
    layout->addWidget(Pass, 1, 1);
    layout->addWidget(LogInButton, 2, 0);

    gridGroupBox = new QGroupBox("Log-in screen");
    gridGroupBox->setLayout(layout);

    gridGroupBox->setMinimumSize(300,200);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(gridGroupBox);
    mainLayout->addWidget(grindGroupBoxx2);

    setLayout(mainLayout);

    setWindowTitle(APPNAME_VERSION);

    grindGroupBoxx2->hide();
}

void SubWindow::CheckName(){
    QString AdminName = Name->text();
    QString AdminPass = Pass->text();

    if(AdminName.compare("Admin") == 0 && AdminPass.compare("Admin") == 0){
        setLogDisplay("You logged in");
        AddDrinks();
    } else {
        setLogDisplay("Wrong Name or Password");
    }
}

void SubWindow::setLogDisplay(const QString &text) {
    Logdisplay->setText(text);
    Logdisplay->update();
}

void SubWindow::AddDrinks(){
    AvailableAmount1 = 3;
    AvailableAmount2 = 3;
    AvailableAmount3 = 3;

    grindGroupBoxx2->show();
}

void SubWindow::subsubWindow(){
    buttons[0] = new QPushButton("Add Drinks");
    buttons[1] = new QPushButton("Remove Drinks");
    buttons[2] = new QPushButton("Add Change");
    buttons[3] = new QPushButton("Remove Change");

    Drink = new QLineEdit();
    Change = new QLineEdit();

    QGridLayout *layout1 = new QGridLayout;

    buttons[0]->setFixedWidth(100);

    layout1->addWidget(buttons[0], 0, 0);
    layout1->addWidget(buttons[1], 0, 1);
    layout1->addWidget(buttons[2], 1, 0);
    layout1->addWidget(buttons[3], 1, 1);
    layout1->addWidget(Drink, 0, 2);
    layout1->addWidget(Change, 1, 2);

    //connect(buttons[0], SIGNAL(released()), this, SLOT(coin10C()));
    //connect(buttons[1], SIGNAL(released()), this, SLOT(coin20C()));
    //connect(buttons[2], SIGNAL(released()), this, SLOT(coin50C()));
    //connect(buttons[3], SIGNAL(released()), this, SLOT(coin100C()));

    buttons[0]->setEnabled(true);
    buttons[1]->setEnabled(true);
    buttons[2]->setEnabled(true);
    buttons[3]->setEnabled(true);
    QApplication::processEvents();


    grindGroupBoxx2 = new QGroupBox("Add/Remove window");
    grindGroupBoxx2->setLayout(layout1);
}









