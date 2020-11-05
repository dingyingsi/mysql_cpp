#ifndef _MYSQL_H_
#define _MYSQL_H_
#include <iostream>
#include <string>
#include <mysql.h>

using namespace std;

class Mysql {

    private:
        MYSQL *conn;
        MYSQL_RES *result;
        MYSQL_ROW row;

    public:
        Mysql();
        ~Mysql();
        bool initDb(string host,string user,string password,string db_name);
        bool execSql(string sql);
};

#endif