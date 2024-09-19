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

class Map
{
private:
    int _playerTries;
    int _wrongTriesAllowed;
    int random();
    std::array<std::array<Case, arraySize>, arraySize> theMap;
public:
    int getArraySize();
    int getPlayerTries();
    int getWrongTriesAllowed();
    bool isNumber();
   

  
    void createMap();
    void showMap();
    bool checkWin(int line, int column);

    
    Map() : _wrongTriesAllowed(5), _playerTries(0)
    {
        createMap();
    }
};
