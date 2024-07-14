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
        cin >> choice;
        makeMove(choice);
    }
}

int main() {
    // int choice; // 0 = lower, 1 = higher
    genRound();
    
    makeMove(choice);
    return 0;
}