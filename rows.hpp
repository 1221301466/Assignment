#include <iostream>
using namespace std;

int row(int rows)
    {
     cout << "Enter number of rows => ";
     cin >> rows;
     int n = (rows % 2);
    if(n == 0)
    {
        cout << "Invalid" << endl;
        cout << "Input must be odd number";
        cout << endl;
        return row(rows);
    } 
    return rows;
    }
