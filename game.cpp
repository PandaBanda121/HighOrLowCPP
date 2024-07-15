#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdlib>
using namespace std;

string choice;
int N = 20;
int rounds, attempts, quota;
int num1, num2;
double current, mult;
double deposit = 0;
bool gameFinish = false;
void intro() {
    cout << "Welcome! This game is a game of risk taking, both high and low." << endl;
    cout << "[1] Game Background" << endl;
    cout << "[2] Rules and How to Play" << endl;
    cout << "[3] Start" << endl;
    cout << "[4] Quit" << endl;
    string s;
    cin >> s;
    while(s != "4") {
        if(s=="1") {
            cout << "~~==Game Background==~~" << endl;
            cout << "Wow, you're actually reading this." << endl;
            cout << "Well, Panda Banda (me) developed this game in the summer of 2024, because I'm bored." << endl;
            cout << "Anyways, enjoy the game." << endl;
            cout << "~~==MENU==~~" << endl;
            cout << "[1] Game Background" << endl;
            cout << "[2] Rules" << endl;
            cout << "[3] Start" << endl;
            cout << "[4] Quit" << endl;
            cin >> s;
        } else if(s=="2") {
            cout << "~~==Rules and How to Play==~~" << endl;
            cout << "Initial info: You are stuck starting with 10 coins" << endl;
            cout << "Initial info: You need to increase your multiplier to reach a quota before you lose all your turns and die." << endl;
            cout << "Initial info: How to increase multiplier? Guess 'High or Low'" << endl;
            cout << "1: You will be given a number between 1 and 20 (inclusive), let's say 15." << endl;
            cout << "2: You will have to guess is the next number going to be above or below the given number (15)." << endl;
            cout << "3: These numbers are all chosen independently and randomly with equal chance" << endl;
            cout << "4: If playing safely, most people will choose lower, since there are more numbers lower than 15 compared to higher" << endl;
            cout << "5: Here's the twist: If you choose the safer option, your multiplier increases less if you win, and also decreases less if you lose." << endl;
            cout << "6: But... If you choose the *riskier* option, your multiplier increases more if you win, but also decreases more if you lose." << endl;
            cout << "7: Once you reach your quota, you can either continue taking risks to earn more before the next round or just end the current round and continue to the next round" << endl;
            cout << "8: Once the round ends and you have met the quota, you start the next round with your last round's earnings but multiplier is reset to 1" << endl;
            cout << "9: Don't risk too much but don't play too safe either! Good luck." << endl;
            cout << "~~==MENU==~~" << endl;
            cout << "[1] Game Background" << endl;
            cout << "[2] Rules" << endl;
            cout << "[3] Start" << endl;
            cout << "[4] Quit" << endl;
            cin >> s;
        } else if(s=="3") {
            cout << "Alright, let the risks begin!" << endl;
            break;
        } else {
            cout << "Invalid input, try again." << endl;
            cin >> s;
        }
    }
    if(s=="4") {
        cout << "Aight, cya bucko, take some risks later, you only live once, learn from it, then do better, even when it's not in your favor." << endl;
        gameFinish = true;
    }
}

void genRound() {
    num1 = rand()%N+1;
    num2 = rand()%N+1;
    while(num1 == num2) num2 = rand()%N+1;
    cout << "The first number is " << num1 << "." << endl;
}

void makeMove(string choice) {
    cout << "Enter H or L for high or low." << endl;
    cin >> choice;
    if(choice == "H") {
        if(num2>num1) cout << "Yay you win! It was higher." << endl;
        else cout << "Womp womp it was lower." << endl;
    } else if(choice == "L") {
        if(num2<num1) cout << "Yay you win! It was lower." << endl;
        else cout << "Womp womp it was higher." << endl;
    } else {
        cout << "Bro invalid input, enter again." << endl;
        makeMove(choice);
    }
}

int main() {
    intro();
    if(gameFinish) return 0;
    genRound();
    makeMove(choice);
    return 0;
}