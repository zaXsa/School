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

#include "AppInfo.h"
#include "MainWindow.h"

MainWindow::MainWindow()
{
   pStateMachine = new StateMachine(this);

   createMenu();
   createHorizontalGroupBoxes();
   createGridGroupBox();

   buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                    | QDialogButtonBox::Cancel);
   connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
   connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

   QVBoxLayout *mainLayout = new QVBoxLayout;
   mainLayout->setMenuBar(menuBar);
   mainLayout->addWidget(horizontalGroupBox1);
   mainLayout->addWidget(gridGroupBox);
   mainLayout->addWidget(horizontalGroupBox2);
   mainLayout->addWidget(buttonBox);

   setLayout(mainLayout);
   setWindowTitle(tr(APPNAME_VERSION));
   pStateMachine->handleEvent(E_INIT);
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
   logDisplay->insertPlainText("\n" + text);
   logDisplay->moveCursor(QTextCursor::End);
}

void MainWindow::createMenu()
{
   menuBar = new QMenuBar;
   fileMenu = new QMenu(tr("&File"), this);
   exitAction = fileMenu->addAction(tr("E&xit"));
   menuBar->addMenu(fileMenu);
   connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}

void MainWindow::createHorizontalGroupBoxes()
{
   // HorizontalGroupBox 1 -----------------------------------------------------
   horizontalGroupBox1 = new QGroupBox(tr("Input cents"));
   QHBoxLayout *layout1 = new QHBoxLayout;

   buttons[0] = new QPushButton(tr("5C"));
   layout1->addWidget(buttons[0]);
   connect(buttons[0], SIGNAL(released()), this, SLOT(coin5C()));

   buttons[1] = new QPushButton(tr("10C"));
   layout1->addWidget(buttons[1]);
   connect(buttons[1], SIGNAL(released()), this, SLOT(coin10C()));

   buttons[2] = new QPushButton(tr("20C"));
   layout1->addWidget(buttons[2]);
   connect(buttons[2], SIGNAL(released()), this, SLOT(coin20C()));

   buttons[3] = new QPushButton(tr("50C"));
   layout1->addWidget(buttons[3]);
   connect(buttons[3], SIGNAL(released()), this, SLOT(coin50C()));

   enableCentButtons(false);
   horizontalGroupBox1->setLayout(layout1);

   // HorizontalGroupBox 2 -----------------------------------------------------
   horizontalGroupBox2 = new QGroupBox(tr("Logging"));
   QHBoxLayout *layout2 = new QHBoxLayout;
   logDisplay = new QTextEdit("Logging started", this);
   logDisplay->setOverwriteMode(false);
   logDisplay->setReadOnly(true);
   layout2->addWidget(logDisplay);
   horizontalGroupBox2->setLayout(layout2);
}

void MainWindow::createGridGroupBox()
{
   gridGroupBox = new QGroupBox(tr("Display"));
   QGridLayout *layout = new QGridLayout;

   QPixmap *image = new QPixmap(":/icons/Cola.ico");  // in CVMresources.qrc
   QLabel *label = new QLabel;
   label->setPixmap(*image);
   layout->addWidget(label, 0, 0);

   display = new QTextEdit(this);
   display->setReadOnly(true);
   display->setTextColor(QColor(0,0,0));
   display->setFontPointSize(30);
   display->setFixedSize(500, 50);
   display->setOverwriteMode(true);
   layout->addWidget(display, 0, 1, 1, 5);

   layout->setColumnStretch(1, 10);
   layout->setColumnStretch(2, 20);
   gridGroupBox->setLayout(layout);
}

//----------------------------------------------------------- GUI event handlers
void MainWindow::coin5C()
{
   pStateMachine->handleEvent(E_IN5C);
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
