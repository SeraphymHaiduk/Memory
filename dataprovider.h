#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H
#include <QJsonDocument>
#include <QTime>
#include <map>
#include <utility>
#include <vector>
#include <memory>
class DataProvider
{
public:
    DataProvider();
    void initField();
    void clearSession();

    void addSec();
    QTime getTime();

    void addStep();
    int getSteps();

    void setSize(int n);
    int getSize();

    void setMark(std::pair<int,int>, std::pair<int,int>);
    int getMarkCount();
    bool isMarked(int x,int y);

    bool isRecord();
    QVariant getRecords();

    bool isPairing(std::pair<int,int>,std::pair<int,int>);
    QVariant getNamesField();
private:
    std::vector<QString> names;
    std::vector<std::vector<QString*>> fieldStr;
    std::vector<std::vector<bool>> fieldBool;
    int markCounter;
    std::map<std::pair<uint32_t, uint32_t>,std::pair<uint32_t, uint32_t>> fieldPairs;
    int steps;
    int size;
    QTime time;
    void saveRecord();
};

#endif // DATAPROVIDER_H
