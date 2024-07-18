#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdlib>

#include "round.h"

using namespace std;

string choice;
int N = 20;
double current=10, mult=1;
int num1, num2;
double deposit = 0;
bool gameFinish = false;
bool winRound = false;
bool lost = false;
void intro() {
    cout << "Welcome! This game is a game of risk taking, both high and low." << endl;
    cout << "[1] Game Background" << endl;
    cout << "[2] How to Play" << endl;
    cout << "[3] Start" << endl;
    string s;
    cin >> s;
    while(s != "3") {
        if(s=="1") {
            cout << "~~==Game Background==~~" << endl;
            cout << "Wow, you're actually reading this." << endl;
            cout << "Well, Panda Banda (developer) created this game in the summer of 2024, because he was bored." << endl;
            cout << "Anyways, enjoy the game." << endl << endl;
            cout << "~~==MENU==~~" << endl;
            cout << "[1] Game Background" << endl;
            cout << "[2] How to Play" << endl;
            cout << "[3] Start" << endl;
            cin >> s;
        } else if(s=="2") {
            cout << "~~==How to Play==~~" << endl;
            cout << "Initial info: You start with 10 coins and you need to reach a quota before you finish the round" << endl;
            cout << "Initial info: In each round, you start off with how many coins you had last round" << endl;
            cout << "1: You will be given a number between 1 and 20 (inclusive), let's say 15." << endl;
            cout << "2: You will have to guess if the next number is higher or lower than the given number (15). (Note: no chance it will be 15 again)" << endl;
            cout << "3: If you choose the safer option, you earn less but also lose less if you're wrong." << endl;
            cout << "4: If you choose the *riskier* option, you earn more but also lose more if you're wrong." << endl;
            cout << "5: Happy risk taking :)" << endl << endl;
            cout << "~~==MENU==~~" << endl;
            cout << "[1] Game Background" << endl;
            cout << "[2] How to Play" << endl;
            cout << "[3] Start" << endl;
            cin >> s;
        } else {
            cout << "Invalid input, try again." << endl;
            cin >> s;
        }
    }
    cout << "Alright, let the risks begin!" << endl << endl;
}

void genTurn(Round *rou) {
    num1 = rand()%N+1;
    num2 = rand()%N+1;
    while(num1 == num2) num2 = rand()%N+1;
    cout << "The first number is " << num1 << ". " << num2 << endl;
}

void makeMove(Round *rou) {
    cout << "Enter h/H or l/L for higher or lower." << endl;
    cin >> choice;
    bool win = ( (choice=="H"||choice=="h") && num2>num1 ) || ( (choice=="L"||choice=="l") && num2<num1 );
    if(choice == "H" || choice == "h") {
        if(num2>num1) cout << "Congrats, it was higher (" << num2 << ")" << endl;
        else cout << "Womp womp it was lower (" << num2 << ")" << endl;
    } else if(choice == "L" || choice == "l") {
        if(num2<num1) cout << "Congrats, it was lower (" << num2 << ")" << endl;
        else cout << "Womp womp it was higher (" << num2 << ")" << endl;
    } else {
        cout << "Bro invalid input. ";
        makeMove(rou);
    }
    double multAdd = (double) num1/N;
    if(choice=="l" || choice == "L") multAdd = 1.00-multAdd;
    if(!win) multAdd = -multAdd;
    mult = mult+multAdd;
    cout << "You now have " << (current*mult) << endl << endl;


}

void checkDeposit(Round *rou) {
    if(mult*current >= rou->quota) {
        cout << "You reached the quota for this round, play it safe and deposit all or keep the risks going?" << endl;
        cout << "If you keep going, you can earn more before next round, or win this round first." << endl;
        cout << "Enter y/Y to deposit, or n/N to keep going" << endl;
        cin >> choice;
        while(choice != "y" && choice != "Y" && choice != "n" && choice != "N") {
            cout << "Bro invalid input." << endl;
            cin >> choice;
        }
        if(choice == "y" || choice == "Y") {
            cout << "Congratulations! You finished round #" << rou->roundNum << ". Entering next round." << endl;
            deposit = deposit + rou->quota;
            current = mult*current;
            current = current-rou->quota;
            current = round(current-0.5);
            cout << "Deposit: " << deposit << endl;
            cout << "Current: " << current << endl;
            winRound = true;
        } else if (choice == "n" || choice == "N") {
            cout << "Alrighty, keep the risks rolling!" << endl;
            winRound = false;
        }
    }
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
        makeMove(rou);
        if(turnNum == rou->turns) {
            cout << "Aight, you just finished your last move for this turn, time to end it" << endl;
        } else checkDeposit(rou);
        if(winRound) break;
    }
    if(!winRound) {
        if(current*mult < rou->quota) {
            cout << "Womp womp, you lost. Try harder next time :(" << endl << endl;
            lost = true;
        } else {
            cout << "Wow, played until the last round to win huh, time to go to the next round" << endl << endl;
        }
    }
}

int main() {
    srand(time(0));
    intro();
    Round *r1 = new Round(), *r2 = new Round(), *r3 = new Round(), *r4 = new Round(), *r5 = new Round();
    r1->roundNum = 1, r1->quota = 12, r1->turns = 10;
    r2->roundNum = 2, r2->quota = 15, r2->turns = 10;
    r3->roundNum = 3, r3->quota = 18, r3->turns = 7;
    r4->roundNum = 4, r4->quota = 25, r4->turns = 6;
    r5->roundNum = 5, r5->quota = 43, r5->turns = 5;
    // cout << r1->roundNum << " " << r1->quota << " " << r1->turns << endl;
    genRound(r1);
    if(lost) return 0;
    genRound(r2);
    if(lost) return 0;
    genRound(r3);
    if(lost) return 0;
    genRound(r4);
    if(lost) return 0;
    cout << "Game finished, type a string and hit enter to quit";
    string s;
    cin >> s;
    return 0;
}