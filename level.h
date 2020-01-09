#ifndef LEVEL_H
#define LEVEL_H
#include <stdio.h>
#include <string.h>
#include "wall.h"
#include "candy_field.h"
#include "field.h"
#include "random_candy.h"

class Level
{
public:
    int score=0;
    int r;                      // amount of rows
    int c;                      // amonut of colums
    unsigned char grid[10][10]; // grid as playing field

    Level(int row, int colum);
    ~Level();

    void printGrid();   // prints grid
    void Move();        // make a move on the field
    int Check_Move(int x, int y, char move[]);  // check if move is legal position wise
    bool Check_Break_Move(int x, int y);        // check if move is legal combo wise --> no combo no move
    void Find_Combo();          // check for combo's on the field and replace them by new candy

private:
    const char* Up="U";
    const char* Down="D";
    const char* Left="L";
    const char* Right="R";

};

#endif // LEVEL_H
