#include "database_manager.h"

#include <cstdlib>
#include <iostream>

int main() {
    DatabaseManager database_manager;
    database_manager.init();

    bool rc;
    rc = database_manager.createTable();
    rc = database_manager.insertTable();
    rc = database_manager.updateTable();
    rc = database_manager.selectTable();

    std::cout << "Beginning of Password Archive" << std::endl;
    return EXIT_SUCCESS;
}
