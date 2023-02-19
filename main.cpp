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
#include <iostream>

using namespace std;

Enemy zombie;
movement alien;

vector<vector<char>> map_; // Gameboard vector
vector<int> ZomY_;
vector<int> ZomX_;
int dimX_ = 9, dimY_ = 3, zomB_ = 1;   // variables for the initial gameboard

char ranobj, x;

void emptymap(int dX, int dY)
{
    map_.resize(dY); // create empty rows
    for (int i = 0; i < dY; ++i)
    {
        map_[i].resize(dX); // resize each row
    }
}

void emptyZomvec()
{
    ZomY_.clear();
    ZomX_.clear();
}

void init(int dimX, int dimY, int zomb) 
{
    dimX_ = dimX;
    dimY_ = dimY;
    zomB_ = zomb;

    char zomBie[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; 
    int noOfObjects = 10;  // number of objects in the objects array

    // create dynamic 2D array using vector
    emptymap(dimX_, dimY_);
    emptyZomvec();

    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
			ranobj = randomObject(x);
            map_[i][j] = ranobj;
        }
    }

    int Getstatus = GetLoad();
    if (Getstatus == 0)
    {
        // put random zombies into the vector array 
        for (int i = 0; i < zomB_; ++i)
        {
            int randY = rand() % dimY_;
            int randX = rand() % dimX_;
            map_[randY][randX] = zomBie[i];
            ZomY_.push_back(randY);
            ZomX_.push_back(randX);
        }

        // Alien in the middle of the gameboard
        int y = dimY_ / 2;
        int x = dimX_ / 2;
        char Alien[] = "A";
        map_[y][x] = Alien[0];
    }
}

void display() // 
{
    ClearScreen();
    cout << " ****************************** " << endl;
    cout << " *    .:'Alien vs Zombie':.   * " << endl;
    cout << " ****************************** " << endl;

    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << " ";
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
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    // display column number
    cout << " ";
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

int setZomY(int num, int newnum)
{
    ZomY_[num] = newnum;
    return ZomY_[num];
}

int setZomX(int num, int newnum)
{
    ZomX_[num] = newnum;
    return ZomX_[num];
}
// set the number of column
int setDimX(int x)
{
    dimX_ = x;
    return dimX_;
}
// set the number of row
int setDimY(int y)
{
    dimY_ = y;
    return dimY_;
}
// set the object into map_
vector<vector<char>> setmap(int y, int x, char obj)
{
    map_[y][x] = obj;
    return map_;
}
// set the number of zombies
int setZomB(int z) 
{
    zomB_ = z;
    return zomB_;
}
// get zombie column
int getZomY(int num)
{
    return ZomY_[num];
}
int getZomX(int num)
{
    return ZomX_[num];
}
// get the number of column
int getDimX() 
{
    return dimX_;
}
// get the number of row
int getDimY() 
{
    return dimY_;
}
// get the number of zombies
int getZomB()   
{
    return zomB_;
}
// get object from the map_
char getObject(int y, int x) 
{
    return map_[y][x];
}

// game setting screen
void changesetting() 
{
    ClearScreen();
    int rows, columns, Zcount;   
    cout << endl; 
    
    cout << "Game Settings         " << endl;
    cout << "                      " << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-* " << endl;
    cout << "                      " << endl;
    cout << " Rows => ";
    cin >> rows;
    cout << endl;
    cout << "Columns => ";
    cin >> columns;
    cout << endl;
    cout << "Zombies => ";
    cin >> Zcount;

    system("cls");

    cout << endl;
    cout << "NEW Game Settings " << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- " << endl;
    cout << "                      " << endl;
    cout << "No of Board rows    : " << rows << endl;
    cout << "No of Board columns : " << columns << endl;
    cout << "No of Zombies       : " << Zcount << endl;
    cout << endl;

    if (rows % 2 == 0 || columns % 2 == 0) 
    {
        cout << "Rows and Columns must be odd numbers.\n\n";
        Pause();
        ClearScreen();
    }

    else
    {
        if (Zcount < 1 || Zcount > 9)
        {
            cout << "Number of Zombies must not exceed 9 or less than 1 " << endl;
            Pause();
            ClearScreen();
        }

        else
        {  
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
            cout << "Congrats the settings are updated..." << endl;
            system("pause");
            system("cls");
            setDimX(rows);
            setDimY(columns);
            setZomB(Zcount); 
            init(rows, columns, Zcount); 
            display(); 
            int no = zomB_; 
            alien.alienturndisplay();   
            zombie.zombiegen(no); 
			play();
        }
    }
}

// initial gameboard initialization
void Board()
{
    ClearScreen();
    // srand(1);
    display();
    int no = zomB_; 
    alien.alienturndisplay();   
	zombie.zombiegen(no); 
	play();
}

void zomdisplay(int no)
{
    int b = no;

    for (int i = 0; i < b; i++)
    {
        cout << '\n' << "  Zombie " << i + 1 << " | Health point :" << zombie.ZHpVec[i] << "| Attack  " << zombie.ZAtkVec[i] << "| Range " << zombie.ZRngVec[i];
    }
    cout << endl;
}

void zomturndisplay(int no, int num)
{
    int b = no;
    if(num == 0)
    {
        cout << '\n' << "> Zombie " << num + 1 << " | Health point :" << zombie.ZHpVec[num] << "| Attack  " << zombie.ZAtkVec[num] << "| Range " << zombie.ZRngVec[num];
        for (int i = num + 1; i < no; i++)
        {
            if(num!=i)
            {        
                cout << '\n' << "  Zombie " << i + 1 << " | Health point :" << zombie.ZHpVec[i] << "| Attack  " << zombie.ZAtkVec[i] << "| Range " << zombie.ZRngVec[i];
            }    
        }
    }
    else if(num>0 && num<no)
    {
        for (int i = 0; i < num; i++)
        {     
            cout << '\n' << "  Zombie " << i + 1 << " | Health point :" << zombie.ZHpVec[i] << "| Attack  " << zombie.ZAtkVec[i] << "| Range " << zombie.ZRngVec[i];
        }
        cout << '\n' << "> Zombie " << num + 1 << " | Health point :" << zombie.ZHpVec[num] << "| Attack  " << zombie.ZAtkVec[num] << "| Range " << zombie.ZRngVec[num];
        for (int i = num + 1; i < no; i++)
        {
            if(num!=i)
            {        
                cout << '\n' << "  Zombie " << i + 1 << " | Health point :" << zombie.ZHpVec[i] << "| Attack  " << zombie.ZAtkVec[i] << "| Range " << zombie.ZRngVec[i];
            }    
        }
    }
    else
    {
        for (int i = 0; i < num; i++)
        {        
            cout << '\n' << "  Zombie " << i + 1 << " | Health point :" << zombie.ZHpVec[i] << "| Attack  " << zombie.ZAtkVec[i] << "| Range " << zombie.ZRngVec[i];
        }
        cout << '\n' << "> Zombie " << num + 1 << " | Health point :" << zombie.ZHpVec[num] << "| Attack  " << zombie.ZAtkVec[num] << "| Range " << zombie.ZRngVec[num];
    }
    cout << endl;
}

void setZomHP(int num, int Zhp)
{
    zombie.ZHpVec.at(num) = Zhp;
}

int getZHP(int num)
{
    return zombie.ZHpVec[num];
}

int getZATK(int num)
{
    return zombie.ZAtkVec[num];
}

int getZRNG(int num)
{
    return zombie.ZRngVec[num];
}

int *getZomHP(int num)
{
    int numZ = num;
    static int Zhp[9];

    for (int i = 0; i < numZ; i++)
    {
        Zhp[i] = zombie.ZHpVec[i];
    }
    return Zhp;
}

int *getZomAtk(int numZom)
{
    int Zonum = numZom;
    static int Zatk[9];

    for (int i = 0; i < numZom; i++)
    {
        Zatk[i] = zombie.ZAtkVec[i];
    }
    return Zatk;
}

int *getZomRge(int numofZ)
{
    int Znumber = numofZ;
    static int Zrge[9];

    for (int i = 0; i < Znumber; i++)
    {
        Zrge[i] = zombie.ZRngVec[i];
    }
    return Zrge;
}

// Main function
int main() 
{
	init(dimX_, dimY_, zomB_);
	menu();
}


