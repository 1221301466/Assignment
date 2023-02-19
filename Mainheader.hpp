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
#include <string>
#include <vector>
#include <cmath>
#include <cfenv>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()

#ifndef MAINHEADER_H
#define MAINHEADER_H

using namespace std;
// Global--------------------------------------------------------------------------------------- 

    
    int ClearScreen(); // (from tutorial)
    int Pause(); // (from tutorial)
    

    extern vector<vector<char>> map_;
    extern vector<int> ZomY_;
    extern vector<int> ZomX_;
    extern vector<vector<int>> ZB_atrr;
    void emptymap(int dX, int dY);
    void emptyZomvec(int Zom);
    void menu();
    void controls(); 
    void help(); 
    void gameover(); 
    void playgame(); 
    char randomObject(char j);
    char refreshObj(char x);
    void ranupd();
    void rockupd(int y, int x);
    void changesetting(); 
    void Board(); 
    void zomdisplay(int no);
    void zomturndisplay(int no, int num);
    void play();


        void init(int dimX, int dimY, int zomb);  
        void display(); 
        int setDimX(int x); 
        int setDimY(int y); 
        int setZomB(int z); 
        int setZomY(int num, int newnum);
        int setZomX(int num, int newnum);
        void setZomHP(int num, int Zhp);

        std::vector<std::vector<char>> setmap(int y, int x, char obj);

        int getDimX();   
        int getDimY();   
        int getZomB();   
        int getZomY(int num);
        int getZomX(int num);
        int getZHP(int num);
        int getZATK(int num);
        int getZRNG(int num);
        char getObject(int dimX, int dimY);   

    int *getZomHP(int num);
    int *getZomAtk(int numZom);
    int *getZomRge(int numofZ);
    int fileExist();
    void loadmap();
    int GetLoad();
    int GetAlienX();
    int GetAlienY();
    int GetAlienHP();
    int GetAlienATK();
    void saveHP(int hp);
    void saveATK(int atk);


class Enemy 
{
    public:
        vector<int> ZHpVec;
        vector<int> ZAtkVec;     
        vector<int> ZRngVec;
        void zombiegen(int no);

};

class movement : public Enemy
{
    public:
        int alhp_ = 100;
        int alatk_ = 0;
        int AlienX_;
        int AlienY_;
        vector<int> zomXVec;
        vector<int> zomYVec;

        void Alienturn();
        void Zombieturn(int num);
        void alienturndisplay();
        void aliendisplay();
        int getalhp_();
        int setplusalhp_(int hp);
        int setminusalhp_(int hp);
        int getalatk_();
        int setalatk_(int atk);
        int resetatk_();
        void podatk(int podY, int podX);
        void subalatk(int num);
        void Alienattack(char obj);

        int setalienX_(int x);
        int setalienY_(int y);
        int getalienX_() const;
        int getalienY_() const;

        void move_up();
        void move_down();
        void move_left();
        void move_right();
        void move_arrow(int y, int x, string z);
        void zommove();
};



#endif
