#include "logic.h"
//#include <QDebug>
#include <iostream>
#include <QVariant>
Logic::Logic(std::shared_ptr<DataProvider> dataProvider,QObject* parent) : QObject(parent)
{
    this->dataProvider = dataProvider;
    QObject::connect(&timer,&QTimer::timeout,this,
                     [this](){
                        try{
                            this->dataProvider->addSec();
                        }
                        catch(const char* msg){
//                            qDebug() << msg;
                        }
                        emit timeUpdate(this->dataProvider->getTime());
                        }
    );
    lastPressed = std::pair(-1,-1);
}
QVariant Logic::getRecords(){
    return dataProvider->getRecords();
}
void Logic::pressOn(int x, int y){
    if(dataProvider->isMarked(x,y)){
        return;
    }
    if(dataProvider->getSteps() == 0){
        timer.start(1000);
    }
//    qDebug() << 2;
    std::pair<int,int> newPair = std::make_pair(x,y);
    if(lastPressed!=std::pair(-1,-1)){
        if(!dataProvider->isPairing(lastPressed,newPair)){
            emit flipBack(lastPressed.first,lastPressed.second, x, y);
            lastPressed = std::pair(-1,-1);
            dataProvider->addStep();
            emit stepsUpdate(dataProvider->getSteps());
        }
        else{
//        qDebug() << 3;
        dataProvider->setMark(lastPressed,newPair);
        emit flip(newPair.first,newPair.second);
        dataProvider->addStep();
        emit stepsUpdate(dataProvider->getSteps());
        emit scoreUpdate(dataProvider->getMarkCount());
        lastPressed = std::make_pair(-1, -1);
//        qDebug() << 5;
        if(dataProvider->getMarkCount() == (dataProvider->getSize()*dataProvider->getSize())/2){
            QVariantMap score;
            score["size"] = dataProvider->getSize();
            score["steps"] = dataProvider->getSteps();
            score["time"] = dataProvider->getTime().toString("hh:mm:ss");
            emit victory(QVariant(score), dataProvider->isRecord());
            timer.stop();
            //???????????????? ???????????????? ??????????????
        }
//        qDebug() << 6;
        dataProvider->addStep();
//        qDebug() << 7;
        }
    }
    else{
        emit flip(x,y);
        lastPressed = std::make_pair(x, y);
    }
}
void Logic::startNewGame(int size){
    dataProvider->clearSession();
    timer.stop();
    emit scoreUpdate(0);
    emit stepsUpdate(0);
    emit timeUpdate(QTime::fromString("00:00:00","hh:mm:ss"));
    dataProvider->setSize(size);
    try{
        dataProvider->initField();
    }
    catch(const char* msg){
        std::cerr << msg << std::endl;
    }
    emit sessionInnitialised(dataProvider->getNamesField(),dataProvider->getSize());
//    qDebug() << "emit sessionInnitialised";

}

Logic::~Logic(){

}
