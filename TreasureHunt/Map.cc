#include "Map.h"

#include <iostream>
#include <ostream>

int Map::getArraySize()
{
   return arraySize;
}
int Map::getNumberTry()
{
   return numberTry;
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
   else
   {
      return false;
   }
}


void Map::createMap()
{
   srand(time(NULL));
   for (int i = 0; i < numberArray; ++i)
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
   for(int i = 0; i < numberArray; i++)
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
   if(theMap[line][column] == Case::Treasure)
   {
      std::cout << "You win! What will you do with all that money ? Nah i don't care.\n";
      return true;
   }
   numberTry--;
   std::cout << "Careful you can't miss the tresure more than" << numberTry << " times.\nYou are really that bad ??";
   return false;
   
}

