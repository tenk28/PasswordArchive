#pragma once

#include <sqlite/sqlite3.h>

class DatabaseManager {
public:
    ~DatabaseManager();

    bool init();

    bool createTable();
    // methods

private:
    static int callback(void *data, int argc, char **argv, char **azColName);
private:
    sqlite3 *db;
};
