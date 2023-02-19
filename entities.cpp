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

void Enemy::zombiegen(int no)
{
    int b = no;

    for (int i = 0; i < b; i++)
    {
        int Rhealth = rand() % 2 + 1;
        int Rattack = rand() % 2 + 1;
        int Rrange = rand() % 4 + 1;
        int ZHp = 100 + (Rhealth * 50);
        int ZAtk = 5 + (Rattack  * 5);
        int ZRng = Rrange ;
        if (GetLoad() == 1)
        {
            ZHpVec.push_back(ZB_atrr[i][0]);
            ZAtkVec.push_back(ZB_atrr[i][1]);
            ZRngVec.push_back(ZB_atrr[i][2]);
            cout << '\n'
                 << "  Zombie " << i + 1 << " | Health point :" << ZB_atrr[i][0] << "| Attack :" << ZB_atrr[i][1] << "| Range :" << ZB_atrr[i][2];
        }
        else
        {
            ZHpVec.push_back(ZHp);
            ZAtkVec.push_back(ZAtk);
            ZRngVec.push_back(ZRng);
            cout << '\n'
                 << "  Zombie " << i + 1 << " | Health point :" << ZHp << "| Attack :" << ZAtk << "| Range :" << ZRng;
        }
    }
    cout << endl;
}
