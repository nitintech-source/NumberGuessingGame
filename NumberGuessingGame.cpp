#include <iostream> 
#include <cstdlib>  
#include <ctime>     
#include <limits>    
#include <string>   
using namespace std;

int generateNumber(int maxRange) {
    return rand() % maxRange + 1;
}

int main() {
    srand(time(0));  
    int maxRange, bestScore = 11;
    char playAgain;
    string playerName;

    cout << "?? Welcome to the Number Guessing Game!\n";
    cout << "Please enter your name: ";
    getline(cin, playerName); 

    do {
        int level;
        cout << "\n?? Hello, " << playerName << "! Let's choose a difficulty level:\n";
        cout << "1. Easy (1-50)\n2. Medium (1-100)\n3. Hard (1-200)\n";
        cout << "Enter your choice (1/2/3): ";
        cin >> level;

        switch(level) {
            case 1: maxRange = 50; break;
            case 2: maxRange = 100; break;
            case 3: maxRange = 200; break;
            default: maxRange = 100; cout << "Invalid choice. Defaulting to Medium.\n";
        }

        int secretNumber = generateNumber(maxRange);  
        int guess, attempts = 0;
        bool won = false;

        cout << "\n?? " << playerName << ", I have selected a number between 1 and " << maxRange << ".\n";
        cout << "?? You have up to 10 attempts to guess it.\n";

        while (attempts < 10) {
            cout << "\nAttempt " << (attempts + 1) << ": Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess == secretNumber) {
                cout << "\n?? CONGRATULATIONS, " << playerName << "! YOU WIN! ??\n";
                cout << "?? Correct number: " << secretNumber << "\n";
                cout << "?? Attempts used: " << attempts << "\n";
                won = true;

                if (attempts < bestScore) {
                    bestScore = attempts;
                    cout << "?? NEW HIGH SCORE, " << playerName << "! ??\n";
                }
                break;
            } else if (guess > secretNumber) {
                cout << "?? Too high! Try a smaller number.\n";
            } else {
                cout << "?? Too low! Try a bigger number.\n";
            }
        }

        if (!won) {
            cout << "\n?? Sorry " << playerName << ", YOU LOSE! ??\n";
            cout << "?? The correct number was: " << secretNumber << "\n";
        }

        if (bestScore <= 10)
            cout << "?? " << playerName << ", your best score (minimum attempts): " << bestScore << "\n";

        cout << "\n?? Do you want to play again, " << playerName << "? (y/n): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n?? Thank you for playing, " << playerName << "! See you next time. ??\n";
    return 0;
}
