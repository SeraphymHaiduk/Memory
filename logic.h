#ifndef LOGIC_H
#define LOGIC_H
#include <QObject>
#include <memory>
#include "dataprovider.h"
#include <QTimer>
#include <QVariant>

class Logic : public QObject
{
    Q_OBJECT
public:
    Logic(std::shared_ptr<DataProvider> dataProvider, QObject *parent = 0);
    ~Logic();

    Q_INVOKABLE void startNewGame(int size);
    Q_INVOKABLE void pressOn(int x,int y);
    Q_INVOKABLE QVariant getRecords();
signals:
    void sessionInnitialised(QVariant images, int size);
    void flipBack(int x1,int y1,int x2,int y2);
    void flip(int x,int y);

    void timeUpdate(QTime time);
    void stepsUpdate(int steps);
    void scoreUpdate(int score);

    void victory(QVariant score,bool isRecord);
private:
    std::shared_ptr<DataProvider> dataProvider;
    QTimer timer;
    std::pair<int,int> lastPressed;
};

#endif // LOGIC_H
