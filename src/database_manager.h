#pragma once

#include <sqlite/sqlite3.h>

#include <string>

class DatabaseManager {
  public:
    ~DatabaseManager();

    bool init();

    bool createTable();
    bool insertTable();
    bool selectTable();
    bool updateTable();

  private:
    bool exec(const std::string& sql_query);
    static int callback(void* data, int argc, char** argv, char** az_col_name);
    sqlite3* db;
};
