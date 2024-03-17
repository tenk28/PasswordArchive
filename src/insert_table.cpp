#include <iostream>
#include "sqlite/sqlite3.h"

static int callback(void *data, int argc, char **argv, char **azColName){
    int i;

    std::cout << (const char*)data;

    for(i = 0; i<argc; i++) {
        std::string argString = argv[i] ? argv[i] : "NULL";
        std::cout << azColName[i] << " = " <<  argString << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *zErrMsg = nullptr;
    int rc;
    char *sql;
    const char* data = "Callback function called";

    // Open database
    rc = sqlite3_open("test.db", &db);

    if( rc ) {
        std::cout << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return(0);
    } else {
        std::cout << "Opened database successfully" << std::endl;
    }

    // Create merged SQL statement
    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

    // Execute SQL statement
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        std::cout << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Operation done successfully" << std::endl;
    }
    sqlite3_close(db);
    return 0;
}
