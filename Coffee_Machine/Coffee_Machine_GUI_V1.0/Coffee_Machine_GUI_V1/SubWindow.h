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
class QVBoxLayout;
//QT_END_NAMESPACE
class SubWindow: public QDialog
{
Q_OBJECT // to make it possible to use events(SIGNAL)/event-handlers(SLOT)

public:
    SubWindow();
    ~SubWindow();

    QLineEdit *Name;
    QLineEdit *Pass;
    QTextEdit *Logdisplay;
    QPushButton *LogInButton;
    QGroupBox *gridGroupBox;
    QGroupBox *grindGroupBoxx2;
    QGroupBox *vertical;

    fstream AdminFile;

    QString AdminNamed;
    QString AdminPassed;

    void setLogDisplay(const QString& text);
    void subsubWindow(void);
    void UpdateDisplay(void);
    void SetAdmin(void);
    void UpdateFile(void);
private:
    QGroupBox *VerticalGroup1;
    QPushButton *buttons[5];

    QLineEdit *Drink;
    QLineEdit *Change;
    QLineEdit *NewName;
    QLineEdit *NewPass;
private slots:
    void CheckName();
    void AddDrinks();
    void RemoveDrinks();
    void AddChange();
    void RemoveChange();
    void GetUpdated();
};

#endif // SUBWINDOW_H
