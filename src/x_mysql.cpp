#include <iostream>

#include "x_mysql/x_mysql.h"

using namespace x_mysql;
using namespace std;

X_MySQL::X_MySQL()
{
    mysql_ = mysql_init(NULL);
}

X_MySQL::~X_MySQL()
{
    mysql_close(mysql_);
}

bool X_MySQL::inputPassworld()
{
    cout<<"user name: ";
    cin>>user_name_;
    cout<<"password: ";
    system("stty -echo");
    cin>>user_password_;
    system("stty echo");
    // cout<<"\nuser_password: "<<user_password_<<endl;

    try
    {
        mysql_ = mysql_real_connect(mysql_, "localhost", user_name_.c_str(), user_password_.c_str(), NULL, 0, NULL, 0);
        if (!mysql_)
        {
            return false;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}