#include <bits/stdc++.h>
#include<conio.h>

using namespace std;

int playr1=0,playr2=0,x=1,y=0;
char input1, input2;


class player
{
public:
    string player1;
    string player2;
    char ch;
    void GetNames();
    int TakeToss();
    void MainGame();
    int player1score(char x);
    int player2score(char y);
    char inputkey1(void);
    char inputkey2(void);
    int show_highscore(void);
    void highscore(int j,string k);
    int option(void);
    void gamerules(void);
};
void player::GetNames()
{
    cin.ignore();
    cout<<"Enter First Player Name"<<endl;
    getline(cin,player1);
    cout<<"Enter Second Player Name"<<endl;
    getline(cin,player2);
}
int player::TakeToss()
{
    cout<<"\t\t\t\t\t"<<player1<<" Please enter any one key'H' or 'h' for Head and T or 't' for Tails"<<endl;
    cin>>ch;
    int number,yes_no;

    srand(time(NULL));
    number=(rand()%6);
    if(ch=='H'||ch=='h'||ch=='t'||ch=='T')
    {
        if(number==0||number==2||number==4)
        {
            cout<<"\t\t\t\t\t\t\t-------->> Congrats!"<<player1<<" win the Toss <<--------\n"<<endl;
            cout<<"\n\n--->> "<<player1<<" Do you like to bat first?"<<endl;
            cout<<"\n\t1 YES\n\t2 NO"<<endl;
            cin>>yes_no;
            if(yes_no==2)
            {
                player1.swap(player2);
            }
            system("cls");
            cout<<"\n\t\t\t\t-------->> "<<player1<<" Remember that you can only use key a for 1,s for 2,d for 3,w for 4 and e for 6 <<--------"<<endl;
            cout<<"\n\t\t\t\t-------->> "<<player2<<" Remember that you can only use key l for 1,k for 2,j for 3,o for 4 and i for 6 <<--------"<<endl;
        }
        else if(number==1||number==3||number==5)
        {
            cout<<"\t\t\t\t\t\t-------->> Sorry!"<<player1<<" you loss the Toss <<--------"<<endl;
            cout<<"\n\n--->> "<<player2 <<" ! do you like to bat first?"<<endl;

            cout<<"\n\t1 YES\n\t2 NO"<<endl;
            cin>>yes_no;
            if(yes_no==1)
            {
                player1.swap(player2);
            }
            //system("cls");
            cout<<"\n\t\t\t\t-------->>"<<player1<<" Remember that you can only use key a for 1,s for 2,d for 3,w for 4 and e for 6 <<--------"<<endl;
            cout<<"\n\t\t\t\t-------->> "<<player2<<" Remember that you can only use key l for 1,k for 2,j for 3,o for 4 and i for 6 <<--------"<<endl;
        }
    }
    cout<<"\n\n-------->> Let's Start The Game "<<player1<<" -------->>"<<endl;
}
void player::MainGame()
{
    while(1)
        {
            inputkey1();

            if(input1=='a'&&input2=='l'||input1=='s'&&input2=='k'||input1=='d'&&input2=='j'||input1=='w'&&input2=='o'||input1=='e'&&input2=='i')
            {
                cout<<"\n\n\n\t\t\t\t-------->> "<<player1 <<" You Are Out!-------->> "<<endl;
                cout<<"\t\t\t\t-------->> Your Total Score is : "<<playr1<<"--------"<<endl;
                x=1,y=0;
                break;
            }

            else
                player1score(input1);
        }

        cout<<player2<<" Now Your Turn"<<endl;

        while(1)
        {
            inputkey2();

            if(input1=='l'&&input2=='a'||input1=='k'&&input2=='s'||input1=='j'&&input2=='d'||input1=='o'&&input2=='w'||input1=='i'&&input2=='e')
            {
                cout<<"\t\t\t\t-------->> "<<player2<<" You Are Out!-------->>"<<endl;
                cout<<"\t\t\t\t-------->> Your score is : "<<playr2<<" -------->>"<<endl;
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

            {
                cout<<"\t\t\t>>>>>--------> Draw >>>>>-------->"<<endl;
                cout<<"\t\t\t>>>>>--------> Both Of Your Score is : "<<playr1<<" >>>>>-------->"<<endl;

            }

            highscore(playr1,player1);
            playr1=0;
            playr2=0;

        }

        else if(playr1>playr2)
        {

            cout<<"\t\t\t>>>>>--------> "<<player1<<" You Win The Game >>>>>-------->"<<endl;
            cout<<"\t\t\t>>>>>--------> Your Score is : "<<playr1<<" >>>>>-------->"<<endl;

            highscore(playr1,player1);
            playr1=0;
            playr2=0;



        }
        else
        {

            cout<<"\t\t\t>>>>>--------> "<<player2<<" You Win The Game >>>>>-------->"<<endl;
            cout<<"\t\t\t>>>>>--------> Your Score is : "<<playr2<<" >>>>>-------->"<<endl;
            highscore(playr2,player2);
            playr1=0;
            playr2=0;



        }

    }


int player::player1score(char x)
{
    switch(x)
    {
        case 'a':
            playr1+=1;
            cout << "- - - - -" << endl;
            cout << "  |" << endl;
            cout << "| * |" << endl;
            cout << "  |" << endl;
            cout << " - - - - -" << endl;
            cout<<player1<<" Your Score: "<<playr1<<endl;
            break;

        case 's':
            playr1+=2;
            cout << "- - - - -" << endl;
            cout << "| * |" << endl;
            cout << "     " << endl;
            cout << "| * |" << endl;
            cout << " - - - - -" << endl;
            cout<<player1<<" Your Score: "<<playr1<<endl;
            break;

        case 'd':
            playr1+=3;
            cout << "- - - - -" << endl;
            cout << "| * |" << endl;
            cout << "  *  " << endl;
            cout << "| * |" << endl;
            cout << " - - - - -" << endl;
            cout<<player1<<" Your Score: "<<playr1<<endl;
            break;

        case 'w':
            playr1+=4;
            cout << "- - - - -" << endl;
            cout << "| * * |" << endl;
            cout << "       " << endl;
            cout << "| * * |" << endl;
            cout << " - - - - -" << endl;
            cout<<player1<<" Your Score: "<<playr1<<endl;
            break;

        case 'e':
            playr1+=6;
            cout << "- - - - -" << endl;
            cout << "| * * |" << endl;
            cout << "  * *  " << endl;
            cout << "| * * |" << endl;
            cout << " - - - - -" << endl;
            cout<<player1<<" Your Score: "<<playr1<<endl;
            break;

    }
}

int player::player2score(char y)
{
    switch(y)
    {
        case 'l':
            playr2+=1;
            cout << "- - - - -" << endl;
            cout << "  |" << endl;
            cout << "| * |" << endl;
            cout << "  |" << endl;
            cout << " - - - - -" << endl;
            cout<<player2<<" Your Score: "<<playr2<<endl;
            break;

        case 'k':
            playr2+=2;
            cout << "- - - - -" << endl;
            cout << "| * |" << endl;
            cout << "  |" << endl;
            cout << "| * |" << endl;
            cout << " - - - - -" << endl;
            cout<<player2<<" Your Score: "<<playr2<<endl;
            break;

        case 'j':
            playr2+=3;
            cout << "- - - - -" << endl;
            cout << "| * |" << endl;
            cout << "| * |" << endl;
            cout << "| * |" << endl;
            cout << " - - - - -" << endl;
            cout<<player2<<" Your Score: "<<playr2<<endl;
            break;

        case 'o':
            playr2+=4;
            cout << "- - - - -" << endl;
            cout << "| * * |" << endl;
            cout << "       " << endl;
            cout << "| * * |" << endl;
            cout << " - - - - -" << endl;
            cout<<player2<<" Your Score: "<<playr2<<endl;
            break;

        case 'i':
            playr2+=6;
            cout << "- - - - -" << endl;
            cout << "| * * |" << endl;
            cout << "  * *  " << endl;
            cout << "| * * |" << endl;
            cout << " - - - - -" << endl;
            cout<<player2<<" Your Score: "<<playr2<<endl;
            break;


    }

}
char player::inputkey1(void)
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
                cout<<"\n\t\t\t\t>>>>>-------->Don't Press Wrong keyword >>>>>-------->"<<endl;
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
                cout<<"\n\t\t\t\t>>>>>-------->Don,t Press Wrong keyword >>>>>-------->"<<endl;
                continue;
            }
        }
    }

}
char player::inputkey2(void)
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
                cout<<"\n\t\t\t\t>>>>>-------->Don't Press Wrong keyword >>>>>-------->"<<endl;
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
                cout<<"\n\t\t\t\t>>>>>-------->Don't Press Wrong keyword >>>>>-------->"<<endl;
                continue;
            }
        }
    }

}
void player:: highscore(int j,string k)
{
    int Size;

    streampos begin,end;
    ifstream myfile ("afile.txt", ios::binary);
    begin = myfile.tellg();
    myfile.seekg (0, ios::end);
    end = myfile.tellg();
    myfile.close();
    Size=end-begin;
    if(Size==0)
    {
        fstream outfile;
        outfile.open("afile.txt");
        outfile <<"Score By(" <<k<<")"<< endl;
        outfile<<j<<endl;
        outfile.close();
    }
    else
    {
        string Name;
        int score;
        fstream infile;
        infile.open("afile.txt");
        infile >> Name;
        infile >> score;
        infile.close();
        if(score<j)
        {
            fstream outfile;
            outfile.open("afile.txt");
            outfile <<"ScoreBy("<<k<<")"<< endl;
            outfile<<j<<endl;
            outfile.close();

        }
    }
}

int player::option(void)
{
    printf("\n\n\n\t\t\t\t1 Start Game\n\t\t\t\t2 Highest score\n\t\t\t\t3 Game Instructions\n\t\t\t\t4 Quit\n\n\n");

}
int player::show_highscore(void)
{
        string Name;
        int score;
        fstream infile;
        infile.open("afile.txt");
        infile >> Name;
        infile >> score;
        cout<<Name<<"  "<<score;
        infile.close();

}
void player::gamerules(void)
{
    printf(">--->> Mainly this game is based on that game which kids are usually play using their fingers like ROCK PAPER SCISSORS.\n\n");
    printf(">--->> This game held between two players.He will give input first who batted first.Then the opponent player will give input.\n");
    printf("\tIf the opponent player's input matched with first player's input then the first player will be out.\n");
    printf("\tThen second player will bat at the same way and first player try to out him.\n\n");
    printf(">--->> For runs 1,2,3,4 and 6 press the key 'a'/'l','s'/'k','d'/'j','w'/'o'&'e'/'i' of keyboard respectively.\n");
    printf("\tAt the same time to out him opponent player also use same way.\n\n");
    printf(">--->> Remember That Keys a,s,d,w & e Only for First Player and Keys l,k,j,o & i for Second Player.\n\n\n");
    printf(">--->> Two keyboard can be used to play the game.\n\n\n");
}
int main()
{
    int choice;
    player obj;
    cout<<"Programed by PEAL MAZUMDER(NSTU CSTE 12batch)\n";
    obj.option();
    cin>>choice;
    if(choice==1)
    {
        system("cls");
        obj.GetNames();
        obj.TakeToss();
        obj.MainGame();
        main();
    }
    if(choice==2)
    {
        system("cls");
        obj.show_highscore();
        main();
    }
    if(choice==3)
    {
        system("cls");
        obj.gamerules();
        main();
    }
    if(choice==4)
    {
        return 0;
    }

    return 0;
}
