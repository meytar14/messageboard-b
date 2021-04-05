#ifndef BOARD
#define BOARD
#include "Direction.hpp"
#include <string>
#include <vector>
using namespace std;
namespace ariel{

    class Point
   {
   private:
       
   public:
        unsigned int x;
        unsigned int y;
        Point();
        Point(unsigned int x,unsigned int y);
        ~Point();
        Point returnMax(Point p);
        Point returnMin(Point p);
   }; 

   class Board
   {
   private:
       
   public:
       Point min;
       Point max;
       vector<vector<char>> matrix;
       Board();
       ~Board();
       bool isInBoard(unsigned int x,unsigned int y,Direction d,std::string s);
       void post(unsigned int x,unsigned int y,Direction d,std::string s);
       std::string read(unsigned int x,unsigned int y,Direction d,unsigned int num);
       void show();
   };
}
#endif