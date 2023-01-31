#include <iostream>
using namespace std;

  int column(int columns)
    {
     cout << "Enter number of columns => ";
     cin >> columns;
     int n = (columns % 2);
    if(n == 0)
    {
        cout << "Invalid" << endl;
        cout << "Input must be odd number";
        cout << endl;
        return column(columns);
    } 
    return columns;
    }