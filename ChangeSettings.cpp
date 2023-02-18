#include <iostream>
#include "rows.hpp"
#include "columns.hpp"
#include "zombies.hpp"

void changesettings(int &rows, int &columns, int &Zcount)
{
    system("cls");
    
    std::cout << "Game Settings         " << std::endl;
    std::cout << "                      " << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-* " << std::endl;
    std::cout << "                      " << std::endl;
    rows = row(rows);
    std::cout << std::endl;
    columns = column(columns);
    std::cout << std::endl;
    Zcount = zombies(Zcount);

    system("cls");

    std::cout << std::endl;
    std::cout << "NEW Game Settings " << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- " << std::endl;
    std::cout << "                      " << std::endl;
    std::cout << "No of Board rows    : " << rows << std::endl;
    std::cout << "No of Board columns : " << columns << std::endl;
    std::cout << "No of Zombies       : " << Zcount << std::endl;
    std::cout << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;
    std::cout << "Congrats the settings are updated..." << std::endl;
    system("pause");
    system("cls");
}