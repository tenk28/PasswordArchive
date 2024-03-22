#pragma once

#include "sqlite/sqlite3.h"

class UpdateTable {
public:
    ~UpdateTable();

    bool init();

    bool updateTable();
    // methods

private:
    static int callback(void *data, int argc, char **argv, char **azColName);
private:
    sqlite3 *db;
};
