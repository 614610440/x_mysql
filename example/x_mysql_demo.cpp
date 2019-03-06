#include <iostream>
#include "x_mysql/x_mysql.h"

using namespace std;
using namespace x_mysql;

int main()
{
    X_MySQL mysql;
    bool result = mysql.inputPassworld();
    if (result)
    {
        cout<<"connect success!"<<endl;
    }
    else
    {
        cout<<"connect failed!"<<endl;
    }
    
    return 0;
}