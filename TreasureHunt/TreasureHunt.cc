#include <iostream>
#include <map>

#include "Map.h"

void main()
{
    Map map1;
    std::cout << "Welcome to Treasure Hunt! You will have "<< map1.getWrongTriesAllowed() <<" tries to guess where is the treasure.\nLet's see the map.\nPress enter...";
    std::cin.get();
    while (true)
    {
        map1.showMap();
        std::cout << "Okay now where do you want to dig ?\n";
        int line;
        int column;
        do
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Chose a line inside the map: ";
            std::cin >> line;
        }
        while (map1.isNumber() || line < 1 || line > map1.getArraySize());
    
        do
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Now chose a column inside the map: ";
            std::cin >> column;
        }
        while (map1.isNumber() || column < 1 || column > map1.getArraySize());
        
        if (map1.checkWin(line-1, column-1))
        {
            map1.getPlayerTries() > 1 ? std::cout << "Waaaw you win in " << map1.getPlayerTries()
            << "tries! What will you do with all that money ? Nah i don't care.\n"
            : std::cout << "Okay okay this guy is very lucky or youuu cannn readddd inn theee computerrr minnddd,"
            " anyways you win in " << map1.getPlayerTries() << " try that's impressive good day to you mister.\n";
            break;
        }
        if(map1.getWrongTriesAllowed() > 0)
        {
            std::cout << "Careful you can't miss the treasure more than " << map1.getWrongTriesAllowed() << " times.\n";
            continue;
      
        }
        std::cout << "Poin poin poin you lose..\nYou've fail too many times so yes you are bad...\n";
        break;
        
    };
    map1.showMap();
    
}
