#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "chessbyperson.h"
#include "fightai.h"
#include "aifight.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void myslot();
    void changeone();
    void changetwo();
    void changethree();
    void dealchessByPerson();
    void dealfightAI();
    void dealAIfight();

private:
    Ui::Widget *ui;

    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;

    chessByPerson w1;
    fightAI w2;
    AIfight w3;

};

#endif // WIDGET_H
