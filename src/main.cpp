#include "database_manager/include/create_table.h"
#include "database_manager/include/insert_table.h"
#include "database_manager/include/update_table.h"
#include "database_manager/include/select_table.h"

#include <cstdlib>
#include <iostream>

int main() {
    CreateTable create_table;
    create_table.init();

    //bool rc = create_table.createTable();

    InsertTable insert_table;
    insert_table.init();

    //bool rc = insert_table.insertTable();

    UpdateTable update_table;
    update_table.init();

    //bool rc = update_table.updateTable();

    SelectTable select_table;
    select_table.init();

    //bool rc = select_table.selectTable();

    std::cout << "Beginning of Password Archive" << std::endl;
    return EXIT_SUCCESS;
}
