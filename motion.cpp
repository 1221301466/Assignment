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

// Shows Alien stats
void movement::alienturndisplay()
{
    if (GetLoad() == 1)
    {
        alhp_ = GetAlienHP();
        alatk_ = GetAlienATK();
    }

    cout << "> Alien    ";
    cout << "| Health point  :" << alhp_ << "|   Attack :" << alatk_;
    saveHP(alhp_);
    saveATK(alatk_);
}

void movement::aliendisplay()
{
    if (GetLoad() == 1)
    {
        alhp_ = GetAlienHP();
        alatk_ = GetAlienATK();
    }

    cout << "  Alien    ";
    cout << "| Health point  :" << alhp_ << "| Attack   :" << alatk_;
    saveHP(alhp_);
    saveATK(alatk_);
}

int movement::getalhp_()
    {
        return alhp_;
    }

int movement::setplusalhp_(int hp)
    {
        if (alhp_ < 100)
        {
            alhp_ = alhp_ + hp;
        }
        return alhp_;
    }

int movement::setminusalhp_(int hp)
    {
        alhp_ = alhp_ - hp;
        if (alhp_ <= 0)
        {
            alhp_ = 0;
        }
        return alhp_;
    }

int movement::resetatk_()
    {
        return alatk_ = 0;
    }  

int movement::getalatk_()
    {
        return alatk_;
    }

int movement::setalatk_(int atk)
    {
        alatk_ = alatk_ + atk;
        return alatk_;
    }

int movement::setalienX_(int x)
    {
        return AlienX_ = x;
    }

int movement::setalienY_(int y)
    {
        return AlienY_ = y;
    }

int movement::getalienX_() const
    {
        return AlienX_;
    }

int movement::getalienY_() const
    {
        return AlienY_;
    }

//*****************************************


void movement::Alienturn()  //alien 
{
    int no = getZomB();
    alienturndisplay(); 
    zomdisplay(no);
}

void movement::Zombieturn(int num) //zombie
{
    int no = getZomB();
    aliendisplay(); 
    zomdisplay(no);
}

//******************************************

void movement::move_up()  //alien movment
    {

        int y = getDimY() - 1; 
        char trail[] = {'.'};
        int AlX = AlienX_;
        for(int i = AlienY_; i > 0; --i) 
        {
            int temp = i;
            setmap(temp, AlienX_, trail[0]);
            char obj = getObject(temp - 1, AlienX_);
            if (obj == 'h') 
            {
                cout << "attain 20 Health" << endl;
                Pause();
                getalhp_();
                setplusalhp_(20);
                AlienY_ = i - 1; 
                setalienY_(AlienY_); 
            }
            else if (obj == 'v')           // move down by 1 and stop
            {
                cout << "Alien discovers an arrow" << endl;
                cout << "Alien's attack + 20" << endl;
                Pause();
                setalatk_(20);
                AlienY_ = i - 1;
                setalienY_(AlienY_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_down();
                break;
            }
            else if (obj == '^')         // move up by 1 and stop
            {
                cout << "Alien discovers an  arrow." << endl;
                cout << "Alien's attack + 20." << endl;
                Pause();
                setalatk_(20);
                AlienY_ = i - 1;
                setalienY_(AlienY_);
            }
            else if (obj == '<') // move to the left by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienY_ = i - 1;
                setalienY_(AlienY_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_left();
                break;
            }
            else if (obj == '>') // move to the right by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack + 20." << endl;
                Pause();
                setalatk_(20);
                AlienY_ = i - 1;
                setalienY_(AlienY_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_right();
                break;
            }
            else if (obj == 'p') // attack nearby Zombie
            {
                cout << "Pod detected, searching nearby Zombie to attack." << endl;
                Pause();
                int podY = temp - 1;
                int podX = AlienX_;
                podatk(podY , podX);
                cout << "Zombie affected by 10 damage." << endl;
                Pause();
                AlienY_ = i - 1; // good
                setalienY_(AlienY_); // good
            }
            else if (obj == 'r')
            {
                cout << "Alien discovers a rock." << endl;
                cout << "Breaking the rock." << endl;
                Pause();
                rockupd(temp - 1, AlienX_);
                AlienY_ = i;
                setalienY_(AlienY_);
                i = 0;
            }
            else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
            {
                cout << "Attacking Zombie." << endl;
                Pause();
                Alienattack(obj);
                Pause();
                char obj2 = getObject(temp - 1, AlienX_);
                if (obj2 == ' ')
                {
                    AlienY_ = i - 1;
                    setalienY_(AlienY_);
                }
                else
                {
                    AlienY_ = i;
                    setalienY_(AlienY_);
                    i = 0;
                }
            }
            else 
            {
                cout << "Alien discovers an empty space." << endl;
                Pause();
                AlienY_ = i - 1;
                setalienY_(AlienY_);
            }
            setmap(AlienY_, AlienX_, 'A');
            display();
            Alienturn();
            Pause();
        }
        ranupd();
        display(); 
        resetatk_();
        Alienturn();
        saveHP(alhp_);
        saveATK(alatk_);
    }

    void movement::move_down()
    {
        int y = getDimY() - 1; 
        char trail[] = {'.'};
        int AlX = AlienX_;
        for(int i = AlienY_; i < y; ++i)
        {
            int temp = i;
            setmap(temp, AlienX_, trail[0]);
            char obj = getObject(temp + 1, AlienX_);
            if (obj == 'h')
            {
                cout << "+ 20 Health." << endl;
                Pause();
                getalhp_();
                setplusalhp_(20);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
            }
            else if (obj == 'v') // move down by 1 and stop
            {
                cout << "Alien discovers arrow." << endl;
                cout << "Alien's attack + 20." << endl;
                Pause();
                setalatk_(20);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
            }
            else if (obj == '^') // move up by 1 and stop
            {
                cout << "Alien discovers arrow." << endl;
                cout << "Alien's attack + 20." << endl;
                Pause();
                setalatk_(20);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_up();
                break;
            }
            else if (obj == '<')     // move to the left by 1
            {
                cout << "Alien discovers arrow." << endl;
                cout << "Alien's attack + 20." << endl;
                Pause();
                setalatk_(20);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_left();
                break;
            }
            else if (obj == '>')      // move to the right by 1 
            {
                cout << "Alien discovers arrow." << endl;
                cout << "Alien's attack + 20." << endl;
                Pause();
                setalatk_(20);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_right();
                break;
            }
            else if (obj == 'p') 
            {
                cout << "Pod detected , searching neraby Zombie to attack." << endl;
                Pause();
                int podY = temp + 1;
                int podX = AlienX_;
                podatk(podY , podX);
                cout << "Zombie -10 damage." << endl;
                Pause();
                AlienY_ = i + 1;
                setalienY_(AlienY_);
            }
            else if (obj == 'r')
            {
                cout << "Alien discovers rock." << endl;
                cout << "Breaking the rock." << endl;
                Pause();
                rockupd(temp + 1, AlienX_);
                AlienY_ = i;
                setalienY_(AlienY_);
                i = y;
            }
            else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
            {
                cout << "Attacking Zombie." << endl;
                Pause();
                Alienattack(obj);
                Pause();
                char obj2 = getObject(temp + 1, AlienX_);
                if (obj2 == ' ')
                {
                    AlienY_ = i + 1;
                    setalienY_(AlienY_);
                }
                else
                {
                    AlienY_ = i;
                    setalienY_(AlienY_);
                    i = y;
                }
            }
            else 
            {
                cout << "Alien discovers an empty space." << endl;
                Pause();
                AlienY_ = i + 1;
                setalienY_(AlienY_);
            }
            setmap(AlienY_, AlienX_, 'A');
            display();
            Alienturn();
            Pause();
        }
        ranupd();
        display(); 
        resetatk_();
        Alienturn();
        saveHP(alhp_);
        saveATK(alatk_);
    }

    void movement::move_left()
    {
        int x = getDimX() - 1; 
        char trail[] = {'.'};
        int AlY = AlienY_;
        for(int i = AlienX_; i > 0; --i) 
        {
            int temp = i;
            setmap(AlienY_, temp, trail[0]);
            char obj = getObject(AlienY_ , temp - 1);
            if (obj == 'h')            // Health (+20 health to Alien)
            {
                cout << "+ 20 Health." << endl;
                Pause();
                getalhp_();
                setplusalhp_(20);
                AlienX_ = i - 1;
                setalienX_(AlienX_);
            }
            else if (obj == 'v')       // move down by 1 
            {
                cout << "Alien discovers an arrow." << endl;
                cout << "Alien's attack + 20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i - 1;
                setalienX_(AlienX_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_down();
                break;
            }
            else if (obj == '^')    // move up by 1 
            {
                cout << "Alien discovers an arrow." << endl;
                cout << "Alien's attack +20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i - 1;
                setalienX_(AlienX_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_up();
                break;
            }
            else if (obj == '<')        // move to the left by 1 
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = AlienX_ - 1;
                setalienX_(AlienX_);
            }
            else if (obj == '>')       // move to the right by 1 
            {
                cout << "Alien discvers an arrow." << endl;
                cout << "Alien's attack + 20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i - 1;
                setalienX_(AlienX_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_right();
                break;
            }
            else if (obj == 'p') 
            {
                cout << "Pod detected, searching nearby Zombie to Attack" << endl;
                Pause();
                int podY = AlienY_;
                int podX = temp - 1;
                podatk(podY , podX);
                cout << "Zombie -10 damage." << endl;
                Pause();
                AlienX_ = i - 1;
                setalienX_(AlienX_);
            }
            else if (obj == 'r')
            {
                cout << "Alien discovers a rock." << endl;
                cout << "Breaking the rock." << endl;
                Pause();
                rockupd(AlienY_ , temp - 1);
                AlienX_ = i;
                setalienX_(AlienX_);
                i = 0;
            }
            else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
            {
                cout << "Attacking Zombie." << endl;
                Pause();
                Alienattack(obj);
                Pause();
                char obj2 = getObject(AlienY_, temp - 1);
                if (obj2 == ' ')
                {
                    AlienX_ = i - 1;
                    setalienX_(AlienX_);
                }
                else
                {
                    AlienX_ = i;
                    setalienX_(AlienX_);
                    i = 0;
                }
            }
            else 
            {
                cout << "Alien discovers an empty space." << endl;
                Pause();                
                AlienX_ = i - 1;
                setalienX_(AlienX_);
            }
            setmap(AlienY_, AlienX_, 'A');
            display();
            Alienturn();
            Pause();
        }
        ranupd();
        display(); 
        resetatk_();
        Alienturn();
        saveHP(alhp_);
        saveATK(alatk_);
    }

    void movement::move_right()
    {
        int x = getDimX() - 1;
        char trail[] = {'.'};
        int AlY = AlienY_;
        for(int i = AlienX_; i < x; ++i)
        {
            int temp = i;
            setmap(AlienY_, temp, trail[0]);
            char obj = getObject(AlienY_ , temp + 1);
            if (obj == 'h')           // Health (+20 health to Alien)
            {
                cout << " Gained 20 Health. " << endl;
                Pause();
                getalhp_();
                setplusalhp_(20);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
            }
            else if (obj == 'v')      // move down by 1 
            {
                cout << "Alien discovers an arrow." << endl;
                cout << "Alien's attack + 20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_down();
                break;
            }
            else if (obj == '^')        // move up by 1 
            {
                cout << "Alien discovers an arrow." << endl;
                cout << "Alien's attack +20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_up();
                break;
            }
            else if (obj == '<')           // move to the left by 1 
            {
                cout << "Alien DISCOVERS an arrow." << endl;
                cout << "Alien's +20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_left();
                break;
            }
            else if (obj == '>')            // move to the right by 1 
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
            }
            else if (obj == 'p') 
            {
                cout << "Pod detected, searching nearby Zombie to attack." << endl;
                Pause();
                int podY = AlienY_;
                int podX = temp + 1;
                podatk(podY , podX);
                cout << "Zombie -10 damage." << endl;
                Pause();
                AlienX_ = i + 1;
                setalienX_(AlienX_);
            }
            else if (obj == 'r')
            {
                cout << "Alien dicovers a rock." << endl;
                cout << "Breaking the rock." << endl;
                Pause();
                rockupd(AlienY_ , temp + 1);
                AlienX_ = i;
                setalienX_(AlienX_);
                i = x;
            }
            else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
            {
                cout << "Attacking Zombie." << endl;
                cout << "Attacking Zombie." << endl;
                Pause();
                Alienattack(obj);
                Pause();
                char obj2 = getObject(AlienY_, temp + 1);
                if (obj2 == ' ')
                {
                    AlienX_ = i + 1;
                    setalienX_(AlienX_);
                }
                else
                {
                    AlienX_ = i;
                    setalienX_(AlienX_);
                    i = x;
                }
            }
            else 
            {
                cout << "Alien discovers an empty space." << endl;
                Pause();
                AlienX_ = i + 1;
                setalienX_(AlienX_);
            }
            setmap(AlienY_, AlienX_, 'A');
            display();
            Alienturn();
            Pause();
        }
        ranupd();
        display(); 
        resetatk_();
        Alienturn();
        saveHP(alhp_);
        saveATK(alatk_);
    }

    void movement::move_arrow(int x, int y, string z)
    {

        int ary = getDimY() - y;
        int arx = x - 1;
        string dir = z;
        Pause();
        if ( dir.compare("up") == 0)
        {
            setmap(ary, arx, '^');
            display(); 
            Alienturn();
        }
        else if ( dir.compare("down") == 0)
        {
            setmap(ary, arx, 'v');
            display(); 
            Alienturn();
        }
        else if ( dir.compare("left") == 0)
        {
            setmap(ary, arx, '<');
            display(); 
            Alienturn();
        }
        else if ( dir.compare("right") == 0)
        {
            setmap(ary, arx, '>');
            display(); 
            Alienturn();
        }

    }

// ZOMBIE MOVEMENT
void movement::zommove()
{
    int no = getZomB();
    for (int i = 0; i < no; ++i)
    {
        cout << "  Zombie " << i+1 << " is making a move." << endl;
        Pause();
        fesetround(FE_UPWARD);
        char Zombody[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int Zy = getZomY(i);
        int Zx = getZomX(i);
        int Ay = getalienY_();
        int Ax = getalienX_();

        int DisY = Zy - Ay;
        int DisX = Zx - Ax;
        float DisTemp = pow(DisY,2) + pow(DisX,2);
        float Distance = llrint(sqrt(DisTemp));
        int Zhp  = getZHP(i);
        int Zatk = getZATK(i);     
        int Zrng = getZRNG(i);

        int ZtoAY = abs(DisY);
        int ZtoAX = abs(DisX);
        if (Distance <= Zrng)
        {
            int dmg = Zatk;
            setminusalhp_(dmg);
            cout << "Alien in range" << endl;
            Pause();
            cout << "Alien take " << Zatk << " damage from zombie "<< i + 1 << endl;
            Pause();
            cout << "Zombie recover " << Zatk << " Health from attacking Alien "<< endl;
            Zhp = Zhp + Zatk;
            setZomHP(i, Zhp);
            display();
            Zombieturn(i);
            Pause();
        }
        else if (ZtoAX > ZtoAY)   
        {        
            cout << "  Zombie " << i+1 << " cannot find Alien in range." << endl;
            Pause();
            cout << "  Zombie " << i+1 << " is moving towards Alien." << endl;
            Pause();
            if(DisX<0)    
            {
                 
                char obj = getObject(Zy, Zx + 1);
                if (obj == 'h')         // Health (+20 health to Alien)
                {
                    cout << " Zombie Gained 20 Health " << endl;
                    Pause();
                    Zhp = Zhp + 20;
                    setZomHP(i, Zhp);
                    setmap(Zy, Zx, ' ');
                    Zx = Zx + 1; 
                    setZomX(i,Zx);
                    setmap(Zy, Zx, Zombody[i]);
                    display();
                    Zombieturn(i);
                    Pause();
                }

                else 
                {
                    setmap(Zy, Zx, ' ');
                    Zx = Zx + 1; 
                    setZomX(i,Zx);
                    setmap(Zy, Zx, Zombody[i]);
                    display();
                    Zombieturn(i);
                    Pause();
                }
            }
            else 
            {
                
                char obj = getObject(Zy, Zx - 1);
                if (obj == 'h')           // Health (+20 health to Alien)
                {
                    cout << " Zombie Gained 20 Health " << endl;
                    Pause();
                    Zhp = Zhp + 20;
                    setZomHP(i, Zhp);
                    setmap(Zy, Zx, ' ');
                    Zx = Zx - 1; 
                    setZomX(i,Zx);
                    setmap(Zy, Zx, Zombody[i]);
                    display();
                    Zombieturn(i);
                    Pause();
                }

                else 
                {
                    setmap(Zy, Zx, ' ');
                    Zx = Zx - 1; 
                    setZomX(i,Zx);
                    setmap(Zy, Zx, Zombody[i]);
                    display();
                    Zombieturn(i);
                    Pause();
                }
            }
        }
        else 
        {
            cout << "  Zombie " << i+1 << " cannot find Alien in range." << endl;
            Pause();
            cout << "  Zombie " << i+1 << " is moving towards Alien." << endl;
            Pause();
            if (DisY<0)
            {
                
                char obj = getObject(Zy + 1, Zx);
                if (obj == 'h')           // Health (+20 health to Alien)
                {
                    cout << " Zombie Gained 20 Health " << endl;
                    Pause();
                    Zhp = Zhp + 20;
                    setZomHP(i, Zhp);
                    setmap(Zy, Zx, ' ');
                    Zy = Zy + 1; 
                    setZomY(i,Zy);
                    setmap(Zy, Zx, Zombody[i]);
                    display();
                    Zombieturn(i);
                    Pause();
                }

                else 
                {
                    setmap(Zy, Zx, ' ');
                    Zy = Zy + 1;
                    setZomY(i,Zy);
                    setmap(Zy, Zx, Zombody[i]);
                    display();
                    Zombieturn(i);
                    Pause();
                }
            }
            else 
            {
                
                char obj = getObject(Zy - 1, Zx);
                if (obj == 'h')            // Health (+20 health to Alien)
                {
                    cout << " Zombie Gained 20 Health " << endl;
                    Pause();
                    Zhp = Zhp + 20;
                    setZomHP(i, Zhp);
                    setmap(Zy, Zx, ' ');
                    Zy = Zy - 1; 
                    setZomY(i,Zy);
                    setmap(Zy, Zx, Zombody[i]);
                    display();
                    Zombieturn(i);
                    Pause();
                }

                else 
                {
                    setmap(Zy, Zx, ' ');
                    Zy = Zy - 1;
                    setZomY(i,Zy);
                    setmap(Zy, Zx, Zombody[i]);
                    display();
                    Zombieturn(i);
                    Pause();
                }
            }
        }
    }
}

void movement::podatk(int podY, int podX)
{
    int no = getZomB();
    int Dispod[] = {};
    for (int i = 0; i < no; ++i)
    {
        fesetround(FE_UPWARD);
        int Zy = getZomY(i);
        int Zx = getZomX(i);
        int DisY = Zy - podY;
        int DisX = Zx - podX;
        float DisTemp = pow(DisY,2) + pow(DisX,2);
        float Distance = llrint(sqrt(DisTemp));
        Dispod[i] = Distance;
    }
    int near = Dispod[0];
    int zomnum = 0;
    for (int i = 0; i < no; ++i)
    {
        if(Dispod[i] < near)
        {
            near = Dispod[i];
            zomnum = i;
        }
    }
    int Zhp  = getZHP(zomnum); 
    Zhp = Zhp - 10;
    setZomHP(zomnum, Zhp);
}


void movement::subalatk(int num)
{
    int Zy_ = getZomY(num);
    int Zx_ = getZomX(num);

    int ZomHp_ = getZHP(num);
    int Alatk_ = getalatk_();
    ZomHp_ = ZomHp_ - Alatk_;
    cout << " Alien, attack Zombie " << num+1 << " with " << Alatk_ << " damage. " << endl;
    Pause();
    if (ZomHp_<=0)
    {
        ZomHp_ = 0;
        setZomHP(num, ZomHp_);
        setmap(Zy_, Zx_, ' ');
        display();
        Alienturn();
        Pause();
        cout << " Zombie " << num+1 << ", defeated." << endl;
        Pause();
    }
    else
    {
        setZomHP(num, ZomHp_);
        display();
        Alienturn();
        Pause();
        cout << " Zombie " << num+1 << " is still alive." << endl;
        Pause();
    }
}

void movement::Alienattack(char obj)
{
    if (obj == '1')
    {
        int num = 0;
        subalatk(num);
    }
    else if (obj == '2')
    {
        int num = 1;
        subalatk(num);
    }
    else if (obj == '3')
    {
        int num = 2;
        subalatk(num);
    }
    else if (obj == '4')
    {
        int num = 3;
        subalatk(num);
    }
    else if (obj == '5')
    {
        int num = 4;
        subalatk(num);
    }
    else if (obj == '6')
    {
        int num = 5;
        subalatk(num);
    }
    else if (obj == '7')
    {
        int num = 6;
        subalatk(num);
    }
    else if (obj == '8')
    {
        int num = 7;
        subalatk(num);
    }
    else if (obj == '9')
    {
        int num = 8;
        subalatk(num);
    }
}
