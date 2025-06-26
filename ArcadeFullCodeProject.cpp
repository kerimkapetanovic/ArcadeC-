#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<fstream>
using namespace std;

class SettingMode
{
  public:
    //Credits for the arcade
    double credits;
    //Variables used for "Horse Race"
    int numberOfHorses,horseRaceCredits,bettedHorseRaceCredits, bettedHorse,horseWon,betHorseRaceWon;
    //Variables used for "Mine Field"
    int numberOfMines, sizeOfTheMineField,xBoard,yBoard,mineFieldCredits,chooseY,bettedMineFieldCredits,chosenX,chosenY,mineFieldReturn,betMineFieldWon;
    char chooseX;
    //Char used for playing more games
    char anotherGame;
    //Variables used for "Blackjack"
    int blackJackCredits,bettedBlackJackCredits,firstCard,secondCard,anotherCard,sumOfCards,betBlackJackWon;
    char HitOrStay;

    //Functions used for "Horse Race"
    int HorseRace();
    int settingModeHorseRace();
    int defaultSettingModeHorseRace();
    //Functions used for "Mine Field"
    int MineField();
    int settingModeMineField();
    int defaultSettingModeMineField();
    void printBoard(int rows, int columns);
    int letterXToInt(int returnedInt);
    void checkMineField(int rows,int columns, int chosenX,int chosenY);
    //Functions used for "Blackjack"
    int Blackjack();
    int settingModeBlackJack();
    int defaultSettingModeBlackJack();
    int hit(int currentCards);
};

//Arcade main
int main()
{
    SettingMode ModeSetting;
    int chooseGame;
    cout<<"======================"<<endl;
    cout<<"Welcome To The Arcade!"<<endl;
    cout<<"======================"<<endl;
    cout<<"Enter how many credits you have:"<<endl;
    cin>>ModeSetting.credits;
    cout<<"======================"<<endl;
    do
    {
         cout<<"Choose a game to play: Horse race(1), MineField(2), Blackjack(3):"<<endl;
    cin>>chooseGame;
    if(chooseGame==1)
    {
        ModeSetting.HorseRace();
    }
    else if(chooseGame==2)
    {
        ModeSetting.MineField();
    }
    else if(chooseGame==3)
    {
        ModeSetting.Blackjack();
    }
    else
    {
        cout<<"Error,please choose a game!!!"<<endl;
    }
     cout<<"Current credit status: "<<ModeSetting.credits<<"!"<<endl;
     cout<<"======================"<<endl;
     cout<<"Do you want to play another game? (Y/N)"<<endl;
     cin>>ModeSetting.anotherGame;

    }
    while(ModeSetting.anotherGame=='Y'|| ModeSetting.anotherGame=='y');
    cout<<"======================"<<endl;
    cout<<"Game over!!! Thank you for playing!"<<endl;

    return 0;
}

//Horse Race Function
int SettingMode::HorseRace()
{
    srand(time(0));

    int chooseHorseRaceMode;
      cout<<"======================"<<endl;
    cout<<"You are now playing ''Horse Race''"<<endl;
     cout<<"======================"<<endl;
    cout<<"Choose setting mode(1) or game mode(2):"<<endl;
     cout<<"======================"<<endl;
    cin>>chooseHorseRaceMode;
    if(chooseHorseRaceMode==1)
    {
        settingModeHorseRace();
    }
    else if(chooseHorseRaceMode==2)
    {
        defaultSettingModeHorseRace();
    }
    else
    {
        while(chooseHorseRaceMode!=1 && chooseHorseRaceMode!=2)
        {

        cout<<"Error,please choose setting mode(1) or game mode(2)!!!"<<endl;
        cin>>chooseHorseRaceMode;
        }

    }


    cout<<"You have "<<credits<<" credits!."<<endl;
     cout<<"======================"<<endl;
    if(credits<horseRaceCredits)
    {
        cout<<"Error, you don't have enough credits to play ''Horse Race''"<<endl;
        return 0;

    }
      cout<<"Rules:\nThe game costs "<<horseRaceCredits<<" credits!\nChoose one horse that you bet on!\nIf you win, you receive double the credits you bet!\nHave fun!!!"<<endl;
       cout<<"======================"<<endl;
      cout<<"How much money do you bet?"<<endl;
      cin>>bettedHorseRaceCredits;
      while(bettedHorseRaceCredits>credits)
      {
          cout<<"Error,you can't bet credits that you don't have!!!"<<endl;
          cout<<"Please enter again: "<<endl;
          cin>>bettedHorseRaceCredits;
      }
        credits=credits-bettedHorseRaceCredits;
       cout<<"======================"<<endl;
      cout<<"What horse do you bet on?"<<endl;
      cin>>bettedHorse;
      while(bettedHorse>numberOfHorses || bettedHorse==0)
      {
          cout<<"Error,that horse does not compete!!!"<<endl;
           cout<<"Please enter again: "<<endl;
            cin>>bettedHorse;
      }
       cout<<"======================"<<endl;

      horseWon=rand()%numberOfHorses+1;
      cout<<"Horse "<<horseWon<<" won!!!"<<endl;
       cout<<"======================"<<endl;
      if(bettedHorse==horseWon)
      {
        betHorseRaceWon=bettedHorseRaceCredits*2;
        cout<<"You won "<<betHorseRaceWon<<" credits!!!"<<endl;
         cout<<"======================"<<endl;
        credits=credits+betHorseRaceWon;
       return credits;

      }
      else
      {
        cout<<"You lost "<<bettedHorseRaceCredits<<"!!!"<<endl;
        cout<<"======================"<<endl;
       return credits;
      }

}

//Mine Field Function
int SettingMode::MineField()
{
     int chooseMineFieldMode;
       cout<<"======================"<<endl;
    cout<<"You are now playing ''Mine Field''"<<endl;
     cout<<"======================"<<endl;
    cout<<"Choose setting mode(1) or game mode(2):"<<endl;
     cout<<"======================"<<endl;
    cin>>chooseMineFieldMode;
    if(chooseMineFieldMode==1)
    {
        settingModeMineField();
    }
    else if(chooseMineFieldMode==2)
    {
        defaultSettingModeMineField();
    }
    else
    {
         while(chooseMineFieldMode!=1 && chooseMineFieldMode!=2)
        {

        cout<<"Error,please choose setting mode(1) or game mode(2)!!!"<<endl;
        cin>>chooseMineFieldMode;
        }
    }
     cout<<"You have "<<credits<<" credits!."<<endl;
     cout<<"======================"<<endl;
    if(credits<mineFieldCredits)
    {
        cout<<"Error, you don't have enough credits to play ''Mine Field''"<<endl;
        return 0;
    }
      cout<<"Rules:\nThe game costs "<<mineFieldCredits<<" credits\nChoose one coordinate by entering rows with the Alphabetical letters(A,B,C...) and by entering collums with numbers(1,2,3...)\nIf you don't hit the mine, you win 10 credits!\nHave fun!!!"<<endl;
      cout<<"======================"<<endl;
      cout<<"How much credits do you bet?"<<endl;
      cin>>bettedMineFieldCredits;
       while(bettedMineFieldCredits>credits)
      {
          cout<<"Error,you can't bet credits that you don't have!!!"<<endl;
          cout<<"Please enter again: "<<endl;
          cin>>bettedMineFieldCredits;
      }
      credits=credits-bettedMineFieldCredits;
      cout<<"Enter 'X' and 'Y' coordinates: (Note: Choose coordinates in format 'A0','B1','C2' etc)"<<endl;
      cin>>chooseX>>chooseY;
      while(letterXToInt(chooseX)>xBoard || chooseY>yBoard)
      {
          cout<<"Error,that does not exist on the board!!!"<<endl;
          cout<<"Please enter again: "<<endl;
          cin>>chooseX>>chooseY;

      }
      cout<<"======================"<<endl;
      cout<<"You choose:"<<letterXToInt(chooseX)<<" "<<chooseY<<endl;
      cout<<"======================"<<endl;
      checkMineField(xBoard,yBoard,letterXToInt(chooseX),chooseY);
      if(mineFieldReturn==1)
      {
         cout<<"======================"<<endl;
         cout<<"You hit a mine, you lost!!!"<<endl;
         cout<<"======================"<<endl;

         return credits;
      }
      else
      {
         cout<<"======================"<<endl;
         cout<<"You won!!!"<<endl;
         cout<<"======================"<<endl;
         betMineFieldWon=bettedMineFieldCredits+10;
         credits=credits+betMineFieldWon;
         return credits;
      }
}

//Blackjack Function
int SettingMode::Blackjack()
{
    srand(time(0));
    int chooseBlackJackMode;
      cout<<"======================"<<endl;
     cout<<"You are now playing ''Blackjack''"<<endl;
     cout<<"======================"<<endl;
    cout<<"Choose setting mode(1) or game mode(2):"<<endl;
     cout<<"======================"<<endl;
    cin>>chooseBlackJackMode;
    if(chooseBlackJackMode==1)
    {
        settingModeBlackJack();
    }
    else if(chooseBlackJackMode==2)
    {
        defaultSettingModeBlackJack();
    }
    else
    {
         while(chooseBlackJackMode!=1 && chooseBlackJackMode!=2)
        {

        cout<<"Error,please choose setting mode(1) or game mode(2)!!!"<<endl;
        cin>>chooseBlackJackMode;
        }
    }

     cout<<"You have "<<credits<<" credits!."<<endl;
     cout<<"======================"<<endl;
      if(credits<blackJackCredits)
    {
        cout<<"Error, you don't have enough credits to play ''Blackjack''"<<endl;
        return 0;

    }
     cout<<"Rules:\nThe game costs "<<blackJackCredits<<" credits\nYou will have two cards in your hand ranging from 1 to 11\nYou will have the option to ''Hit'' or ''Stay''\nHit means you get another card\nPass means stick to your current cards\nAt the end, you will earn the percentage of the cards in your hand by the betted credits\nThe game is played to 21\nIf you hit 21, you win double the betted credits\nHowever, if you go over 21, you lose!\nHave fun!!!"<<endl;
      cout<<"======================"<<endl;
     cout<<"How much credits do you bet?"<<endl;
     cin>>bettedBlackJackCredits;
     while(bettedBlackJackCredits>credits)
     {
         cout<<"Error,you can't bet credits that you don't have!!!"<<endl;
          cout<<"Please enter again: "<<endl;
          cin>>bettedBlackJackCredits;
     }
      cout<<"======================"<<endl;
     firstCard=rand()%11+1;
     secondCard=rand()%11+1;
     sumOfCards=firstCard+secondCard;
     cout<<"First card: "<<firstCard<<endl;
     cout<<"Second card: "<<secondCard<<endl;
     cout<<"Current sum of cards: "<<sumOfCards<<endl;
     do
     {
         cout<<"Do you want to hit of stay?(H/S)"<<endl;
     cin>>HitOrStay;
     if(HitOrStay=='H' || HitOrStay=='h')
     {
         hit(sumOfCards);
          cout<<"Okay,your sum is "<<sumOfCards<<"!"<<endl;
     }
     else if(HitOrStay=='S' || HitOrStay=='s')
     {
         cout<<"Okay,your sum is "<<sumOfCards<<"!"<<endl;

     }
     else
     {
         cout<<"Error, please choose H/S!!!"<<endl;
         cin>>HitOrStay;
     }
     }
     while(HitOrStay=='H'|| HitOrStay=='h');

     if(sumOfCards>21)
     {
         cout<<"You went over 21, you lose!!!"<<endl;
         cout<<"======================"<<endl;
          credits=credits-bettedBlackJackCredits;

         return credits;
     }
     else if(sumOfCards==21)
     {
         cout<<"Wow, you hit 21, you won!!!"<<endl;
          credits=credits-bettedBlackJackCredits;
         betBlackJackWon=bettedBlackJackCredits*2;
         credits=credits+betBlackJackWon;
              cout<<"In total, you won "<<credits<<" credits!"<<endl;
              cout<<"======================"<<endl;
         return credits;
     }
     else
     {
          cout<<"You won !!!"<<endl;
          cout<<"You receive "<<sumOfCards<<"% extra of "<<bettedBlackJackCredits<<" credits!!!"<<endl;
            credits=credits-bettedBlackJackCredits;
           betBlackJackWon=((double)sumOfCards/100)*bettedBlackJackCredits;
           credits=credits+betBlackJackWon+bettedBlackJackCredits;
           cout<<"In total, you won "<<credits<<" credits!"<<endl;
           cout<<"======================"<<endl;
           return credits;
     }

}
//Setting mode for Horse Race
int SettingMode::settingModeHorseRace()
{
    cout<<"How much does the game cost?"<<endl;
    cin>>horseRaceCredits;
     cout<<"======================"<<endl;
    cout<<"Set Number Of Horses:"<<endl;
    cin>>numberOfHorses;
     cout<<"======================"<<endl;

  return horseRaceCredits,numberOfHorses;
}

//Default mode for Horse Race
int SettingMode::defaultSettingModeHorseRace()
{

    horseRaceCredits=10;
    numberOfHorses=5;
   return horseRaceCredits,numberOfHorses;
}

//Setting mode for Mine Field
int SettingMode::settingModeMineField()
{
     cout<<"======================"<<endl;
   cout<<"How much does the game cost?"<<endl;
    cin>>mineFieldCredits;
     cout<<"======================"<<endl;
    cout<<"Enter 'X' and 'Y' coordinates:"<<endl;
    cin>>xBoard>>yBoard;
     cout<<"======================"<<endl;
      cout<<"This is your board:"<<endl;
       cout<<"======================"<<endl;
    printBoard(xBoard, yBoard);
    cout<<"Set Number Of Mines:"<<endl;
     cout<<"======================"<<endl;
    cin>>numberOfMines;
     return numberOfMines,mineFieldCredits;

}

//Default mode for Mine Field
int SettingMode::defaultSettingModeMineField()
{
    mineFieldCredits=10;
    xBoard=5;
    yBoard=5;
    numberOfMines=10;
    cout<<"This is your board:"<<endl;
     cout<<"======================"<<endl;
    printBoard(xBoard,yBoard);
    return numberOfMines,mineFieldCredits;
}

//Function that converts 'X' coordinate to integers
int SettingMode:: letterXToInt(int returnedInt)
{
    switch(returnedInt)
    {
    case'A':
        returnedInt=0;
        break;
    case'B':
        returnedInt=1;
        break;
    case'C':
        returnedInt=2;
        break;
    case'D':
        returnedInt=3;
        break;
    case'E':
        returnedInt=4;
        break;
    case'F':
        returnedInt=5;
        break;
    case'G':
        returnedInt=6;
        break;
    case'H':
        returnedInt=7;
        break;
    case'I':
        returnedInt=8;
        break;
    case'J':
        returnedInt=9;
        break;
    case'K':
        returnedInt=10;
        break;
    case'L':
        returnedInt=11;
        break;
    case'M':
        returnedInt=12;
        break;
    case'N':
        returnedInt=13;
        break;
    case'O':
        returnedInt=14;
        break;
    case'P':
        returnedInt=15;
        break;
    case'Q':
        returnedInt=16;
        break;
    case'R':
        returnedInt=17;
        break;
    case'S':
        returnedInt=18;
        break;
    case'T':
        returnedInt=19;
        break;
    case'U':
        returnedInt=20;
        break;
    case'V':
        returnedInt=21;
        break;
    case'X':
        returnedInt=22;
        break;
    case'Y':
        returnedInt=23;
        break;
    case'Z':
        returnedInt=24;
        break;
    }
    return returnedInt;
}

//Prints the board for Mine Field
void SettingMode::printBoard(int rows, int columns)
{
    char field[rows][columns];


    for (int i=0; i<rows; i++)
        {
            for (int j = 0; j<columns;j++)
            {
                field[i][j]='O';
            }
        }

    for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      cout<<field[i][j]<<" ";
    }
    cout<<endl;
  }
}

//Checks for mines on Mine Field
void SettingMode::checkMineField(int rows,int columns,int chosenX,int chosenY)
{
    srand(time(0));

    char field[rows][columns];


    for (int i=0; i<rows; i++)
        {
            for (int j = 0; j<columns;j++)
            {
                field[i][j]='O';
            }
        }
         for(int k=1; k<=numberOfMines;k++)
        {
            int a=rand()%rows;
             int b=rand()%columns;

                   field[a][b]='X';
                   if(a==chosenX && b==chosenY)
                   {
                       mineFieldReturn=1;
                   }

        }

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<columns; j++)
        {
            cout<<field[i][j]<<" ";
        }
    cout<<endl;
  }

}

//Setting mode for Blackjack
int SettingMode::settingModeBlackJack()
{
    cout<<"======================"<<endl;
   cout<<"How much does the game cost?"<<endl;
    cin>> blackJackCredits;
    return blackJackCredits;
}

//Default mode for Blackjack
int SettingMode::defaultSettingModeBlackJack()
{
     blackJackCredits=10;
     return blackJackCredits;
}

//Gives another card for Blackjack
int SettingMode::hit(int currentCards)
{
    anotherCard=rand()%11+1;
    cout<<"AnotherCard: "<<anotherCard<<endl;
    sumOfCards=sumOfCards+anotherCard;
    return sumOfCards;
}
