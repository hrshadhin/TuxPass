#ifndef PASSGENERATE_H
#define PASSGENERATE_H
#include <QString>
class passgenerate
{
public:
    passgenerate();
    QString genPass();
private:
    int randomNum(int range);
};

#endif // PASSGENERATE_H
