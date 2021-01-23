#include<iostream>
#include<conio.h>
#include<windows.h>
#include<graphics.h>
#include<cstdlib>
#include<time.h>
using namespace std;
struct coord
{
    int tx, ty;
};
enum direction {   RIGHT,LEFT , UP , DOWN};  // directions
direction dir;
int fruitx = (rand() % 799) +201  , fruity = ( rand() % 499) +50 +20 ; int length= 5 ; coord body[1000]; int score=0; coord headpast;
  int x =fruitx-15, y=fruity;
void setup();
void direction();   //DIRECTION
void moveit();
void checkfruit();
void snakebody();
int checkout();
int checkwall();
int main()
{            srand( time(0)) ;       // WINDOW SIZES .
                    DWORD screenWidth = GetSystemMetrics(  SM_CXSCREEN);
                    DWORD screenHeight = GetSystemMetrics( SM_CXSCREEN);
         initwindow( screenHeight, screenHeight );   int page = 0; char a[100];
while(1)
   {
setactivepage( page );
setvisualpage( 1- page); cleardevice();
       headpast.tx=x; headpast.ty=y;
        setfillstyle( SOLID_FILL ,  RED);
setcolor( RED);
       rectangle(190, 40 , 1010 ,  510);
          rectangle( 200 , 50  , 1000 , 500);
          floodfill( 195 , 45 , RED);
          setcolor(WHITE);

                 // SCORE BOARD
           setcolor(RED);
          circle( 1200 , 250 , 150  );
          circle( 1200 , 250 , 130  );
           setfillstyle( SOLID_FILL , BLUE);
          floodfill( 1200 , 390 , RED);
           setfillstyle( SOLID_FILL , LIGHTGRAY);
            setcolor( YELLOW);
           settextstyle ( BOLD_FONT , HORIZ_DIR ,7);  sprintf( a, "%d", score);
          outtextxy(1090 , 200 , "SCORE");
          outtextxy( 1170 , 300 , a);
      // SCOREBOARDEND
      // NAME
setcolor(RED);
      rectangle( 50 , 550, 1250 ,  730);
   floodfill( 0 , 0 , RED);
   setcolor( YELLOW);
   settextstyle( BOLD_FONT , HORIZ_DIR , 10);
   outtextxy( 160 , 550 , "SNAKE ARENA ");
   settextstyle(BOLD_FONT , HORIZ_DIR , 2  );
   outtextxy (   500 , 700 , "BY SHUBHAM RANA");
   //NAME
 settextstyle ( BOLD_FONT , HORIZ_DIR ,2);
          setcolor( WHITE);outtextxy( x , y , "0");
          for( int i=0 ; i<length ; i++)
          {              outtextxy( body[i].tx , body[i].ty , "0");
          }

                      setcolor( LIGHTGREEN);
                    circle( fruitx , fruity , 5);
                    setfillstyle( SOLID_FILL , LIGHTGREEN);
                    floodfill( fruitx , fruity , LIGHTGREEN);

setcolor( YELLOW);
        if (GetAsyncKeyState(  VK_UP )   )  dir = UP;
        if (GetAsyncKeyState(  VK_DOWN)  ) dir =DOWN;
        if (GetAsyncKeyState( VK_LEFT ) ) dir=LEFT;
        if (GetAsyncKeyState( VK_RIGHT ) ) dir =RIGHT;
        if( dir == UP) y-=12;
        if ( dir == DOWN) y+=12;
        if( dir== LEFT) x-=10;
        if( dir== RIGHT)  x+=10;
        checkfruit();snakebody();
        if( checkout() == 1 || checkwall() == 1)
                 {
outtextxy(  500 , 10 , "GAMEOVER  . PRESS 'E' TO EXIT  'P' TO PLAY AGAIN.");
char ch=getch();
 if( ch != 'P' || ch !='p')
  {
 break;
   }
       } // score
       if ( checkout( ) == 0 )
       {
           outtextxy(  500  ,10 , "PLAYING" );
       }

page= 1- page;
delay(30);

   }

           closegraph();

    return 0 ;
}
void checkfruit()
{
    if(   ( ( x-fruitx <10 && x-fruitx >-10)  &&  (y-fruity <10  && y-fruity >-10)  ) || ( fruitx==x && fruity==y)           )
    {
         fruitx = (rand() % 780) +201 ; fruity = ( rand() % 440) +55 ; score++ ; length++;
    }
}
void snakebody()
{
     for( int i= length-1 ; i>0 ; i--)
    {
        body[i].tx=body[i-1].tx ; body[i].ty=body[i-1].ty ;
    }
if( score>=1)   body[0] .tx=headpast.tx; body[0].ty=headpast.ty;
}

int checkout()
{
    for( int i=0 ; i< length ; i++)
    {
        if (    body[i] .tx== x && body[i].ty==y  )
        { return 1;}

    }
    return 0;
}
int checkwall()
{
// for right and left walls
if ( x -190 < 5     ||   990- x< 5)
    return 1 ;
if ( 500 - y <5   || y  - 30<5  )
  return 1;



}
