#include <iostream>
#include <string>

#include "mysql_cpp.h"

Mysql::Mysql() {
    conn = mysql_init(NULL);
    if (conn == NULL) {
        cout << "error occurs " << mysql_error(conn);
        exit(1);
    }
}

Mysql::~Mysql() {
    if (conn != NULL) {
        mysql_close(conn);
    }
}

bool Mysql::initDb(string host, string user, string password, string db_name) {
    conn = mysql_real_connect(conn, host.c_str(), user.c_str(), password.c_str(), db_name.c_str(), 0, NULL, 0);
    if (conn == NULL) {
        cout << "error occurs " << mysql_error(conn);
        exit(1);
    }
    return true;
}

bool Mysql::execSql(string sql) {
    if (mysql_query(conn, sql.c_str())) {
        cout << "query error " << mysql_error(conn) << endl;
        return false;
    } else {
        result = mysql_use_result(conn);
        if (result) {
            int num_fields = mysql_num_fields(result);
            int num_rows = mysql_field_count(conn);
            for (int i = 0; i < num_rows; i++) {
                row = mysql_fetch_row(result);
                if (row == NULL) {
                    break;
                }
                for (int j = 0; j < num_fields; j++) {
                    cout << row[j] << "\t";
                }
                cout << endl;
            }
        }
        mysql_free_result(result);
    }
    return true;
}

int main(int argc, char** argv){
    Mysql db;
    db.initDb("192.168.31.132","root","Dingyingsi1988!","e_coupon");
    db.execSql("select * from e_coupon");
    return 0;
}