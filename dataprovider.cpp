#include "dataprovider.h"
#include "QDir"
#include <algorithm>
#include <time.h>
#include <functional>
#include <QJsonObject>
#include <QDebug>
#include <QVariant>
#include <QVariantMap>

DataProvider::DataProvider()
{
        clearSession();
}


void DataProvider::clearSession(){
    steps = 0;
    size = 0;
    markCounter = 0;
    time = QTime::fromString("00:00:00","hh:mm:ss");
//    qDebug() << time;
    fieldBool.clear();
    fieldPairs.clear();
    fieldStr.clear();
}


QVariant DataProvider::getRecords(){
    QFile file("records.json");
    if(!file.open(QIODevice::ReadWrite)){
        throw("Can't open records file");
    }
    QJsonDocument jd = QJsonDocument(QJsonDocument::fromJson(file.readAll()));
    QJsonObject jo = jd.object();
    QStringList keys = jo.keys();
    QVariantMap map;
    for(QString& s: keys){
        QVariantMap map1;
        map1["steps"] = jo[s].toObject()["steps"].toInt();
        map1["time"] = jo[s].toObject()["time"].toString();
        map1["size"] = s;
        map[s] = map1;
    }
    return map;
}


bool DataProvider::isRecord(){
    QFile file("records.json");
    if(!file.open(QIODevice::ReadWrite)){
        throw("Can't open records file");
    }
    QJsonDocument jd = QJsonDocument(QJsonDocument::fromJson(file.readAll()));
    QJsonObject jo = jd.object();
    QString s = QVariant(size).toString();
    auto writeRecord = [&](){
        QJsonObject jo1;
        jo1["steps"] = steps;
        jo1["time"] = time.toString("hh:mm:ss");
        jo[s] = jo1;
        file.seek(0);
        file.write(QJsonDocument(jo).toJson());
    };
    qDebug() << "record1";
    if(jo.size() == 0){
        qDebug() << "record2";
        writeRecord();
        return true;
    }
    else{
        qDebug() << "record3";
        if(steps <= jo[s].toObject()["steps"].toInt()){
            qDebug() << "record4";
            if(steps == jo[s].toObject()["steps"].toInt()){
                qDebug() << "record5";
                if(time < QTime::fromString(jo[s].toObject()["time"].toString(),"hh:mm:ss")){
                    qDebug() << "record6";
                    writeRecord();
                    return true;
                }
                qDebug() << "record7";
                return false;
            }
            else{
                qDebug() << "record8";
            writeRecord();
            return true;
            }
        }
        return false;
    }
}


int DataProvider::getMarkCount(){
    return markCounter;
}


void DataProvider::setSize(int n){
    if(n!=this->size){
        if(names.size()!=0){
            names.clear();
        }
    }
    size = n;
}


void DataProvider::setMark(std::pair<int, int> coord1, std::pair<int, int> coord2){
    qDebug() << 4;
    fieldBool[coord1.first][coord1.second] = true;
    fieldBool[coord2.first][coord2.second] = true;
    markCounter+=1;
}


bool DataProvider::isPairing(std::pair<int,int> coord1,std::pair<int,int> coord2){
    std::pair<int,int> pair = fieldPairs[coord1];
    if(pair.first == coord2.first && pair.second == coord2.second){
        return 1;
    }
    else{
        return 0;
    }
}


bool DataProvider::isMarked(int x,int y){
    return fieldBool[x][y];
}


void DataProvider::addSec(){
    if(!time.isValid()){
        throw("time property is invalid ♿");
    }
    time = time.addSecs(1);
}


QTime DataProvider::getTime(){
    return time;
}


void DataProvider::addStep(){
    steps++;
}


int DataProvider::getSteps(){
    return steps;
}


int DataProvider::getSize(){
    return size;
}


void DataProvider::initField(){
    if(size%2!=0){
        throw("size is not pair");
    }
    if(size == 0){
        throw("size wasn't initialised");
    }
    int count = size*size/2;
    if(names.size() == 0){
        QDir directory(":/Pictures");
        QStringList files = directory.entryList(QStringList(QString("*.png")));
        if(files.size()<count){
//            qDebug() << "Error: files.size() is " << files.size();
            throw("is few images in folder");
        }

        names.resize(count);
        for(int i = 0;i<count;i++){
            names[i] = (std::move(files[i]));
        }
        files.clear();
    }
    std::vector<QString*> extendetNames;
    extendetNames.resize(count*2);
    std::vector<QString>::iterator it;
    for(int i = 0; i < 2;i++){
        it = names.begin();
        for(int j = 0; j < count; j++){
            if(it == names.end()){
                throw("Mistake in extendetList filling");
            }
            extendetNames[i*count+j] = (&(*it));
            it++;
        }
    }
    srand(std::time(NULL));
    std::random_shuffle(extendetNames.begin(), extendetNames.end());
    fieldStr.assign(size,std::vector<QString*>(size));
    fieldBool.clear();
    fieldBool.assign(size,std::vector<bool>(size,0));

    auto squareFor = [=](auto func){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                func(i,j);
            }
        }
    };

    auto findPairs = [&](int i, int j, auto& vec, auto& pairsMap){
        squareFor([&](int k, int m){
            if(vec[k*size+m] == vec[i*size+j]){
                if(k != i || m != j){
                    pairsMap[std::make_pair(k,m)] = std::make_pair(i,j);
                    pairsMap[std::make_pair(i,j)] = std::make_pair(k,m);
                }
            }
        });
    };
    squareFor([&](int i,int j){
        if(fieldPairs.find(std::make_pair(i,j)) == fieldPairs.end()){
            findPairs(i,j,extendetNames,fieldPairs);
        }
    });

//    squareFor([&](int i, int j){
//        qDebug() << fieldPairs[std::make_pair(i,j)];
//    });

    squareFor([&](int i, int j){
        fieldStr[i][j] = extendetNames[i*size+j];
    });

//    for(auto& a: fieldStr){
//        for(auto b: a){
//            qDebug() << *b;
//        }
//        qDebug() << '\n';
//    }

//    for(auto a: *extendetNames){
//        qDebug() << *a;
//    }
//    qDebug() << extendetNames->size();
//Запросить список имён файлов в директории
//Проверить наличие количества не меньше чем (size*size)/2
//Оставить только необходимое количество
//Рандомно перемешать список
}


QVariant DataProvider::getNamesField(){
    QVariantList lst;
    std::vector<std::vector<QString*>>::iterator it = fieldStr.begin();
    while(it!=fieldStr.end()){
        std::vector<QString*>::iterator it1 = (*it).begin();
        while(it1!=(*it).end()){
            lst.append(**it1);
            it1++;
        }
        it++;
    }
    return lst;
}

