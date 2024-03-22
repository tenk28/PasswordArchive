#pragma once

#include "sqlite/sqlite3.h"

class SelectTable {
public:
    ~SelectTable();

    bool init();

    bool selectTable();
    // methods

private:
    static int callback(void *data, int argc, char **argv, char **azColName);
private:
    sqlite3 *db;
};
