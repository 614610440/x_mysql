#ifndef _X_TABLE_H_
#define _X_TABLE_H_

#include <mysql/mysql.h>
#include <map>
#include <string>

namespace x_mysql
{

class X_Table
{
public:
    X_Table();
    ~X_Table();

    std::string getName();
    int getRows();

private:
    std::string name_;

    MYSQL_RES *result_;
};

}

#endif /* _X_TABLE_H_ */