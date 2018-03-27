#include <QApplication>
#include <QPushButton>
//http://www.bogotobogo.com/Qt/Qt5_SignalsSlotsGui.php

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QGridLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Grid layout with 3 buttons
    QGridLayout *gridLayout = new QGridLayout;

    QLabel *L1 = new QLabel("Helle world");

    QPushButton *b1 = new QPushButton("A");
    QPushButton *b2 = new QPushButton("B");
    QPushButton *b3 = new QPushButton("C");
    QPushButton *b4 = new QPushButton("D");
    QPushButton *b5 = new QPushButton("E");
    QPushButton *b6 = new QPushButton("F");
    QPushButton *b7 = new QPushButton("G");
    QPushButton *b8 = new QPushButton("H");



    gridLayout->setMargin(100);
    gridLayout->SetMaximumSize;

    // addWidget(*Widget, row, column, rowspan, colspan)
    // 0th row
    gridLayout->addWidget(b1,0,0,2,1);
    gridLayout->addWidget(b2,0,1,3,1);
    gridLayout->addWidget(b3,0,2,4,1);
    gridLayout->addWidget(b7,0,3,5,1);

    // 1st row
    gridLayout->addWidget(b4,1,0,2,1);

    // 2nd row with 2-column span
    gridLayout->addWidget(b5,2,0,3,2);

    // 3rd row with 3-column span
    gridLayout->addWidget(b6,3,0,4,3);

    // 4rd row with 4-column span
    gridLayout->addWidget(L1,6,0,5,1);

    // Create a widget
    QWidget *w = new QWidget();

    // Set the grid layout as a main layout
    w->setLayout(gridLayout);

    // Window title
    w->setWindowTitle("Grid Layouts (4x4)");

    // Display
    w->show();

    // Event loop
    return app.exec();
}
