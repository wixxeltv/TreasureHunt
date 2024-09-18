#pragma once
#include <array>


enum class Case
{
    Diged,
    Treasure,
    Nothing,
    FoundTreasure
};


const int arraySize = 3;
const int numberArray = 3;

class Map
{
private:
    int numberTry;
    int random();
public:
    int getArraySize();
    int getNumberTry();
    bool isNumber();
    std::array<std::array<Case, arraySize>, numberArray> theMap;

  
    void createMap();
    void showMap();
    bool checkWin(int line, int column);

    
    Map() : numberTry(5)
    {
        createMap();
    }
};
