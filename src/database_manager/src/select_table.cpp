#include "../include/select_table.h"

#include <iostream>

SelectTable::~SelectTable() {
    sqlite3_close(db);
}

bool SelectTable::init() {
    int rc = sqlite3_open("test.db", &db);

    if (rc) {
        std::cout << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    return true;
}

bool SelectTable::selectTable() {
    char *sql = "SELECT * from COMPANY";

    //Execute SQL statement
    char *zErrMsg = nullptr;
    int rc = sqlite3_exec(db, sql, SelectTable::callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ) {
        std::cout << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        return false;
    }
    return true;
}

int SelectTable::callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    std::cout << (const char*)data;

    for(i = 0; i<argc; i++) {
        std::string argString = argv[i] ? argv[i] : "NULL";
        std::cout << azColName[i] << " = " <<  argString << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
