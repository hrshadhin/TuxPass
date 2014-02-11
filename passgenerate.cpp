#include "passgenerate.h"
#include <QString>
#include <stdlib.h>

passgenerate::passgenerate()
{
}
QString passgenerate::genPass(){
    QString theLetters = "abcdefghijklmnopqrstuvwxyz";
    QString theSymbols = "?+-*/;:{]}[~!@#$%^&()";
    QString StrongPasswordArray ="";

    int capitalise,i;
    srand (time(NULL));
    for ( i = 0; i < 20; i++) {
        capitalise = randomNum(6);
        if (capitalise == 0) {
            StrongPasswordArray += theLetters[randomNum(26)].toUpper();
        }
        else {
            StrongPasswordArray += theLetters[randomNum(26)];
        }
    }
    // adding symbols in password
    int numberOfSym = randomNum(5);
    int positionForSym, theSym;
    for (i = 0; i < numberOfSym; i++) {
        positionForSym = randomNum(20);
        theSym = randomNum(21);
         StrongPasswordArray[positionForSym] = theSymbols[theSym];
    }
    //adding numbers in password
    int numberOfDigits = randomNum(5) +1;
    int positionForNumeric, theNumber;
    for (i = 0; i < numberOfDigits; i++) {
        positionForNumeric = randomNum(20);
        theNumber = randomNum(9);
        theNumber +=48;
         StrongPasswordArray[positionForNumeric] = (char)theNumber;
    }
    return StrongPasswordArray;

}
//random number generate function
int passgenerate::randomNum(int range){

    return ( rand() % range );
}


