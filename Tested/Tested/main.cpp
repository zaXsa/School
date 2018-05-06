#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QVBoxLayout>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    QWidget *MainWindow = new QWidget;
    MainWindow->setWindowTitle("This is a test");

    QVBoxLayout *Vlayout = new QVBoxLayout;
    QHBoxLayout *Hlayout1 = new QHBoxLayout;
    QHBoxLayout *Hlayout2 = new QHBoxLayout;

    QLabel *L1 = new QLabel("Show it");
    QPushButton *B1 = new QPushButton("Push it");
    QSlider *S1 = new QSlider();
    QSpinBox *P1 = new QSpinBox();

    QObject::connect(B1, SIGNAL(pressed()),L1,SLOT(setText(QString)));



    QObject::connect(S1, SIGNAL(valueChanged(int)),P1,SLOT(setValue(int)));
    QObject::connect(P1, SIGNAL(valueChanged(int)),S1,SLOT(setValue(int)));

    P1->setRange(10,50);
    S1->setRange(10,50);
    S1->setValue(10);

    Hlayout1->addWidget(L1);
    Hlayout1->addWidget(B1);

    Hlayout2->addWidget(S1);
    Hlayout2->addWidget(P1);

    Vlayout->addLayout(Hlayout1);
    Vlayout->addLayout(Hlayout2);

    MainWindow->setLayout(Vlayout);
    MainWindow->show();
    return a.exec();
}
