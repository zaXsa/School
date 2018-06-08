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
class MainWindow;
class StateMachine;
//QT_END_NAMESPACE
class SubWindow: public QDialog
{
Q_OBJECT // to make it possible to use events(SIGNAL)/event-handlers(SLOT)

public:
    SubWindow();

    QLineEdit *Name;
    QLineEdit *Pass;
    QTextEdit *Logdisplay;
    QPushButton *LogInButton;
    QGroupBox *gridGroupBox;

    void setLogDisplay(const QString& text);
    void AddDrinks(void);
    void subsubWindow(void);
private:
    QGroupBox *VerticalGroup1;
    QPushButton *buttons[4];
    QGroupBox *grindGroupBoxx2;

    QLineEdit *Drink;
    QLineEdit *Change;
private slots:
    void CheckName();
};

#endif // SUBWINDOW_H
