#include "Map.h"

#include <iostream>
#include <ostream>

int Map::getArraySize()
{
   return arraySize;
}
int Map::getPlayerTries()
{
   return  _playerTries;
}

int Map::getWrongTriesAllowed()
{
   return _wrongTriesAllowed;
}

int Map::random()
{
   return rand() % arraySize;
}
bool Map::isNumber()
{
   if(std::cin.fail())
   {
      std::cin.clear();
      std::cin.ignore();
      return true;
   }
   return false;
}
void Map::createMap()
{
   srand(time(NULL));
   for (int i = 0; i < arraySize; ++i)
   {
      for (int j = 0; j < arraySize; ++j)
      {
         theMap[i][j] = Case::Nothing;
      }
   }
   theMap[random()][random()] = Case::Treasure;
}

void Map::showMap() 
{
   for(int i = 0; i < arraySize; i++)
   {
      std::cout << "|";
      for(int j = 0; j < arraySize; j++)
      {
         switch (theMap[i][j])
         {
            case Case::Nothing: std::cout << "?"; break;
            case Case::Diged: std::cout << "o"; break;
            case Case::FoundTreasure: std::cout << "$"; break;
            case Case::Treasure: std::cout << "?"; break;
         }
         std::cout << "|";
      }
      std::cout << "\n";
   }
}
bool Map::checkWin(int line, int column)
{
   _playerTries++;
   if(theMap[line][column] == Case::Treasure)
   {
      theMap[line][column] = Case::FoundTreasure;
      return true;
   }
   _wrongTriesAllowed--;
   theMap[line][column] = Case::Diged;
   return false;
   
}

