#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    // Horizontal layout with 3 buttons
    QHBoxLayout *hLayout = new QHBoxLayout;

    QVBoxLayout *vvLayout = new QVBoxLayout;
    QPushButton *b1 = new QPushButton("A");
    QPushButton *b2 = new QPushButton("B");
    QPushButton *b3 = new QPushButton("C");
    vvLayout->addWidget(b1);
    vvLayout->addWidget(b2);
    vvLayout->addWidget(b3);

    // Vertical layout with 3 buttons
    QVBoxLayout *vLayout = new QVBoxLayout;
    QPushButton *b4 = new QPushButton("D");
    QPushButton *b5 = new QPushButton("E");
    QPushButton *b6 = new QPushButton("F");

    vLayout->addWidget(b4);
    vLayout->addWidget(b5);
    vLayout->addWidget(b6);

    hLayout->addLayout(vvLayout);
    hLayout->addLayout(vLayout);

    // Outer Layer
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Add the previous two inner layouts
    mainLayout->addLayout(hLayout);
    mainLayout->addLayout(vLayout);

    // Create a widget
    QWidget *w = new QWidget();

    // Set the outer layout as a main layout
    // of the widget
    w->setLayout(mainLayout);

    // Window title
    w->setWindowTitle("layouts");

    w->show();                                                              // Display
    return app.exec();                                                      // Event loop
}















