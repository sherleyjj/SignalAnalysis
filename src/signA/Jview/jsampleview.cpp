#include "jsampleview.h"

QT_CHARTS_USE_NAMESPACE

QVector<QVector<QPointF>> convertIntToQPointF(QVector<QVector<int>> data);

JSampleView::JSampleView(QWidget *parent) : QWidget(parent)
{
    this->mec = 1000;
    this->timer=new QTimer();
    initUI();
    init(parent);

}
void JSampleView::init(QWidget *parent){

    for (int index =0;index < 4; index++) {
        (*this->charts)[index] = new QChart();
        (*this->chartview)[index] = new QChartView(this->charts->at(index));
        (*this->lineSeries)[index]=new QLineSeries();
//        this->charts->at(index)->setTitle("通道"+QString().append(index));
        this->charts->at(index)->legend()->hide();

        this->charts->at(index)->addSeries(this->lineSeries->at(index));
        this->charts->at(index)->createDefaultAxes();
        this->charts->at(index)->axisX()->setRange(0,20000);
        this->charts->at(index)->axisY()->setRange(-10,10);
//        this->chartview->at(index)->setChart(this->charts->at(index));
        this->chartview->at(index)->setRenderHint(QPainter::Antialiasing);
    }
    for (int var = 0; var < 20000; ++var) {
        this->lineSeries->at(0)->append(var,var%10);
        this->lineSeries->at(1)->append(var,var%5+5);
        this->lineSeries->at(2)->append(var,sin(var));
        this->lineSeries->at(3)->append(var,cos(var));
    }

//    QChartView *view = new QChartView(this->charts->at(0));
//    QChartView *view2 = new QChartView(this->charts->at(1));
//    QChartView *view3 = new QChartView(this->charts->at(2));
//    QChartView *view4 = new QChartView(this->charts->at(3));
//    view->setRenderHint(QPainter::Antialiasing);//开启抗锯齿
//    view2->setRenderHint(QPainter::Antialiasing);
//    view3->setRenderHint(QPainter::Antialiasing);
//    view4->setRenderHint(QPainter::Antialiasing);
    QGridLayout *layout = new QGridLayout(parent);
    QVBoxLayout *layout1 = new QVBoxLayout();
    QHBoxLayout *layout11 = new QHBoxLayout();
    QHBoxLayout *layout12 = new QHBoxLayout();
    layout11->addWidget(this->chartview->at(0));
    layout11->addWidget(this->chartview->at(1));
    layout12->addWidget(this->chartview->at(2));
    layout12->addWidget(this->chartview->at(3));
    layout->addLayout(layout1,0,0);
    layout1->addLayout(layout11);
    layout1->addLayout(layout12);
}

void JSampleView::initUI(){
    connect(this->timer,&QTimer::timeout,this,&JSampleView::refresh);
}

void JSampleView::setDataViewEcho(JDataViewEcho *data){
    this->dataViewEcho = data;
}

void JSampleView::stopSample(){
    qDebug()<<"停止刷新"<<endl;
    this->timer->stop();
    this->hide();
}
/**
 * todo
 * @brief JSampleView::setNextShowData
 * @param data
 * @param size
 * @param flag
 */
void JSampleView::setNextShowData(QVector<QVector<int>> *data, int size,bool *flag){
    if (*flag != false)
        return;
    QVector<QLineSeries *> series;
    QVector<QVector<QPointF>> points =  convertIntToQPointF(*data);
    for (int var = 0; var < data->size(); ++var) {
        this->lineSeries->at(var)->replace(points[var]);
    }
    data->clear();
}

void JSampleView::setInterval(int mesc){
    this->mec = mesc;
}

void JSampleView::startSampleWithTimer(){
    if(this->timer->isActive()){
        qDebug()<<"定时器已经激活!!"<<endl;
        return;
    }
    qDebug()<<"定时器启动"<<endl;
    this->show();
    this->timer->setInterval(this->mec);
    this->timer->start();
}

void JSampleView::refresh(){
    qDebug()<<"refresh"<<endl;
//    qSetGlobalQHashSeed(this->timer->timerId());
    QVector<QVector<int>> *data =new QVector<QVector<int>>(4);
    for (int i=0;i<4;i++) {
        (*data)[i] = QVector<int>(20000);
        for (int j=0;j<20000;j++) {
            (*data)[i][j] = 5*sin( qrand()%3 *(8*sin(0.000001*3.1412956*j) + qrand()%2)*0.01*j+qrand()%2);
        }
    }
    bool * flag = new bool;
    *flag = false;
    setNextShowData(data,20000,flag);
    delete data;
}

void JSampleView::hide(){

    for (int var = 0; var < 4; ++var) {
        this->lineSeries->at(var)->hide();
    }
}

void JSampleView::show(){
    for (int var = 0; var < 4; ++var) {
        this->lineSeries->at(var)->show();
    }
}
void JSampleView::pause(){
    this->timer->stop();
}
void JSampleView::resume(){
    this->timer->start(this->mec);
}



/* 类外工具  */

QVector<QVector<QPointF>> convertIntToQPointF(QVector<QVector<int>> data){
    QVector<QVector<QPointF>> res;
    res.append(QVector<QPointF>());
    res.append(QVector<QPointF>());
    res.append(QVector<QPointF>());
    res.append(QVector<QPointF>());
    for(int i= 0 ; i < data.size();i++){
        for(int j =0;j<data[i].size();j++){
            res[i].append(QPointF(j,data[i][j]));
        }
    }
    return res;
}
