#include <iostream>
#include <fstream> // Needed for file input and output
#include <string>

using namespace std;

// Takes in population and year, then prints out, in proper format, the data point as a bar with a year on the left side.
void dataPoint(int p, int y) // input is (population, year)
{
    cout << y << " ";

    // Loop which prints asterisks for each 1000 in the population, decreasing by 1000 until no more should be printed.
    while (p >= 500) // If the remainder from dividing population into portions of 1000 is 500 or greater, the figure will be rounded up.
    {
        cout << "*";
        p -= 1000;
    }
}

int main()
{
    // The variables, being population, year, town name, file name, and the variable used for the input file.
    int population;
    string rawPopulation; // This is just used to store the string form of population before it is converted to int
    int year = 1900;
    string townName;
    string fileName;
    ifstream dataFile;

    // Gets data file name and town name from user
    cout << "What is the name of the data file for town? (include file extension)\n";
    cin >> fileName;
    cout << "And what is the name of this town?\n";
    cin >> townName;

    dataFile.open(fileName); // Opens the file named by the user as input file dataFile

    // Gives an error if the data file failed to be opened
    if (!dataFile.is_open())
    {
        cout << "ERROR: File not found.\n";
        return 1;
    }

    // Gives a title and clarification to the bar graph
    cout << townName << " Population Over Time\n";
    cout << "(Each * represents 1000 people)\n";

    // While there is data left to be read, convert to population then execute loop code
    while (getline(dataFile, rawPopulation))
    {
        population = stoi(rawPopulation); // Converts the raw string from getline() to an integer, population

        dataPoint(population, year); // Uses void function dataPoint() with the input of population from dataFile and the year
        cout << endl;

        year += 20; // Adds 20 to the year once the data point has been printed, ensuring the first point is 1900.
    }

    // File is closed, and program ends.
    dataFile.close();
    return 0;
}
