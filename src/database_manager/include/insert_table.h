#pragma once

#include "sqlite/sqlite3.h"

class InsertTable{
public:
    ~InsertTable();

    bool init();

    bool insertTable();



private:
    static int callback(void *data, int argc, char **argv, char **azColName);
private:
    sqlite3 *db;
};
