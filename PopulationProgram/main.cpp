#include <iostream>

using namespace std;

// The function which takes the three inputs of the program and verifies they are of acceptable value, returning an error if not.
int verifyInput(int sp, float ri, int d)
{
    if (sp < 2) // Starting population is at least 2
    {
        cout << "Invalid Starting Population: Must be at least 2.\n";
        return 1;
    }
    else if (ri < 0) // Rate of increase is not negative
    {
        cout << "Invalid Rate of Increase: Cannot be negative.\n";
        return 1;
    }
    else if (d < 1) // Days is not less than 1
    {
        cout << "Invalid Number of Days: Must be at least 1.\n";
        return 1;
    }
    else // If all checks are passed
        return 0;
}

int simulateDay(int p, float ri) // Takes in population and rate of increase
{
    static int population = p;
    population = population + (population * ri);

    cout << "Population of " << population << endl;
    return population;
}

int main()
{
    // Variables of the program, for the starting population, days, and the rate of increase.
    int startingPopulation, days;
    float rateIncrease;

    // Prompts user for the inputs of the program
    cout << "Welcome to the Population Simulation.\n";
    cout << "Please enter your starting population: ";
    cin >> startingPopulation;
    cout << "Please enter the rate of population increase (%): ";
    cin >> rateIncrease;
    rateIncrease /= 100; // Converts the rate of population increase to a float.
    cout << "Please enter the number of days your simulation will run for: ";
    cin >> days;

    if (verifyInput(startingPopulation, rateIncrease, days) == 1) // Calls verifyInput(), and if any of the input verifications fail, the program will end through main.
    {
        return 1;
    }

    // The loop which simulates the population for the specified number of days
    for (int dayNumber = 1; dayNumber <= days; dayNumber++)
    {
        cout << "After " << dayNumber << " day(s): ";
        simulateDay(startingPopulation, rateIncrease); // Simulates the day
    }

    cout << "Simulation complete.\n";
    return 0;
}
