#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
int k=0;
class userword
{
    private:
    char word[15];
    public:
        char comman;
        int gameover();
        int length(){return strlen(word);}
        int check_last_alphabet();
        void input();
        int comp();
        void game();
        int checkrepetition();
        friend void margin();
};

void margin()
{
            cout<<"\t\t\t\t";
}
int userword::checkrepetition()
{
    int i,j=1,c;
   char temp[15];
   ifstream f1;
   f1.open("temp.txt");
   for(i=0;i<k;i++)
   {

       f1 >> temp;
       c=strcmp(word,temp);
       if(c==0)
       {
           j=0;
           break;
       }

   }
   return j;
}



void userword::input()
{
    margin();
    cout<<">>";
    cin>>word;
    ofstream fp;
    if(k==0)
    {
        fp.open("temp.txt");
        fp << word <<endl;
        fp.close();
    }
    if (k>0)
    {
        fp.open("temp.txt",ios::app);
        fp << word <<endl;
        fp.close();
    }

}

int userword::gameover()
{   int s;char n[20];
    char pname[10];

    ifstream f1;
    f1.open("highscore.txt");
    f1 >> s;
    f1 >> n;
    cout<<endl;
    margin();
    cout<<"Your Score:"<<k<<"\tLast Highscore:"<<s<<"("<<n<<")"<<endl<<endl;margin();
    cout<<"::::::::::::::::::::GAME OVER:::::::::::::::::::::"<<endl<<endl;
    f1.close();
    if (k > s)
    {
        margin();
        cout<<":::you got high score:::"<<endl;
        margin();
        cout<<"enter your name :";
        cin>>pname;
        ofstream f2;
        f2.open("highscore.txt");
        f2 << k;
        f2 << pname<<endl;

        f2.close();
    }
    return 1;
}


int userword::comp()
{   int a,i;char fileword[15];
    ifstream f1;
    f1.open("jky.txt");
    //for(i=0;i<20000;i++)
    while(!f1.eof())
    {
        f1 >> fileword;
        a=strcmp(word,fileword);
        if (a==0)
        {
            return 0;
             break;

        }
    }

}

int userword::check_last_alphabet()
{
        if(comman==word[0])
            return 0;
        else if (k==0)
            return 0;
        else
            return 1;
}


void userword::game()
{


    int i,check_in_dictionary,cmn,stop=0,sl,rept;
    margin();
    cout<<"Enter your first word"<<endl;

    while(stop==0)
    {
        input();
        check_in_dictionary=comp();
        rept=checkrepetition();
        sl=length();
        cmn=check_last_alphabet();
        if(check_in_dictionary==0 && cmn==0 && rept==1 )
        {
            margin();
            cout<<"Enter word starting with "<<word[sl-1]<<endl;
            k++;
            comman=word[sl-1];
        }
        else
        {
            stop=gameover();
        }
    }
}

void title()
{
    margin();
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    margin();
    cout<<"::            _   _          _       ___  _      _       _   _     ::"<<endl;
    margin();
    cout<<"::  \\  /\\  / | | |_|  |\\    |_| |\\ |  |  |_| |/ |_  |_| |_| |_| |  ::"<<endl;
    margin();
    cout<<"::   \\/  \\/  |_| |\\   |/    | | | \\|  |  | | |\\  _| | | | | |\\  |  ::"<<endl;
    margin();
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl<<endl;
}

void menu()
{
    title();
    margin();
    cout<<"1.NEW GAME"<<endl;margin();
    cout<<"2.HIGH SCORES"<<endl;margin();
    cout<<"3.HISTORY"<<endl;margin();
    cout<<"4.ABOUT"<<endl;margin();
    cout<<"5.EXIT"<<endl;
}

void highscore()
{
    char pname[10];
    int score;
    ifstream f1;
    f1.open("highscore.txt");
    f1 >> pname;
    f1 >> score;
    cout<<pname<<" "<<score;
    f1.close();

}

void history()
{
    int i;
    char word[15];
    ifstream f1;
    f1.open("temp.txt");
    for(i=0;i<100;i++)
    {
        f1 >> word;
        margin();
        cout<<word<<endl;
        if( f1.eof())
        break;
    }
    f1.close();
}

void about()
{
    cout<<endl;
    margin();
    cout<<"C++ PROGRAMING LAB PROJECT 2017"<<endl;margin();
    cout<<" STUDENT NAME : PRADEEP JANGID"<<endl;margin();
    cout<<"\tBATCH : B-1";margin();
}

void exit()
{
    cout<<endl;
    margin();
    cout<<"GOOD BYE.........."<<endl;
}


main()
{
    userword w;
    int n;
    menu();
    margin();
    cin>>n;
    switch(n)
    {
        case 1:
            w.game();
        break;

        case 2:
            highscore();
        break;

        case 3:
            history();
        break;

        case 4:
            about();
        break;

        case 5:
            exit();
        break;

        default:
            cout<<"wrong input";
    }
}
