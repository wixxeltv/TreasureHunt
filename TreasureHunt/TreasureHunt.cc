#include <iostream>
#include <map>

#include "Map.h"

void main()
{
    Map map1;
    std::cout << "Welcome to Treasure Hunt!\nLet's see the map.\nPress enter...";
    std::cin.get();
    map1.showMap();
    std::cout << "Okay now where do you want to dig ?\n";
    int line;
    int column;
    std::cin >> line;;
    do
    {
        std::cout << "Line : ";
        std::cin >> line;
    }
    while (map1.isNumber() || line < 1 || line > map1.getArraySize() );
    {
        std::cout << "You are outside!\n";
    }
    
    do
    {
        std::cout << "Column : ";
        std::cin >> column;
    }
    while (map1.isNumber() || column < 1 || column > map1.getArraySize() );
    {
        std::cout << "You are outside!\n";
    }
    if (map1.checkWin(line, column))
    {
        
    }
    
}
