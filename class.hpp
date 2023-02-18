#include <iostream>
#include <vector>

using namespace std;

class Mars
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_;          // to indicate private data

public:
    Mars(int dimX = 9, int dimY = 5);
    void init(int dimX, int dimY);
    void display();
    

    int getDimX() const;
    int getDimY() const; 
     char getObject(int X, int Y) const;
    void setObject(int x, int y, char ch);
    bool isInsideMap(int dimX, int dimY);

};


