#ifndef LOGIC_H
#define LOGIC_H
#include <QObject>
#include <memory>
#include "dataprovider.h"
#include <QTimer>
class Logic : public QObject
{
    Q_OBJECT
public:
    Logic(DataProvider* dataProvider, QObject *parent = 0);
    ~Logic();

    Q_INVOKABLE void startNewGame(int size);
    Q_INVOKABLE void pressOn(int x,int y);
    Q_INVOKABLE QVariant getRecords();
signals:
    void sessionInnitialised(QVariant images, int size);
    void flipBack(int x1,int y1,int x2,int y2);
    void flip(int x,int y);

    void timeUpdate(QTime);
    void stepsUpdate(int);
    void scoreUpdate(int);

    void victory(QVariant score,bool isRecord);
private:
    std::unique_ptr<DataProvider> dataProvider;
    QTimer timer;
    std::pair<int,int> lastPressed;
};

#endif // LOGIC_H
