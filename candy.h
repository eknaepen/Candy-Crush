#ifndef CANDY_H
#define CANDY_H

#include <iostream>
#include <string>

class Candy
{
public:
    enum COLOR  // change to graphic's later
    {
        RED = 'R',      //1 for randomizer
        BLUE = 'B',     //2
        GREEN = 'G',    //3
        ORANGE = 'O',   //4
        YELLOW = 'Y'    //5
    };

    Candy(COLOR color)  : color(color){}
    ~Candy() {}

    const COLOR color;

    COLOR getColor() const  // get color for combo checker
    {
        return color;
    }

    void print()    // print color for testing
    {
        switch(color)
        {
        case RED:
            std::cout << "R\n";
            break;
        case BLUE:
            std::cout << "B\n";
            break;
        case GREEN:
            std::cout << "G\n";
            break;
        case YELLOW:
            std::cout << "O\n";
            break;
        case ORANGE:
            std::cout << "Y\n";
            break;
        default:
            std::cout << "no color\n";
            break;
        }
    }
};

#endif // CANDY_H
