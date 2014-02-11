#include "endecrypter.h"
#include <QString>
enDecrypter::enDecrypter()
{
}

QString enDecrypter::encrypt(QString str)
{
    QString enString="",keyString="abc1234++";
    int strlen=str.length();
    int l=0,j=0;
    while(l<strlen){
             int len_key=keyString.length();
             enString +=encoder(keyString[j].toLatin1(),str[l].toLatin1());
               j++;
               if(j==len_key){
                  j=0;
                }
               l++;

      }
     return enString;
}

char enDecrypter::encoder(char k,char v){
        int ms = (int)v;
         int ns = (int)k;
         int result = ~(ms^ns);
          char enchar = (char)result;
          return enchar;
 }
