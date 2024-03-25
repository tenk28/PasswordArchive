#pragma once

#include <sqlite/sqlite3.h>

class DatabaseManager {
  public:
    ~DatabaseManager();

    bool init();

    bool createTable();
    bool insertTable();
    bool selectTable();
    bool updateTable();

  private:
    static int callback(void* data, int argc, char** argv, char** az_col_name);

  private:
    sqlite3* db;
};
