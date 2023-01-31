#include <iostream>

char defaultsettings(int rows, int columns, int Zcount)
{
    char choice;
    std::cout << "Default Game Settings " << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-* " << std::endl;
    std::cout << "                      " << std::endl;
    std::cout << "No of Board rows    : " << rows << std::endl;
    std::cout << "No of Board columns : " << columns << std::endl;
    std::cout << "No of Zombies       : " << Zcount << std::endl;
    std::cout << "                      " << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-* " << std::endl;
    std::cout << "                      " << std::endl;
    std::cout << "                      " << std::endl;
    std::cout << "Do you wish to proceed with the default settings (Y/N) ? ";
    std::cin >> choice;
    return choice;
}
