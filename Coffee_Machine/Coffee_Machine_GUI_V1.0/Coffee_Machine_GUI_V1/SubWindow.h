#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include <QDialog>
#include <QLineEdit>

//QT_BEGIN_NAMESPACE
class QlineEdit;
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
//QT_END_NAMESPACE
class SubWindow: public QDialog
{
Q_OBJECT // to make it possible to use events(SIGNAL)/event-handlers(SLOT)

public:
    SubWindow();
private:
    QGroupBox *VerticalGroup1;

    QLineEdit *Name;
    QLineEdit *Pass;
};

#endif // SUBWINDOW_H
