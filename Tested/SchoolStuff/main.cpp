#include <QApplication>
#include <QPushButton>
#include <QLabel>

class test{
  public:
    QPushButton *button = new QPushButton("show");
    QLabel *label = new QLabel("Ass");
    test(){button->show();}

public slots:
    void showass(){label->show();}
};

int main(int argc, char *argv[]){
    QApplication app(argc, argv);                           //
    test tests;

    QObject::connect(tests.button, SIGNAL(clicked()),
    &tests, SLOT(showass()));
    return app.exec();                                      // Execute
}
