#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#define UP 72
#define RIGHT 77
#define LEFT 75
#define DOWN 80
void bilding1();
void bilding2();
void move();
void left();
void right();
void down();
void up();
void chek();
void randfood();
void keybord();
void doshman();
void doshman2();
void entekhab1();
void entekhab2();
void entekhab3();
void bazi1();
void bazi2();
void bazi3();
void doshman3();
//void savew();
int N=40,M=40;
int andazehmar=1;
int kilid;
int flag=0;
int point=0;
int helth=3;
int direction=1;
int direction2d=1;
int direction3d=1;
int fooddirection=1;
int code=1;
int code2=1;
int parcham=1;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
    int x;
    int y;
    int direction;
} deraye;

deraye body[30];
deraye head;
deraye food[2];
deraye doshman1;
deraye doshmanx2;
deraye doshmanx3;
deraye finish;
deraye divarbazi2[40];
deraye extrafood;
FILE *save;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fill()
{
    head.x=5;
    head.y=5;
    head.direction=RIGHT;
    body[0].x=4;
    body[0].y=5;
    body[1].x=3;
    body[1].y=5;
    food[0].x=11;
    food[0].y=11;
    food[1].x=16;
    food[1].y=4;
    food[2].x=21;
    food[2].y=21;
    doshman1.x=15;
    doshman1.y=15;
    doshmanx2.x=14;
    doshmanx2.y=14;
    doshmanx3.x=12;
    doshmanx3.y=12;
    finish.x=24;
    finish.y=10;
    extrafood.x=17;
    extrafood.y=17;

    int i;
    for(i=0; i<10; i++)
    {
        divarbazi2[i].x=i;
        divarbazi2[i].y=20;

    }

    for(i=10; i<20; i++)
    {
        divarbazi2[i].x=20;
        divarbazi2[i].y=i;
    }

}

/*void saver(){
save=fopen("aziz","r");
fscanf(save,"%d\n",&head.x);
fscanf(save,"%d\n",&head.y);
fscanf(save,"%d\n",&head.direction);
fscanf(save,"%d\n",&food[0].x);
fscanf(save,"%d\n",&food[0].y);
fscanf(save,"%d\n",&food[1].x);
fscanf(save,"%d\n",&food[1].y);
fscanf(save,"%d\n",&food[2].x);
fscanf(save,"%d\n",&food[2].y);

for (int t = 0 ; t<andazehmar; t++){
    fscanf(save,"%d\n",&body[t].x);
    fscanf(save,"%d\n",&body[t].y);
}
fscanf(save,"%d\n",&helth);
fscanf(save,"%d\n",&point);
fclose(save);

}*/






void bilding1()
{

    int i,j,k;
    for(i=0; i<N; i++)
    {

        for(j=0; j<M; j++)
        {

            if(i==0 && j==0 )
                printf("%c",201);
            else if(i==N-1 && j==N-1 )
                printf("%c",188);
            else if(i==N-1 && j==0 )
                printf("%c",200);
            else  if(i==0 && j==N-1 )
                printf("%c",187);

            else if( i==0 || i==N-1 )
            {
                if(i!=0 || i!=N-1)
                {
                    printf("%c",205);
                }
            }
            else if(j==0 || j==N-1 )
            {
                if( j!=0 || j!=N-1 )
                {
                    printf("%c",186);
                }
            }
            else if(i==food[0].x && j==food[0].y)
            {

                printf("%c",178);

            }
            else if(i==food[1].x && j==food[1].y)
            {
                printf("%c",178);
            }
            else if(i==food[2].x && j==food[2].y)
            {
                printf("%c",178);
            }
            else if(head.x==i && head.y==j)
            {
                printf("%c",176);


            }


            else if(i==finish.x && j==finish.y && point>=5)
            {
                printf("%c",4);
            }
            else
            {

                int h=0;
                for(k=0; k<=andazehmar; k++)
                {
                    if(i==body[k].x && j==body[k].y&&h==0)
                    {
                        printf("%c",177);
                        h=1;
                    }
                }
                if(h==0)
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n point = %d",point);
    printf("\n helth = %d",helth);
    printf("\n lenth = %d\n",andazehmar);
}

void bilding2()
{

    int i,j,k;
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            if(i==0 && j==0 )
                printf("%c",201);
            else if(i==N-1 && j==N-1 )
                printf("%c",188);
            else if(i==N-1 && j==0 )
                printf("%c",200);
            else  if(i==0 && j==N-1 )
                printf("%c",187);

            else if( i==0 || i==N-1 )
            {
                if(i!=0 || i!=N-1)
                {
                    printf("%c",205);
                }
            }
            else if(j==0 || j==N-1 )
            {
                if( j!=0 || j!=N-1 )
                {
                    printf("%c",186);
                }
            }

            else if(i==food[0].x && j==food[0].y)
            {
                printf("%c",178);
            }
            else if(i==food[1].x && j==food[1].y)
            {
                printf("%c",178);
            }
            else if(i==food[2].x && j==food[2].y)
            {
                printf("%c",178);
            }
            else if(head.x==i && head.y==j)
            {
                printf("%c",176);


            }

            else if(i==finish.x && j==finish.y && point>=4)
            {
                printf("%c",4);
            }
            else if(i==doshman1.x && j==doshman1.y)
            {
                printf("%c",2);
            }
            else
            {
                int h=0;
                for(k=0; k<20; k++)
                {
                    if(i==divarbazi2[k].x && j==divarbazi2[k].y)
                    {
                        printf("%c",206);
                        h=1;

                    }
                }

                for(k=0; k<=andazehmar; k++)
                {
                    if(i==body[k].x && j==body[k].y && h==0)
                    {
                        printf("%c",177);
                        h=1;
                    }
                }
                if(h==0 )
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n point = %d",point);
    printf("\n helth = %d\n",helth);
    printf("\n lenth = %d\n",andazehmar);

}
void bilding3()
{

    int i,j,k;
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            if(i==0 && j==0 )
            {
                printf("%c",201);
            }

            else if(i==N-1 && j==N-1 )
            {

                printf("%c",188);
            }

            else if(i==N-1 && j==0 )
            {
                printf("%c",200);

            }

            else  if(i==0 && j==N-1 )
            {
                printf("%c",187);

            }


            else if( i==0 || i==N-1 )
            {
                if(i!=0 || i!=N-1)
                {
                    printf("%c",205);
                }
            }
            else if(j==0 || j==N-1 )
            {
                if( j!=0 || j!=N-1 )
                {
                    printf("%c",186);
                }
            }
            else if(i==food[0].x && j==food[0].y)
            {
                printf("%c",178);
            }
            else if(i==food[1].x && j==food[1].y)
            {
                printf("%c",178);
            }
            else if(i==doshmanx3.x && j==doshmanx3.y)
            {
                printf("%c",2);
            }
            else if(i==doshmanx2.x && j==doshmanx2.y)
            {
                printf("%c",2);
            }

            else if(head.x==i && head.y==j)
            {
                printf("%c",176);


            }
            else if(i==extrafood.x && j==extrafood.y)
            {
                printf("%c",219);
            }

            else if(i==finish.x && j==finish.y && point>=5)
            {
                printf("%c",4);
            }
            else
            {

                int h=0;
                for(k=0; k<=andazehmar; k++)
                {
                    if(i==body[k].x && j==body[k].y)
                    {
                        printf("%c",177);
                        h=1;
                    }
                }
                if(h==0)
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n point = %d",point);
    printf("\n helth = %d\n",helth);
    printf("\n lenth = %d\n",andazehmar);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void right()
{
    head.y++;

}
void left()
{

    head.y--;

}
void up()
{
    head.x--;

}
void down()
{
    head.x++;

}

void move()
{


    if(-kbhit())
    {

        char N=-getch();
        N=getch();
        kilid=N;


        if((kilid==UP && head.direction!=UP && head.direction!=DOWN) ||
                (kilid==DOWN && head.direction!=UP && head.direction!=DOWN) ||
                (kilid==LEFT && head.direction!=LEFT&& head.direction!=RIGHT) ||
                (kilid==RIGHT && head.direction!=LEFT && head.direction!=RIGHT ) )
        {
            if(kilid==UP)
            {
                head.x--;
                head.direction=UP;
            }
            else if(kilid==LEFT)
            {
                head.y--;
                head.direction=LEFT;

            }
            else if(kilid==RIGHT)
            {
                head.y++;
                head.direction=RIGHT;
            }
            else if(kilid==DOWN)
            {
                head.x++;
                head.direction=DOWN;
            }

        }
        else
        {
            move();
        }
    }
    else
    {
        if(head.direction==UP )
        {
            up();

        }
        else if(head.direction==DOWN   )
        {
            down();

        }
        else if(head.direction==LEFT )
        {
            left();
        }
        else if (head.direction==RIGHT  )
        {
            right();

        }
    }
}



void aziz()
{
    int x1=body[0].x;
    int y1=body[0].y;
    int x2, y2;
    body[0].x=head.x;
    body[0].y=head.y;
    int i;
    for(i=1; i<=andazehmar; i++)
    {
        x2=body[i].x;
        y2=body[i].y;
        body[i].x=x1;
        body[i].y=y1;
        x1=x2;
        y1=y2;
    }

}

void savew (){
save=fopen("aziz","w");
fprintf(save,"%d\n",head.x);
fprintf(save,"%d\n",head.y);
fprintf(save,"%d\n",head.direction);
fprintf(save,"%d\n",food[0].x);
fprintf(save,"%d\n",food[0].y);
fprintf(save,"%d\n",food[1].x);
fprintf(save,"%d\n",food[1].y);
fprintf(save,"%d\n",food[2].x);
fprintf(save,"%d\n",food[2].y);

for (int t = 0 ; t<andazehmar; t++){
    fprintf(save,"%d\n",body[t].x);
    fprintf(save,"%d\n",body[t].y);
}
fprintf(save,"%d\n",helth);
fprintf(save,"%d\n",point);
fclose(save);

}

void randfood(int c)
{
    int i;
    food[c].x=rand()%N+1;
    food[c].y=rand()%M+1;
    if(food[c].x==0 || food[c].y==0|| food[c].x ==N || food[c].y==M )
    {
        randfood(c);
    }
    if(c==0)
    {
        for(i=0; i<20; i++)
        {
            if(food[c].x==food[c+1].x && food[c].y==food[c+1].y ||
                    food[c].x==food[c+2].x && food[c].y==food[c+2].y
                    ||(food[c].x==divarbazi2[i].x && food[c].y==divarbazi2[i].y))
            {
                randfood(c);
            }
        }
    }
    if(c==1)
    {
        for(i=0; i<20; i++)
        {
            if(food[c].x==food[c+1].x && food[c].y==food[c+1].y ||
                    food[c].x==food[c-1].x && food[c].y==food[c-1].y
                    ||(food[c].x==divarbazi2[i].x && food[c].y== divarbazi2[i].y))
            {
                randfood(c);
            }
        }
    }
    if(c==2)
    {
        for(i=0; i<20; i++)
        {
            if(food[c].x==food[c-1].x && food[c].y==food[c-1].y ||
                    food[c].x==food[c-2].x && food[c].y==food[c-2].y
                    ||(food[c].x==divarbazi2[i].x && food[c].y== divarbazi2[i].y))
            {
                randfood(c);
            }
        }
    }
}


void randextafood()
{
    int i;
    extrafood.x=rand()%N+1;
    extrafood.y=rand()%M+1;
    if(extrafood.x==0 || extrafood.y==0|| extrafood.x ==N || extrafood.y==M )
    {
        randextafood();
    }
}



void action1()
{
    int i;
    if(head.x<=0 || head.y<=0 || head.x>N-2 || head.y>M-2)
    {

        flag=1;
        helth--;
        keybord1();

    }

    for(i=0; i<andazehmar; i++)
    {
        if  (head.x== body[i].x&& head.y == body[i].y)
        {
            flag=1;
            helth--;
            keybord1();

        }
    }
    for(i=0; i<andazehmar; i++)
    {
        if  (doshman1.x == body[i].x && doshman1.y == body[i].y)
        {
            direction=-direction;

        }
    }

    if   (head.x==doshman1.x && head.y== doshman1.y)
    {
        flag=1;
        helth--;
        keybord1();
    }

    for(i=0; i<3; i++)
    {
        if  (head.x==food[i].x && head.y==food[i].y)
        {
            point++;
            andazehmar++;

            randfood(i);
        }
        if (head.x==finish.x &&  head.y==finish.y)
        {
            andazehmar=-1;

        }
        else ;
    }
}


void action3()
{
    int i;
    if(head.x<=0 || head.y<=0 || head.x>N-2 || head.y>M-2)
    {

        flag=1;
        helth--;
        keybord3();

    }
    if(head.x== finish.x && head.y== finish.y)
    {
        flag=1;
        helth=0;

    }

    for(i=0; i<andazehmar; i++)
    {
        if(head.x== body[i].x&& head.y == body[i].y)
        {
            flag=1;
            helth--;
            keybord3();

        }
    }
    if(head.x== doshmanx3.x&& doshmanx3.y==head.y)
        {
            flag=1;
            helth--;
            keybord3();

        }
        for(i=0; i<andazehmar; i++)
    {
        if  (doshmanx3.x == body[i].x && doshmanx3.y == body[i].y)
        {
            direction3d=-direction3d;

        }
    }

    for(i=0; i<andazehmar; i++)
    {
        if(extrafood.x == body[i].x && extrafood.y == body[i].y)
        {
            fooddirection=-fooddirection;

        }
    }
    for(i=0; i<andazehmar; i++)
    {
        if(doshmanx2.x == body[i].x && doshmanx2.y == body[i].y)
        {
            direction2d=-direction2d;

        }
    }

    for(i=0; i<andazehmar; i++)
    {
        if(doshmanx3.x == body[i].x && doshmanx3.y == body[i].y)
        {
            direction3d=-direction3d;

        }
    }

    for(i=0; i<3; i++)
    {
        if(head.x==food[i].x && head.y==food[i].y)
        {
            point++;
            andazehmar++;

            randfood(i);
        }
    }
    if(head.x==extrafood.x && head.y == extrafood.y)
    {
        point++;
        andazehmar++;
        randextafood();
    }
}


void action2()
{
    int i;
    if(head.x<=0 || head.y<=0 || head.x>N-2 || head.y>M-2)
    {

        flag=1;
        helth--;
        keybord2();

    }

    for(i=0; i<andazehmar; i++)
    {
        if(head.x== body[i].x&& head.y == body[i].y)
        {
            flag=1;
            helth--;
            keybord2();

        }
    }
    for(i=0; i<andazehmar; i++)
    {
        if(doshman1.x == body[i].x && doshman1.y == body[i].y)
        {
            direction=-direction;

        }
    }
    for(i=0; i<20; i++)
    {
        if(head.x== divarbazi2[i].x && head.y == divarbazi2[i].y)
        {
            flag=1;
            helth--;
            keybord2();

        }
    }
    if(head.x==doshman1.x && head.y== doshman1.y)
    {
        flag=1;
        helth--;
        keybord2();
    }
    if (head.x==finish.x &&  head.y==finish.y)
        {
            andazehmar=-1;

        }


    for(i=0; i<3; i++)
    {
        if(head.x==food[i].x && head.y==food[i].y)
        {
            point++;
            andazehmar++;

            randfood(i);
        }
    }

}



void chekf()
{
    if(point==30)
    {
        flag=1;
    }

}

void keybord1()
{
    while(-kbhit())
    {

        char N=-getch();
        N=getch();
        kilid=N;
    }


    if((kilid==UP && head.direction!=UP && head.direction!=DOWN) ||
            (kilid==DOWN && head.direction!=UP && head.direction!=DOWN) ||
            (kilid==LEFT && head.direction!=LEFT&& head.direction!=RIGHT) ||
            (kilid==RIGHT && head.direction!=LEFT && head.direction!=RIGHT ) )
    {
        if(kilid==UP )
        {

            if(head.y==0)
            {
                head.y++;//rast
                head.x--;//bala
            }
            else
            {
                head.y--;//chap
                head.x--;//bala
            }
            head.direction=UP;
            bazi1();
        }
        if(kilid==LEFT)
        {

            if(head.x==0)
            {
                head.x++;
                head.y--;
            }
            else
            {
                head.x--;
                head.y--;
            }
            head.direction=LEFT;
            bazi1();
        }
        else if(kilid==RIGHT)
        {

            if(head.x==0)
            {
                head.x++;//paiin
                head.y++;//rast
            }
            else
            {
                head.x--;//bala
                head.y++;//rast
            }
            head.direction=RIGHT;
            bazi1();
        }
        else if(kilid==DOWN)
        {

            if(head.y==0)
            {
                head.y++;//rast
                head.x++;//paiin
            }
            else
            {
                head.y--;//chap
                head.x++;//paiin
            }

            head.direction=DOWN;
            bazi1();
        }

    }
    else
    {
        keybord1();
    }
}


void keybord2()
{
    char N;
    while(-kbhit())


        N=-getch();
    N=getch();
    kilid=N;
    {

        if((kilid==UP && head.direction!=UP && head.direction!=DOWN) ||
                (kilid==DOWN && head.direction!=UP && head.direction!=DOWN) ||
                (kilid==LEFT && head.direction!=LEFT&& head.direction!=RIGHT) ||
                (kilid==RIGHT && head.direction!=LEFT && head.direction!=RIGHT ) )
        {
            if(kilid==UP )
            {

                if(head.y==0)
                {
                    head.y++;//rast
                    head.x--;//bala


                }
                else
                {
                    head.y--;//chap
                    head.x--;//bala
                }
                head.direction=UP;
                bazi2();
            }
            if(kilid==LEFT)
            {

                if(head.x==0)
                {
                    head.x++;
                    head.y--;
                }
                else
                {
                    head.x--;
                    head.y--;
                }
                head.direction=LEFT;
                bazi2();
            }
            else if(kilid==RIGHT)
            {

                if(head.x==0)
                {
                    head.x++;//paiin
                    head.y++;//rast
                }
                else
                {
                    head.x--;//bala
                    head.y++;//rast
                }
                head.direction=RIGHT;
                bazi2();
            }
            else if(kilid==DOWN)
            {

                if(head.y==0)
                {
                    head.y++;//rast
                    head.x++;//paiin
                }
                else
                {
                    head.y--;//chap
                    head.x++;//paiin
                }

                head.direction=DOWN;
                bazi2();
            }

        }
        else
        {
            keybord2();
        }
    }
}


void keybord3()
{
    while(-kbhit())

    {

        char N=-getch();
        N=getch();
        kilid=N;
    }


    if((kilid==UP && head.direction!=UP && head.direction!=DOWN) ||
            (kilid==DOWN && head.direction!=UP && head.direction!=DOWN) ||
            (kilid==LEFT && head.direction!=LEFT&& head.direction!=RIGHT) ||
            (kilid==RIGHT && head.direction!=LEFT && head.direction!=RIGHT ) )
    {
        if(kilid==UP )
        {

            if(head.y==0)
            {
                head.y++;//right
                head.x--;//up
            }
            else
            {
                head.y--;//left
                head.x--;//right
            }
            head.direction=UP;
            bazi3();
        }
        if(kilid==LEFT)
        {

            if(head.x==0)
            {
                head.x++;
                head.y--;
            }
            else
            {
                head.x--;
                head.y--;
            }
            head.direction=LEFT;
            bazi3();
        }
        else if(kilid==RIGHT)
        {

            if(head.x==0)
            {
                head.x++;//down
                head.y++;//right
            }
            else
            {
                head.x--;//up
                head.y++;//right
            }
            head.direction=RIGHT;
            bazi3();
        }
        else if(kilid==DOWN)
        {

            if(head.y==0)
            {
                head.y++;//right
                head.x++;//down
            }
            else
            {
                head.y--;//left
                head.x++;//down
            }

            head.direction=DOWN;
            bazi3();
        }

    }
    else
    {
        keybord3();
    }
}
void doshman()
{
    if(doshman1.x==1)
        direction=1;
    if(doshman1.x==N-2)
        direction=-1;
    doshman1.x+=direction;

}
void doshman2()
{
    if(doshmanx2.x==1)
        direction=1;
    if(doshmanx2.x==N-2)
        direction=-1;
    doshmanx2.x+=direction;

}
void doshman3()
{
    if(doshmanx3.y==1)
        direction3d=1;
    if(doshmanx3.y==N-2)
        direction3d=-1;
    doshmanx3.y+=direction3d;

}
void Xextrafood()
{
    if(extrafood.y==1)
        fooddirection=1;
    if(extrafood.y==N-2)
        fooddirection=-1;
    extrafood.y+=fooddirection;
}



void bazi1()
{
    while(flag!=1)
    {
        bilding1();
        aziz();
        doshman();
        move();
        action1();
        chekf();
        Sleep(70);
        system("cls");
    }
    if(helth!=0)
    {
        bilding2();
        flag=0;
        bazi1();
    }

}


void bazi2()
{
    while(flag!=1)
    {
        bilding2();
        aziz();
        move();
        doshman();
        action2();
        chekf();
        Sleep(70);
        system("cls");
    }
    if(helth!=0)
    {

        flag=0;
        bazi2();
    }

}

void bazi3()
{
    while(flag!=1)
    {
        bilding3();
        doshman2();
        doshman3();
        aziz();
        move();
        Xextrafood();
        action3();
        chekf();
        Sleep(70);
        system("cls");
    }
    if(helth!=0)
    {
        flag=0;
        bazi3();
    }

}

void start()
{
    printf("\n start");
    getch();
}

void entekhab1()
{
    system("cls");
    printf("\n >> level 1\n   level 2\n   level 3\n");
    code=1;
}

void entekhab2()
{
    system("cls");
    printf("\n   level 1\n >> level 2\n   level 3\n");
    code=2;
}

void entekhab3()
{
    system("cls");
    printf("\n   level 1\n   level 2\n >> level 3\n");
    code=3;
}



void enter()
{

    if(-kbhit())
    {
        char N=getch();
        N=getch();

        if(N==RIGHT)
        {
            if(code==1)
            {
                bazi1();
                code2=2;
            }
            else if(code==2)
            {
                bazi2();
                code2=2;
            }
            else if(code==3)
            {
                bazi3();
                code2=2;
            }
        }
        else if(N==DOWN)
        {
            if(code==3)
            {
                entekhab1();
            }
            else
                code=code+1;
        }
        else if(N==UP)
        {
            if(code==1)
            {
                entekhab3();
            }
            else
                code=code-1;
        }
        else
        {
            enter();
        }
    }
    if(code==1 && code2==1)
    {
       entekhab1();
    }
    if(code==2 && code2==1)
    {
        entekhab2();
    }
    if(code==3 && code2==1)
    {
        entekhab3();
    }
}



int main()
{

    srand(time(NULL));
    fill();
    start();
    while(1)
    {
     if(time(NULL)%10000==0){
        //saver();
     }

        enter();

    }

    if(point>=3)
        printf("\t\t finish");
    else
        printf("\n\n\n\n\n\t\t gameover\n\n\n\n\n");

    return 0;
}


