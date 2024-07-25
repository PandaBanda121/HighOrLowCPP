#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <unistd.h>


#include <Windows.h>
#pragma execution_character_set("utf-8")

#include <fcntl.h>


#include "set.h"

using namespace std;

vector<vector<bool>> falseVector3x5 = {{false, false, false, false, false},
                                      {false, false, false, false, false},
                                      {false, false, false, false, false}};


vector<vector<string>> unrevealedLetter = {{"?","?","?","?","?"},
                                           {"?","?","?","?","?"},
                                           {"?","?","?","?","?"},
                                           {"?","?","?","?","?"},
                                           {"?","?","?","?","?"}};

vector<vector<string>> num0Letter = {{"┌","─","─","─","┐"},
                                     {"│"," "," "," ","│"},
                                     {"│"," "," "," ","│"},
                                     {"│"," "," "," ","│"},
                                     {"└","─","─","─","┘"}};
vector<vector<string>> num1Letter = {{" ","─","┐"," "," "},
                                     {" "," ","│"," "," "},
                                     {" "," ","│"," "," "},
                                     {" "," ","│"," "," "},
                                     {"─","─","┴","─","─"}};
vector<vector<string>> num2Letter = {{"╶","─","─","─","┐"},
                                     {" "," "," "," ","│"},
                                     {"┌","─","─","─","┘"},
                                     {"│"," "," "," "," "},
                                     {"└","─","─","─","╴"}};
vector<vector<string>> num3Letter = {{"╶","─","─","─","┐"},
                                     {" "," "," "," ","│"},
                                     {"╶","─","─","─","┤"},
                                     {" "," "," "," ","│"},
                                     {"╶","─","─","─","┘"}};
vector<vector<string>> num4Letter = {{"╷"," "," "," ","╷"},
                                     {"│"," "," "," ","│"},
                                     {"└","─","─","─","┤"},
                                     {" "," "," "," ","│"},
                                     {" "," "," "," ","╵"}};
vector<vector<string>> num5Letter = {{"┌","─","─","─","╴"},
                                     {"│"," "," "," "," "},
                                     {"└","─","─","─","┐"},
                                     {" "," "," "," ","│"},
                                     {"╶","─","─","─","┘"}};
vector<vector<string>> num6Letter = {{"┌","─","─","─","╴"},
                                     {"│"," "," "," "," "},
                                     {"├","─","─","─","┐"},
                                     {"│"," "," "," ","│"},
                                     {"└","─","─","─","┘"}};
vector<vector<string>> num7Letter = {{"┌","─","─","─","┐"},
                                     {" "," "," "," ","│"},
                                     {" "," "," "," ","│"},
                                     {" "," "," "," ","│"},
                                     {" "," "," "," ","╵"}};
vector<vector<string>> num8Letter = {{"┌","─","─","─","┐"},
                                     {"│"," "," "," ","│"},
                                     {"├","─","─","─","┤"},
                                     {"│"," "," "," ","│"},
                                     {"└","─","─","─","┘"}};
vector<vector<string>> num9Letter = {{"┌","─","─","─","┐"},
                                     {"│"," "," "," ","│"},
                                     {"└","─","─","─","┤"},
                                     {" "," "," "," ","│"},
                                     {" "," "," "," ","│"}};
vector<vector<vector<string>>> numbers = {num0Letter, num1Letter, num2Letter, num3Letter, num4Letter, num5Letter, num6Letter, num7Letter, num8Letter, num9Letter};
vector<vector<string>> num1TensBox = unrevealedLetter;
vector<vector<string>> num1OnesBox = unrevealedLetter;
vector<vector<string>> num2TensBox = unrevealedLetter;
vector<vector<string>> num2OnesBox = unrevealedLetter;


vector<vector<string>> setNum0Letter = {{"╭","─","─","─","╮"},
                                          {"│"," "," "," ","│"},
                                          {"╰","─","─","─","╯"}};
vector<vector<string>> setNum1Letter = {{" ","─","┐"," "," "},
                                          {" "," ","│"," "," "},
                                          {"─","─","┴","─","─"}};
vector<vector<string>> setNum2Letter = {{"╶","─","─","─","┐"},
                                          {"┌","─","─","─","┘"},
                                          {"└","─","─","─","╴"}};
vector<vector<string>> setNum3Letter = {{"╶","─","─","─","┐"},
                                          {"╶","─","─","─","┤"},
                                          {"╶","─","─","─","┘"}};
vector<vector<string>> setNum4Letter = {{"╷"," "," "," ","╷"},
                                          {"└","─","─","─","┤"},
                                          {" "," "," "," ","╵"}};
vector<vector<string>> setNum5Letter = {{"┌","─","─","─","╴"},
                                          {"└","─","─","─","┐"},
                                          {"╶","─","─","─","┘"}};
vector<vector<string>> setNum6Letter = {{"┌","─","─","─","╴"},
                                          {"├","─","─","─","┐"},
                                          {"└","─","─","─","┘"}};
vector<vector<string>> setNum7Letter = {{"┌","─","─","─","┐"},
                                          {" "," "," "," ","│"},
                                          {" "," "," "," ","╵"}};
vector<vector<string>> setNum8Letter = {{"┌","─","─","─","┐"},
                                          {"├","─","─","─","┤"},
                                          {"└","─","─","─","┘"}};
vector<vector<string>> setNum9Letter = {{"┌","─","─","─","┐"},
                                          {"└","─","─","─","┤"},
                                          {" "," "," "," ","╵"}};
vector<vector<vector<string>>> setNumbers = {setNum0Letter, setNum1Letter, setNum2Letter, setNum3Letter, setNum4Letter, setNum5Letter, setNum6Letter, setNum7Letter, setNum8Letter, setNum9Letter};
vector<vector<string>> setTensBox = setNumbers[0];
vector<vector<string>> setOnesBox = setNumbers[0];
vector<vector<bool>> setTensChanged = falseVector3x5;
vector<vector<bool>> setOnesChanged = falseVector3x5;

int setNum = 1;

//                     7654321
int animateMicroSeconds = 1000;


int N = 20;
int num1 = 5, num2 = 15;

int input;
int introSelect = 0; //0: Lore, 1: instructions, 2: startgame
int introPrint = 0; //0: welcome, 1: lore, 2: instructions

int gameSelect = 1; //0: low, 1: high

double current=10, mult=1;
double quota;

int turns
double totalEarned = 0;
double totalLost = 0;

int lostStreak = 0;
int winStreak = 0;

int longestLostStreak = 0;
int longestWinStreak = 0;

string result = "                                                   ";

int quota;




bool winSet = false;
bool winGame = false;
bool lostGame = false;
bool quitGame = false;


// Intro Screen
void printIntroScreen();

//Game Screen
void printGameScreen();

// Back-end Main Function

// 3 smaller functions for back-end

// Quit Game Checker


string vectorToString(vector<string> arr) {
    string s = "";
    for(string thing : arr) s = s+thing;
    return s; 
}



void printIntroScreen() {
    string top =                   "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    string empty =                 "┃                                                                    ┃\n";
    vector<string> intro =        {"┃                              Welcome!                              ┃\n",
                                   "┃        Here to feed your uncontrollable gambling addiction?        ┃\n",
                                   "┃                    You came to the right place.                    ┃\n",
                                   "┃               This is a simple game of taking risks.               ┃\n",
                                   "┃                             Good luck!                             ┃\n"};
    vector<string> lore =         {"┃              Oh, so you want to know lore about this?              ┃\n",
                                   "┃             Well... the game all started with a \033[;36mPanda\033[;37m.             ┃\n",
                                   "┃             He relaxed under the calm spring sunshine.             ┃\n",
                                   "┃                             That's it.                             ┃\n",
                                   "┃                            (Part 01/25)                            ┃\n"};
    vector<string> instructions = {"┃  In each set, you have to reach a quota within a number of turns.  ┃\n",
                                   "┃  In each turn, you're given a number and you guess if the next is  ┃\n",
                                   "┃                          \033[1;31mhigher\033[0m or \033[1;32mlower\033[0m.                          ┃\n",
                                   "┃           The riskier the guess, the greater the reward,           ┃\n",
                                   "┃          but, also the worse the punishment... Good Luck!          ┃\n"};
    vector<string> butt1high =    {"┃                    ╭──────────────────────────╮                    ┃\n",
                                   "┃                    │ [1] Game Background/Lore │                    ┃\n",
                                   "┃                    ╰──────────────────────────╯                    ┃\n"};
    vector<string> butt1 =        {"┃                                                                    ┃\n",
                                   "┃                      [1] Game Background/Lore                      ┃\n",
                                   "┃                                                                    ┃\n"};
    vector<string> butt2high =    {"┃                        ╭──────────────────╮                        ┃\n",
                                   "┃                        │ [2] Instructions │                        ┃\n",
                                   "┃                        ╰──────────────────╯                        ┃\n"};
    vector<string> butt2 =        {"┃                                                                    ┃\n",
                                   "┃                          [2] Instructions                          ┃\n",
                                   "┃                                                                    ┃\n"};
    vector<string> butt3high =    {"┃                         ╭────────────────╮                         ┃\n",
                                   "┃                         │ [3] Start Game │                         ┃\n",
                                   "┃                         ╰────────────────╯                         ┃\n"};
    vector<string> butt3 =        {"┃                                                                    ┃\n",
                                   "┃                           [3] Start Game                           ┃\n",
                                   "┃                                                                    ┃\n"};
    string controls =              "┃       [W][S]: Scroll through options  [Enter]: Select option       ┃\n";
    string bottom =                "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    cout << "\033[2J\033[1;1H";
    cout << top << empty << empty;
    if(introPrint == 0) for(string line : intro) cout << line;
    else if(introPrint == 1) for(string line : lore) cout << line;
    else if(introPrint == 2) for(string line : instructions) cout << line;
    cout << empty;
    if(introSelect == 0) for(string line : butt1high) cout << line;
    else for(string line : butt1) cout << line;
    if(introSelect == 1) for(string line : butt2high) cout << line;
    else for(string line : butt2) cout << line;
    if(introSelect == 2) for(string line : butt3high) cout << line;
    else for(string line : butt3) cout << line;
    cout << empty << empty;
    cout << controls;
    cout << empty << empty;
    cout << bottom;

    input = getch(); //w: 119, 87 s: 115, 83
    if(input == 87 || input == 119) { // W/w
        introSelect = (introSelect-1+3)%3;
        printIntroScreen();
    } else if(input == 83 || input == 115) { // S/s
        introSelect = (introSelect+1+3)%3;
        printIntroScreen();
    } else if(input == 13) { // [Enter]
        if(introSelect == 2) printGameScreen;
        else {
            introPrint = introSelect+1;
            introSelect = 0;
            printIntroScreen();
        }
    } else printIntroScreen();
}


void printGameScreen() {
    string gameScreenTop =                       "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    vector<string> gameScreenSet =            {"┃                                         ╭───╴╭───╴╶─┬─╴ "+vectorToString(setTensBox[0])+vectorToString(setOnesBox[0])+" ┃\n",
                                                 "┃                                         ╰───╮├───╴  │   "+vectorToString(setTensBox[1])+vectorToString(setOnesBox[1])+" ┃\n",
                                                 "┃                                         ╶───╯╰───╴  ╵   "+vectorToString(setTensBox[2])+vectorToString(setOnesBox[2])+" ┃\n"};
    string gameScreenEmpty =                     "┃                                                                    ┃\n";
    vector<string> gameScreenTurnsQuotaWallet = {"┃             ╭─────────────────╮    ╭─────────────────╮             ┃\n",
                                                 "┃             │    Turn #00     │    │   Quota: 000.00 │             ┃\n",
                                                 "┃             │ Total turns: 00 │    │  Wallet: 000.00 │             ┃\n",
                                                 "┃             ╰─────────────────╯    ╰─────────────────╯             ┃\n"};
    vector<string> upButtHigh =                 {"┃  ╔═════════╗                                                       ┃\n",
                                                 "┃  ║  ↑↑↑↑↑  ║                                                       ┃\n",
                                                 "┃  ║  ↑↑↑↑↑  ║    ╭─────────────╮    ╭─────────────╮                 ┃\n",
                                                 "┃  ║  ↑↑↑↑↑  ║    │ "+vectorToString(num1TensBox[0])+" "+vectorToString(num1OnesBox[0])+" │    │ "+vectorToString(num2TensBox[0])+" "+vectorToString(num2OnesBox[0])+" │                 ┃\n",
                                                 "┃  ╚═════════╝    │ "+vectorToString(num1TensBox[1])+" "+vectorToString(num1OnesBox[1])+" │    │ "+vectorToString(num2TensBox[1])+" "+vectorToString(num2OnesBox[1])+" │                 ┃\n",
                                                 "┃                 │ "+vectorToString(num1TensBox[2])+" "+vectorToString(num1OnesBox[2])+" │    │ "+vectorToString(num2TensBox[2])+" "+vectorToString(num2OnesBox[2])+" │                 ┃\n",
                                                 "┃  ┌─────────┐    │ "+vectorToString(num1TensBox[3])+" "+vectorToString(num1OnesBox[3])+" │    │ "+vectorToString(num2TensBox[3])+" "+vectorToString(num2OnesBox[3])+" │                 ┃\n",
                                                 "┃  │  ↓↓↓↓↓  │    │ "+vectorToString(num1TensBox[4])+" "+vectorToString(num1OnesBox[4])+" │    │ "+vectorToString(num2TensBox[4])+" "+vectorToString(num2OnesBox[4])+" │                 ┃\n",
                                                 "┃  │  ↓↓↓↓↓  │    ╰─────────────╯    ╰─────────────╯                 ┃\n",
                                                 "┃  │  ↓↓↓↓↓  │                                                       ┃\n",
                                                 "┃  └─────────┘    "+result+"┃\n"};
    vector<string> downButtHigh =               {"┃  ┌─────────┐                                                       ┃\n",
                                                 "┃  │  ↑↑↑↑↑  │                                                       ┃\n",
                                                 "┃  │  ↑↑↑↑↑  │    ╭─────────────╮    ╭─────────────╮                 ┃\n",
                                                 "┃  │  ↑↑↑↑↑  │    │ "+vectorToString(num1TensBox[0])+" "+vectorToString(num1OnesBox[0])+" │    │ "+vectorToString(num2TensBox[0])+" "+vectorToString(num2OnesBox[0])+" │                 ┃\n",
                                                 "┃  └─────────┘    │ "+vectorToString(num1TensBox[1])+" "+vectorToString(num1OnesBox[1])+" │    │ "+vectorToString(num2TensBox[1])+" "+vectorToString(num2OnesBox[1])+" │                 ┃\n",
                                                 "┃                 │ "+vectorToString(num1TensBox[2])+" "+vectorToString(num1OnesBox[2])+" │    │ "+vectorToString(num2TensBox[2])+" "+vectorToString(num2OnesBox[2])+" │                 ┃\n",
                                                 "┃  ╔═════════╗    │ "+vectorToString(num1TensBox[3])+" "+vectorToString(num1OnesBox[3])+" │    │ "+vectorToString(num2TensBox[3])+" "+vectorToString(num2OnesBox[3])+" │                 ┃\n",
                                                 "┃  ║  ↓↓↓↓↓  ║    │ "+vectorToString(num1TensBox[4])+" "+vectorToString(num1OnesBox[4])+" │    │ "+vectorToString(num2TensBox[4])+" "+vectorToString(num2OnesBox[4])+" │                 ┃\n",
                                                 "┃  ║  ↓↓↓↓↓  ║    ╰─────────────╯    ╰─────────────╯                 ┃\n",
                                                 "┃  ║  ↓↓↓↓↓  ║                                                       ┃\n",
                                                 "┃  ╚═════════╝    "+result+"┃\n"};
    string gameScreenControls =                  "┃     [W][S]: Switch Up/Down  [Space]: Deposit  [Enter]: Confirm     ┃\n";
    string gameScreenBottom =                    "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    cout << "\033[2J\033[1;1H";
    cout << gameScreenTop;
    for(string line : gameScreenSet) cout << line;
    cout << gameScreenEmpty;
    for(string line : gameScreenTurnsQuotaWallet) cout << line;
    if(gameSelect == 1) for(int i = 0; i < 11; i++) cout << upButtHigh[i];
    else for(int i = 0; i < 11; i++) cout << downButtHigh[i];
    cout << gameScreenEmpty;
    cout << gameScreenControls;
    cout << gameScreenEmpty;
    cout << gameScreenBottom;
}




/*

Breakdown of backend (bc it needs to be reworked):
Game init:
1. Create initial 10 coins and mult = 1, and prepare for set 1

Set init:
1. Generate set: initiate setNum, quota, and how many turns

2. Wait for player move: A) select higher, B) select lower

3. Create result:
Front end: show right or wrong
Back end:
double multAdd = (double) num1/N;
if(chosen lower) multAdd = 1.00-multAdd;
if(!winTurn) multAdd = -multAdd;
mult = mult+multAdd;

4. check if deposit possible
if not, go to next turn

turn++ until reach turn number

check if reached quota: go to next round
if not, lose, game over

*/

void genTurnNumbers() {
    // printGameScreen();
    num1 = rand()%(N-1)+1, num2 = rand()%(N+1);
    while(num2 == num1) num2 = rand()%(N+1);
    for(int temp = 0; temp < 25; temp++) {
        int LocX = rand()%5;
        int LocY = rand()%5;
        while(num1TensBox[LocX][LocY]+"" != "?") LocX = rand()%5, LocY = rand()%5;
        num1TensBox[LocX][LocY] = numbers[num1/10][LocX][LocY];
        usleep(animateMicroSeconds);
        LocX = rand()%5, LocY = rand()%5;
        while(num1OnesBox[LocX][LocY]+"" != "?") LocX = rand()%5, LocY = rand()%5;
        num1OnesBox[LocX][LocY] = numbers[num1%10][LocX][LocY];
        printGameScreen();
        usleep(animateMicroSeconds);
    }
}

void genNextNumbers() {
    // printGameScreen();
    for(int temp = 0; temp < 25; temp++) {
        int LocX = rand()%5;
        int LocY = rand()%5;
        while(num2TensBox[LocX][LocY]+"" != "?") LocX = rand()%5, LocY = rand()%5;
        num2TensBox[LocX][LocY] = numbers[num2/10][LocX][LocY];
        usleep(animateMicroSeconds);
        LocX = rand()%5, LocY = rand()%5;
        while(num2OnesBox[LocX][LocY]+"" != "?") LocX = rand()%5, LocY = rand()%5;
        num2OnesBox[LocX][LocY] = numbers[num2%10][LocX][LocY];
        printGameScreen();
        usleep(animateMicroSeconds);
    }
}

void genSetNumbers() {
    for(int temp = 0; temp < 15; temp++) {
        int LocX = rand()%3;
        int LocY = rand()%5;
        while(setTensChanged[LocX][LocY]) LocX = rand()%3, LocY = rand()%5;
        setTensChanged[LocX][LocY] = true;
        setTensBox[LocX][LocY] = setNumbers[setNum/10][LocX][LocY];
        usleep(animateMicroSeconds);
        LocX = rand()%3, LocY = rand()%5;
        while(setOnesChanged[LocX][LocY]) LocX = rand()%3, LocY = rand()%5;
        setOnesChanged[LocX][LocY] = true;
        setOnesBox[LocX][LocY] = setNumbers[setNum%10][LocX][LocY];
        printGameScreen();
        usleep(animateMicroSeconds);
    }
    setTensChanged = falseVector3x5;
    setOnesChanged = falseVector3x5;
}

void genSet() {
    genSetNumbers();
    genTurnNumbers();
    input = 0;
    while(input != 13) {
        //W: 87 119 | S: 83 115 | Space: 32
        if(input == 87 || input == 119) gameSelect = 1;
        if(input == 83 || input == 115) gameSelect = 0;
        printGameScreen();
        input = getch();
    }
    genNextNumbers();
    bool winTurn = ( (gameSelect == 1) && num2>num1 ) || ( (gameSelect == 0) && num2<num1 );
    if(winTurn) {
        winStreak++;
        if(winStreak > longestWinStreak) longestWinStreak = winStreak;
        lostStreak = 0;
        if(winStreak == 1)       result = "Correct.                                           ";
        else if (winStreak == 2) result = "Correct. Again.                                    ";
        else if(winStreak >= 3)  result = "Correct. Again... Are you cheating???              ";
    } else{
        lostStreak++;
        if(lostStreak > longestLostStreak) longestLostStreak = lostStreak;
        winStreak = 0;
        if(lostStreak == 1)      result = "Wrong.                                             ";
        else if(lostStreak == 2) result = "Wrong. Again.                                      ";
        else if(lostStreak >= 3) result = "Wrong. Again... Are you trying to lose???          ";
    }
    printGameScreen();
    double multAdd = (double) num1/N;
    if(gameSelect == 0) multAdd = 1.00-multAdd;
    if(!winTurn) multAdd = -multAdd;
    mult = mult+multAdd;

    cout << "You now have " << (current*mult) << endl << endl;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    _setmode(_fileno(stdout), CP_UTF8);

    srand(time(0));

    printIntroScreen();
    genSetNumbers();
    printGameScreen();
    /*
    generate round:
    1. generate turn
    2. print game screen
    3. get input
    4. print result screen
    5. generate new turn
    6. repeat
    i need to rework this entire thing
    */
    
    genSet();


    // printGameScreen();
    
    
    
    
    input = getch();
    while(input != 13) {
        cout << input << endl;
        input = getch();
    }
    return 0;
}

/*



    int cListSize = 7;
    Set *cList[cListSize];
    Set *c1 = new Set(), *c2 = new Set(), *c3 = new Set(), *c4 = new Set(), *c5 = new Set(), *c6 = new Set(), *c7 = new Set();
    c1->setNum = 1, c1->quota = 13, c1->turns = 10;
    c2->setNum = 2, c2->quota = 5, c2->turns = 10;
    c3->setNum = 3, c3->quota = 8, c3->turns = 7;
    c4->setNum = 4, c4->quota = 15, c4->turns = 6;
    c5->setNum = 5, c5->quota = 20, c5->turns = 5;
    c6->setNum = 6, c6->quota = 24, c6->turns = 5;
    c7->setNum = 6, c7->quota = 25, c7->turns = 4;
    cList[0] = c1;
    cList[1] = c2;
    cList[2] = c3;
    cList[3] = c4;
    cList[4] = c5;
    cList[5] = c6;
    cList[6] = c7;


    cout << "Wow... you won? Congratulations huh... You did it :)" << endl;
    cout << "Game finished, hit enter to quit";

*/