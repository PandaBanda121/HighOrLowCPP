#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <unistd.h>
#include <sstream>


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

vector<vector<string>> num0LetterBold = {{"┏","━","━","━","┓"},
                                     {"┃"," "," "," ","┃"},
                                     {"┃"," "," "," ","┃"},
                                     {"┃"," "," "," ","┃"},
                                     {"┗","━","━","━","┛"}};
vector<vector<string>> num1LetterBold = {{" ","━","┓"," "," "},
                                     {" "," ","┃"," "," "},
                                     {" "," ","┃"," "," "},
                                     {" "," ","┃"," "," "},
                                     {"━","━","┻","━","━"}};
vector<vector<string>> num2LetterBold = {{"╺","━","━","━","┓"},
                                     {" "," "," "," ","┃"},
                                     {"┏","━","━","━","┛"},
                                     {"┃"," "," "," "," "},
                                     {"┗","━","━","━","╸"}};
vector<vector<string>> num3LetterBold = {{"╺","━","━","━","┓"},
                                     {" "," "," "," ","┃"},
                                     {"╺","━","━","━","┫"},
                                     {" "," "," "," ","┃"},
                                     {"╺","━","━","━","┛"}};
vector<vector<string>> num4LetterBold = {{"╻"," "," "," ","╻"},
                                     {"┃"," "," "," ","┃"},
                                     {"┗","━","━","━","┫"},
                                     {" "," "," "," ","┃"},
                                     {" "," "," "," ","╹"}};
vector<vector<string>> num5LetterBold = {{"┏","━","━","━","╸"},
                                     {"┃"," "," "," "," "},
                                     {"┗","━","━","━","┓"},
                                     {" "," "," "," ","┃"},
                                     {"╺","━","━","━","┛"}};
vector<vector<string>> num6LetterBold = {{"┏","━","━","━","╸"},
                                     {"┃"," "," "," "," "},
                                     {"┣","━","━","━","┓"},
                                     {"┃"," "," "," ","┃"},
                                     {"┗","━","━","━","┛"}};
vector<vector<string>> num7LetterBold = {{"┏","━","━","━","┓"},
                                     {" "," "," "," ","┃"},
                                     {" "," "," "," ","┃"},
                                     {" "," "," "," ","┃"},
                                     {" "," "," "," ","╹"}};
vector<vector<string>> num8LetterBold = {{"┏","━","━","━","┓"},
                                     {"┃"," "," "," ","┃"},
                                     {"┣","━","━","━","┫"},
                                     {"┃"," "," "," ","┃"},
                                     {"┗","━","━","━","┛"}};
vector<vector<string>> num9LetterBold = {{"┏","━","━","━","┓"},
                                     {"┃"," "," "," ","┃"},
                                     {"┗","━","━","━","┫"},
                                     {" "," "," "," ","┃"},
                                     {" "," "," "," ","┃"}};
vector<vector<vector<string>>> numbers = {num0LetterBold, num1LetterBold, num2LetterBold, num3LetterBold, num4LetterBold, num5LetterBold, num6LetterBold, num7LetterBold, num8LetterBold, num9LetterBold};

vector<vector<string>> num1TensBox = unrevealedLetter;
vector<vector<string>> num1OnesBox = unrevealedLetter;
vector<vector<string>> num2TensBox = unrevealedLetter;
vector<vector<string>> num2OnesBox = unrevealedLetter;


vector<vector<string>> setNum0Letter = {{"╭","─","─","─","╮"},
                                          {"│"," "," "," ","│"},
                                          {"╰","─","─","─","╯"}};
vector<vector<string>> setNum1Letter = {{" ","─","╮"," "," "},
                                          {" "," ","│"," "," "},
                                          {"─","─","┴","─","─"}};
vector<vector<string>> setNum2Letter = {{"╶","─","─","─","╮"},
                                          {"╭","─","─","─","╯"},
                                          {"╰","─","─","─","╴"}};
vector<vector<string>> setNum3Letter = {{"╶","─","─","─","╮"},
                                          {"╶","─","─","─","┤"},
                                          {"╶","─","─","─","╯"}};
vector<vector<string>> setNum4Letter = {{"╷"," "," "," ","╷"},
                                          {"╰","─","─","─","┤"},
                                          {" "," "," "," ","╵"}};
vector<vector<string>> setNum5Letter = {{"╭","─","─","─","╴"},
                                          {"╰","─","─","─","╮"},
                                          {"╶","─","─","─","╯"}};
vector<vector<string>> setNum6Letter = {{"╭","─","─","─","╴"},
                                          {"├","─","─","─","╮"},
                                          {"╰","─","─","─","╯"}};
vector<vector<string>> setNum7Letter = {{"╭","─","─","─","╮"},
                                          {" "," "," "," ","│"},
                                          {" "," "," "," ","╵"}};
vector<vector<string>> setNum8Letter = {{"╭","─","─","─","╮"},
                                          {"├","─","─","─","┤"},
                                          {"╰","─","─","─","╯"}};
vector<vector<string>> setNum9Letter = {{"╭","─","─","─","╮"},
                                          {"╰","─","─","─","┤"},
                                          {" "," "," "," ","╵"}};
vector<vector<vector<string>>> setNumbers = {setNum0Letter, setNum1Letter, setNum2Letter, setNum3Letter, setNum4Letter, setNum5Letter, setNum6Letter, setNum7Letter, setNum8Letter, setNum9Letter};

vector<vector<string>> setNum0LetterBold = {{"╭","━","━","━","╮"},
                                          {"┃"," "," "," ","┃"},
                                          {"╰","━","━","━","╯"}};
vector<vector<string>> setNum1LetterBold = {{" ","━","╮"," "," "},
                                          {" "," ","┃"," "," "},
                                          {"━","━","┻","━","━"}};
vector<vector<string>> setNum2LetterBold = {{"╺","━","━","━","╮"},
                                          {"╭","━","━","━","╯"},
                                          {"╰","━","━","━","╴"}};
vector<vector<string>> setNum3LetterBold = {{"╺","━","━","━","╮"},
                                          {"╺","━","━","━","┫"},
                                          {"╺","━","━","━","╯"}};
vector<vector<string>> setNum4LetterBold = {{"╻"," "," "," ","╻"},
                                          {"╰","━","━","━","┫"},
                                          {" "," "," "," ","╵"}};
vector<vector<string>> setNum5LetterBold = {{"╭","━","━","━","╴"},
                                          {"╰","━","━","━","╮"},
                                          {"╺","━","━","━","╯"}};
vector<vector<string>> setNum6LetterBold = {{"╭","━","━","━","╴"},
                                          {"┣","━","━","━","╮"},
                                          {"╰","━","━","━","╯"}};
vector<vector<string>> setNum7LetterBold = {{"╭","━","━","━","╮"},
                                          {" "," "," "," ","┃"},
                                          {" "," "," "," ","╵"}};
vector<vector<string>> setNum8LetterBold = {{"╭","━","━","━","╮"},
                                          {"┣","━","━","━","┫"},
                                          {"╰","━","━","━","╯"}};
vector<vector<string>> setNum9LetterBold = {{"╭","━","━","━","╮"},
                                          {"╰","━","━","━","┫"},
                                          {" "," "," "," ","╵"}};
vector<vector<vector<string>>> setNumbersBold = {setNum0LetterBold, setNum1LetterBold, setNum2LetterBold, setNum3LetterBold, setNum4LetterBold, setNum5LetterBold, setNum6LetterBold, setNum7LetterBold, setNum8LetterBold, setNum9LetterBold};

vector<vector<string>> setTensBox = setNumbers[0];
vector<vector<string>> setOnesBox = setNumbers[0];
vector<vector<bool>> setTensChanged = falseVector3x5;
vector<vector<bool>> setOnesChanged = falseVector3x5;
int setNum = 1;

int input;
int introSelect = 0; //0: Lore, 1: instructions, 2: gameScreen, 3: achievementScreen
int introPrint = 0; //0: welcome, 1: lore, 2: instructions

string bGreen = "\033[1;32m"; // choose higher
string bRed = "\033[1;31m"; // choose lower
string bYellow = "\033[1;33m"; // Set Color
string bBlue = "\033[1;34m"; // Turn/Quota/Wallet Color
string white = "\033[0m";


//                         7654321
int animateSetMicroSeconds = 10000;  // Set animation
int animateMicroSeconds0 =   20000;  // Turn Num animation 0
int animateMicroSeconds1 =   20000;  // Turn Num animation 1
int animateMicroSeconds2 =   20000;  // Turn Num animation 2
int animateMicroSeconds3 =   20000;  // Turn Num animation 3
int animateMicroSeconds4 =   20000;  // Turn Num animation 4
int animateMicroSeconds5 =   20000;  // Turn Num animation 5
int resultMicroSeconds =   1000000;  // result

string result = "                                                   ";


int N = 20;
int num1 = 5, num2 = 15;
int gameSelect = 1; //0: low, 1: high

double wallet=10, mult=1;
string stringTurns = "00";
string stringTotalTurns = "00";
string stringWallet = "000.00";
string stringQuota = "000.00";


double totalEarned = 0;
double totalLost = 0;
int lostStreak = 0;
int winStreak = 0;
int longestLostStreak = 0;
int longestWinStreak = 0;



string goalFinisherTitleUnlocked =                   "┃ Goal Finisher            (02/25)                                   ┃\n";
string flawlessWinTitleUnlocked =                    "┃ Flawless Win             (03/25)                                   ┃\n";
string undeniablePerseveranceTitleUnlocked =         "┃ Undeniable Perseverance  (04/25)                                   ┃\n";
string theNextRichWarriorTitleUnlocked =             "┃ The next rich Warrior    (05/25)                                   ┃\n";
string unluckyBastardTitleUnlocked =                 "┃ Unlucky bastard          (06/25)                                   ┃\n";

vector<string> goalFinisherLoreUnlocked =           {"┃ As Panda relaxed, well? He                                                  ┃\n",
                                                     "┃ Temporary place holder12                                           ┃\n",
                                                     "┃ Temporary place holder13                                           ┃\n",
                                                     "┃ Temporary place holder14                                           ┃\n"};
vector<string> flawlessWinLoreUnlocked =            {"┃ Temporary place holder21                                           ┃\n",
                                                     "┃ Temporary place holder22                                           ┃\n",
                                                     "┃ Temporary place holder23                                           ┃\n",
                                                     "┃ Temporary place holder24                                           ┃\n"};
vector<string> undeniablePerseveranceLoreUnlocked = {"┃ Temporary place holder31                                           ┃\n",
                                                     "┃ Temporary place holder32                                           ┃\n",
                                                     "┃ Temporary place holder33                                           ┃\n",
                                                     "┃ Temporary place holder34                                           ┃\n"};
vector<string> theNextRichWarriorLoreUnlocked =     {"┃ Temporary place holder41                                           ┃\n",
                                                     "┃ Temporary place holder42                                           ┃\n",
                                                     "┃ Temporary place holder43                                           ┃\n",
                                                     "┃ Temporary place holder44                                           ┃\n"};
vector<string> unluckyBastardLoreUnlocked =         {"┃ Temporary place holder51                                           ┃\n",
                                                     "┃ Temporary place holder52                                           ┃\n",
                                                     "┃ Temporary place holder53                                           ┃\n",
                                                     "┃ Temporary place holder54                                           ┃\n"};

bool goalFinisherUnlocked = false;
bool flawlessWinUnlocked = false;
bool undeniablePerseveranceUnlocked = false;
bool theNextRichWarriorUnlocked = false;
bool unluckyBastardUnlocked = false;

bool notLostRoundYetForFlawlessWin = true;
bool endOfSetForFlawlessWin = false;
bool winSet = false;
bool winGame = false;
bool lostGame = false;
bool quitGame = false;


// Intro Screen
void printIntroScreen();

//Game Screen
void printGameScreen();

//Achievement Screen
void printAchievementsScreen();

// Back-end Main Function

// 3 smaller functions for back-end

// Achievements Checker
void checkAchievements(Set *&s1);

// Quit Game Checker
void quit();

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
                                   "┃                          \033[1;32mhigher\033[0m or \033[1;31mlower\033[0m.                          ┃\n",
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
    vector<string> butt4high =    {"┃                        ╭──────────────────╮                        ┃\n",
                                   "┃                        │ [4] Achievements │                        ┃\n",
                                   "┃                        ╰──────────────────╯                        ┃\n"};
    vector<string> butt4 =        {"┃                                                                    ┃\n",
                                   "┃                          [4] Achievements                          ┃\n",
                                   "┃                                                                    ┃\n"};
    string controls =              "┃       [W][S]: Scroll through options  [Enter]: Select option       ┃\n";
    string bottom =                "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    cout << "\033[2J\033[1;1H";
    cout << top << empty << empty;
    if(introPrint == 0) for(string line : intro) cout << line;
    else if(introPrint == 1) for(string line : lore) cout << line;
    else if(introPrint == 2) for(string line : instructions) cout << line;
    cout << empty << empty;
    if(introSelect == 0) for(string line : butt1high) cout << line;
    else for(string line : butt1) cout << line;
    if(introSelect == 1) for(string line : butt2high) cout << line;
    else for(string line : butt2) cout << line;
    if(introSelect == 2) for(string line : butt3high) cout << line;
    else for(string line : butt3) cout << line;
    if(introSelect == 3) for(string line : butt4high) cout << line;
    else for(string line : butt4) cout << line;
    
    cout << empty << empty;
    cout << controls;
    cout << empty << empty;
    cout << bottom;

    input = getch(); //w: 119, 87 s: 115, 83
    if(input == 87 || input == 119) { // W/w
        introSelect = (introSelect-1+3)%3;
        printIntroScreen();
    } else if(input == 83 || input == 115) { // S/s
            introSelect = (introSelect+1+4)%4;
            printIntroScreen();
        } else if(input == 13) { // [Enter]
            if(introSelect == 2) printGameScreen();
            else if(introSelect == 3) printAchievementsScreen();
            else {
                introPrint = introSelect+1;
                introSelect = 0;
                printIntroScreen();
            }
    } else printIntroScreen();
}


void printGameScreen() {
    string gameScreenTop =                       "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    vector<string> gameScreenSet =              {"┃                                         "+bYellow+"╭───╴╭───╴╶─┬─╴ "+vectorToString(setTensBox[0])+vectorToString(setOnesBox[0])+white+" ┃\n",
                                                 "┃                                         "+bYellow+"╰───╮├───╴  │   "+vectorToString(setTensBox[1])+vectorToString(setOnesBox[1])+white+" ┃\n",
                                                 "┃                                         "+bYellow+"╶───╯╰───╴  ╵   "+vectorToString(setTensBox[2])+vectorToString(setOnesBox[2])+white+" ┃\n"};
    string gameScreenEmpty =                     "┃                                                                    ┃\n";
    vector<string> gameScreenTurnsQuotaWallet = {"┃             "+bBlue+"╭─────────────────╮    ╭─────────────────╮"+white+"             ┃\n",
                                                 "┃             "+bBlue+"│    Turn #"+stringTurns+"     │    │   Quota: "+stringQuota+" │"+white+"             ┃\n",
                                                 "┃             "+bBlue+"│ Total turns: "+stringTotalTurns+" │    │  Wallet: "+stringWallet+" │"+white+"             ┃\n",
                                                 "┃             "+bBlue+"╰─────────────────╯    ╰─────────────────╯"+white+"             ┃\n"};
    vector<string> upButtHigh =                 {"┃  "+bGreen+"╔═════════╗"+white+"                                                       ┃\n",
                                                 "┃  "+bGreen+"║  ↑↑↑↑↑  ║"+white+"                                                       ┃\n",
                                                 "┃  "+bGreen+"║  ↑↑↑↑↑  ║    ╭─────────────╮    ╭─────────────╮"+white+"                 ┃\n",
                                                 "┃  "+bGreen+"║  ↑↑↑↑↑  ║    │ "+vectorToString(num1TensBox[0])+" "+vectorToString(num1OnesBox[0])+" │    │ "+vectorToString(num2TensBox[0])+" "+vectorToString(num2OnesBox[0])+" │"+white+"                 ┃\n",
                                                 "┃  "+bGreen+"╚═════════╝    │ "+vectorToString(num1TensBox[1])+" "+vectorToString(num1OnesBox[1])+" │    │ "+vectorToString(num2TensBox[1])+" "+vectorToString(num2OnesBox[1])+" │"+white+"                 ┃\n",
                                                 "┃                 "+bGreen+"│ "+vectorToString(num1TensBox[2])+" "+vectorToString(num1OnesBox[2])+" │    │ "+vectorToString(num2TensBox[2])+" "+vectorToString(num2OnesBox[2])+" │"+white+"                 ┃\n",
                                                 "┃  ┌─────────┐    "+bGreen+"│ "+vectorToString(num1TensBox[3])+" "+vectorToString(num1OnesBox[3])+" │    │ "+vectorToString(num2TensBox[3])+" "+vectorToString(num2OnesBox[3])+" │"+white+"                 ┃\n",
                                                 "┃  │  ↓↓↓↓↓  │    "+bGreen+"│ "+vectorToString(num1TensBox[4])+" "+vectorToString(num1OnesBox[4])+" │    │ "+vectorToString(num2TensBox[4])+" "+vectorToString(num2OnesBox[4])+" │"+white+"                 ┃\n",
                                                 "┃  │  ↓↓↓↓↓  │    "+bGreen+"╰─────────────╯    ╰─────────────╯"+white+"                 ┃\n",
                                                 "┃  │  ↓↓↓↓↓  │                                                       ┃\n",
                                                 "┃  └─────────┘    "+result+"┃\n"};
    vector<string> downButtHigh =               {"┃  ┌─────────┐                                                       ┃\n",
                                                 "┃  │  ↑↑↑↑↑  │                                                       ┃\n",
                                                 "┃  │  ↑↑↑↑↑  │    "+bRed+"╭─────────────╮    ╭─────────────╮"+white+"                 ┃\n",
                                                 "┃  │  ↑↑↑↑↑  │    "+bRed+"│ "+vectorToString(num1TensBox[0])+" "+vectorToString(num1OnesBox[0])+" │    │ "+vectorToString(num2TensBox[0])+" "+vectorToString(num2OnesBox[0])+" │"+white+"                 ┃\n",
                                                 "┃  └─────────┘    "+bRed+"│ "+vectorToString(num1TensBox[1])+" "+vectorToString(num1OnesBox[1])+" │    │ "+vectorToString(num2TensBox[1])+" "+vectorToString(num2OnesBox[1])+" │"+white+"                 ┃\n",
                                                 "┃                 "+bRed+"│ "+vectorToString(num1TensBox[2])+" "+vectorToString(num1OnesBox[2])+" │    │ "+vectorToString(num2TensBox[2])+" "+vectorToString(num2OnesBox[2])+" │"+white+"                 ┃\n",
                                                 "┃  "+bRed+"╔═════════╗    │ "+vectorToString(num1TensBox[3])+" "+vectorToString(num1OnesBox[3])+" │    │ "+vectorToString(num2TensBox[3])+" "+vectorToString(num2OnesBox[3])+" │"+white+"                 ┃\n",
                                                 "┃  "+bRed+"║  ↓↓↓↓↓  ║    │ "+vectorToString(num1TensBox[4])+" "+vectorToString(num1OnesBox[4])+" │    │ "+vectorToString(num2TensBox[4])+" "+vectorToString(num2OnesBox[4])+" │"+white+"                 ┃\n",
                                                 "┃  "+bRed+"║  ↓↓↓↓↓  ║    ╰─────────────╯    ╰─────────────╯"+white+"                 ┃\n",
                                                 "┃  "+bRed+"║  ↓↓↓↓↓  ║"+white+"                                                       ┃\n",
                                                 "┃  "+bRed+"╚═════════╝"+white+"    "+result+"┃\n"};
    string lore1 =                               "┃                                                                    ┃\n";
    string lore2 =                               "┃                                                                    ┃\n";
    string lore3 =                               "┃                                                                    ┃\n";
    string gameScreenControls =                  "┃   [W][S]: Up/Down  [Space]: Deposit  [Enter]: Confirm  [Q]: Quit   ┃\n";
    string gameScreenBottom =                    "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    cout << "\033[2J\033[1;1H";
    cout << gameScreenTop;
    for(string line : gameScreenSet) cout << line;
    cout << gameScreenEmpty;
    for(string line : gameScreenTurnsQuotaWallet) cout << line;
    cout << gameScreenEmpty;
    if(gameSelect == 1) for(int i = 0; i < 11; i++) cout << upButtHigh[i];
    else for(int i = 0; i < 11; i++) cout << downButtHigh[i];
    cout << lore1;
    cout << lore2;
    cout << lore3;
    cout << gameScreenControls;
    cout << gameScreenEmpty;
    cout << gameScreenEmpty;
    cout << gameScreenBottom;
}

void printAchievementsScreen() {
    string achievementsTop =                     "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    string goalFinisherTitle =                   "┃ title1?????                                                        ┃\n";
    string flawlessWinTitle =                    "┃ title2?????                                                        ┃\n";
    string undeniablePerseveranceTitle =         "┃ title3?????                                                        ┃\n";
    string theNextRichWarriorTitle =             "┃ title4?????                                                        ┃\n";
    string unluckyBastardTitle =                 "┃ title5?????                                                        ┃\n";
    vector<string> goalFinisherLore =           {"┃ ?????11                                                            ┃\n",
                                                 "┃ ?????12                                                            ┃\n",
                                                 "┃ ?????13                                                            ┃\n",
                                                 "┃ ?????14                                                            ┃\n"};
    vector<string> flawlessWinLore =            {"┃ ?????21                                                            ┃\n",
                                                 "┃ ?????22                                                            ┃\n",
                                                 "┃ ?????23                                                            ┃\n",
                                                 "┃ ?????24                                                            ┃\n"};
    vector<string> undeniablePerseveranceLore = {"┃ ?????31                                                            ┃\n",
                                                 "┃ ?????32                                                            ┃\n",
                                                 "┃ ?????33                                                            ┃\n",
                                                 "┃ ?????34                                                            ┃\n"};
    vector<string> theNextRichWarriorLore =     {"┃ ?????41                                                            ┃\n",
                                                 "┃ ?????42                                                            ┃\n",
                                                 "┃ ?????43                                                            ┃\n",
                                                 "┃ ?????44                                                            ┃\n"};
    vector<string> unluckyBastardLore =         {"┃ ?????51                                                            ┃\n",
                                                 "┃ ?????52                                                            ┃\n",
                                                 "┃ ?????53                                                            ┃\n",
                                                 "┃ ?????54                                                            ┃\n"};
    string control =                             "┃ > Press any key to go back to intro screen                         ┃\n";
    string achievementsBottom =                  "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
    
    cout << "\033[2J\033[1;1H";
    if(goalFinisherUnlocked) {
        goalFinisherTitle = goalFinisherTitleUnlocked;
        goalFinisherLore = goalFinisherLoreUnlocked;
    }
    if(flawlessWinUnlocked) {
        flawlessWinTitle = flawlessWinTitleUnlocked;
        flawlessWinLore = flawlessWinLoreUnlocked;
    }
    if(undeniablePerseveranceUnlocked) {
        undeniablePerseveranceTitle = undeniablePerseveranceTitleUnlocked;
        undeniablePerseveranceLore = undeniablePerseveranceLoreUnlocked;
    }
    if(theNextRichWarriorUnlocked) {
        theNextRichWarriorTitle = theNextRichWarriorTitleUnlocked;
        theNextRichWarriorLore = theNextRichWarriorLoreUnlocked;
    }
    if(unluckyBastardUnlocked) {
        unluckyBastardTitle = unluckyBastardTitleUnlocked;
        unluckyBastardLore = unluckyBastardLoreUnlocked;
    }
    cout << achievementsTop;
    cout << goalFinisherTitle;
    for(string line : goalFinisherLore) cout << line;
    cout << flawlessWinTitle;
    for(string line : flawlessWinLore) cout << line;
    cout << undeniablePerseveranceTitle;
    for(string line : undeniablePerseveranceLore) cout << line;
    cout << theNextRichWarriorTitle;
    for(string line : theNextRichWarriorLore) cout << line;
    cout << unluckyBastardTitle;
    for(string line : unluckyBastardLore) cout << line;
    cout << control;
    cout << achievementsBottom;
    input = getch();
    printIntroScreen();
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
    // 3 ways to show the new numbers: 
    // OG: rng through them
    // Cliche: checker board, use this: █
    // Smooth if good animation: Reveal from top to bottom, one by one left to right
    /* 
    I'm kinda lazy rn I'll do these tmrw :3
    */
    int transitionType = rand()%6;
    // transitionType = 2;
    if(transitionType == 0) {
        for(int temp = 0; temp < 25; temp++) {
            int LocX = rand()%5, LocY = rand()%5;
            while(num1TensBox[LocX][LocY]+"" != "?") LocX = rand()%5, LocY = rand()%5;
            num1TensBox[LocX][LocY] = numbers[num1/10][LocX][LocY];
            LocX = rand()%5, LocY = rand()%5;
            while(num1OnesBox[LocX][LocY]+"" != "?") LocX = rand()%5, LocY = rand()%5;
            num1OnesBox[LocX][LocY] = numbers[num1%10][LocX][LocY];
            printGameScreen();
            usleep(animateMicroSeconds0);
        }
    } else if(transitionType == 1) {
        num1TensBox[0][0] = numbers[num1/10][0][0];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 2; i++) num1TensBox[2-i][i] = numbers[num1/10][2-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 4; i++) num1TensBox[4-i][i] = numbers[num1/10][4-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 2; i++) num1TensBox[4-i][i+2] = numbers[num1/10][4-i][i+2];
        printGameScreen();
        usleep(animateMicroSeconds1);
        num1TensBox[4][4] = numbers[num1/10][4][4];
        printGameScreen();
        usleep(animateMicroSeconds1);

        num1OnesBox[0][0] = numbers[num1%10][0][0];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 2; i++) num1OnesBox[2-i][i] = numbers[num1%10][2-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 4; i++) num1OnesBox[4-i][i] = numbers[num1%10][4-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 2; i++) num1OnesBox[4-i][i+2] = numbers[num1%10][4-i][i+2];
        printGameScreen();
        usleep(animateMicroSeconds1);
        num1OnesBox[4][4] = numbers[num1%10][4][4];
        printGameScreen();
        usleep(animateMicroSeconds1);


        num1TensBox[1][0] = numbers[num1/10][1][0];
        num1TensBox[0][1] = numbers[num1/10][0][1];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 3; i++) num1TensBox[3-i][i] = numbers[num1/10][3-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 1; i <= 4; i++) num1TensBox[5-i][i] = numbers[num1/10][5-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        num1TensBox[4][3] = numbers[num1/10][4][3];
        num1TensBox[3][4] = numbers[num1/10][3][4];
        printGameScreen();
        usleep(animateMicroSeconds1);

        num1OnesBox[1][0] = numbers[num1%10][1][0];
        num1OnesBox[0][1] = numbers[num1%10][0][1];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 3; i++) num1OnesBox[3-i][i] = numbers[num1%10][3-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 1; i <= 4; i++) num1OnesBox[5-i][i] = numbers[num1%10][5-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        num1OnesBox[4][3] = numbers[num1%10][4][3];
        num1OnesBox[3][4] = numbers[num1%10][3][4];
        printGameScreen();
        usleep(animateMicroSeconds1);
    } else if(transitionType==2) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                num1TensBox[i][j] = numbers[num1/10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds2);
            }
        }
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                num1OnesBox[i][j] = numbers[num1%10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds2);
            }
        }
    } else if(transitionType==3) {
        for(int j = 0; j < 5; j++) {
            for(int i = 0; i < 5; i++) {
                num1TensBox[i][j] = numbers[num1/10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds3);
            }
        }
        for(int j = 0; j < 5; j++) {
            for(int i = 0; i < 5; i++) {
                num1OnesBox[i][j] = numbers[num1%10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds3);
            }
        }
    } else if(transitionType==4) {
        for(int j = 4; j >= 0; j--) {
            for(int i = 0; i < 5; i++) {
                num1OnesBox[i][j] = numbers[num1%10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds4);
            }
        }
        for(int j = 4; j >= 0; j--) {
            for(int i = 0; i < 5; i++) {
                num1TensBox[i][j] = numbers[num1/10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds4);
            }
        }
    } else if(transitionType==5) {
        for(int i = 4; i >= 0; i--) {
            for(int j = 0; j < 5; j++) {
                num1TensBox[i][j] = numbers[num1/10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds5);
            }
        }
        for(int i = 4; i >= 0; i--) {
            for(int j = 0; j < 5; j++) {
                num1OnesBox[i][j] = numbers[num1%10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds5);
            }
        }
    }
}

void genNextNumbers() {
    // printGameScreen();
    int transitionType = rand()%6;
    // transitionType = 2;
    if(transitionType == 0) {
        for(int temp = 0; temp < 25; temp++) {
            int LocX = rand()%5, LocY = rand()%5;
            while(num2TensBox[LocX][LocY]+"" != "?") LocX = rand()%5, LocY = rand()%5;
            num2TensBox[LocX][LocY] = numbers[num2/10][LocX][LocY];
            LocX = rand()%5, LocY = rand()%5;
            while(num2OnesBox[LocX][LocY]+"" != "?") LocX = rand()%5, LocY = rand()%5;
            num2OnesBox[LocX][LocY] = numbers[num2%10][LocX][LocY];
            printGameScreen();
            usleep(animateMicroSeconds0);
        }
    } else if(transitionType == 1) {
        num2TensBox[0][0] = numbers[num2/10][0][0];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 2; i++) num2TensBox[2-i][i] = numbers[num2/10][2-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 4; i++) num2TensBox[4-i][i] = numbers[num2/10][4-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 2; i++) num2TensBox[4-i][i+2] = numbers[num2/10][4-i][i+2];
        printGameScreen();
        usleep(animateMicroSeconds1);
        num2TensBox[4][4] = numbers[num2/10][4][4];
        printGameScreen();
        usleep(animateMicroSeconds1);

        num2OnesBox[0][0] = numbers[num2%10][0][0];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 2; i++) num2OnesBox[2-i][i] = numbers[num2%10][2-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 4; i++) num2OnesBox[4-i][i] = numbers[num2%10][4-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 2; i++) num2OnesBox[4-i][i+2] = numbers[num2%10][4-i][i+2];
        printGameScreen();
        usleep(animateMicroSeconds1);
        num2OnesBox[4][4] = numbers[num2%10][4][4];
        printGameScreen();
        usleep(animateMicroSeconds1);


        num2TensBox[1][0] = numbers[num2/10][1][0];
        num2TensBox[0][1] = numbers[num2/10][0][1];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 3; i++) num2TensBox[3-i][i] = numbers[num2/10][3-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 1; i <= 4; i++) num2TensBox[5-i][i] = numbers[num2/10][5-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        num2TensBox[4][3] = numbers[num2/10][4][3];
        num2TensBox[3][4] = numbers[num2/10][3][4];
        printGameScreen();
        usleep(animateMicroSeconds1);

        num2OnesBox[1][0] = numbers[num2%10][1][0];
        num2OnesBox[0][1] = numbers[num2%10][0][1];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 0; i <= 3; i++) num2OnesBox[3-i][i] = numbers[num2%10][3-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        for(int i = 1; i <= 4; i++) num2OnesBox[5-i][i] = numbers[num2%10][5-i][i];
        printGameScreen();
        usleep(animateMicroSeconds1);
        num2OnesBox[4][3] = numbers[num2%10][4][3];
        num2OnesBox[3][4] = numbers[num2%10][3][4];
        printGameScreen();
        usleep(animateMicroSeconds1);
    } else if(transitionType==2) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                num2TensBox[i][j] = numbers[num2/10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds2);
            }
        }
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                num2OnesBox[i][j] = numbers[num2%10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds2);
            }
        }
    } else if(transitionType==3) {
        for(int j = 0; j < 5; j++) {
            for(int i = 0; i < 5; i++) {
                num2TensBox[i][j] = numbers[num2/10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds3);
            }
        }
        for(int j = 0; j < 5; j++) {
            for(int i = 0; i < 5; i++) {
                num2OnesBox[i][j] = numbers[num2%10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds3);
            }
        }
    } else if(transitionType==4) {
        for(int j = 4; j >= 0; j--) {
            for(int i = 0; i < 5; i++) {
                num2OnesBox[i][j] = numbers[num2%10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds4);
            }
        }
        for(int j = 4; j >= 0; j--) {
            for(int i = 0; i < 5; i++) {
                num2TensBox[i][j] = numbers[num2/10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds4);
            }
        }
    } else if(transitionType==5) {
        for(int i = 4; i >= 0; i--) {
            for(int j = 0; j < 5; j++) {
                num2TensBox[i][j] = numbers[num2/10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds5);
            }
        }
        for(int i = 4; i >= 0; i--) {
            for(int j = 0; j < 5; j++) {
                num2OnesBox[i][j] = numbers[num2%10][i][j];
                printGameScreen();
                usleep(animateMicroSeconds5);
            }
        }
    }
}

void genSetNumbers() {
    for(int temp = 0; temp < 15; temp++) {
        int LocX = rand()%3;
        int LocY = rand()%5;
        while(setTensChanged[LocX][LocY]) LocX = rand()%3, LocY = rand()%5;
        setTensChanged[LocX][LocY] = true;
        setTensBox[LocX][LocY] = setNumbers[setNum/10][LocX][LocY];
        usleep(animateSetMicroSeconds);
        LocX = rand()%3, LocY = rand()%5;
        while(setOnesChanged[LocX][LocY]) LocX = rand()%3, LocY = rand()%5;
        setOnesChanged[LocX][LocY] = true;
        setOnesBox[LocX][LocY] = setNumbers[setNum%10][LocX][LocY];
        printGameScreen();
        usleep(animateSetMicroSeconds);
    }
    setTensChanged = falseVector3x5;
    setOnesChanged = falseVector3x5;
}

void genRound(Set *&s1) {
    winSet = false;
    
    result = "                                                   ";
    genTurnNumbers();
    
    input = getch();
    while(true) {
        if(input == 13) break;
        if(input == 87 || input == 119) {
            gameSelect = 1;
            printGameScreen();
        }
        if(input == 83 || input == 115) {
            gameSelect = 0;
            printGameScreen();
        }
        
        if(input == 32) {
            if(wallet*mult > s1->quota) {
                result = "Alrighty, you deposited, good luck on the next set!";
                printGameScreen();
                winSet = true;
                usleep(resultMicroSeconds*3);
                break;
            } else {
                result = "You don't even have enough to deposit, try harder. ";
                printGameScreen();
            }
        }

        if(input == 113 || input == 81) {
            result = "Press [Q] again to quit. Press any key to cancel.  ";
            printGameScreen();
            input = getch();
            if(input == 113 || input == 81) {
                quitGame = true;
                break;
            } else {
                result = "Good choice, keep going! Persevere on pal          ";
                printGameScreen();
            }
        }
        input = getch();
    }

    if(!winSet && !quitGame) {
        genNextNumbers();
        bool winTurn = ( (gameSelect == 1) && num2>num1 ) || ( (gameSelect == 0) && num2<num1 );
        if(winTurn) {
            winStreak++;
            if(winStreak > longestWinStreak) longestWinStreak = winStreak;
            lostStreak = 0;
            if(winStreak == 1)       result = "Correct.                                           ";
            else if (winStreak == 2) result = "Correct, again.                                    ";
            else if (winStreak == 3) result = "Correct, again, AGAIN.                             ";
            else if (winStreak >= 4) result = "Correct, again and again... Are you cheating???    ";
        } else {
            notLostRoundYetForFlawlessWin = false;
            lostStreak++;
            if(lostStreak > longestLostStreak) longestLostStreak = lostStreak;
            winStreak = 0;
            if(lostStreak == 1)      result = "Wrong.                                             ";
            else if(lostStreak == 2) result = "Wrong, again. AGAIN.                               ";
            else if(lostStreak >= 4) result = "Wrong, again and again... Are you trying to lose???";
        }
        printGameScreen();
        double multAdd = (double) num1/N;
        if(gameSelect == 0) multAdd = 1.00-multAdd;
        if(!winTurn) multAdd = -multAdd;
        mult = mult+multAdd;
        if(winTurn) {
            totalEarned = totalEarned + wallet*multAdd;
        } else {
            totalLost = totalLost + wallet*multAdd;
        }
    }
}

void genSet(Set *&s1) {
    winSet = false;
    setNum = s1->setNum;
    mult = 1;
    genSetNumbers();
    if(s1->turns < 10) stringTotalTurns = "0"+to_string(s1->turns);
    else stringTotalTurns = to_string(s1->turns);
    
    double printedAmount = wallet*mult;
    stringstream stream;
    stream << fixed << setprecision(2) << printedAmount;
    stringWallet = stream.str();
    if(printedAmount < 0) stringWallet = "000.00";
    else if(printedAmount < 10) stringWallet = "00"+stringWallet;
    else if(printedAmount < 100) stringWallet = "0"+stringWallet;
    else stringWallet = stringWallet;
    
    if(s1->quota < 10) stringQuota = "00" + to_string(s1->quota)+".00";
    else if(s1->quota < 100) stringQuota = "0" + to_string(s1->quota)+".00";
    else stringQuota = to_string(s1->quota)+".00";
    
    notLostRoundYetForFlawlessWin = true;

    for(int currentTurn = 1; currentTurn <= s1->turns; currentTurn++) {
        gameSelect = 1;
        num1TensBox = unrevealedLetter;
        num1OnesBox = unrevealedLetter;
        num2TensBox = unrevealedLetter;
        num2OnesBox = unrevealedLetter;
        if(currentTurn < 10) stringTurns = "0"+to_string(currentTurn);
        else stringTurns = to_string(currentTurn);
        genRound(s1);
        if(quitGame) {
            break;
        }
        printedAmount = wallet*mult;
        stringstream stream;
        stream << fixed << setprecision(2) << printedAmount;
        stringWallet = stream.str();
        if(printedAmount < 0) stringWallet = "000.00";
        else if(printedAmount < 10) stringWallet = "00"+stringWallet;
        else if(printedAmount < 100) stringWallet = "0"+stringWallet;
        printGameScreen();
        
        usleep(resultMicroSeconds);
        if(currentTurn == s1->turns) {
            endOfSetForFlawlessWin = true;
            if(mult*wallet > s1->quota) {
                result = "You played until the end huh, going to next set.   ";
                winSet = true;
                printGameScreen();
                usleep(resultMicroSeconds*3);
            } else {
                result = "Wow... you tried all you could but still lost. GG. ";
                lostGame = true;
                printGameScreen();
                usleep(resultMicroSeconds*3);
            }
        }
        if(winSet) {
            wallet = wallet*mult;
            wallet = wallet-s1->quota;
            break;
        }
        if(mult <= 0) {
            usleep(resultMicroSeconds*2);
            wallet = 0;
            if(mult <= 0) {
                stringWallet = "000.00";
                result = "You lost it all. press [Q] to quit.                ";
            } else if(currentTurn == s1->turns) {
                result = "You didn't meet quota. press [Q] to quit.          ";
            }
            printGameScreen();
            input = getch();
            while(input != 113 && input != 81) input = getch();
            quit();
        }
        checkAchievements(s1);
    }
}

void checkAchievements(Set *&s1) {
    if(endOfSetForFlawlessWin && notLostRoundYetForFlawlessWin) {
        flawlessWinUnlocked = true;
    }
    if(totalLost >= 15 && s1->setNum >= 3) {
        undeniablePerseveranceUnlocked = true;
    }
    if(totalEarned-totalLost >= 50) {
        theNextRichWarriorUnlocked = true;
    }
    if(totalLost >= 50) {
        unluckyBastardUnlocked = true;
    }
    if(winSet && s1->setNum == 7) {
        goalFinisherUnlocked = true;
    }
}



void quit() {
    lostGame = true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    _setmode(_fileno(stdout), CP_UTF8);
    cout << fixed << setprecision(2);
    srand(time(0));

    

    printIntroScreen();
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
    


    // printGameScreen();
    
    int sListSize = 7;
    Set *sList[sListSize];
    Set *s1 = new Set(), *s2 = new Set(), *s3 = new Set(), *s4 = new Set(), *s5 = new Set(), *s6 = new Set(), *s7 = new Set();
    s1->setNum = 1, s1->quota = 13, s1->turns = 10;
    s2->setNum = 2, s2->quota = 5, s2->turns = 10;
    s3->setNum = 3, s3->quota = 8, s3->turns = 7;
    s4->setNum = 4, s4->quota = 15, s4->turns = 6;
    s5->setNum = 5, s5->quota = 20, s5->turns = 5;
    s6->setNum = 6, s6->quota = 24, s6->turns = 5;
    s7->setNum = 6, s7->quota = 100, s7->turns = 20;
    sList[0] = s1;
    sList[1] = s2;
    sList[2] = s3;
    sList[3] = s4;
    sList[4] = s5;
    sList[5] = s6;
    sList[6] = s7;
    
    for(int i = 0; i < 3; i++) {
        genSet(sList[i]);
        if(quitGame || !winSet) {
            break;
        }
    }
    cout << " Thank you for playing!" << endl;

    // genSet(s1);
    // genSet(s2);
    // genSet(s3);

    
    return 0;
}

/*

22.5
5 3



*/