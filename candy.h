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

    COLOR getColor() const  // get color for combo checker
    {
        return color;
    }

    void print()    // print color for testing
    {
        std::cout << color;
    }

private:
    const COLOR color;  // can't be changed
};

#endif // CANDY_H
