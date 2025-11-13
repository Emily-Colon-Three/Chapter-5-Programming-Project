#include <iostream>
#include <random>

using namespace std;

// Prints message saying guess is too high or too low, and prints nothing if neither condition is active, allowing the loop to break and game to conclude.
void isLowOrHigh(int g, int a) // g is guess, a is answer
{
    if (g < a) // If guess is lower than answer
    {
        cout << "Your guess is too low, try again. \n";
    }
    if (g > a) // If guess is higher than answer
    {
        cout << "Your guess is too high, try again. \n";
    }
}

int main()
{
    // Defines the necessary parts of random number generation, getting a random number from 0 to 1000.
    random_device answerEngine;
    uniform_int_distribution<int> randomNumber(0, 1000);

    // answer is randomized, number of guesses initialized to 0, and the user's guess defined.
    int answer = randomNumber(answerEngine);
    int numberOfGuesses = 0;
    int userGuess;

    // Loop will activate at least once
    do {
        cout << "Please make a guess for the random number.\n";
        cin >> userGuess;

        isLowOrHigh(userGuess, answer); // Will call the function to tell the user if their guess is too high or low.

        numberOfGuesses++; // Increases number of guesses with each guess taken

    } while (userGuess != answer); // Every time the guess is wrong, this loop repeats

    // Results given to user once they win, and program ends.
    cout << "You have correctly guessed the random number! Congratulations!\n";
    cout << "Guesses taken: " << numberOfGuesses;
    return 0;
}
