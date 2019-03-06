#include "x_mysql/x_table.h"

using namespace x_mysql;

X_Table::X_Table()
{

}

X_Table::~X_Table()
{

}

std::string X_Table::getName()
{
    return name_;
}

int X_Table::getRows()
{
    return mysql_num_rows(result_);
}