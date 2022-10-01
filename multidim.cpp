#include <iostream>
#include <vector>
#include "color.h"

#define debugOut false && std::cout

typedef std::vector<std::vector<int>> twoDimInt;

int main()
{
    int dimx = 5;
    int dimy = 8;
    twoDimInt distanzen(dimx, std::vector<int>(dimy, 13));

    for (size_t j = 0; j < dimy; j++)
    {
        for (size_t i = 0; i < dimx; i++)
        {
            std::cout << distanzen[i][j] << "\t";
        }

        debugOut << std::endl;
        debugOut << colorRed << "=====" << resetColor;

        std::cout << std::endl;
    }
}