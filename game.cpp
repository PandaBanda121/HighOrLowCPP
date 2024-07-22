#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <conio.h>

#include <Windows.h>
#pragma execution_character_set("utf-8")


#include "round.h"

using namespace std;

int input;
int introSelect = 0; //0: Lore, 1: instructions, 2: startgame, 3: startgame
int introPrint = 0; //0: welcome, 1: lore, 2: instructions

int gameSelect = 1; //0: down, 1: up

vector<string> unrevealedLetter = {"?????",
                                   "?????",
                                   "?????",
                                   "?????",
                                   "?????"};

vector<string> num0Letter = {"┌───┐",
                       "│   │",
                       "│   │",
                       "│   │",
                       "└───┘"};
vector<string> num1Letter = {" ─┐  ",
                       "  │  ",
                       "  │  ",
                       "  │  ",
                       "──┴──"};
vector<string> num2Letter = {"╶───┐",
                       "    │",
                       "┌───┘",
                       "│    ",
                       "└───╴"};
vector<string> num3Letter = {"╶───┐",
                       "    │",
                       "╶───┤",
                       "    │",
                       "╶───┘"};
vector<string> num4Letter = {"╷   ╷",
                       "│   │",
                       "└───┤",
                       "    │",
                       "    ╵"};
vector<string> num5Letter = {"┌───╴",
                       "│    ",
                       "└───┐",
                       "    │",
                       "╶───┘"};
vector<string> num6Letter = {"┌───╴",
                       "│    ",
                       "├───┐",
                       "│   │",
                       "└───┘"};
vector<string> num7Letter = {"┌───┐",
                       "    │",
                       "    │",
                       "    │",
                       "    ╵"};
vector<string> num8Letter = {"┌───┐",
                       "│   │",
                       "├───┤",
                       "│   │",
                       "└───┘"};
vector<string> num9Letter = {"┌───┐",
                       "│   │",
                       "└───┤",
                       "    │",
                       "    │"};

vector<vector<string>> numbers = {num0Letter, num1Letter, num2Letter, num3Letter, num4Letter, num5Letter, num6Letter, num7Letter, num8Letter, num9Letter};

vector<string> cycleNum0Letter = {"╭───╮",
                            "│   │",
                            "╰───╯"};
vector<string> cycleNum1Letter = {" ─┐  ",
                            "  │  ",
                            "──┴──"};
vector<string> cycleNum2Letter = {"╶───┐",
                            "┌───┘",
                            "└───╴"};
vector<string> cycleNum3Letter = {"╶───┐",
                            "╶───┤",
                            "╶───┘"};
vector<string> cycleNum4Letter = {"╷   ╷",
                            "└───┤",
                            "    ╵"};
vector<string> cycleNum5Letter = {"┌───╴",
                            "└───┐",
                            "╶───┘"};
vector<string> cycleNum6Letter = {"┌───╴",
                            "├───┐",
                            "└───┘"};
vector<string> cycleNum7Letter = {"┌───┐",
                            "    │",
                            "    ╵"};
vector<string> cycleNum8Letter = {"┌───┐",
                            "├───┤",
                            "└───┘"};
vector<string> cycleNum9Letter = {"┌───┐",
                            "└───┤",
                            "    ╵"};

vector<vector<string>> cycleNumbers = {cycleNum0Letter, cycleNum1Letter, cycleNum2Letter, cycleNum3Letter, cycleNum4Letter, cycleNum5Letter, cycleNum6Letter, cycleNum7Letter, cycleNum8Letter, cycleNum9Letter};
vector<string> cycleTensBox = cycleNumbers[0];
vector<string> cycleOnesBox = cycleNumbers[0];


int N = 20;
double current=10, mult=1;
int num1 = 5, num2 = 15;

vector<string> num1TensBox = numbers[0];
vector<string> num1OnesBox = numbers[0];

vector<string> num2TensBox = unrevealedLetter;
vector<string> num2OnesBox = unrevealedLetter;

double deposit = 0;
bool winRound = false;
bool winGame = false;
bool lostGame = false;
bool quitGame = false;


// Intro Screen
void printIntroScreen();

//Game Screen
void printGameScreen();

// Back-end Main Function
void genRound(Round *rou);

// 3 smaller functions for back-end
void genTurn(Round *rou);
void makeMove(Round *rou);
void checkDeposit(Round *rou);

// Quit Game Checker
void checkQuit();




void printIntroScreen() {
    cout << "\033[2J\033[1;1H";
    string top =                  "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    string empty =                "┃                                                                    ┃\n";
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
    } else {
        printIntroScreen();
    }
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

    input = getch();
    //W: 87 119
    //S: 83 115
    //Space: 32
    //Enter: 13
    if(input == 87 || input == 119 || input == 83 || input == 115 || input == 32) {
        gameSelect = (gameSelect+1)%2;
        printGameScreen();
    } else if(input == 13) {
        /* Back end moment (im scared of animating revealing the number oh boy) */
/*
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
*/
        printGameScreen();
    } else {
        printGameScreen();
    }

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


int main() {
    SetConsoleOutputCP(CP_UTF8);
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

    printGameScreen();
    
    int rListSize = 7;
    Round *rList[rListSize];
    Round *r1 = new Round(), *r2 = new Round(), *r3 = new Round(), *r4 = new Round(), *r5 = new Round(), *r6 = new Round(), *r7 = new Round();
    r1->roundNum = 1, r1->quota = 13, r1->turns = 10;
    r2->roundNum = 2, r2->quota = 5, r2->turns = 10;
    r3->roundNum = 3, r3->quota = 8, r3->turns = 7;
    r4->roundNum = 4, r4->quota = 15, r4->turns = 6;
    r5->roundNum = 5, r5->quota = 20, r5->turns = 5;
    r6->roundNum = 6, r6->quota = 24, r6->turns = 5;
    r7->roundNum = 6, r7->quota = 25, r7->turns = 4;
    rList[0] = r1;
    rList[1] = r2;
    rList[2] = r3;
    rList[3] = r4;
    rList[4] = r5;
    rList[5] = r6;
    rList[6] = r7;


    
    cout << "Wow... you won? Congratulations huh... You did it :)" << endl;
    cout << "Game finished, hit enter to quit";
    
    input = getch();
    while(input != 13) {
        cout << input << endl;
        input = getch();
    }
    return 0;
}

/*


Ideas?
Ideas?
Ideas?
Ideas?
Ideas?


*/