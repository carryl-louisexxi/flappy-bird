#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
using namespace std;

bool gameover;
const int Mapwidth=40;
const int Mapheight=15;
int BirdX, BirdY, score;
int i,j;
enum eDirection{ STOP=0,  UP  } dir;

void Setup()
{
    gameover=false;
    dir=STOP;
    BirdX=5;
    BirdY=14;

}
void Draw()
{
    system("cls");
    for(i=0; i<Mapwidth+2; i++)
        cout<<"#";
        cout<<endl;
    for(i=0; i<Mapheight; i++)
    {
        for(j=0; j<Mapwidth; j++)
        {
            if(j==0)
                cout<<"#";
            if(i==BirdY && j==BirdX)
                cout<<"O";
            else if(i==13 && j==10 || i==14 && j==10)
                cout<<"0";
            else if(i==13 && j==20 || i==14 && j==20)
                cout<<"0";
            else if(i==13 && j==30 || i==14&& j==30)
                cout<<"0";
            else
                cout<<" ";
            if(j==Mapwidth-1)
                cout<<"#";
        }
        cout<<endl;
    }
    for(i=0; i<Mapwidth+2; i++)
        cout<<"#";
        cout<<endl;
}
void Input()
{
    if(_kbhit)
    {
        switch(getch())
        {
        case 'a':
            dir=UP;
            break;

        case 'x':
            gameover=true;
        }
    }


}
void Logic()
{
    switch(dir)
    {
    case UP:
        BirdX++;
        BirdY--;
        break;
    }


}


int main()
{
    Setup();
    while(!gameover)
    {
        Draw();
        Input();
        Logic();
        Sleep(10);
    }
}
