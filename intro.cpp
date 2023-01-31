#include <iostream>
#include <chrono> // reequired to use sleep_for()
#include <thread> // reequired to use sleep_for()
using namespace std;


void delay(int milliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void display(const char text[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << text[i];
    }
    cout << endl;
}

void rotateLeft(char text[], int size)
{
    int tempChar = text[0];
    for (int i = 0; i < size - 1; ++i)
    {
        text[i] = text[i + 1];
    }
    text[size - 1] = tempChar;
}

void rotateRight(char text[], int size)
{
    int tempChar = text[size - 1];
    for (int i = size - 1; 0 < i; --i)
    {
        text[i] = text[i - 1];
    }
    text[0] = tempChar;
}

void intro()
{
    
    using namespace std::chrono;
    auto finish = system_clock::now() + 0.15min;
    const int textLength = 25;
    
    char greetText1[textLength] = {'A', 'L', 'I', 'E', 'N', ' ', ' ', ' ',
                                   ' ', 'V', 'S', ' ', ' ', ' ', ' ', 'Z',
                                   'O', 'M', 'B', 'I', 'E', 'S', ' ', ' ', ' '};
    char greetText2[textLength] = {'F', 'I', 'G', 'H', 'T', ' ', ' ',
                                   ' ', 'T', 'O', ' ', ' ', ' ', 'T',
                                   'H', 'E', ' ', ' ', ' ', 'E', 'N', 'D', ' ', ' ', ' '};

    bool key = false;
    

    do
    {
        system("cls"); // or system("clear"); for Linux/MacOS
        cout << "o-o-o-o-o-o-o-o-o-o-o-o-o" << endl;
        cout << "*************************" << endl;
        cout << "o-o-o-o-o-o-o-o-o-o-o-o-o" << endl;
        cout << endl;
        display(greetText1, textLength);
        rotateLeft(greetText1, textLength);
        cout << endl;
        display(greetText2, textLength);
        rotateRight(greetText2, textLength);
        delay(800); // delay for certain milliseconds
        
    }
    while (system_clock::now() < finish);

    return;
}