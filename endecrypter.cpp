#include "endecrypter.h"
#include <QString>
enDecrypter::enDecrypter()
{
}

QString enDecrypter::encrypt(QString str)
{
    QString enString="",keyString="8768280e19e10a8ff812a41acd3710b477b620ff3abee939ffed80c254efb726001a61cea43aec962a8016c45f217ee1103e86ce4cbb596104f2efe055a4a60c";
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
