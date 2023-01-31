#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
#include "class.hpp"

void display(int X, int Y);
char defaultsettings(int rows, int columns, int Zcount);
void changesettings(int &rows, int &columns, int &Zcount);
void intro();

Mars::Mars(int dimX, int dimY)
{
    init(dimX, dimY);
    
}

void Mars::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {'>', '<', '^', 'v', ' ', ' ', 'O', 'H', 'A', '#'};
    int noOfObjects = 10; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}




void fix()
{
    srand(time(NULL)); // use this for fixed map during testing
    // srand(time(NULL)); // try this for random map
     
}

void Mars::display(int X, int Y) 
{
    intro();
    system("cls");
    dimX_ = X;
    dimY_ = Y;
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (dimY_ - i);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}



int main()
{
    int rows = 5, columns = 9, Zcount = 1;
    char input;
    int X, Y;

    Mars obj;

    input = defaultsettings(rows, columns, Zcount);
    
    switch (input)
    {
        case 'N':
        changesettings(rows, columns, Zcount);
        X = columns;
        Y = rows;
        obj.display(X, Y);
        system("pause");
        break;

        case 'Y':
        X = columns;
        Y = rows;
        obj.display(X, Y);
        system("pause");
        break;

        default:
        std::cout << "Invalid choice!" << std::endl;
        system("pause");
        system("cls");
        return main();
    }

}

