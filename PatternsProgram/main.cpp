#include <iostream>

using namespace std;

int main()
{
    // Variable for the number of characters in a given line
    int width;

    width = 1; // Width is set to 1 before starting Pattern A

    // Loop for Pattern A
    for (int i = 10; i > 0; i--)
    {
        for (int c = 0; c < width; c++)
        {
            cout << "+";
        }

        // Increments the width and starts a new line once all characters are printed.
        width++;
        cout << endl;
    }

    width = 10; // Width is set to 10 before starting Pattern B

    // Loop for Pattern B
    for (int i = 10; i > 0; i--)
    {
        for (int c = 0; c < width; c++)
        {
            cout << "+";
        }

        // Decrements width and ends line after all characters of a line are printed.
        width--;
        cout << endl;
    }

    // Ends program.
    return 0;
}
