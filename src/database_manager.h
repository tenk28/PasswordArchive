#pragma once

#include "sqlite/sqlite3.h"

class DatabaseManager {
public:
    ~DatabaseManager();

    bool init();

    bool createTable();
    bool insertTable();
    bool selectTable();
    bool updateTable();
    // methods

private:
    static int callback(void *data, int argc, char **argv, char **azColName);
private:
    sqlite3 *db;
};
