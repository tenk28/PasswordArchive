#include "database_manager.h"

#include <cstdlib>
#include <iostream>

int main() {
    DatabaseManager create_table{};
    create_table.init();

    //bool rc = create_table.createTable();

    DatabaseManager insert_table{};
    insert_table.init();

    //bool rc = insert_table.insertTable();

    DatabaseManager update_table{};
    update_table.init();

    //bool rc = update_table.updateTable();

    DatabaseManager select_table{};
    select_table.init();

    //bool rc = select_table.selectTable();

    std::cout << "Beginning of Password Archive" << std::endl;
    return EXIT_SUCCESS;
}
