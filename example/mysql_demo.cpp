#include <stdio.h>
#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    string pwd;
    printf ("pwd: ");
    system("stty -echo");
    cin>>pwd;
    system("stty echo");

    MYSQL* mysql;
    mysql = mysql_init(NULL);
    // mysql = mysql_real_connect(mysql, "localhost", "root", pwd.c_str(), "test_table", 0, NULL, 0);
    mysql = mysql_real_connect(mysql, "localhost", "root", pwd.c_str(), NULL, 0, NULL, 0);
    if(!mysql)
    {
        printf("connect failed!\n");
    }
    else
    {
        printf("connect success!\n");
    }

    // if (mysql_query(mysql,"INSERT INTO sys.test_table value('2029-5-20','test7')"))
    // {
    //     mysql_commit(mysql);
    //     printf("send error!\n");
    //     return -1;
    // }

    if (mysql_query(mysql,"SELECT * FROM sys.test_table"))
    {
        printf("query error!\n");
        return -1;
    }
    else
    {
        printf("query success!\n");
        MYSQL_RES *result = mysql_store_result(mysql);
        int column = mysql_num_fields(result);
        int row = mysql_num_rows(result);
        for (int i=0; i < mysql_field_count(mysql); i++)
        {
            MYSQL_FIELD *field_name = mysql_fetch_field(result);
            cout << field_name->name << "        ";
        }

        cout<<endl;

        printf ("row: %d\n", row);
        for (int j = 0; j < row; j++)
        {
            MYSQL_ROW result_row = mysql_fetch_row(result);
            for (int k = 0; k < column; k++)
            {
                cout<< result_row[k]<<"  ";
            }
            cout<<endl;
        }
    }

    mysql_close(mysql);
    return 0;
}