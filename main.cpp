#include <QCoreApplication>
#include <QStringList>
#include <QDebug>
#include <QDate>
#include <QCryptographicHash>
#include <QFile>

int main(int argc, char *argv[])
{

    QCryptographicHash md5(QCryptographicHash::Md5);

    QFile f("C:/Users/Hammer/Desktop/3094");
    char buf[4096];
    int n;

    do {
        if(!f.open(QIODevice::ReadOnly)) {
            qDebug()<<"md5 fopen failed!";
            break;
        }
        while((n = f.read(buf, sizeof(buf))) > 0) {
            md5.addData(buf, n);
        }
        f.close();

        qDebug()<<"md5 = "<<md5.result().toHex().toUpper();

        bool success = f.rename("C:/Users/Hammer/Desktop/3094", "C:/Users/Hammer/Desktop/com.qihoo.appstore_416439.apk");

        qDebug()<< "success = "<<success;

    } while(0);

    return 0;

}
