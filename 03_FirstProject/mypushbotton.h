#ifndef MYPUSHBOTTON_H
#define MYPUSHBOTTON_H

#include <QPushButton>

class myPushBotton : public QPushButton
{
    Q_OBJECT
public:
    explicit myPushBotton(QWidget *parent = nullptr);

    ~myPushBotton();

signals:

};

#endif // MYPUSHBOTTON_H
