#include "SignalFeature.h"

SignalFeature::SignalFeature()
{

}

std::map<QString, double> SignalFeature::getFeaturesWithMap(QVector<double> &value)
{
    double maxv,minv,meanv= value[0];
    double s2v,ev,sumv,peakv=0; //方差，有效值，总值,峰值
    for(int index = 0 ; index < value.size(); index++){
        sumv += value[index];
        maxv = qMax(value[index],maxv);
        minv = qMin(value[index],minv);
        ev += value[index]*value[index];
    }
    ev = sqrt(ev/value.size());
    meanv = sumv/value.size();
    peakv = maxv - minv;
    for(int index = 0 ; index < value.size(); index++){
        s2v += pow((value[index] - meanv),2);
    }
    s2v =s2v/ value.size();

    std::map<QString,double> res;
    res["最大值"] = maxv;
    res["最小值"] = minv;
    res["均值"] = meanv;
    res["峰值"] = peakv;
    res["有效值"] = ev;
//    res["方差"] = s2v;
    return res;
}

QString SignalFeature::getFeaturesWithString(QVector<double> &value)
{
    auto map = getFeaturesWithMap(value);
    QString res = "";
    auto it =map.begin();
    while(it!=map.end()){
       res += it->first+":"+QString::number(it->second) + "\n";
       it++;
    }
    return res;
}

