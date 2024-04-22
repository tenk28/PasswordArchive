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

bool DatabaseManager::exec(const std::string& sql_query) {

    char* z_err_msg = nullptr;
    int rc          = sqlite3_exec(db, sql_query.c_str(), &DatabaseManager::callback, nullptr, &z_err_msg);

    if (rc != SQLITE_OK) {
        std::cout << "SQL error: " << z_err_msg << std::endl;
        sqlite3_free(z_err_msg);
        return false;
    }
    return true;
}

bool DatabaseManager::createTable() {
    const char* sql = "CREATE TABLE COMPANY("
                      "ID INT PRIMARY KEY     NOT NULL,"
                      "NAME           TEXT    NOT NULL,"
                      "AGE            INT     NOT NULL,"
                      "ADDRESS        CHAR(50),"
                      "SALARY         REAL );";

    return exec(sql);
}

bool DatabaseManager::insertTable() {
    const char* sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
                      "VALUES (1, 'Paul', 32, 'California', 20000.00 ); "
                      "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
                      "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "
                      "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
                      "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );"
                      "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
                      "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";
    return exec(sql);
}

bool DatabaseManager::selectTable() {
    const char* sql = "SELECT * from COMPANY";

    return exec(sql);
}

bool DatabaseManager::updateTable() {
    const char* sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1;";
    return exec(sql);
}

int DatabaseManager::callback(void* data, int argc, char** argv, char** azColName) {
    if (data) {
        std::cout << "Data: " << (const char*)data;
    }

    for (int i = 0; i < argc; i++) {
        std::string argString = argv[i] ? argv[i] : "NULL";
        std::cout << azColName[i] << " = " << argString << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
