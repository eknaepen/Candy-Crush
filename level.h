#ifndef LEVEL_H
#define LEVEL_H
#include "field.h"
#include "random_candy.h"
#include "step_limit.h"

class Level
{
public:

    int grid[5][5];
    Level();
    ~Level();

    void New_Grid();
    void Fill_field(int x, int y);
    void printGrid();

};

#endif // LEVEL_H
