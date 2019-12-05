#include "level.h"

Level::Level() {}

void New_Grid()
{
    for(int r=0;r<5;r++)
    {
        for(int c=0;c<5;r++)
        {
            Field* field = new Field(r,c);
        }
    }
}

void Fill_field(int x, int y)
{

}

void printGrid()
{

}
