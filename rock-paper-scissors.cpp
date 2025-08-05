#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enWinner
{
    Computer = 1,
    Player = 2,
    Draw = 3
};

enum enGameChoices
{
    rock = 1,
    papers = 2,
    scissors = 3
};

struct stGameResult
{
    int gameRounds = 0;
    int PlayerWins = 0;
    int ComputerWins = 0;
    int nbOfDraws = 0;
    enWinner gameWinner;
    string winnerName;
};

struct stRoundInfo
{
    int roundNumber = 0;
    enGameChoices playerChoice;
    enGameChoices computerChoice;
    enWinner roundWinner;
    string winnerName;
};

int RandNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

enGameChoices getComputerChoice()
{
    return (enGameChoices)RandNumber(1, 3);
}

enGameChoices readPlayerChoice()
{
    short choiceNumber = 0;
    do
    {
        cout << "\nPLease Choose an option: [1]rock , [2] papers, [3] scissors ?" << endl;
        cin >> choiceNumber;
    } while (choiceNumber < 1 || choiceNumber > 3);

    return (enGameChoices)choiceNumber;
}

enWinner roundWinner(stRoundInfo round)
{
    if (round.playerChoice == round.computerChoice)
    {
        return Draw;
    }

    switch (round.playerChoice)
    {
    case rock:
        return (round.computerChoice == papers) ? Computer : Player;
    case papers:
        return (round.computerChoice == rock) ? Player : Computer;
    case scissors:
        return (round.computerChoice == rock) ? Computer : Player;
    default:
        break;
    }
}

string readPlayerName()
{
    string name = "";
    cout << "\nEnter You're Name : ";
    cin >> name;
    return name;
}

string GetWinnerName(enWinner winner, string playerName)
{
    string arrWinnerNames[3] = {"Computer", playerName, "Draw"};
    return arrWinnerNames[winner - 1];
}

string GetChoiceName(enGameChoices choice)
{
    string arrGameChoices[3] = {"rock", "paperS", "scissors"};
    return arrGameChoices[choice - 1];
}

void GetFinalWinner(stGameResult &game)
{
    if (game.ComputerWins == game.PlayerWins)
    {
        game.winnerName = "Draw";
    }
    else if (game.ComputerWins > game.PlayerWins)
    {
        game.winnerName = "Computer";
    }
    else
    {
        game.winnerName = "Player";
    }
}

short readHowManyRounds()
{
    short rounds = 0;
    do
    {
        cout << "Please Enter how many rounds do you want to play : " << endl;
        cin >> rounds;
    } while (rounds <= 0);
    return rounds;
}

void showRoundResults(stRoundInfo round)
{
    cout << "\n__________Round[" << round.roundNumber << "]__________" << endl;
    cout << "Player Choice : " << GetChoiceName(round.playerChoice) << endl;
    cout << "Computer Choice : " << GetChoiceName(round.computerChoice) << endl;
    cout << "Round Winner : " << round.winnerName << endl;
    cout << "____________________________" << endl;
}

void updateWinDrawsCounter(stRoundInfo round, stGameResult &game)
{

    if (round.winnerName == "Player")
    {
        game.PlayerWins++;
    }
    else if (round.winnerName == "Computer")
    {
        game.ComputerWins++;
    }
    else
    {
        game.nbOfDraws++;
    }
}

void displayColor(string winner)
{
    if (winner == "Computer")
    {
        system("color 4F");
    }
    else if (winner == "Draw")
    {
        system("color 6F");
    }
    else
    {
        system("color 2F");
    }
}

void showEndScreen(stGameResult &game, string playerName)
{
    displayColor(game.winnerName);
    GetFinalWinner(game);
    cout << "\n\t\t_____________________________" << endl;
    cout << "\n\t\t__________Game Over__________" << endl;
    cout << "\t\tGAME ROUNDS : " << game.gameRounds << endl;
    cout << "\t\t" << playerName << " wins : " << game.PlayerWins << endl;
    cout << "\t\tComputer Winds : " << game.ComputerWins << endl;
    cout << "\t\tDraws times : " << game.nbOfDraws << endl;
    cout << "\t\tGame Winner : " << game.winnerName << endl;
    cout << "\t\t_____________________________" << endl;
}

stGameResult playGame(short gameRounds, string playerName)
{
    int gameRound = 1;
    stRoundInfo round;
    stGameResult gameResult;
    gameResult.gameRounds = gameRounds;
    while (gameRound <= gameRounds)
    {
        cout << "\nRound [" << gameRound << "]  begins :" << endl;
        round.roundNumber = gameRound;
        round.computerChoice = getComputerChoice();
        round.playerChoice = readPlayerChoice();
        round.roundWinner = roundWinner(round);
        round.winnerName = GetWinnerName(round.roundWinner, playerName);
        showRoundResults(round);
        updateWinDrawsCounter(round, gameResult);
        gameRound++;
    }
    return gameResult;
}

void startGame()
{
    char playAgain = 'y';

    do
    {
        system("color 0F");
        string playerName = readPlayerName();
        stGameResult game = playGame(readHowManyRounds(), playerName);
        showEndScreen(game, playerName);
        cout << "\nDo You Want to play again y or n ?" << endl;
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));
    startGame();

    return 0;
}