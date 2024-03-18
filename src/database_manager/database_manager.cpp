#include "database_manager.h"

#include <iostream>

DatabaseManager::~DatabaseManager() {
    sqlite3_close(db);
}

bool DatabaseManager::init() {
    int rc = sqlite3_open("test.db", &db);

    if (rc) {
        std::cout << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    return true;
}

bool DatabaseManager::createTable() {
    char *sql = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

    //Execute SQL statement
    char *zErrMsg = nullptr;
    int rc = sqlite3_exec(db, sql, DatabaseManager::callback, NULL, &zErrMsg);

    if( rc != SQLITE_OK ) {
        std::cout << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        return false;
    }
    return true;
}

int DatabaseManager::callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    std::cout << (const char*)data;

    for(i = 0; i<argc; i++) {
        std::string argString = argv[i] ? argv[i] : "NULL";
        std::cout << azColName[i] << " = " <<  argString << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
