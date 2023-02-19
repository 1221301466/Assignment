// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT9L 
// Names: JOSEPH_MASASI | IBRAHIM_ABDULKAREEM | MOHAM_SALEH 
// IDs: 1221301466 | 1211300223 | 1221301877 
// Emails: 1221301466@STUDENT.MMU.EDU.MY| 1211300223@STUDENT.MMU.EDU.MY | 1221301877@STUDENT.MMU.EDU.MY 
// Phones: +601137704976 | +601131830435 | +966567626353 
// *********************************************************

#include "MainHeader.h"

using namespace std;

    int ClearScreen() // clear screen
    {
        #if defined(_WIN32)
            return std::system("cls");
        #elif defined(_linux) || defined(__APPLE_)
            return std::system("clear");
        #endif
    }

    int Pause() // Pause the game
    {
        #if defined(_WIN32)
            return std::system("pause");
        #elif defined(_linux) || defined(__APPLE_)
            return std::system(R"(read -p "Press any key to continue . . . " dummy)");
        #endif
    }
    
// randomise object for gameboard
char randomObject(char j) 
{
    int N = rand() % 11 + 1;
    switch (N)             
    {
    case 1:
        j = '^'; 
        break;

    case 2:
        j = 'v'; 
        break;

    case 3:
        j = '<'; 
        break;

    case 4:
        j = '>'; 
        break;

    case 5:
        j = 'h'; 
        break;

    case 6:
        j = 'o';
        break;

    case 7:
        j = 'r';
        break;

    case 8:
        j = ' ';
        break;

    case 9:
        j = ' ';
        break;

    case 10:
        j = ' ';
        break;

    case 11:
        j = ' ';
        break;
    }
    return j;
}

char refreshObj(char x) 
{
    int Num = rand() % 6 + 1;
    switch (Num)             
    {
    case 1:
        x = 'h'; 
        break;

    case 2:
        x = 'o';
        break;

    case 3:
        x = ' ';
        break;

    case 4:
        x = ' ';
        break;

    case 5:
        x = ' ';
        break;

    case 6:
        x = ' ';
        break;
    }
    return x;
}

void rockupd(int y, int x)
{
    char ranobj, obj;
    if(map_[y][x] == 'r')
    {
        ranobj = randomObject(obj);
        map_[y][x] = ranobj;
    }
}

void ranupd()
{
    char ranobj, x;
    int dimY = getDimY();
    int dimX = getDimX();
    for (int i = 0; i < dimY; ++i)
    {
        for (int j = 0; j < dimX; ++j)
        {
            if(map_[i][j] == '.')
            {
                ranobj = randomObject(x);
                map_[i][j] = ranobj;
            }
        }
    }
}
