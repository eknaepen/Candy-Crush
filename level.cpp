#include <iostream>
#include "level.h"
using namespace std;

Level::Level(int row, int colum)        // create and fill grid --> playing field or level
{
    r=row;
    c=colum+2;
    srand((unsigned)time(nullptr));
    for(int x=0;x<r;x++)
    {
        for(int y=0;y<c;y++)
        {
            if(y==0 || y==(c-1))
            {
                Wall* wall = new Wall;      // wall's on the side for default level
                grid[x][y] = wall->setsign();
            }
            else
            {
                Candy_Field* candy_field = new Candy_Field;     // fill the rest with candy
                grid[x][y] = candy_field->setsign();
            }
        }
    }
}

void Level::printGrid()     // print grid
{
    cout << "  ";
    for(int i=0;i<c-2;i++)
    {
        cout << i;
    }
    cout << "\n";

    for(int x=0;x<r;x++)
    {
        cout << x;
        for(int y=0;y<c;y++)
        {
            cout << grid[x][y];         //loop trough grid from [0][0] to [r][c] --> r=rows, c=colums
        }
        cout << "\n";
    }
    cout << "\n";
}

void Level::Move()      // make a move on the field
{
    int a1;
    int b1;
    int a2;
    int b2;
    char move[10];          // choose candy for move
    cout << "Colum: ";
    cin >> b1;
    cout << "Row: ";
    cin >> a1;
    b1++;

    cout << "Up=U, Down=D, Left=L, Right=R\n" << "Choice: ";        // choose wich move --> up is switch candy witch candy above ....
    cin >> move;
    cout << "\n";

    if(Check_Move(b1,a1,move)==3)  // Up        // if move is legal position wise switch the candy's
    {
        a2=a1-1;
        b2=b1;
    }
    else if(Check_Move(b1,a1,move)==4) //Down
    {
        a2=a1+1;
        b2=b1;
    }
    else if(Check_Move(b1,a1,move)==1) //Left
    {
        a2=a1;
        b2=b1-1;
    }
    else if(Check_Move(b1,a1,move)==2) //Right
    {
        a2=a1;
        b2=b1+1;
    }
    else
    {
        a2=a1;
        b2=b1;
        cout << "\nIllegal move\n\n";       // if move is illegal position wise don't switch but try again
        printGrid();
        Move();
    }

    grid[a1][b1]^=grid[a2][b2];
    grid[a2][b2]^=grid[a1][b1];
    grid[a1][b1]^=grid[a2][b2];

    if(Check_Break_Move(a2,b2))         // if move is illegal combo wise switch back and try again
    {
        grid[a1][b1]^=grid[a2][b2];
        grid[a2][b2]^=grid[a1][b1];
        grid[a1][b1]^=grid[a2][b2];
        cout << "\nIllegal move --> no combo\n\n";
        printGrid();
        Move();
    }
    printGrid();
}

int Level::Check_Move(int x, int y, char move[10])      // check position of chosen candy and look for wall's or level boundarys
{                                                       // if wall or boundary move is illegal because switch not possible
    if(strcmp(move,Left)==0 && x!=1)
    {
        return 1;   //left side --> left move enable
    }
    if(strcmp(move,Right)==0 && x!=c-2)
    {
        return 2;   //right side --> right move enable
    }
    if(strcmp(move,Up)==0 && y!=0)
    {
        return 3;   //top side --> up move enable
    }
    if(strcmp(move,Down)==0 && y!=r-1)
    {
        return 4;   //bottom side --> down move enable
    }
    else
    {
        return 0;
    }
}

bool Level::Check_Break_Move(int x, int y)              // check if the move made a new combo --> if not switch back and ask for new move
{
    if(grid[x][y]==grid[x+1][y] && grid[x][y]==grid[x-1][y])
    {
        return false;
    }
    else if(grid[x][y]==grid[x-1][y] && grid[x][y]==grid[x-2][y])
    {
        return false;

    }
    else if(grid[x][y]==grid[x+1][y] && grid[x][y]==grid[x+2][y])
    {
        return false;

    }
    else if(grid[x][y]==grid[x][y+1] && grid[x][y]==grid[x][y-1])
    {
        return false;
    }
    else if(grid[x][y]==grid[x][y-1] && grid[x][y]==grid[x][y-2])
    {
        return false;
    }
    else if(grid[x][y]==grid[x][y+1] && grid[x][y]==grid[x][y+2])
    {
        return false;
    }
    else
    {
        return true;
    }
}



void Level::Find_Combo()                            // check the field for combo's and turn into new candy's
{
    Candy_Field * new1 = new Candy_Field;
    Candy_Field * new2 = new Candy_Field;
    Candy_Field * new3 = new Candy_Field;
    for(int x=0;x<r;x++)
    {
        for(int y=1;y<c-1;y++)              // loop trough the grid/field and check in all directions
        {
            if(grid[x][y]==grid[x+1][y] && grid[x][y]==grid[x-1][y])
            {
                grid[x][y]=new1->setsign();
                grid[x+1][y]=new2->setsign();           // fill field with new candy
                grid[x-1][y]=new3->setsign();
                score++;                                // add score because combo give's you points
            }
            else if(grid[x][y]==grid[x-1][y] && grid[x][y]==grid[x-2][y])
            {
                grid[x][y]=new1->setsign();
                grid[x-1][y]=new2->setsign();
                grid[x-2][y]=new3->setsign();
                score++;
            }
            else if(grid[x][y]==grid[x+1][y] && grid[x][y]==grid[x+2][y])
            {
                grid[x][y]=new1->setsign();
                grid[x+1][y]=new2->setsign();
                grid[x+2][y]=new3->setsign();
                score++;
            }
            else if(grid[x][y]==grid[x][y+1] && grid[x][y]==grid[x][y-1])
            {
                grid[x][y]=new1->setsign();
                grid[x][y+1]=new2->setsign();
                grid[x][y-1]=new3->setsign();
                score++;
            }
            else if(grid[x][y]==grid[x][y-1] && grid[x][y]==grid[x][y-2])
            {
                grid[x][y]=new1->setsign();
                grid[x][y-1]=new2->setsign();
                grid[x][y-2]=new3->setsign();
                score++;
            }
            else if(grid[x][y]==grid[x][y+1] && grid[x][y]==grid[x][y+2])
            {
                grid[x][y]=new1->setsign();
                grid[x][y+1]=new2->setsign();
                grid[x][y+2]=new3->setsign();
                score++;
            }
        }
    }
}
