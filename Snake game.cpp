#include <iostream>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x,y, fruitx,fruity,score;
int tailx[50],taily[50];
int ntail;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void setup()
{
    gameOver = false;
    dir = STOP;
    x = width/2; // position of our snake
    y = height/2;
    fruitx = rand()% width;// random fruit positions
    fruity = rand()% height;
    score = 0; // score of the game
}
//the characters in the game will be in the draw function.
void draw()
{
    system("cls");//function to clear screen
    for(int i = 0; i < width+2 ; i++)// prints map width of the game
        cout <<"#";
    cout << endl;

    for(int i=0; i < height; i++)
    {
        for(int j=0; j < width; j++)
        {
            if(j==0)
                cout<< "#";
                if(i == y && j == x)// if the position is in the middle
                cout<< "P";
                else if(i== fruity && j == fruitx)// if the position is at the fruit
                    cout<<"M";
                else
                {
                    bool print = false;
                    for(int k=0; k< ntail; k++)
                    {
                        if(tailx[k] == j && taily[k] == i)
                        {
                            cout<< "o";
                            print = true;
                        }
                    }
                    if(!print)
                        cout<< " ";

                }

            if(j == width -1)
                cout <<"#";
        }
        cout << endl;
    }
    for (int i=0; i< width+2; i++)
        cout<< "#";
    cout<< endl;
    cout<< "SCOORE :"<<score<< endl;
}
void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 's' :
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w' :
            dir = UP;
            break;
        case 'p':
            gameOver = true;
            break;

        }
    }

}
void logic()
{
     int prevx = tailx[0];
     int prevy = taily[0];
     int prev2x, prev2y;
     tailx[0] =x;
     taily[0]= y;
     for(int i =1; i< ntail; i++)
     {
         prev2x = tailx[i];
         prev2y = taily[i];
         tailx[i] = prevx;
         taily[i] = prevy;
         prevx = prev2x;
         prevy = prev2y;
     }
     switch(dir)
     {
     case LEFT:
         x--;
        break;
     case RIGHT:
         x++;
        break;
     case UP:
         y--;
        break;
     case DOWN:
         y++;
        break;
     default:
        break;

     }
     if(x > width || x < 0 || y > height || y<0 )
        gameOver = true;
     if (x == fruitx && y == fruity)
     {

        score += 100;
        fruitx =rand()% width;
        fruity =rand()% height;
        ntail++;

     }


}

int main()
{
    setup();
    while(!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(10);
    }
    return 0;


}
