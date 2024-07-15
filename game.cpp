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

void genTurn() {
    num1 = rand()%N+1;
    num2 = rand()%N+1;
    while(num1 == num2) num2 = rand()%N+1;
    cout << "The first number is " << num1 << "." << endl;
}

void makeMove(string choice) {
    cout << "Enter H or L for higher or lower." << endl;
    cin >> choice;
    if(choice == "H") {
        if(num2>num1) cout << "Yay you win! It was higher (" << num2 << ")" << endl;
        else cout << "Womp womp it was lower." << endl;
    } else if(choice == "L") {
        if(num2<num1) cout << "Yay you win! It was lower (" << num2 << ")" << endl;
        else cout << "Womp womp it was higher." << endl;
    } else {
        cout << "Bro invalid input. ";
        makeMove(choice);
    }
}

int main() {
    intro();
    genTurn();
    makeMove(choice);
    return 0;
}