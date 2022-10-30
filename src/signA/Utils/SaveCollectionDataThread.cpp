#include "SaveCollectionDataThread.h"

void SaveCollectionDataThread::run(){


    saveThread->theApp->m_bisSave = true;
    // 初始化采集队列
    std:map<QString, ThreadSafeQueue<double>>::iterator iter = saveThread->theApp->m_mpcolllectioinDataQueue.begin();

    while (iter != saveThread->theApp->m_mpcolllectioinDataQueue.end()){
        ConsumerThread *everyConsumer  = new ConsumerThread(saveThread,iter->first);
        threadVector.push_back(everyConsumer);
        iter++;
    }
    qDebug()<<"threadsize------------------------------------------------------"<<threadVector.size()<<endl;;
    for (int i = 0; i < threadVector.size();i++){
        threadVector[i]->start();
    }
    for (int i = 0; i < threadVector.size();i++){
        threadVector[i]->wait();
    }
    //所有线程都完事了，执行保存操作
    saveThread->theApp->m_bisSave = false;

}

void ConsumerThread::run(){

    QString fileName = QString("D:\\QtCollectionData\\%1.txt").arg(this->signalCode);
    QFile f(fileName);

    if(!f.open(QIODevice::WriteOnly))
    {
       qDebug()<<"fileed"<<endl;
    }
    QDataStream outputStream(&f);
    outputStream.setVersion(QDataStream::Qt_5_9);

    ThreadSafeQueue<double> saveData;

    while (consumer->theApp->m_icollectState){
        if (consumer->theApp->m_icollectState == 2){
             //暂停状态就卡在这
            msleep(10);
            continue;
        }
        while (consumer->theApp->m_mpcolllectioinDataQueue[signalCode].size() > 0){
            //qDebug()<<"\n队列长度%d\n", m_mpcolllectioinDataQueue[signalCode].size()<<endl;
            saveData.push(*(consumer->theApp->m_mpcolllectioinDataQueue[signalCode].wait_and_pop()));
            if (saveData.size() == consumer->theApp->m_icollectSignalsStoreCount){
                consumer->theApp->m_signalController.SaveCollectionData2Binary(outputStream,saveData);
        }
      }
    }
        //点完停止采集之后，还有数据需要保存！！！
    QVector<double> restVector;
    while (consumer->theApp->m_mpcolllectioinDataQueue[signalCode].size() > 0){
        if(restVector.size()==20000){
            outputStream << restVector;
            QVector<double>().swap(restVector);
        }
        saveData.push(*(consumer->theApp->m_mpcolllectioinDataQueue[signalCode].wait_and_pop()));

        std::shared_ptr<double> signal = saveData.wait_and_pop();
        restVector.append(*signal);

    }

    outputStream<<restVector;

    f.close();

}


//--------------------------------------------------保存成一个二维vector------------------

//QString fileName = QString("D:\\QtCollectionData\\%1.txt").arg(this->signalCode);
//QFile f(fileName);

//if(!f.open(QIODevice::WriteOnly))
//{
//   qDebug()<<"fileed"<<endl;
//}
//QDataStream outputStream(&f);
//outputStream.setVersion(QDataStream::Qt_5_9);

//QVector<QVector<double>> sumSignal;

//ThreadSafeQueue<double> saveData;

//while (consumer->theApp->m_icollectState){
//    if (consumer->theApp->m_icollectState == 2){
//         //暂停状态就卡在这
//        msleep(10);
//        continue;
//    }
//    while (consumer->theApp->m_mpcolllectioinDataQueue[signalCode].size() > 0){
//        //qDebug()<<"\n队列长度%d\n", m_mpcolllectioinDataQueue[signalCode].size()<<endl;
//        saveData.push(*(consumer->theApp->m_mpcolllectioinDataQueue[signalCode].wait_and_pop()));
//        if (saveData.size() == consumer->theApp->m_icollectSignalsStoreCount){
//            consumer->theApp->m_signalController.SaveCollectionData2Vector(sumSignal,saveData);
//    }
//  }
//}
//    //点完停止采集之后，还有数据需要保存！！！
//QVector<double> restVector;     //保存剩余的数据

//while (consumer->theApp->m_mpcolllectioinDataQueue[signalCode].size() > 0){
//    if(restVector.size()==20000){
//        sumSignal.append(restVector);
//        QVector<double>().swap(restVector);
//    }
//    saveData.push(*(consumer->theApp->m_mpcolllectioinDataQueue[signalCode].wait_and_pop()));
//    shared_ptr<double> signal = saveData.wait_and_pop();
//    restVector.append(*signal);

//}
//sumSignal.append(restVector);

//outputStream<<sumSignal;




















































//void SaveCollectionDataThread::OpenThread2SaveCollectionData(){

//    thread t(&SaveCollectionDataThread::SaveSumCollectionData, this);
//    t.detach();
//    t.join();
//}

//void SaveCollectionDataThread::SaveSumCollectionData(){
//        saveThread->theApp->m_bisSave = true;
//        map<QString, ThreadSafeQueue<double>>::iterator iter = saveThread->theApp->m_mpcolllectioinDataQueue.begin();
//        vector<thread> threadVector;//size = 4
//        while (iter != saveThread->theApp->m_mpcolllectioinDataQueue.end()){
//            threadVector.push_back(thread(&SaveCollectionDataThread::SaveCollectionData, this, iter->first));
//            iter++;
//        }
//        qDebug()<<"threadsize"<<threadVector.size()<<endl;;
//        for (int i = 0; i < threadVector.size();i++){
//            threadVector[i].join();
//        }
//        //所有线程都完事了，执行保存操作
//        saveThread->theApp->m_bisSave = false;
//}

//void SaveCollectionDataThread::SaveCollectionData(QString signalCode){

//       bool exist;
//       QString fileName = QString("D:\\QtCollectionData\\%1.txt").arg(signalCode);
//       QByteArray data ;
//       data.resize(10);
//       memset(data.data(),0x00,data.size());

//       QDir *folder = new QDir;
//       exist = folder->exists("D:\\QtCollectionData");

//       QFile f(fileName);

//       //f.write(data);
//       f.write("你好");
//       f.close();

//}
