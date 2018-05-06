// Testing: https://wiki.qt.io/How_to_catch_enter_key#Key_pressed.3F

#include <iostream>
#include <QObject>
#include <QKeyEvent>
#include <QEvent>

using namespace std;

class keyEnterReceiver : public QObject{
    Q_OBJECT
protected:
    bool eventFilter(QObject* obj, QEvent* event);
};

bool keyEnterReceiver::eventFilter(QObject* obj, QEvent* event){
    if (event->type()==QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
            //Enter or return was pressed
        } else {
            return QObject::eventFilter(obj, event);
        }
        return true;
    } else {
        return QObject::eventFilter(obj, event);
    }
    return false;
}


int main(){
    keyEnterReceiver obj1;
    bool test = true;
    while(1){
    }
}
