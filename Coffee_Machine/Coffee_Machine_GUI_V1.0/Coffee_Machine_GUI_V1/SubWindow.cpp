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

#include <bits/stdc++.h>

#include <iostream>
#include <fstream>
using namespace std;

#include "AppInfo.h"
#include "MainWindow.h"

extern int AvailableAmount1;
extern int AvailableAmount2;
extern int AvailableAmount3;

extern int AvailableChange1;
extern int AvailableChange2;
extern int AvailableChange3;
extern int AvailableChange4;
extern int AvailableChange5;

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

    QVBoxLayout *layout4 = new QVBoxLayout;
    layout4->addWidget(Logdisplay);
    vertical = new QGroupBox();
    vertical->setLayout(layout4);

    subsubWindow();

    QGridLayout *layout = new QGridLayout();

    layout->addWidget(Name, 1, 0);
    layout->addWidget(Pass, 1, 1);
    layout->addWidget(LogInButton, 2, 0);

    gridGroupBox = new QGroupBox("Log-in screen");
    gridGroupBox->setLayout(layout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(vertical);
    mainLayout->addWidget(gridGroupBox);
    mainLayout->addWidget(grindGroupBoxx2);

    setLayout(mainLayout);

    setWindowTitle(APPNAME_VERSION);
    setMinimumSize(300,200);

    grindGroupBoxx2->hide();
}

SubWindow::~SubWindow() {
    UpdateFile();
    Name->clear();
    Pass->clear();
}

void SubWindow::UpdateDisplay(){
    setLogDisplay("Current Amount of drinks\n  Drink 1: "
                  +QString::number(AvailableAmount1)
                  +"\n  Drink 2: "+QString::number(AvailableAmount2)
                  +"\n  Drink 3: "+QString::number(AvailableAmount3)
                  +"\nCurrent Amount of Change\n  10 Cent: "+QString::number(AvailableChange1)
                  +"\n  20 Cent: "+QString::number(AvailableChange2)
                  +"\n  50 Cent: "+QString::number(AvailableChange3)
                  +"\n  100 Cent: "+QString::number(AvailableChange4));
}

void SubWindow::CheckName(){
    QString AdminName = Name->text();
    QString AdminPass = Pass->text();

    SetAdmin();

    if(AdminName.compare(AdminNamed) == 0 && AdminPass.compare(AdminPassed) == 0){
        UpdateDisplay();
        Name->clear();
        Pass->clear();
        gridGroupBox->hide();
        Logdisplay->setFixedSize(350,200);
        setMinimumSize(600,500);
        grindGroupBoxx2->show();
    } else {
        setLogDisplay("Wrong Name or Password");
    }
}

void SubWindow::SetAdmin(){
    string Word;
    int i = 0;
    string fileName;
    fileName = "Admin.txt";
    AdminFile.open(fileName.c_str());
    while(AdminFile >> Word){
        switch(i){
        case 0:
            AdminNamed = QString::fromStdString(Word);
            break;
        case 1:
            AdminPassed = QString::fromStdString(Word);
            break;
        default:
            break;
        }
        i++;
    }
    AdminFile.close();
}

void SubWindow::setLogDisplay(const QString &text) {
    Logdisplay->setText(text);
    Logdisplay->update();
}

void SubWindow::AddDrinks(){
    QString Buf = Drink->text();
    AvailableAmount1 += Buf.toInt();
    AvailableAmount2 += Buf.toInt();
    AvailableAmount3 += Buf.toInt();
    UpdateDisplay();
}

void SubWindow::RemoveDrinks(){
    QString Buf = Drink->text();
    AvailableAmount1 -= Buf.toInt();
    AvailableAmount2 -= Buf.toInt();
    AvailableAmount3 -= Buf.toInt();

    if (AvailableAmount1 < 0){
        AvailableAmount1 = 0;
    }
    if (AvailableAmount2 < 0){
        AvailableAmount2 = 0;
    }
    if (AvailableAmount3 < 0){
        AvailableAmount3 = 0;
    }
    UpdateDisplay();
}

void SubWindow::AddChange(){
    QString Buf = Change->text();
    AvailableChange1 += Buf.toInt();
    AvailableChange2 += Buf.toInt();
    AvailableChange3 += Buf.toInt();
    AvailableChange4 += Buf.toInt();
    UpdateDisplay();
}

void SubWindow::RemoveChange(){
    QString Buf = Change->text();
    AvailableChange1 -= Buf.toInt();
    AvailableChange2 -= Buf.toInt();
    AvailableChange3 -= Buf.toInt();
    AvailableChange4 -= Buf.toInt();

    if (AvailableChange1 < 0){
        AvailableChange1 = 0;
    }
    if (AvailableChange2 < 0){
        AvailableChange2 = 0;
    }
    if (AvailableChange3 < 0){
        AvailableChange3 = 0;
    }
    if (AvailableChange4 < 0){
        AvailableChange4 = 0;
    }
    UpdateDisplay();
}

void SubWindow::subsubWindow(){
    buttons[0] = new QPushButton("Add Drinks");
    buttons[1] = new QPushButton("Remove Drinks");
    buttons[2] = new QPushButton("Add Change");
    buttons[3] = new QPushButton("Remove Change");
    buttons[4] = new QPushButton("Set New Login");

    Drink = new QLineEdit();
    Change = new QLineEdit();
    NewName = new QLineEdit();
    NewPass = new QLineEdit();

    Drink->setPlaceholderText("Add/ Remove Drinks");
    Change->setPlaceholderText("Add/ Remove Change");

    NewName->setPlaceholderText("New Name");
    NewPass->setPlaceholderText("New Pass");

    QGridLayout *layout1 = new QGridLayout;

    buttons[0]->setFixedWidth(100);

    layout1->addWidget(buttons[0], 0, 0);
    layout1->addWidget(buttons[1], 0, 1);
    layout1->addWidget(buttons[2], 1, 0);
    layout1->addWidget(buttons[3], 1, 1);
    layout1->addWidget(buttons[4], 2, 0);
    layout1->addWidget(Drink, 0, 2);
    layout1->addWidget(Change, 1, 2);
    layout1->addWidget(NewName, 2, 1);
    layout1->addWidget(NewPass, 2, 2);

    connect(buttons[0], SIGNAL(released()), this, SLOT(AddDrinks()));
    connect(buttons[1], SIGNAL(released()), this, SLOT(RemoveDrinks()));
    connect(buttons[2], SIGNAL(released()), this, SLOT(AddChange()));
    connect(buttons[3], SIGNAL(released()), this, SLOT(RemoveChange()));
    connect(buttons[4], SIGNAL(released()), this, SLOT(RemoveChange()));
    connect(buttons[4], SIGNAL(released()), this, SLOT(GetUpdated()));

    buttons[0]->setEnabled(true);
    buttons[1]->setEnabled(true);
    buttons[2]->setEnabled(true);
    buttons[3]->setEnabled(true);
    buttons[4]->setEnabled(true);
    QApplication::processEvents();

    grindGroupBoxx2 = new QGroupBox("Add/Remove window");
    grindGroupBoxx2->setLayout(layout1);
}

void SubWindow::UpdateFile(){
    AdminFile.open("Admin.txt");
    AdminFile << AdminNamed.toStdString() << " " << AdminPassed.toStdString() << " " << AvailableAmount1 << " " << AvailableAmount2 << " " << AvailableAmount3 << endl;
    AdminFile.close();
}

void SubWindow::GetUpdated(){
    AdminNamed = NewName->text();
    AdminPassed = NewPass->text();
    UpdateFile();
}







