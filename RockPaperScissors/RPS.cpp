#include <iostream>

// Constant variables
const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

using namespace std;

char computerOption() {
    srand(time(0));
    int num = rand() % 3 + 1;

    if (num == 1) return 'r';
    if (num == 2) return 'p';
    if (num == 3) return 's';
}

char userOption() {
    char c;
    cout << "Welcome to Rock, Paper, Scissors!\n";
    cout << "You'll be playing against the computer.\nChoose one of the following options\n";
    cout << "-----------------------------------\n";
    cout << "(r) for Rock " << endl << "(p) for Paper" << endl << "(s) for Scissors " << endl;
    cin >> c;
    cout << "-----------------------------------\n";

    while (c != 'r' && c != 'p' && c != 's')
    {
        cout << "Please enter one of the following options only. " << endl;
        cout << "(r) for rock " << endl << "(p) for paper" << endl << "(s) for scissors " << endl;
        cin >> c;
    }

    return c;
}

void showSelectedOption(char option) {
    if (option == 'r') cout << "Rock" << endl;
    if (option == 'p') cout << "Paper" << endl;
    if (option == 's') cout << "Scissors" << endl;
}

void chooseWinner(char uChoice, char cChoice) {
    if (uChoice == ROCK && cChoice == PAPER) {
        cout << "Computer Wins! Paper wraps Rock." << endl;
    }
    else if (uChoice == PAPER && cChoice == SCISSORS) {
        cout << "Computer Wins! Scissors cut Paper." << endl;

    }
    else if (uChoice == SCISSORS && cChoice == ROCK) {
        cout << "Computer Wins! Rock smashes Scissors." << endl;

    }
    else if (uChoice == ROCK && cChoice == SCISSORS) {
        cout << "You Win! Paper wraps Rock." << endl;

    }
    else if (uChoice == PAPER && cChoice == ROCK) {
        cout << "You Win! Paper wraps Rock." << endl;

    }
    else if (uChoice == SCISSORS && cChoice == PAPER) {
        cout << "You Win! Scissors cut Paper." << endl;
    }
    else {
        cout << "Tie. Play again to win the game." << endl;
    }
}

int main() {
    char again = 'y';
    do {
        char uChoice;
        char cChoice;

        uChoice = userOption();
        cout << "Your choice is: ";
        showSelectedOption(uChoice);

        cout << "Computer's choice is: ";
        cChoice = computerOption();
        showSelectedOption(cChoice);

        chooseWinner(uChoice, cChoice);
        
        cout << "\n Would you like to play again? (y or n): ";
        cin >> again;
    } while (again == 'y');

    return 0;
}