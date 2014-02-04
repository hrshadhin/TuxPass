#include "database.h"
#include <QSql>
#include <QString>
#include <QDbug>
database::database()
{
}
/*QString database::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    QDir dir(QApplication::applicationDirPath()+"/db/");
    db.setDatabaseName(dir.filePath("main.sdb"));
    if( !db.open() )
      {
        return false;

      }
      else{
        return true;

    }


      db.close();
}*/

