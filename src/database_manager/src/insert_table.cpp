#include "../include/insert_table.h"

#include <iostream>

InsertTable::~InsertTable() {
    sqlite3_close(db);
}

bool InsertTable::init() {
    int rc = sqlite3_open("test.db", &db);

    if (rc) {
        std::cout << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    return true;
}

bool InsertTable::insertTable() {
    char *sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

    //Execute SQL statement
    char *zErrMsg = nullptr;
    int rc = sqlite3_exec(db, sql, InsertTable::callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ) {
        std::cout << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        return false;
    }
    return true;
}

int InsertTable::callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    std::cout << (const char*)data;

    for(i = 0; i<argc; i++) {
        std::string argString = argv[i] ? argv[i] : "NULL";
        std::cout << azColName[i] << " = " <<  argString << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

