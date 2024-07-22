#include <iostream>
#include <string>
#include <sstream>
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
int N = 20;
double current=10, mult=1;
int num1, num2;
double deposit = 0;
bool winRound = false;
bool winGame = false;
bool lostGame = false;
bool quitGame = false;


// Intro and Game Screen
void printIntroScreen(int &introSelect, int &introPrint);
void printGameScreen();

// Back-end Main Function
void genRound(Round *rou);

// 3 smaller functions for back-end
void genTurn(Round *rou);
void makeMove(Round *rou);
void checkDeposit(Round *rou);

// Quit Game Checker
void checkQuit();




void printIntroScreen(int &introSelect, int &introPrint) {
    cout << "\033[2J\033[1;1H";
    string top =             "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    string empty =           "┃                                                                    ┃\n";
    string intro[] =        {"┃                              Welcome!                              ┃\n",
                             "┃        Here to feed your uncontrollable gambling addiction?        ┃\n",
                             "┃                    You came to the right place.                    ┃\n",
                             "┃               This is a simple game of taking risks.               ┃\n",
                             "┃                             Good luck!                             ┃\n"};
    string lore[] =         {"┃              Oh, so you want to know lore about this?              ┃\n",
                             "┃             Well... the game all started with a \033[;36mPanda\033[;37m.             ┃\n",
                             "┃             He relaxed under the calm spring sunshine.             ┃\n",
                             "┃                             That's it.                             ┃\n",
                             "┃                            (Part 01/25)                            ┃\n"};
    string instructions[] = {"┃  You're given a number, then guess if the next is higher or lower  ┃\n",
                             "┃   If you guess correct, you gain coins, if wrong, you lose coins   ┃\n",
                             "┃   Here's the twist: the riskier the guess, the better the reward   ┃\n",
                             "┃                but also the worse the punishment...                ┃\n",
                             "┃            Stay safe as always, don't go insane, yet ;)            ┃\n"};
    string butt1high[] =    {"┃                    ╭──────────────────────────╮                    ┃\n",
                             "┃                    │ [1] Game Background/Lore │                    ┃\n",
                             "┃                    ╰──────────────────────────╯                    ┃\n"};
    string butt1[] =        {"┃                                                                    ┃\n",
                             "┃                      [1] Game Background/Lore                      ┃\n",
                             "┃                                                                    ┃\n"};
    string butt2high[] =    {"┃                        ╭──────────────────╮                        ┃\n",
                             "┃                        │ [2] Instructions │                        ┃\n",
                             "┃                        ╰──────────────────╯                        ┃\n"};
    string butt2[] =        {"┃                                                                    ┃\n",
                             "┃                          [2] Instructions                          ┃\n",
                             "┃                                                                    ┃\n"};
    string butt3high[] =    {"┃                         ╭────────────────╮                         ┃\n",
                             "┃                         │ [3] Start Game │                         ┃\n",
                             "┃                         ╰────────────────╯                         ┃\n"};
    string butt3[] =        {"┃                                                                    ┃\n",
                             "┃                           [3] Start Game                           ┃\n",
                             "┃                                                                    ┃\n"};
    string controls =        "┃       [W][S]: Scroll through options  [Enter]: Select option       ┃\n";
    string bottom =          "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

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
    cout << bottom;
    input = getch(); //w: 119, 87 s: 115, 83
    if(input == 87 || input == 119) { // W/w
        introSelect = (introSelect-1+3)%3;
        printIntroScreen(introSelect, introPrint);
    } else if(input == 83 || input == 115) { // S/s
        introSelect = (introSelect+1+3)%3;
        printIntroScreen(introSelect, introPrint);
    } else if(input == 13) { // [Enter]
        if(introSelect == 2) printGameScreen;
        else {
            introPrint = introSelect+1;
            introSelect = 0;
            printIntroScreen(introSelect, introPrint);
        }
    } else {
        input = getch();
    }
}


void printGameScreen() {
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    cout << "┃                                                                    ┃\n";
    cout << "┃                                                                    ┃\n";
    cout << "┃                                                                    ┃\n";
    cout << "┃                                                                    ┃\n";
    cout << "┃                                                                    ┃\n";
    cout << "┃    ╭─────────────╮          ╭─────────────╮                        ┃\n";
    cout << "┃    │ ┌───┐ ┌──── │          │ ????? ????? │                        ┃\n";
    cout << "┃    │ │   │ │     │          │ ????? ????? │                        ┃\n";
    cout << "┃    │ │   │ └───┐ │          │ ????? ????? │                        ┃\n";
    cout << "┃    │ │   │     │ │          │ ????? ????? │                        ┃\n";
    cout << "┃    │ └───┘ ────┘ │          │ ????? ????? │                        ┃\n";
    cout << "┃    ╰─────────────╯          ╰─────────────╯                        ┃\n";
    cout << "┃                                                                    ┃\n";
    cout << "┃                                                                    ┃\n";
    cout << "┃                                                                    ┃\n";
    cout << "┃    ╔═════════╗   ┌─────────┐                                       ┃\n";
    cout << "┃    ║  ↑↑↑↑↑  ║   │  ↓↓↓↓↓  │                                       ┃\n";
    cout << "┃    ║  ↑↑↑↑↑  ║   │  ↓↓↓↓↓  │                                       ┃\n";
    cout << "┃    ║  ↑↑↑↑↑  ║   │  ↓↓↓↓↓  │                                       ┃\n";
    cout << "┃    ╚═════════╝   └─────────┘                                       ┃\n";
    cout << "┃                                                                    ┃\n";
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
    cout << "1234567890123456789012345678901234567890123456789012345678901234567890\n";
    cout << "┃ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456776543210ZYXWVUTSRQPONMLKJIHGFEDCBA┃\n";
}




void genRound(Round *rou) {
    winRound = false;
    mult = 1;
    cout << "ROUND #" << rou->roundNum << endl;
    cout << "Number of turns: " << rou->turns << endl;
    cout << "Quota: " << rou->quota << endl;
    for(int turnNum = 1; turnNum <= rou->turns; turnNum++) {
        cout << "Turn #" << turnNum << endl;
        genTurn(rou);
        if(quitGame) break;
        makeMove(rou);
        if(quitGame) break;
        if(turnNum == rou->turns) {
            cout << "Aight, you just finished your last move for this turn, time to end it" << endl;
        } else checkDeposit(rou);
        if(winRound) break;
    }
    if(!winRound) {
        if(current*mult < rou->quota) {
            cout << "Womp womp, you lost. Try harder next time :(" << endl << endl;
            lostGame = true;
        } else {
            cout << "Wow, played until the last round to win huh, time to go to the next round" << endl << endl;
        }
    }
}


void genTurn(Round *rou) {
    num1 = rand()%N+1;
    while(num1 == 1 || num1 == N) num1 = rand()%N+1;
    num2 = rand()%N+1;
    while(num1 == num2 || num2 == 1 || num2 == N) num2 = rand()%N+1;
    cout << "The first number is " << num1 << ". " << num2 << endl;
}

void makeMove(Round *rou) {
    if(!quitGame) {
        cout << "Enter h/H or l/L for higher or lower." << endl;
        input = getch();
        checkQuit();
        if(quitGame) return;
        bool winTurn = ( (input == 104 || input == 72) && num2>num1 ) || ( (input == 108 || input == 76) && num2<num1 );
        if(input == 104 || input == 72) {
            if(num2>num1) cout << "Congrats, it was higher (" << num2 << ")" << endl;
            else cout << "Womp womp it was lower (" << num2 << ")" << endl;
        } else if(input == 108 || input == 76) {
            if(num2<num1) cout << "Congrats, it was lower (" << num2 << ")" << endl;
            else cout << "Womp womp it was higher (" << num2 << ")" << endl;
        }
        double multAdd = (double) num1/N;
        if(input == 108 || input == 76) multAdd = 1.00-multAdd;
        if(!winTurn) multAdd = -multAdd;
        mult = mult+multAdd;
        cout << "You now have " << (current*mult) << endl << endl;
    }
}

void checkDeposit(Round *rou) {
    if(mult*current >= rou->quota) {
        cout << "You reached the quota for this round, play it safe and deposit all or keep the risks going?" << endl;
        cout << "If you keep going, you can earn more before next round, or win this round first." << endl;
        cout << "Enter y/Y to deposit, or n/N to keep going" << endl;
        input = getch();
        checkQuit();
        if(quitGame) return;
        if(input == 121 || input == 89) {
            cout << "Congratulations! You finished round #" << rou->roundNum << ". Entering next round." << endl;
            deposit = deposit + rou->quota;
            current = mult*current;
            current = current-rou->quota;
            current = round(current-0.5);
            cout << "Deposit: " << deposit << endl;
            cout << "Current: " << current << endl;
            winRound = true;
        } else if (input == 110 || input == 78) {
            cout << "Alrighty, keep the risks rolling." << endl;
            winRound = false;
        }
    }
}

void checkQuit() {
    if(input == 13) {
        cout << "Are you sure you want to quit?" << endl;
        input = getch();
        if(input == 13) quitGame = true;
    }
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    printIntroScreen(introSelect, introPrint);
    printGameScreen();


    srand(time(0));
    /*
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


    genRound(r1);
    if(lostGame) return 0;
    genRound(r2);
    if(lostGame) return 0;
    genRound(r3);
    if(lostGame) return 0;
    genRound(r4);
    if(lostGame) return 0;
    genRound(r5);
    if(lostGame) return 0;
    cout << "Wow... you won? Congratulations huh... You did it :)" << endl;
    cout << "Game finished, hit enter to quit";
    */
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