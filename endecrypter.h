#ifndef ENDECRYPTER_H
#define ENDECRYPTER_H
#include <QString>
class enDecrypter
{
public:
    enDecrypter();
    QString encrypt(QString str);

private:
    char encoder(char k,char v);
};

#endif // ENDECRYPTER_H
