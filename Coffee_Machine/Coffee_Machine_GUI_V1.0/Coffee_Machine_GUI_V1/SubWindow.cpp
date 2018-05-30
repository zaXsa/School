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

    QGridLayout *layout = new QGridLayout();

    layout->addWidget(Logdisplay, 0, 0);
    layout->addWidget(Name, 1, 0);
    layout->addWidget(Pass, 1, 1);
    layout->addWidget(LogInButton, 2, 0);

    gridGroupBox = new QGroupBox("Log-in screen");
    gridGroupBox->setLayout(layout);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(gridGroupBox);

    setLayout(mainLayout);

    setWindowTitle(APPNAME_VERSION);
    setFixedSize(300,200);
}

void SubWindow::CheckName(){
    QString AdminName = Name->text();
    QString AdminPass = Pass->text();

    if(AdminName.compare("Admin") == 0 && AdminPass.compare("Admin") == 0){
        setLogDisplay("You logged in");
    } else {
        setLogDisplay("Wrong Name or Password");
    }
}

void SubWindow::setLogDisplay(const QString &text) {
    Logdisplay->setText(text);
    Logdisplay->update();
}













