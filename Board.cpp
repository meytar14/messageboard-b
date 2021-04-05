#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
namespace ariel{
    
        Point::Point()
        {
            this->x=0;
            this->y=0;
        }
       Point::Point(unsigned int x,unsigned int y)
       {
            this->x=x;
            this->y=y;
       }
       Point::~Point()
       {

       }
       
       Point Point::returnMax(Point p)
       {
            unsigned int max_x=max(this->x,p.x);
            unsigned int max_y=max(this->y,p.y);
            Point pnew=Point(max_x,max_y);
            return pnew;
       }

       
       Point Point::returnMin(Point p)
       {
            unsigned int min_x=min(this->x,p.x);
            unsigned int min_y=min(this->y,p.y);
            Point pnew=Point(min_x,min_y);
            return pnew;
       }
    
  
       Board::Board()
       {
         
       }
       Board::~Board()
       {

       }
        bool Board::isInBoard(unsigned int x,unsigned int y,Direction d,std::string s)
        {
            if(d==Direction::Horizontal)
           {
               if(y<this->min.y||y+s.length()-1>this->max.y||x<this->min.x||x>this->max.x)
               {
                   return false;
               }
              return true;
           }
           else
           {
               if(x<this->min.x||x+s.length()-1>this->max.x||y<this->min.y||y>this->max.y)
               {
                   return false;
               }
              return true;
           }
        }
       void Board::post(unsigned int x,unsigned int y,Direction d,string s)//x=row, y=column
       {
           unsigned int numOfLinesToAdd=0;
           unsigned int numOfCharsToAdd=0;
           bool firstpost=false;
           if(this->matrix.size()==0)
           {
            this->min.x=x;
            this->min.y=y;
            this->max.x=x;
            this->max.y=y;
            firstpost=true;
           }
           if(this->isInBoard(x,y,d,s))
           {
            if(d==Direction::Horizontal)
            {
               for(unsigned int i=0;i<s.length();i++)
               {
                   matrix.at(x-this->min.x).at(y+i-this->min.y)=s[i];
               }
            }
            else
            {
                for(unsigned int i=0;i<s.length();i++)
                {
                   matrix.at(x+i-this->min.x).at(y-this->min.y)=s[i];
                }
            }   
           }

           else
           {
                std::vector<char> v;
                if(firstpost)
                {
                    v=std::vector<char>(s.length(),'_');
                    numOfLinesToAdd=1;
                }
                else
                {
                    v=std::vector<char>(this->matrix.at(0).size(),'_');
                }
                
            if(x<this->min.x)
               {
                   numOfLinesToAdd=this->min.x-x;
                   for(unsigned int i=0;i<numOfLinesToAdd;i++)
                   {
                    this->matrix.insert(this->matrix.begin(),v);
                   }
                   this->min.x=x;
               }
           
            if(x+s.length()-1>this->max.x)//_ _ _ f f
               {
                   if(d==Direction::Horizontal)
                   {
                       if(x>this->max.x)
                       {
                           numOfLinesToAdd=x-this->max.x;
                           this->max.x=x;
                       }
                       else if(firstpost==false)
                       {
                           numOfLinesToAdd=0;
                       }
                   }
                   else
                   {
                    numOfLinesToAdd=x+s.length()-1-this->max.x;
                    this->max.x=x+s.length()-1;
                   }
                   for(unsigned int i=0;i<numOfLinesToAdd;i++)
                   {
                    this->matrix.push_back(v);
                   }
                   
               }
            if(y<this->min.y)
               {
                   numOfCharsToAdd=this->min.y-y;
                   for(unsigned int i=this->min.x;i<=this->max.x;i++)
                   {
                       for(unsigned int k=0;k<numOfCharsToAdd;k++)
                       {
                           (this->matrix.at(i-this->min.x)).insert(this->matrix.at(i-this->min.x).begin(),'_');
                       }
                   }
                   this->min.y=y;
               }
               numOfCharsToAdd=0;
               if(y+s.length()-1>this->max.y)
               {
                   if(d==Direction::Horizontal)
                   {
                       if(firstpost==false)
                       {
                        numOfCharsToAdd=y+s.length()-this->max.y-1;
                       }
                       this->max.y=y+s.length()-1;
                   }
                   else
                   {
                       if(y>this->max.y)
                       {
                           numOfCharsToAdd=y-this->max.y;
                           this->max.y=y;
                       }
                   }
                   for(unsigned int i=this->min.x;i<=this->max.x;i++)
                   {
                       for(unsigned int k=0;k<numOfCharsToAdd;k++)
                       {
                           this->matrix.at(i-this->min.x).push_back('_');
                       }
                   }
               }
                this->post(x,y,d,s);
           }
       }

       std::string Board::read(unsigned int x,unsigned int y,Direction d,unsigned int num)
       {
           string s;
           if(d==Direction::Horizontal)
           {
               for(unsigned int i=0;i<num;i++)
                {
                    if(y+i>this->max.y||y+i<this->min.y||this->matrix.size()==0||x>this->max.x||x<this->min.x)//ddd_ _ _    
                    {
                        s=s+'_';
                    }
                    else
                    {
                        s=s+this->matrix.at(x-this->min.x).at(y+i-this->min.y);
                    }
                }
           }
           else
           {
                for(unsigned int i=0;i<num;i++)
                {
                    if(x+i>this->max.x||x+i<this->min.x||this->matrix.size()==0||y>this->max.y||y<this->min.y)
                    {
                        s=s+'_';
                    }
                    else
                    {
                        s=s+this->matrix.at(x+i-this->min.x).at(y-this->min.y);
                    }
                }
           }
           return s;
       }

       void Board::show()
       {
           for(unsigned int i=0;i<this->matrix.size();i++)
           {
               for(unsigned int k=0;k<this->matrix.at(i).size();k++)
               {
                   cout<<this->matrix.at(i).at(k);
               }
               cout<<endl;
           }
       }
   
   
}