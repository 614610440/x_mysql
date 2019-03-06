#ifndef _X_MYSQL_H_
#define _X_MYSQL_H_

#include <stdlib.h>
#include "x_table.h"

namespace x_mysql
{

class X_MySQL
{
public:
    X_MySQL();
    ~X_MySQL();
    bool inputPassworld();
    int queryTableByName(std::string name);
    int queryAllTable();

private:
    std::string user_name_;
    std::string user_password_;

    MYSQL *mysql_;

    std::map<std::string, X_Table*> table_map_;
};

}

#endif /* _X_MYSQL_H_ */