#ifndef FIELD_H
#define FIELD_H
#include "candy_field.h"
#include "wall.h"
#include "random_candy.h"

class Field
{
public:
    int x;
    int y;

    enum type
    {
        empty,  //moet gevuld worden
        candy,  //is al gevuld
        wall    //kan niet gevuld worden
    };

    Field(int r, int c);
    ~Field();

};

#endif // FIELD_H
