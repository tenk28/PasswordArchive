#include "database_manager/database_manager.h"

#include <cstdlib>
#include <iostream>

int main() {
    DatabaseManager database_manager;
    database_manager.init();

    bool rc = database_manager.createTable();

    std::cout << "Beginning of Password Archive" << std::endl;
    return EXIT_SUCCESS;
}
