// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT9L 
// Names: JOSEPH_MASASI | IBRAHIM_ABDULKAREEM | MOHAM_SALEH 
// IDs: 1221301466 | 1211300223 | 1221301877 
// Emails: 1221301466@STUDENT.MMU.EDU.MY| 1211300223@STUDENT.MMU.EDU.MY | 1221301877@STUDENT.MMU.EDU.MY 
// Phones: +601137704976 | +601131830435 | +966567626353 
// *********************************************************

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
#include "class.hpp"
#include "helper.h"
#include "zombie.hpp"

void display();
char defaultsettings(int rows, int columns, int Zcount);
void changesettings(int &rows, int &columns, int &Zcount);
void intro();

Mars::Mars(int dimX, int dimY, int Zcount)
{
    init(dimX, dimY);
    for(int i = 0; i < Zcount; i++){
        Zombie zombie;
        zombie.land(*this);
    }
}


void Mars::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {'>', '<', '^', 'v', ' ', ' ', 'O', 'H', 'A', '#', ' ', ' ', ' ', ' ', ' '};
    int noOfObjects = 15; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }
    srand(time(NULL));
    // put random characters into the vector array
    int middleY = dimY_ / 2;
    int middleX = dimX_ / 2;

    for (int i = 0; i < dimY_; ++i)
    {
        
        for (int j = 0; j < dimX_; ++j)
        {
             if (i == middleY && j == middleX) 
             {
                map_[i][j] = ' ';
             }
            else
            {
                int objNo = rand() % noOfObjects;
                map_[i][j] = objects[objNo];
            }
            
        }

    }
}


void Mars::setObject(int x, int y, char ch)
{
    map_[dimY_ - y][x - 1] = ch;
}
bool Mars::isInsideMap(int dimX, int dimY)
{
    return (dimX >= 0 && dimX < dimX_) && (dimY >= 0 && dimY < dimY_);
}

void fix()
{
    srand(time(NULL)); // use this for fixed map during testing
     
}

void Mars::display() 
{
    
    system("cls");
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

int Mars::getDimX() const {
  return dimX_;
}
int Mars::getDimY() const {
  return dimY_;
}
char Mars::getObject(int x, int y) const
{
    return map_[dimY_ - y][x - 1];
}

int main()
{ 
   int rows = 5, columns = 9, Zcount = 1;
    char input;
    

    Mars obj;
    
    input = defaultsettings(rows, columns, Zcount);
    
    switch (input)
    {
        case 'N':
        changesettings(rows, columns, Zcount);
        // intro();
        obj.init(columns, rows);
        obj.display();
        system("pause");
        break;

        case 'Y':
        // intro();
        obj.display();
        system("pause");
        break;

        default:
        std::cout << "Invalid choice!" << std::endl;
        system("pause");
        system("cls");
        return main();
    }

}

