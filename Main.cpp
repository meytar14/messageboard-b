#include <iostream>
#include "Board.hpp"
#include "Direction.hpp"
using namespace std;
using namespace ariel;
int main(int argc, char const *argv[])
{
    Board b;
    string s="ffgg";
    b.post(3,3,Direction::Horizontal,s);
    b.post(9,6,Direction::Horizontal,"w a kk_k llll");
    b.post(10,2,Direction::Vertical,"hello world::");
    b.post(3,5,Direction::Vertical,"fkkls");
    b.post(3,5,Direction::Vertical,"hello");

    b.show();
}






