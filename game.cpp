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


#include "cycle.h"

using namespace std;


vector<string> unrevealedLetter = {"?????",
                                   "?????",
                                   "?????",
                                   "?????",
                                   "?????"};

vector<string> num0Letter = {"\u250C\u2500\u2500\u2500\u2510",
                       "\u2502   \u2502",
                       "\u2502   \u2502",
                       "\u2502   \u2502",
                       "\u2514\u2500\u2500\u2500\u2518"};
vector<string> num1Letter = {" \u2500\u2510  ",
                       "  \u2502  ",
                       "  \u2502  ",
                       "  \u2502  ",
                       "\u2500\u2500\u2534\u2500\u2500"};
vector<string> num2Letter = {"\u2576\u2500\u2500\u2500\u2510",
                       "    \u2502",
                       "\u250C\u2500\u2500\u2500\u2518",
                       "\u2502    ",
                       "\u2514\u2500\u2500\u2500\u2574"};
vector<string> num3Letter = {"\u2576\u2500\u2500\u2500\u2510",
                       "    \u2502",
                       "\u2576\u2500\u2500\u2500\u2524",
                       "    \u2502",
                       "\u2576\u2500\u2500\u2500\u2518"};
vector<string> num4Letter = {"\u2577   \u2577",
                       "\u2502   \u2502",
                       "\u2514\u2500\u2500\u2500\u2524",
                       "    \u2502",
                       "    \u2514"};
vector<string> num5Letter = {"\u250C\u2500\u2500\u2500\u2574",
                       "\u2502    ",
                       "\u2514\u2500\u2500\u2500\u2510",
                       "    \u2502",
                       "\u2576\u2500\u2500\u2500\u2518"};
vector<string> num6Letter = {"\u250C\u2500\u2500\u2500\u2574",
                       "\u2502    ",
                       "\u251C\u2500\u2500\u2500\u2510",
                       "\u2502   \u2502",
                       "\u2514\u2500\u2500\u2500\u2518"};
vector<string> num7Letter = {"\u250C\u2500\u2500\u2500\u2510",
                       "    \u2502",
                       "    \u2502",
                       "    \u2502",
                       "    \u2514"};
vector<string> num8Letter = {"\u250C\u2500\u2500\u2500\u2510",
                       "\u2502   \u2502",
                       "\u251C\u2500\u2500\u2500\u2524",
                       "\u2502   \u2502",
                       "\u2514\u2500\u2500\u2500\u2518"};
vector<string> num9Letter = {"\u250C\u2500\u2500\u2500\u2510",
                       "\u2502   \u2502",
                       "\u2514\u2500\u2500\u2500\u2524",
                       "    \u2502",
                       "    \u2502"};
vector<vector<string>> numbers = {num0Letter, num1Letter, num2Letter, num3Letter, num4Letter, num5Letter, num6Letter, num7Letter, num8Letter, num9Letter};
vector<string> num1TensBox = unrevealedLetter;
vector<string> num1OnesBox = unrevealedLetter;
vector<string> num2TensBox = unrevealedLetter;
vector<string> num2OnesBox = unrevealedLetter;


vector<string> cycleNum0Letter = {"\u256D\u2500\u2500\u2500\u256E",
                                  "\u2502   \u2502",
                                  "\u2570\u2500\u2500\u2500\u256F"};
vector<string> cycleNum1Letter = {" \u2500\u256E  ",
                                  "  \u2502  ",
                                  "\u2500\u2500\u2534\u2500\u2500"};
vector<string> cycleNum2Letter = {"\u2576\u2500\u2500\u2500\u256E",
                                  "\u256D\u2500\u2500\u2500\u256F",
                                  "\u2570\u2500\u2500\u2500\u2574"};
vector<string> cycleNum3Letter = {"\u2576\u2500\u2500\u2500\u256E",
                                  "\u2576\u2500\u2500\u2500\u2524",
                                  "\u2576\u2500\u2500\u2500\u256F"};
vector<string> cycleNum4Letter = {"\u2577   \u2577",
                                  "\u2570\u2500\u2500\u2500\u2524",
                                  "    \u2514"};
vector<string> cycleNum5Letter = {"\u256D\u2500\u2500\u2500\u2574",
                                  "\u2570\u2500\u2500\u2500\u256E",
                                  "\u2576\u2500\u2500\u2500\u256F"};
vector<string> cycleNum6Letter = {"\u256D\u2500\u2500\u2500\u2574",
                                  "\u251C\u2500\u2500\u2500\u256E",
                                  "\u2570\u2500\u2500\u2500\u256F"};
vector<string> cycleNum7Letter = {"\u256D\u2500\u2500\u2500\u256E",
                                  "    \u2502",
                                  "    \u2514"};
vector<string> cycleNum8Letter = {"\u256D\u2500\u2500\u2500\u256E",
                                  "\u251C\u2500\u2500\u2500\u2524",
                                  "\u2570\u2500\u2500\u2500\u256F"};
vector<string> cycleNum9Letter = {"\u256D\u2500\u2500\u2500\u256E",
                                  "\u2570\u2500\u2500\u2500\u2524",
                                  "    \u2514"};
vector<vector<string>> cycleNumbers = {cycleNum0Letter, cycleNum1Letter, cycleNum2Letter, cycleNum3Letter, cycleNum4Letter, cycleNum5Letter, cycleNum6Letter, cycleNum7Letter, cycleNum8Letter, cycleNum9Letter};
vector<string> cycleTensBox = cycleNumbers[0];
vector<string> cycleOnesBox = cycleNumbers[0];

//                       7654321
int animateMicroSeconds = 200000;


int N = 20;
int num1 = 5, num2 = 15;

int input;
int introSelect = 0; //0: Lore, 1: instructions, 2: startgame
int introPrint = 0; //0: welcome, 1: lore, 2: instructions

int gameSelect = 1; //0: low, 1: high

double current=10, mult=1;
double totalEarned = 0;
double totalLost = 0;
int loststreak = 0;
int winstreak = 0;

bool winCycle = false;
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




void printIntroScreen() {
    cout << "\033[2J\033[1;1H";
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
    vector<string> instructions = {"┃  You're given a number, then guess if the next is higher or lower  ┃\n",
                                   "┃   If you guess correct, you gain coins, if wrong, you lose coins   ┃\n",
                                   "┃   Here's the twist: the riskier the guess, the better the reward   ┃\n",
                                   "┃                but also the worse the punishment...                ┃\n",
                                   "┃            Stay safe as always, don't go insane, yet ;)            ┃\n"};
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
    cout << "\033[2J\033[1;1H";

    string gameScreenTop =                       "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    vector<string> gameScreenCycle =            {"┃                             ╭───╴╷   ╷╭───╴╷    ╭───╴ "+cycleTensBox[0]+" "+cycleOnesBox[0]+"  ┃\n",
                                                 "┃                             │    ╰─┬─╯│    │    ├───╴ "+cycleTensBox[1]+" "+cycleOnesBox[1]+"  ┃\n",
                                                 "┃                             ╰───╴  ╵  ╰───╴╰───╴╰───╴ "+cycleTensBox[2]+" "+cycleOnesBox[2]+"  ┃\n"};
    string gameScreenEmpty =                     "┃                                                                    ┃\n";
    vector<string> gameScreenTurnsQuotaWallet = {"┃             ╭─────────────────╮    ╭─────────────────╮             ┃\n",
                                                 "┃             │    Turn #00     │    │   Quota: 000.00 │             ┃\n",
                                                 "┃             │ Total turns: 00 │    │  Wallet: 000.00 │             ┃\n",
                                                 "┃             ╰─────────────────╯    ╰─────────────────╯             ┃\n"};
    vector<string> upButtHigh =                 {"┃  ╔═════════╗                                                       ┃\n",
                                                 "┃  ║  ↑↑↑↑↑  ║                                                       ┃\n",
                                                 "┃  ║  ↑↑↑↑↑  ║    ╭─────────────╮    ╭─────────────╮                 ┃\n",
                                                 "┃  ║  ↑↑↑↑↑  ║    │ "+num1TensBox[0]+" "+num1OnesBox[0]+" │    │ "+num2TensBox[0]+" "+num2OnesBox[0]+" │                 ┃\n",
                                                 "┃  ╚═════════╝    │ "+num1TensBox[1]+" "+num1OnesBox[1]+" │    │ "+num2TensBox[1]+" "+num2OnesBox[1]+" │                 ┃\n",
                                                 "┃                 │ "+num1TensBox[2]+" "+num1OnesBox[2]+" │    │ "+num2TensBox[2]+" "+num2OnesBox[2]+" │                 ┃\n",
                                                 "┃  ┌─────────┐    │ "+num1TensBox[3]+" "+num1OnesBox[3]+" │    │ "+num2TensBox[3]+" "+num2OnesBox[3]+" │                 ┃\n",
                                                 "┃  │  ↓↓↓↓↓  │    │ "+num1TensBox[4]+" "+num1OnesBox[4]+" │    │ "+num2TensBox[4]+" "+num2OnesBox[4]+" │                 ┃\n",
                                                 "┃  │  ↓↓↓↓↓  │    ╰─────────────╯    ╰─────────────╯                 ┃\n",
                                                 "┃  │  ↓↓↓↓↓  │                                                       ┃\n",
                                                 "┃  └─────────┘                                                       ┃\n"};
    vector<string> downButtHigh =               {"┃  ┌─────────┐                                                       ┃\n",
                                                 "┃  │  ↑↑↑↑↑  │                                                       ┃\n",
                                                 "┃  │  ↑↑↑↑↑  │    ╭─────────────╮    ╭─────────────╮                 ┃\n",
                                                 "┃  │  ↑↑↑↑↑  │    │ "+num1TensBox[0]+" "+num1OnesBox[0]+" │    │ "+num2TensBox[0]+" "+num2OnesBox[0]+" │                 ┃\n",
                                                 "┃  └─────────┘    │ "+num1TensBox[1]+" "+num1OnesBox[1]+" │    │ "+num2TensBox[1]+" "+num2OnesBox[1]+" │                 ┃\n",
                                                 "┃                 │ "+num1TensBox[2]+" "+num1OnesBox[2]+" │    │ "+num2TensBox[2]+" "+num2OnesBox[2]+" │                 ┃\n",
                                                 "┃  ╔═════════╗    │ "+num1TensBox[3]+" "+num1OnesBox[3]+" │    │ "+num2TensBox[3]+" "+num2OnesBox[3]+" │                 ┃\n",
                                                 "┃  ║  ↓↓↓↓↓  ║    │ "+num1TensBox[4]+" "+num1OnesBox[4]+" │    │ "+num2TensBox[4]+" "+num2OnesBox[4]+" │                 ┃\n",
                                                 "┃  ║  ↓↓↓↓↓  ║    ╰─────────────╯    ╰─────────────╯                 ┃\n",
                                                 "┃  ║  ↓↓↓↓↓  ║                                                       ┃\n",
                                                 "┃  ╚═════════╝                                                       ┃\n"};
    string gameScreenControls =                  "┃    [W][S][Space]: Scroll between choice  [Enter]: Select choice    ┃\n";
    string gameScreenBottom =                    "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    cout << gameScreenTop;
    for(string line : gameScreenCycle) cout << line;
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
1. Create initial 10 coins and mult = 1, and prepare for cycle 1

Cycle init:
1. Generate cycle: initiate cycleNum, quota, and how many turns

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
    while(num1 == 0 || num1 == 20) num1 = rand()%(N-1)+1;
    while(num2 == num1 || num2 == 0 || num2 == 20) num2 = rand()%(N+1);
    for(int temp = 0; temp < 25; temp++) {
        int LocX = rand()%5;
        int LocY = rand()%5;
        while(num1TensBox[LocX][LocY]+"" == "?") LocX = rand()%5, LocY = rand()%5;
        num1TensBox[LocX][LocY] = numbers[num1/10][LocX][LocY];
        LocX = rand()%5, LocY = rand()%5;
        while(num1OnesBox[LocX][LocY]+"" == "?") LocX = rand()%5, LocY = rand()%5;
        num1OnesBox[LocX][LocY] = numbers[num1%10][LocX][LocY];
        printGameScreen();
        usleep(animateMicroSeconds);
    }
}

void genCycle() {
    genTurnNumbers();
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    _setmode(_fileno(stdout), CP_UTF8);

    srand(time(0));

    printIntroScreen();

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
    
    // genCycle();

    genTurnNumbers();
    cout << num1 << endl;
    while(input != 13) {
        //W: 87 119 | S: 83 115 | Space: 32
        if(input == 87 || input == 119 || input == 83 || input == 115 || input == 32) gameSelect = (gameSelect+1)%2;
        printGameScreen();
        input = getch();
    }
    // Revealing animation
    // num2TensBox = numbers[num2/10], num2OnesBox = numbers[num2%10];
    // printGameScreen();
    


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
    Cycle *cList[cListSize];
    Cycle *c1 = new Cycle(), *c2 = new Cycle(), *c3 = new Cycle(), *c4 = new Cycle(), *c5 = new Cycle(), *c6 = new Cycle(), *c7 = new Cycle();
    c1->cycleNum = 1, c1->quota = 13, c1->turns = 10;
    c2->cycleNum = 2, c2->quota = 5, c2->turns = 10;
    c3->cycleNum = 3, c3->quota = 8, c3->turns = 7;
    c4->cycleNum = 4, c4->quota = 15, c4->turns = 6;
    c5->cycleNum = 5, c5->quota = 20, c5->turns = 5;
    c6->cycleNum = 6, c6->quota = 24, c6->turns = 5;
    c7->cycleNum = 6, c7->quota = 25, c7->turns = 4;
    cList[0] = c1;
    cList[1] = c2;
    cList[2] = c3;
    cList[3] = c4;
    cList[4] = c5;
    cList[5] = c6;
    cList[6] = c7;


    cout << "Wow... you won? Congratulations huh... You did it :)" << endl;
    cout << "Game finished, hit enter to quit";




input = getch();
    //W: 87 119
    //S: 83 115
    //Space: 32
    //Enter: 13
    if(input == 87 || input == 119 || input == 83 || input == 115 || input == 32) {
        gameSelect = (gameSelect+1)%2;
        printGameScreen();
    } else if(input == 13) {
        // Back end moment (im scared of animating revealing the number oh boy) 

        vector<vector<bool>> revealed = {{false, false, false, false, false, false, false, false, false, false, false},
                                         {false, false, false, false, false, false, false, false, false, false, false},
                                         {false, false, false, false, false, false, false, false, false, false, false},
                                         {false, false, false, false, false, false, false, false, false, false, false},
                                         {false, false, false, false, false, false, false, false, false, false, false}};
        for(int i = 0; i < 5; i++) for(int j = 0; j < 11; j++) cout << revealed[i][j];
        for(int temp = 0; temp < 50; temp++) {
            int locX = rand()%5;
            int locY = rand()%11;
            while(revealed[locX][locY] || locY == 5) locX = rand()%5, locY = rand()%11;
            revealed[locX][locY] = true;
            num2Box[locX+3][locY+2] = num2ToShow[locX+1][locY+2];
        }
        for(int i = 0; i < 5; i++) for(int j = 0; j < 11; j++) cout << revealed[i][j];

        printGameScreen();
    } else {
        printGameScreen();
    }


*/