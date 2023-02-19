// ******************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT9L 
// Names: JOSEPH_MASASI | IBRAHIM_ABDULKAREEM | MOHAM_SALEH 
// IDs: 1221301466 | 1211300223 | 1221301877 
// Emails: 1221301466@STUDENT.MMU.EDU.MY| 1211300223@STUDENT.MMU.EDU.MY | 1221301877@STUDENT.MMU.EDU.MY 
// Phones: +601137704976 | +601131830435 | +966567626353 
// *******************

#include "MainHeader.h"

using namespace std;

// Command of the game
void play()
{
    movement move;
    int x, y;
    int CheckLStat = GetLoad();
    if (CheckLStat == 1)
    {
        x = GetAlienX();
        y = GetAlienY();
    }

    else
    {
        x = getDimX() / 2;
        y = getDimY() / 2;
    }

    move.setalienX_(x);
    move.setalienY_(y);
    while(1)
    {

        string dir;
        cout << " Command " ;
        cin >> dir ;

        if (dir == "up")
        {
            move.move_up();
            move.zommove();
        }

        if (dir == "down")
        {
            move.move_down();
            move.zommove();
        }

        if (dir == "left")
        {
            move.move_left();
            move.zommove();
        }

        if (dir == "right")
        {
            move.move_right();
            move.zommove();
        }

        if (dir == "arrow")
        {
            cout << "Invalid input!";
            int arrowY, arrowX;
            string ARdir;
            cin >> arrowX >> arrowY >> ARdir;
            move.move_arrow( arrowX,  arrowY,  ARdir);
        }

        if (dir == "help")
        {
            help();
            Pause();
            display(); 
            int no = getZomB(); 
            move.alienturndisplay(); 
            zomdisplay(no);
        }

        if (dir == "save")
        {
            fileExist();
        }

        if (dir == "load")
        {
            loadmap();
            Board();
        }

        if (dir == "quit")
        {
            exit(0);
        }

    }
}
