#include "random_candy.h"

Random_candy::Random_candy()
{

}

void newCandy()
{
    srand((unsigned)time(NULL));
    int i;
    i = (rand()%5)+1;

    Candy* candy;

    switch(i)
    {
    case 1:
        candy = new Candy(Candy::RED);
        break;
    case 2:
        candy = new Candy(Candy::BLUE);
        break;
    case 3:
        candy = new Candy(Candy::GREEN);
        break;
    case 4:
        candy = new Candy(Candy::ORANGE);
        break;
    case 5:
        candy = new Candy(Candy::YELLOW);
        break;
    }
    candy->print();
}
