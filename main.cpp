#include <QCoreApplication>
#include <QProcess>
#include <QTextStream>
#include <iostream>
#include <QFile>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QProcess gzip;
    gzip.start("gzip", QStringList() << "-d" << "-c" << argv[1]);
    if (!gzip.waitForStarted())//正常启动and emit started singal时不返回 不正常时候直接返回错误
    {
        return false;
    }
    gzip.closeWriteChannel();//不close读不出数据

    if (!gzip.waitForFinished())//正常结束and emit finished signal时不返回 不正常时候直接返回错误
    {
        return false;
    }
    QTextStream in(&gzip);
    while (!in.atEnd())
    {
        QString line = in.readLine();//已经去掉末尾的空白
        std::cout<<line.toStdString()<<std::endl;
    }
    return 0;
}
