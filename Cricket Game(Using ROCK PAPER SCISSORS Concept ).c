#include<stdio.h>
#include<conio.h>
#include<windows.h>


int toss(char n);
int player1score(char x);
int player2score(char y);
char inputkey1(void);
char inputkey2(void);
int highscore(int j,char k[10]);
int option(void);
int show_highscore(void);
void gamerules(void);
void gotoxy(int x, int y);//SetConsoleCursorPosition Function


int playr1=0,playr2=0,x=1,y=0;
char input1, input2;
char player1[10],player2[10];


int main()
{

    option();
    int Option,w;
    scanf("%d",&Option);
    system("cls");

    if(Option==1)
    {

        int r , q ;
        gotoxy(30,10);
        printf("Loading.....");
        gotoxy(30,12);

        for(r=1;r<=20;r++)
        {
            for(q=0;q<=100000000;q++);
            printf("%c",178);
        }
        system("cls");

        int tosswinr;
        char ch;
        char ch2;

        printf("Programed by PEAL MAZUMDER(NSTU CSTE 12batch)\n");

        printf("\n\n\nEnter Second Player Name\n");
        scanf("%s",player1);
        printf("Enter Second Player Name\n");
        scanf("%s",player2);

        printf("\t\t\t\t\t %s Please enter any one key'H' or 'h' for Head and T or 't' for Tails\n",player1);
        scanf(" %c",&ch);

        system("cls");

        tosswinr=toss(ch);

        printf("\n\n-------->> Let's Start The Game %s -------->>\n",player1);

        while(1)
        {
            inputkey1();

            if(input1=='a'&&input2=='l'||input1=='s'&&input2=='k'||input1=='d'&&input2=='j'||input1=='w'&&input2=='o'||input1=='e'&&input2=='i')
            {
                printf("\n\n\n\t\t\t\t-------->> %s You Are Out!-------->> \n",player1);
                printf("\t\t\t\t-------->> Your Total Score is : %d <<--------\n",playr1);
                x=1,y=0;
                break;
            }

            else
                player1score(input1);
        }

        printf("%s Now Your Turn\n",player2);

        while(1)
        {
            inputkey2();

            if(input1=='l'&&input2=='a'||input1=='k'&&input2=='s'||input1=='j'&&input2=='d'||input1=='o'&&input2=='w'||input1=='i'&&input2=='e')
            {
                printf("\t\t\t\t-------->> %s You Are Out!-------->>\n",player2);
                printf("\t\t\t\t-------->> Your score is : %d -------->>\n",playr2);
                x=1,y=0;
                break;
            }

            else
            {
                player2score(input1);
                if(playr2>playr1)
                    break;
            }


        }
        if(playr1==playr2)
        {
            system("cls");
            for(w=0;w<=150;w++)
            {
                if(w%3==0)
                {
                    gotoxy(45,10);
                    {
                        printf(">>>>>--------> Draw >>>>>-------->\n");
                        printf("\t\t\t>>>>>--------> Both Of Your Score is : %d >>>>>-------->\n",playr1);

                    }

                }
                else
                {
                    system("cls");
                }

            }

            highscore(playr1,player1);
            playr1=0;
            playr2=0;

            main();

        }

        else if(playr1>playr2)
        {
            system("cls");
            for(w=0;w<=150;w++)
            {
                if(w%3==0)
                {
                    gotoxy(45,10);
                    {
                        printf(">>>>>--------> %s You Win The Game >>>>>-------->\n",player1);
                        printf("\t\t\t>>>>>--------> Your Score is : %d >>>>>-------->\n",playr1);
                    }
                }
                else
                {
                    system("cls");
                }

            }
            highscore(playr1,player1);
            playr1=0;
            playr2=0;

            main();

        }
        else
        {
            system("cls");
            for(w=0;w<=150;w++)
            {
                if(w%3==0)
                {
                    gotoxy(45,10);
                    {
                        printf(">>>>>--------> %s You Win The Game >>>>>-------->\n",player2);
                        printf("\t\t\t>>>>>--------> Your Score is : %d >>>>>-------->\n",playr2);
                    }

                }
                else
                {
                    system("cls");
                }

            }


            highscore(playr2,player2);
            playr1=0;
            playr2=0;

            main();

        }

    }
    else if(Option==2)
    {
        printf("\n\n\n");
        printf("Highest Score is :");
        show_highscore();
        printf("\n");
        main();
    }
    else if(Option==3)
    {
        gamerules();
        main();
    }
    else if(Option==4)
    {
        return 0;
    }

    return 0;

}
int toss(char n)
{
    int number,yes_no;
    char temp[10];
    srand(time(NULL));
    number=(rand()%6);
    if(n=='H'||n=='h'||n=='t'||n=='T')
    {
        if(number==0||number==2||number==4)
        {
            printf("\t\t\t\t\t\t\t-------->> Congrats! %s win the Toss <<--------\n",player1);
            printf("\n\n--->> %s Do you like to bat first?\n",player1);
            printf("\n\t1 YES\n\t2 NO\n");
            scanf("%d",&yes_no);
            if(yes_no==2)
            {
                strcpy(temp,player1);
                strcpy(player1,player2);
                strcpy(player2,temp);
            }
            system("cls");
            printf("\n\t\t\t\t-------->> %s Remember that you can only use key a for 1,s for 2,d for 3,w for 4 and e for 6 <<--------\n",player1);
            printf("\n\t\t\t\t-------->> %s Remember that you can only use key l for 1,k for 2,j for 3,o for 4 and i for 6 <<--------\n",player2);
        }
        else if(number==1||number==3||number==5)
        {
            printf("\t\t\t\t\t\t-------->> Sorry!%s you loss the Toss <<--------\n",player1);
            printf("\n\n--->> %s! do you like to bat first?\n",player2);

            printf("\n\t1 YES\n\t2 NO\n");
            scanf("%d",&yes_no);
            if(yes_no==1)
            {
                strcpy(temp,player1);
                strcpy(player1,player2);
                strcpy(player2,temp);
            }
            system("cls");
            printf("\n\t\t\t\t-------->> %s Remember that you can only use key a for 1,s for 2,d for 3,w for 4 and e for 6 <<--------\n",player1);
            printf("\n\t\t\t\t-------->> %s Remember that you can only use key l for 1,k for 2,j for 3,o for 4 and i for 6 <<--------\n",player2);
        }
    }
}
int player1score(char x)
{
    switch(x)
    {
        case 'a':
            playr1+=1;
            printf("%s Your Score: %d\n",player1,playr1);
            break;

        case 's':
            playr1+=2;
            printf("%s Your Score: %d\n",player1,playr1);
            break;

        case 'd':
            playr1+=3;
            printf("%s Your Score: %d\n",player1,playr1);
            break;

        case 'w':
            playr1+=4;
            printf("%s Your Score: %d\n",player1,playr1);
            break;

        case 'e':
            playr1+=6;
            printf("%s Your Score: %d\n",player1,playr1);
            break;

    }
}

int player2score(char y)
{
    switch(y)
    {
        case 'l':
            playr2+=1;
            printf("%s Your Score: %d\n",player2,playr2);
            break;

        case 'k':
            playr2+=2;
            printf("%s Your Score: %d\n",player2,playr2);
            break;

        case 'j':
            playr2+=3;
            printf("%s Your Score: %d\n",player2,playr2);
            break;

        case 'o':
            playr2+=4;
            printf("%s Your Score: %d\n",player2,playr2);
            break;

        case 'i':
            playr2+=6;
            printf("%s Your Score: %d\n",player2,playr2);
            break;


    }

}

char inputkey1(void)
{
    if(x==1)
    {
        while(1)
        {
            input1=_getch();
            if(input1=='a'||input1=='s'||input1=='d'||input1=='w'||input1=='e')
            {
                x=0,y=1;
                break;
            }
            else
            {
                printf("\n\t\t\t\t>>>>>--------> Guys Don't Press Wrong keyword >>>>>-------->\n");
                continue;
            }
        }
    }

    if(y==1)
    {
        while(1)
        {
            input2=_getch();
            if(input2=='l'||input2=='k'||input2=='j'||input2=='o'||input2=='i')
            {
                x=1,y=0;
                break;
            }
            else
            {
                printf("\n\t\t\t\t>>>>>--------> Guys Don,t Press Wrong keyword >>>>>-------->\n");
                continue;
            }
        }
    }

}
char inputkey2(void)
{
    if(x==1)
    {
        while(1)
        {
            input1=_getch();
            if(input1=='l'||input1=='k'||input1=='j'||input1=='o'||input1=='i')
            {
                x=0,y=1;
                break;
            }
            else
            {
                printf("\n\t\t\t\t>>>>>--------> Guys Don't Press Wrong keyword >>>>>-------->\n");
                continue;
            }
        }
    }


    if(y==1)
    {
        while(1)
        {
            input2=_getch();
            if(input2=='a'||input2=='s'||input2=='d'||input2=='w'||input2=='e')
            {
                x=1,y=0;
                break;
            }
            else
            {
                printf("\n\t\t\t\t>>>>>--------> Guys Don't Press Wrong keyword >>>>>-------->\n");
                continue;
            }
        }
    }

}
int highscore(int j,char k[10])
{
    FILE *fp;
    int size,score,hscore;


    fp=fopen("peal.txt","w");

    if (NULL != fp)
    {
        fseek (fp, 0, SEEK_END);
        size = ftell(fp);

        if (size==0)
        {
            fclose(fp);
            fp=fopen("peal.txt","w");

            fprintf(fp,"%d ",j);
            fprintf(fp,"(Scored By");
            fprintf(fp," %s)",k);

            fclose(fp);
        }
        else
        {

            fp=fopen("peal.txt","r");
            fscanf(fp,"%d",&score);
            hscore=(j>score)? j:score;
            fclose(fp);
            fp=fopen("peal.txt","w+");

            fprintf(fp,"%d ",hscore);
            fprintf(fp,"(Scored By");
            fprintf(fp," %s)",k);

            fclose(fp);
        }
    }
}

int option(void)
{
    printf("\n\n\n\t\t\t\t1 Start Game\n\t\t\t\t2 Highest score\n\t\t\t\t3 Game Instructions\n\t\t\t\t4 Quit\n\n\n");

}
int show_highscore(void)
{
    FILE *fp;
    int highscore;
    char showhighscore[100];
    fp=fopen("peal.txt","r");

        while(!feof(fp))
          {
              fgets(showhighscore,100,fp);
              puts(showhighscore);
          }
          fclose(fp);
}
void gamerules(void)
{
    printf(">--->> Mainly this game is based on that game which kids are usually play using their fingers like ROCK PAPER SCISSORS.\n\n");
    printf(">--->> This game held between two players.He will give input first who batted first.Then the opponent player will give input.\n");
    printf("\tIf the opponent player's input matched with first player's input then the first player will be out.\n");
    printf("\tThen second player will bat at the same way and first player try to out him.\n\n");
    printf(">--->> For runs 1,2,3,4 and 6 press the key 'a'/'l','s'/'k','d'/'j','w'/'o'&'e'/'i' of keyboard respectively.\n");
    printf("\tAt the same time to out him opponent player also use same way.\n\n");
    printf(">--->> Remember That Keys a,s,d,w & e Only for First Player and Keys l,k,j,o & i for Second Player.\n\n\n");
    printf(">--->> Two can be used to play the game.\n\n\n");
}
void gotoxy(int x, int y)//SetConsoleCursorPosition Function
{

 COORD coord;

 coord.X = x;

 coord.Y = y;

 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
