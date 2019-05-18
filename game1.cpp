#include <dos.h>
#include <conio.h>
#include <windows.h>
#include <graphics.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include<Windows.h>
#include<MMSystem.h>


using namespace std;
void Check();
void Highe();
void HIGH();
void Game();
void tail_check();
void choice_level();
void extream_level();
void select_level();
void instruction1();
void instruction2();
void instruction3();
void check_finish();


void GAME();
void CHECK();
void mate();
void Dead();
void infinitylevel();
void help();
void check_collision();
void game();
void check();
void Main_Menu();
void info();
void speed(int);
void lebel2();
void lebel1();
void lebel5();
void lebel6();
void lebel4();
void lebel3();
void lebel7();
void dead();
void level();
void high();
int cursor_y = 130;
char ch;
long long int snake_x[700],snake_y[700],SCore,HighScore,snake_size = 5,score,highscore,Score,Highscore,l;
int spd=103;
int life=0;
bool checkdied = false,BONUS = false;
main()
{

    int gdirect = DETECT,gmode; /* request autodetection */
    initgraph(&gdirect,&gmode,""); /* initialize graphics and local variables */
    initwindow(1250,680,"first game");

    while(1)
    {

        setcolor(RED);
        settextstyle(3,0,8);

        outtextxy(140,30," Snake ");

        setcolor(5);
        settextstyle(3,0,9); /*this part prints menu again but inside while loop,because other functions will return here*/
        outtextxy(220,130,"Main Menu");
        outtextxy(220,250,"Information ");
        outtextxy(220,385,"Exit ");
        if(kbhit)
        {
            ch = getch();
            setcolor(BLACK);
            outtextxy(160,cursor_y,">");
            if(ch == 13)
            {
                if(cursor_y==370) exit(0);
                else if(cursor_y==250) info();
                else if(cursor_y==130)Main_Menu();
            }
        }

        setcolor(WHITE);
        if(ch==80)
        {
            cursor_y+=120;
            if(cursor_y > 386)
            {
                cursor_y=130;
            }
        }
        if(ch==72)
        {
            cursor_y-=120;
            if(cursor_y < 130)
            {
                cursor_y=386;
            }
        }
        outtextxy(160,cursor_y,">");

    }
    clearviewport();
}
void Main_Menu()
{cleardevice();
    while(1)
    {

        clearviewport();
        setcolor(WHITE);
        settextstyle(5,0,9);
        outtextxy(300,30," Snake ");
        setcolor(BLUE);
        settextstyle(3,0,4);
        outtextxy(300,190,"exit");
        outtextxy(300,130,"go to level");
        outtextxy(300,160,"help");

        outtextxy(270,cursor_y,">");
        setcolor(WHITE);
        settextstyle(3,0,3);
        outtextxy(300,280,"<<<Please go to Level First then choose >>>");

        if(kbhit)
        {
            ch = getch();
            setcolor(RED);
            outtextxy(130,cursor_y,">");
            if(ch == 13)
            {
                if(cursor_y==190) exit(0);
                else if(cursor_y==130)  select_level();


                else if(cursor_y==160)help();

            }
        }

        if(ch==80)
        {
            cursor_y+=30;
            if(cursor_y > 190)
            {
                cursor_y=130;
            }
        }
        if(ch==72)
        {
            cursor_y-=30;
            if(cursor_y < 130)
            {
                cursor_y=190;
            }
        }
        outtextxy(120,cursor_y,">");
    }
    clearviewport();


}

void info()
{
    clearviewport();
    setcolor(LIGHTBLUE);
    settextstyle(6,0,4);
    outtextxy(300,200,"Devlopers: ");
    outtextxy(160,300,"Mahfuzul Islam Shimul-2017831055");
    outtextxy(200,360,"MD.Hasan Ali-2017831048");

    ch=getch();
    clearviewport();

}

void select_level()
{
    while(1)
    {
        clearviewport();

        setcolor(YELLOW);
        settextstyle(3,0,3);
        outtextxy(300,130,"choice level");
        outtextxy(300,160,"infinity level");
        outtextxy(300,190,"extream level");
        outtextxy(300,220,"back  ");
        outtextxy(300,250,"exit");
        outtextxy(280,cursor_y,">");

        if(kbhit)
        {
            ch = getch();
            setcolor(BLACK);
            outtextxy(280,cursor_y,">");
            if(ch == 13)
            {

                if(cursor_y==160)infinitylevel();
                else if(cursor_y==220)Main_Menu();
                else if(cursor_y==130) choice_level();
                else if(cursor_y==190) extream_level();
                else if(cursor_y==250)exit(0);
            }
        }
        setcolor(WHITE);
        if(ch==80)
        {
            cursor_y+=30;
            if(cursor_y > 250)
            {
                cursor_y=130;
            }
        }
        if(ch==72)
        {
            cursor_y-=30;
            if(cursor_y < 130)
            {
                cursor_y=250;
            }
        }
        outtextxy(280,cursor_y,">");
    }
}
void help()
{
    clearviewport();

    setcolor(WHITE);
    outtextxy(100,300,"Move the snake using the Arrow keys.");
    outtextxy(100,330,"Press 'alt' to Pause screen");
    outtextxy(100,360,"you will get game instruction in that level page ");
    char ch = getch();
    clearviewport();
    return;
}
void choice_level()
{

    while(1)
    {
        clearviewport();
        setcolor(BLUE);
        settextstyle(3,0,3);
        outtextxy(200,130,"start");
        outtextxy(200,250,"main menu");
        outtextxy(200,160,"select level");
        outtextxy(200,190,"highscore");
        outtextxy(200,220,"instruction");

        outtextxy(160,cursor_y,">");
        setcolor(WHITE);
        settextstyle(3,0,3);
        outtextxy(200,280,"<<<Please Select Level First>>>");

        if(kbhit)
        {
            ch = getch();
            setcolor(BLACK);
            outtextxy(160,cursor_y,">");
            if(ch == 13)
            {
                if(cursor_y==250) Main_Menu();
                else if(cursor_y==160) level();
                //else if(cursor_y==100)Main_Menu();
                else if(cursor_y==130) game();
                else if(cursor_y==190) high();
                else if(cursor_y==220) instruction1();
            }
        }
        setcolor(WHITE);
        if(ch==80)
        {
            cursor_y+=30;
            if(cursor_y > 250)
            {
                cursor_y=130;
            }
        }
        if(ch==72)
        {
            cursor_y-=30;
            if(cursor_y < 130)
            {
                cursor_y=250;
            }
        }
        outtextxy(160,cursor_y,">");
    }
}
void instruction1()
{
    setcolor(WHITE);
    clearviewport();
    outtextxy(360,200,"this is a level choice game .");
    outtextxy(220,220,"there is a wall if snake head touch the wall game will over.");
    outtextxy(130,240,"if snake size greater than 17 then the snake can bite his tail and tail size go its first position and game will continue .");
    char ch = getch();
    clearviewport();
    return;
}
void extream_level()
{
    while(1)
    {
        clearviewport();

        setcolor(MAGENTA);
        settextstyle(3,0,3);
        outtextxy(200,130,"start");
        outtextxy(200,190,"highscore");
        outtextxy(200,160,"instruction");
        outtextxy(200,220,"main menu");
        outtextxy(200,250,"exit");
        outtextxy(180,cursor_y,">");

        if(kbhit)
        {
            ch = getch();
            setcolor(BLACK);
            outtextxy(130,cursor_y,">");
            if(ch == 13)
            {
                if(cursor_y==250) exit(0);
                else if(cursor_y==160) instruction3();
                else if(cursor_y==130) GAME();
                else if(cursor_y==190) HIGH();
                else if(cursor_y==220) Main_Menu();
            }
        }

        if(ch==80)
        {
            cursor_y+=30;
            if(cursor_y > 250)
            {
                cursor_y=130;
            }
        }
        if(ch==72)
        {
            cursor_y-=30;
            if(cursor_y < 130)
            {
                cursor_y=250;
            }
        }
        outtextxy(120,cursor_y,">");
    }
    clearviewport();


}
void instruction3()
{
    setcolor(WHITE);
    clearviewport();
    outtextxy(360,200,"the snake speed increase automatically .");
    outtextxy(220,220,"there is no wall but have obstacles if snake touch them then game will finish.");

    char ch = getch();
    clearviewport();
    return;
}

void GAME()
{
    clearviewport();
    freopen("GaData.dat","r",stdin);
    cin >> HighScore;

    cleardevice();
    char ch;
    string key = "right";
    int maxx = getmaxx()-350;
    int maxy = getmaxy()-50;
    int x = 13,y = 13;

    int food_x = rand()%maxx,food_y = rand()%maxy;
    int temp;
    temp = food_x%13;
    food_x-=temp;
    temp = food_y%13;
    food_y-=temp;

    int i = 0;
    int bonus = 500;


       // setbkcolor(WHITE);
    while(true)
    {
 clearviewport();
        if((SCore%5==1)||(SCore%6==4))
        {
            setcolor(RED);
            setfillstyle(1,4);
            circle(400,50,13);
            floodfill(400,50,RED);
            circle(200,250,13);
            floodfill(200,250,RED);
            circle(600,250,13);
            floodfill(600,250,RED);
            circle(400,250,13);
            floodfill(400,250,RED);
            circle(490,550,13);//////////////
            floodfill(495,540,RED);
            rectangle(100,100,115,580);
            floodfill(109,109,RED);
            rectangle(150,450,650,465);
            floodfill(190,459,RED);
            rectangle(800,150,815,450);
            floodfill(810,199,RED);


            if(snake_x[0]>=385&&snake_x[0]<=417&&snake_y[0]>=35&&snake_y[0]<=65)
                check_finish();
            if(snake_x[0]>=385&&snake_x[0]<=417&&snake_y[0]>=235&&snake_y[0]<=265)
                check_finish();
            if(snake_x[0]>=480&&snake_x[0]<=510&&snake_y[0]>=535&&snake_y[0]<=565)/////
                check_finish();
            if(snake_x[0]>=185&&snake_x[0]<=217&&snake_y[0]>=235&&snake_y[0]<=265)
                check_finish();
            if(snake_x[0]>=585&&snake_x[0]<=617&&snake_y[0]>=235&&snake_y[0]<=265)
                check_finish();
            if(snake_x[0]>=93&&snake_x[0]<=124&&snake_y[0]>=93&&snake_y[0]<=588)
                check_finish();
            if(snake_x[0]>=143&&snake_x[0]<=657&&snake_y[0]>=443&&snake_y[0]<=472)
                check_finish();
            if(snake_x[0]>=793&&snake_x[0]<=824&&snake_y[0]>=143&&snake_y[0]<=458)
                check_finish();
        }

        if(SCore >0 && SCore%5==4) BONUS = true;
        else
        {
            bonus = 500;
            BONUS = false;
        }
        if(!BONUS || bonus == 0)
        {
            setcolor(BLACK);
            setcolor(MAGENTA);
            setfillstyle(SOLID_FILL,MAGENTA);
            circle(food_x,food_y,6); //x position,y position,size
            floodfill(food_x,food_y,MAGENTA);

        }
        else
        {
            setcolor(BLUE);
            setfillstyle(SOLID_FILL,BLUE);
            circle(food_x,food_y,8);
            floodfill(food_x,food_y,BLUE);

            char spp[1000];
            setcolor(BLACK);
            sprintf(spp,"Hurry!! %d",bonus);
            outtextxy(250,10,"Hurry!! 888");
            setcolor(MAGENTA);
            outtextxy(250,10,spp);

        }
        if(kbhit())
        {
            ch = getch();
            if(ch == 0) ch = getch();
            if(ch == 72 && key != "down" ) key = "up";
            if(ch == 80 && key != "up") key = "down";
            if(ch == 75 && key != "right") key = "left";
            if(ch == 77 && key != "left") key = "right";
            if(ch == 27)
            {
                cleardevice();
                return;
            }

        }

        if(i < 5)
        {
            snake_x[i] = x-240;
            snake_y[i] = y-285;
            i++;
        }
        else
        {
            for(int _size = snake_size-2; _size >= 0; _size--)
            {
                snake_x[_size+1] = snake_x[_size];
                snake_y[_size+1] = snake_y[_size];
            }
            snake_x[0] = x;
            snake_y[0] = y;

            setcolor(RED);
            circle(snake_x[0],snake_y[0],8);
            setfillstyle(SOLID_FILL,WHITE);
            floodfill(snake_x[0],snake_y[0],RED);

            setcolor(GREEN);
            for(int _size = 1; _size < snake_size; _size++)
            {
                circle(snake_x[_size],snake_y[_size],7);
                setfillstyle(SOLID_FILL,GREEN);
                floodfill(snake_x[_size],snake_y[_size],GREEN);
            }

            settextstyle(3,0,5);
            char ara[100];
            sprintf(ara,"Score: %d",SCore);
            setcolor(WHITE);
            outtextxy(940,70,ara);
            settextstyle(7,0,4);
            sprintf(ara,"Bestscore: %d",HighScore);
            setcolor(WHITE);
            outtextxy(915,200,ara);

            settextstyle(8,0,5);
            sprintf(ara,"life no %d",life);
            setcolor(WHITE);
            outtextxy(915,400,ara);
            setcolor(RED);
//setlinestyle(3,0,2);
            line(900,0,900,640);
            line(0,0,900,0);
            line(5,0,0,640);
            line(0,640,900,640);

            if(Score>300&&Score<570)
                lebel4();
            else if(Score>640&&Score<870)
                lebel5();
            else if(Score>1000&&Score<1300)
                lebel6();
            else if(Score>1500)
                lebel7();
            else
                delay(50);
        }
        if(x == food_x && y== food_y)
        {
            snake_size++;
            SCore++;
            /* Snake eats food*/
            if(SCore%5==0 && SCore>0)SCore+=bonus;

            food_x = rand()%maxx,food_y = rand()%maxy;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;
            if(food_x>=90&&food_x<=120&&food_y>=95&&food_y<=585)
            {
                food_x-=13;
                food_y-=13;
            }
            if(food_x>=795&&food_x<=820&&food_y>=145&&food_y<=455)
            {
                food_x+=13;
                food_y+=13;
            }
            if(food_x>=145&&food_x<=655&&food_y>=445&&food_y<=470)
            {
                food_x+=13;
                food_y+=13;
            }

            if(food_x < 5 || food_x > maxx - 5 || food_y < 5 || food_y > maxy - 5)
            {
                while(food_x < 5 || food_x > maxx - 5 || food_y < 5 || food_y > maxy - 5)
                {
                    food_x = rand()%maxx,food_y = rand()%maxy;
                    temp = food_x%13;
                    food_x-=temp;
                    temp = food_y%13;
                    food_y-=temp;
                }
            }
        }
        if(key == "right") x = x+13;
        if(x > maxx) x =0;
        if(key == "left") x = x-13;
        if(x < 0) x = maxx-(maxx%13);
        if(key == "up") y = y-13;
        if(y > maxy) y = 0;
        if(key == "down") y = y+13;
        if(y < 0) y = maxy-(maxy%13);
        CHECK();
        if(checkdied)
        {
            dead();
            return;
        }

        if(BONUS)
        {
            if(bonus>0)
                bonus-=10;
        }
        setcolor(WHITE);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(snake_x[0],snake_y[0],WHITE);

        for(int _size = 1; _size < snake_size; _size++)
        {
            circle(snake_x[_size],snake_y[_size],7);
            setfillstyle(SOLID_FILL,WHITE);
            floodfill(snake_x[_size],snake_y[_size],WHITE);
        }

    }
}

void CHECK()//extream level
{
    freopen("GaData.dat","w",stdout);
    if(HighScore < SCore)
        cout << SCore << endl;
    else cout << HighScore << endl;
    for(int i = 1; i < snake_size; i++)
    {
        if(snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
            check_finish();
    }
}



void check_finish()//extream level
{
    delay(1000);
    setcolor(RED);
    for(int i = 0; i < snake_size; i++)
    {
        circle(snake_x[i],snake_y[i],7);
        setfillstyle(SOLID_FILL,RED);
        floodfill(snake_x[i],snake_y[i],RED);
        settextstyle(3,0,5);
        outtextxy(300,200,"game over");
        delay(450);
        while(1)
        {
            clearviewport();
            snake_x[0]=30,snake_y[0]=330;
            life++;
            settextstyle(6,0,8);
            setcolor(BLUE);
            settextstyle(7,0,6);
            outtextxy(300,130,"play again");
            outtextxy(300,190,"Main Menu");
            outtextxy(300,250,"Exit");
            setcolor(MAGENTA);
            outtextxy(215,cursor_y,">");
            if(kbhit)
            {
                ch = getch();
                setcolor(BLACK);
                outtextxy(160,cursor_y,">");
                if(ch == 13)
                {
                    if(cursor_y==250) exit(0);
                    else if(cursor_y==130) GAME();
                    else if(cursor_y==190) Main_Menu();

                }
            }
            setcolor(MAGENTA);
            if(ch==80)
            {
                cursor_y+=60;
                if(cursor_y > 250)
                {
                    cursor_y=130;
                }
            }
            if(ch==72)
            {
                cursor_y-=60;
                if(cursor_y < 130)
                {
                    cursor_y=250;
                }
            }
            outtextxy(215,cursor_y,">");

        }
        clearviewport();
    }
    while(1)
    {
        if(kbhit())
        {
            char ch = getch();
            if(ch == 13)
            {
                checkdied = true;
                return;
            }
        }
    }
}


void HIGH()//extream level
{
    clearviewport();
    freopen("GaData.dat","r",stdin);
    cin >> HighScore;
    char a[100];
    sprintf(a,"HighScore: %d",HighScore);
    setcolor(WHITE);
    outtextxy(200,350,a);
    char ch = getch();
    clearviewport();
}



void game()
{
    clearviewport();
    freopen("GameData.dat","r",stdin);
    cin >> highscore;

    cleardevice();

    string key = "right";
    int maxx = getmaxx()-350;
    int maxy = getmaxy()-50;
    int x = 130,y = 130;

    int food_x = rand()%maxx-8,food_y = rand()%maxy-8;
    int temp;
    temp = food_x%13;
    food_x-=temp;
    temp = food_y%13;
    food_y-=temp;
    int i = 0;

    int bonus = 500;
    clearviewport();
    while(true)
    {



       setcolor(RED);
        rectangle(0,0,900,642);
        setfillstyle(1,CYAN);
        floodfill(50,50,RED);
        if(score >0 && score%5==4)
        {
            BONUS = true;
        }
        else
        {
            bonus = 500;
            BONUS = false;
        }

        if(!BONUS || bonus == 0)
        {
            setcolor(CYAN);
            //outtextxy(250,10,"Hurry!! 888");
            setcolor(MAGENTA);
            setfillstyle(SOLID_FILL,MAGENTA);
            circle(food_x,food_y,7); //x position,y position,size
            floodfill(food_x,food_y,MAGENTA);

        }
        else
        {
            setcolor(BLUE);
            setfillstyle(SOLID_FILL,BLUE);
            circle(food_x,food_y,8);
            floodfill(food_x,food_y,BLUE);

            char spp[1000];
            setcolor(CYAN);
            sprintf(spp,"Hurry!! %d",bonus);
            outtextxy(250,10,"Hurry!! 888");
            setcolor(MAGENTA);
            outtextxy(250,10,spp);

        }
        if(kbhit())
        {
            ch = getch();
            if(ch == 0) ch = getch();
            if(ch == 72 && key != "down" ) key = "up";//h
            if(ch == 80 && key != "up") key = "down";  //shift + p
            if(ch == 75 && key != "right") key = "left";//k
            if(ch == 77 && key != "left") key = "right";//m

            if(ch == 27)
            {
                cleardevice();
                return;
            }

            if(i < 5)
            {
                snake_x[i] = x-240;
                snake_y[i] = y-285;
                i++;
            }

            else
            {
                for(int _size = snake_size-2; _size >= 0; _size--)
                {
                    snake_x[_size+1] = snake_x[_size];
                    snake_y[_size+1] = snake_y[_size];
                }
                snake_x[0] = x;
                snake_y[0] = y;

                setcolor(RED);
                circle(snake_x[0],snake_y[0],8);

                setfillstyle(SOLID_FILL,RED);
                floodfill(snake_x[0],snake_y[0],RED);

                setcolor(GREEN);
                for(int _size = 1; _size < snake_size; _size++)
                {
                    circle(snake_x[_size],snake_y[_size],7);
                    setfillstyle(SOLID_FILL,YELLOW);
                    floodfill(snake_x[_size],snake_y[_size],GREEN);
                }
                settextstyle(3,0,5);
                char ara[100];
                sprintf(ara,"Score: %d",score);
                setcolor(WHITE);
                outtextxy(940,70,ara);
                settextstyle(7,0,4);
                sprintf(ara,"Bestscore: %d",highscore);
                setcolor(WHITE);
                outtextxy(915,200,ara);

                settextstyle(8,0,5);
                sprintf(ara,"snake size %d",snake_size);
                setcolor(WHITE);
                outtextxy(915,400,ara);


                delay(spd);
            }

            if(x == food_x && y== food_y)

                snake_size++;
            score++;
            Beep(5000,50);   /* Snake eats food*/
            if(score%5==0 && score>0)score+=bonus;

            food_x = rand()%maxx,food_y = rand()%maxy;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;

            if(food_x < 5 || food_x > maxx - 5 || food_y < 5 || food_y > maxy - 5)
            {
                while(food_x < 5 || food_x > maxx - 5 || food_y < 5 || food_y > maxy - 5)
                {
                    food_x = rand()%maxx,food_y = rand()%maxy;
                    temp = food_x%13;
                    food_x-=temp;
                    temp = food_y%13;
                    food_y-=temp;
                }
            }
        }
        if(key == "right") x = x+13;
        if(x > maxx) x =0;
        if(key == "left") x = x-13;
        if(x < 0) x = maxx-(maxx%13);
        if(key == "up") y = y-13;
        if(y > maxy) y = 0;
        if(key == "down") y = y+13;
        if(y < 0) y = maxy-(maxy%13);


        if(BONUS)
        {
            if(bonus>0)
                bonus-=10;
        }
        setcolor(BLACK);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(snake_x[0],snake_y[0],BLACK);

        for(int _size = 1; _size < snake_size; _size++)
        {
            circle(snake_x[_size],snake_y[_size],6);
            setfillstyle(SOLID_FILL,WHITE);
            floodfill(snake_x[_size],snake_y[_size],BLACK);
        }
        check();
        if(snake_size<17)
        {
            tail_check();
        }
        if(snake_size>17)
        {
            mate();
        }


        if(checkdied)
        {
            dead();
            return;
        }
    }
}
void tail_check()
{
    for(int i = 1; i < snake_size; i++)
    {
        if(snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
        {
            delay(1000);
            setcolor(WHITE);
            for(int i = 0; i < snake_size; i++)
            {
                circle(snake_x[i],snake_y[i],5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(snake_x[i],snake_y[i],WHITE);
                settextstyle(6,0,8);
                outtextxy(50,200,"game over");
                delay(250);
                while(1)
                {
                    clearviewport();
                    settextstyle(6,0,8);
                    setcolor(BLUE);
                    settextstyle(7,0,6);
                    outtextxy(200,130,"play again");
                    outtextxy(200,190,"Main Menu");
                    outtextxy(200,250,"Exit");
                    setcolor(MAGENTA);
                    outtextxy(145,cursor_y,">");
                    if(kbhit)
                    {
                        ch = getch();
                        setcolor(BLACK);
                        outtextxy(160,cursor_y,">");
                        if(ch == 13)
                        {
                            if(cursor_y==250) exit(0);
                            else if(cursor_y==130) game();
                            else if(cursor_y==190) Main_Menu();

                        }
                    }
                    setcolor(MAGENTA);
                    if(ch==80)
                    {
                        cursor_y+=60;
                        if(cursor_y > 250)
                        {
                            cursor_y=130;
                        }
                    }
                    if(ch==72)
                    {
                        cursor_y-=60;
                        if(cursor_y < 130)
                        {
                            cursor_y=250;
                        }
                    }
                    outtextxy(145,cursor_y,">");

                }
                clearviewport();
            }
            while(1)
            {
                if(kbhit())
                {
                    char ch = getch();
                    if(ch == 13)
                    {
                        checkdied = true;
                        return;
                    }
                }
            }
        }
    }
}


void mate()
{
    for(int i=1; i<snake_size; i++)
    {

        if(snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
        {
            snake_size=5;

        }
    }
}

void check()
{

    freopen("GameData.dat","w",stdout);
    if(highscore < score)
        cout << score << endl;
    else cout << highscore << endl;


    for(int j=886,k = 628; k <650,j<930; j+=1,k+=1)
    {
        if(snake_x[0] == 0||snake_y[0]==0 ||snake_y[0] == k||snake_x[0]==j)
        {

            delay(250);
            setcolor(WHITE);
            for(int i = 0; i < snake_size; i++)
            {
                circle(snake_x[i],snake_y[i],8);
                setfillstyle(SOLID_FILL,RED);
                floodfill(snake_x[i],snake_y[i],WHITE);
                settextstyle(6,0,8);
                outtextxy(50,200,"game over");
                delay(250);
                while(1)
                {
                    clearviewport();
                    settextstyle(6,0,8);
                    setcolor(BLUE);
                    settextstyle(7,0,6);
                    outtextxy(200,130,"play again");
                    outtextxy(200,190,"Main Menu");
                    outtextxy(200,250,"Exit");
                    setcolor(MAGENTA);
                    outtextxy(145,cursor_y,">");
                    if(kbhit)
                    {
                        ch = getch();
                        setcolor(BLACK);
                        outtextxy(160,cursor_y,">");
                        if(ch == 13)
                        {
                            if(cursor_y==250) exit(0);
                            else if(cursor_y==130) game();
                            else if(cursor_y==190) Main_Menu();

                        }
                    }
                    setcolor(MAGENTA);
                    if(ch==80)
                    {
                        cursor_y+=60;
                        if(cursor_y > 250)
                        {
                            cursor_y=130;
                        }
                    }
                    if(ch==72)
                    {
                        cursor_y-=60;
                        if(cursor_y < 130)
                        {
                            cursor_y=250;
                        }
                    }
                    outtextxy(145,cursor_y,">");

                }
                clearviewport();
                j=886;
                k = 628;
            }
            while(1)
            {
                if(kbhit())
                {
                    char ch = getch();
                    if(ch == 13)
                    {
                        checkdied = true;
                        return;
                    }
                }
            }
        }
    }
}
void dead()
{
    checkdied = false;
    snake_size = 5;
    score = 0;
}
void level()
{


    clearviewport();
    char ch;
    char ara[100];
    while(true)
    {

        int i = abs(spd/10-10);
        sprintf(ara,"SELECT LEVEL : %d",i);
        setcolor(WHITE);
        outtextxy(180,350,ara);

        if(kbhit())
        {
            ch = getch();
            if(ch == 80)
            {
                spd-=20;
                if(spd < 0) spd = 100;
            }
            else if(ch == 72)
            {
                spd+=20;
                if(spd > 100) spd = 0;
            }
            else if(ch == 13)
                break;
            sprintf(ara,"SELECT LEVEL : %d",i);
            setcolor(BLACK);
            outtextxy(180,350,ara);
        }
    }
    clearviewport();

}
void infinitylevel()
{
    clearviewport();
    while(1)
    {
        setcolor(CYAN);
        settextstyle(3,0,6);
        outtextxy(220,130,"start game");
        outtextxy(220,190,"highscore ");
        outtextxy(220,250,"instruction  ");
        outtextxy(220,310,"main menu ");
        outtextxy(180,cursor_y,">");
        if(kbhit)
        {
            ch = getch();
            setcolor(BLACK);
            outtextxy(180,cursor_y,">");
            if(ch == 13)
            {
                if(cursor_y==310) Main_Menu();
                else if(cursor_y==190) Highe();
                else if(cursor_y==250) instruction2();
                else if(cursor_y==130)Game();
            }
        }

        setcolor(RED);
        if(ch==80)
        {
            cursor_y+=60;
            if(cursor_y > 310)
            {
                cursor_y=130;
            }
        }
        if(ch==72)
        {
            cursor_y-=60;
            if(cursor_y < 130)
            {
                cursor_y=310;
            }
        }
        outtextxy(180,cursor_y,">");

    }

}

void instruction2()
{
    clearviewport();
    setcolor(WHITE);
    outtextxy(300,200,"this auto speed update level game");
    char ch =getch();
    clearviewport();
}

void Game()//this game for infinity level
{
    clearviewport();
    freopen("GamData.dat","r",stdin);
    cin >> Highscore;

    cleardevice();

    string key = "right";
    int maxx = getmaxx();
    int maxy = getmaxy()-50;
    int x = 13,y = 13;

    int food_x = rand()%maxx,food_y = rand()%maxy;
    int temp;
    temp = food_x%13;
    food_x-=temp;
    temp = food_y%13;
    food_y-=temp;
    int i = 0;

    int bonus = 500;
    clearviewport();
    while(true)
    {


//readimagefile("football.JPEG",20,40,640,480);
        if(Score >0 && Score%5==4)
        {
            BONUS = true;
        }
        else
        {
            bonus = 500;
            BONUS = false;
        }

        if(!BONUS || bonus == 0)
        {
            setcolor(BLACK);
            outtextxy(250,10,"Hurry!! 888");
            setcolor(MAGENTA);
            setfillstyle(SOLID_FILL,MAGENTA);
            circle(food_x,food_y,7); //x position,y position,size
            floodfill(food_x,food_y,MAGENTA);

        }
        else
        {
            setcolor(BLUE);
            setfillstyle(SOLID_FILL,BLUE);
            circle(food_x,food_y,8);
            floodfill(food_x,food_y,BLUE);

            char spp[1000];
            setcolor(BLACK);
            sprintf(spp,"Hurry!! %d",bonus);
            outtextxy(250,10,"Hurry!! 888");
            setcolor(MAGENTA);
            outtextxy(250,10,spp);

        }
        maxx = getmaxx();
        maxy = getmaxy()-50;
        setcolor(WHITE);
        line(0,maxy+8,maxx,maxy+8);
        if(kbhit())
        {
            ch = getch();
            if(ch == 0) ch = getch();
            if(ch == 72 && key != "down" ) key = "up";//h
            if(ch == 80 && key != "up") key = "down";  //shift + p
            if(ch == 75 && key != "right") key = "left";//k
            if(ch == 77 && key != "left") key = "right";//m
            if(ch==8&&key!="tab")key="alt";

            if(ch=='a')key="stop";


            if(ch == 27)
            {
                cleardevice();
                return;
            }


        }

        if(i < 5)
        {
            snake_x[i] = x-240;
            snake_y[i] = y-285;
            i++;
        }

        else
        {
            for(int _size = snake_size-2; _size >= 0; _size--)
            {
                snake_x[_size+1] = snake_x[_size];
                snake_y[_size+1] = snake_y[_size];
            }
            snake_x[0] = x;
            snake_y[0] = y;

            setcolor(RED);
            circle(snake_x[0],snake_y[0],8);

            setfillstyle(SOLID_FILL,RED);
            floodfill(snake_x[0],snake_y[0],RED);

            setcolor(GREEN);
            for(int _size = 1; _size < snake_size; _size++)
            {
                circle(snake_x[_size],snake_y[_size],7);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(snake_x[_size],snake_y[_size],GREEN);
            }
            settextstyle(3,0,3);
            char ara[100];
            sprintf(ara,"Score: %d",Score);
            setcolor(WHITE);
            outtextxy(00,maxy+10,ara);
            sprintf(ara,"Bestscore: %d",Highscore);
            setcolor(WHITE);
            outtextxy(650,maxy+10,ara);


            if(Score<300)
                lebel1();
            else if(Score>400&&Score<600)
                lebel2();
            else if(Score>680&&Score<900)
                lebel3();
            else if(Score>1001&&Score<1270)
                lebel4();
            else if(Score>1340&&Score<1570)
                lebel5();
            else if(Score>1600&&Score<1800)
                lebel6();
            else if(Score>2000)
                lebel7();
            else
                delay(50);
        }

        if(x == food_x && y== food_y)
        {
            snake_size++;
            Score+=2;
            /* Snake eats food*/
            if(Score%5==0 && Score>0)Score+=bonus;

            food_x = rand()%maxx,food_y = rand()%maxy;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;

            if(food_x < 5 || food_x > maxx - 5 || food_y < 5 || food_y > maxy - 5)
            {
                while(food_x < 5 || food_x > maxx - 5 || food_y < 5 || food_y > maxy - 5)
                {
                    food_x = rand()%maxx,food_y = rand()%maxy;
                    temp = food_x%13;
                    food_x-=temp;
                    temp = food_y%13;
                    food_y-=temp;
                }
            }
        }
        if(key == "right") x = x+13;
        if(x > maxx) x =0;
        if(key == "left") x = x-13;
        if(x < 0) x = maxx-(maxx%13);
        if(key == "up") y = y-13;
        if(y > maxy) y = 0;
        if(key == "down") y = y+13;
        if(y < 0) y = maxy-(maxy%13);
        Check();
        if(checkdied)
        {
            Dead();
            return;
        }

        if(BONUS)
        {
            if(bonus>0)
                bonus-=10;
        }
        setcolor(BLACK);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(snake_x[0],snake_y[0],BLACK);

        for(int _size = 1; _size < snake_size; _size++)
        {
            circle(snake_x[_size],snake_y[_size],6);
            setfillstyle(SOLID_FILL,WHITE);
            floodfill(snake_x[_size],snake_y[_size],BLACK);
        }

    }
}
void Check()//this check for infinitylevel
{
    freopen("GamData.dat","w",stdout);
    if(Highscore < Score)
        cout << Score << endl;
    else cout << Highscore << endl;

    for(int i = 1; i < snake_size; i++)
    {
        if(snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
        {
            delay(100);
            setcolor(WHITE);
            for(int i = 0; i < snake_size; i++)
            {
                circle(snake_x[i],snake_y[i],8);
                setfillstyle(SOLID_FILL,RED);
                floodfill(snake_x[i],snake_y[i],WHITE);
                settextstyle(6,0,8);
                outtextxy(50,200,"game over");
                delay(200);
                clearviewport();
                while(1)
                {
                    settextstyle(6,0,8);
                    setcolor(MAGENTA);
                    settextstyle(7,0,5);
                    outtextxy(260,130,"Reply ");
                    outtextxy(260,190,"Main Menu");
                    outtextxy(260,250,"Exit");
                    outtextxy(180,cursor_y,">");
                    if(kbhit)
                    {
                        ch = getch();
                        setcolor(BLACK);
                        outtextxy(180,cursor_y,">");
                        if(ch == 13)
                        {
                            if(cursor_y==250) exit(0);
                            else if(cursor_y==130) Game();
                            else if(cursor_y==190) Main_Menu();

                        }
                    }
                    setcolor(RED);
                    if(ch==80)
                    {
                        cursor_y+=60;
                        if(cursor_y > 250)
                        {
                            cursor_y=130;
                        }
                    }
                    if(ch==72)
                    {
                        cursor_y-=60;
                        if(cursor_y < 130)
                        {
                            cursor_y=250;
                        }
                    }
                    outtextxy(180,cursor_y,">");
                    clearviewport();
                }

            }
            while(1)
            {
                if(kbhit())
                {
                    char ch = getch();
                    if(ch == 13)
                    {
                        checkdied = true;
                        return;
                    }
                }
            }
        }
    }
}
void Dead()//this dead for infinity level
{
    life++;
    checkdied = false;
    snake_size = 5;
    score = 0;
}

void Highe()//this high for infinity level
{
    clearviewport();
    freopen("GamData.dat","r",stdin);
    cin >> Highscore;
    char a[100];
    sprintf(a,"HighScore: %d",Highscore);
    setcolor(WHITE);
    outtextxy(200,350,a);
    char ch = getch();
    clearviewport();
}



void high()//this high for normal level
{
    clearviewport();
    freopen("GameData.dat","r",stdin);
    cin >> highscore;
    char ara[100];
    sprintf(ara,"Highscore: %d",highscore);
    setcolor(WHITE);
    outtextxy(200,350,ara);
    char ch = getch();
    clearviewport();
}

void lebel1()
{
    int spd=100;
    delay(spd);
    speed(spd);
}
void lebel2()
{
    int spd=80;
    delay(spd);
    speed(spd);
}

void lebel3()
{
    int spd=60;
    delay(spd);
    speed(spd);
}

void lebel4()
{
    int spd=40;
    delay(spd);
    speed(spd);
}

void lebel5()
{
    int spd=20;
    delay(spd);
    speed(spd);
}

void lebel6()
{
    int spd=10;
    delay(spd);
    speed(spd);
}

void lebel7()
{
    int spd=2;
    delay(spd);
    speed(spd);
}


void speed(int f)
{
    setcolor(WHITE);
    int spd=f;
    clearviewport();
    char ar[50];
    settextstyle(9,0,4);
    sprintf(ar,"current snake speed %d",spd);
    outtextxy(150,640,ar);
}



