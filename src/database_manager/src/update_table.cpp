#include "../include/update_table.h"

#include <iostream>

UpdateTable::~UpdateTable()  {
    sqlite3_close(db);
}

bool UpdateTable::init() {
    int rc = sqlite3_open("test.db", &db);

    if (rc) {
        std::cout << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    return true;
}

bool UpdateTable::updateTable() {
    char *sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
         "SELECT * from COMPANY";

    //Execute SQL statement
    char *zErrMsg = nullptr;
    int rc = sqlite3_exec(db, sql, UpdateTable::callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ) {
        std::cout << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        return false;
    }
    return true;
}

int UpdateTable::callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    std::cout << (const char*)data;

    for(i = 0; i<argc; i++) {
        std::string argString = argv[i] ? argv[i] : "NULL";
        std::cout << azColName[i] << " = " <<  argString << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
