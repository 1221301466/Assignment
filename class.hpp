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
    void display(int X, int Y);

    int getDimX(int dimX = 9);
    int getDimY(int dim = 5); 

};