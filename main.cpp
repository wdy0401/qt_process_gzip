#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <iostream>
#include <QFile>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QProcess gzip;
    gzip.start("gzip", QStringList() << "-d" << "-c" << "1.txt.gz");
    if (!gzip.waitForStarted())
        return false;

    gzip.closeWriteChannel();

    if (!gzip.waitForFinished())
        return false;

    QTextStream in(&gzip);
    while (!in.atEnd()) {
        QString line = in.readLine();
        //qDebug()<<"##"<<line<<"##\n";
        std::cout<<"##"<<line.toStdString()<<"##"<<std::endl;
        }
    return 0;
//    return a.exec();
}
