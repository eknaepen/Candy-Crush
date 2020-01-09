#include <iostream>
#include "game.h"
using namespace std;

Game::Game()
{
    cout << "geef aantal rijen: ";
    cin >> x;
    cout << "geeft aantal kolomen: ";
    cin >> y;
    cout << "\n";
    level = new Level(x,y);
    level->printGrid();
    level->Find_Combo();
    level->printGrid();
    for(int x=0;x<limit;x++)        // make sure the turn limit is not crossed
    {
        int quit;
        cout << "Give up=0  play=1\n";
        cin >> quit;
        if(quit==1)             // give option to give up if field is stuck
        {
            score=level->score*100;
            cout << "Turn's: " << limit-x << "\nYour score: " << score << "\n";
            Round();
        }
        else
        {
            x=limit;
        }
    }
    score=level->score*100;
    cout << "Your score: " << score << "\n";
}

void Game::Round()      // do a move and get the combo of the field
{
    level->Move();
    level->Find_Combo();
    level->printGrid();
}
