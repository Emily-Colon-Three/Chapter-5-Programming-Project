#include <iostream>
#include <fstream> // fstream is included to use file reading and writing in the standard C++ library

using namespace std;

// Function that takes in the strings for the student, current first place student, and current last place student, and returns a string indicating whether that student is first, last, or neither in line.
string findStudentPlace(string s, string first, string last)
{
    if (s < first) // If the student has a name alphabetically before the current first place
    {
        return "First";
    }
    if (s > last) // If the student has a name alphabetically after the current last place
    {
        return "Last";
    }
    else
    {
        return "Neither";
    }
}
int main()
{
    // Variables for the number of students, the input file of the list of students, the first and last students in line (initialized to "Z" and "A", and a string which holds the current student name being read off the text file.
    int studentCount = 0;
    ifstream studentList;
    string firstStudent = "Z";
    string lastStudent = "A";
    string student; // student is the variable for the current name being read

    studentList.open("LineUp.txt"); // Opens the file

    while (getline(studentList, student)) // While there is a line to read, read it, then execute the code in this loop
    {
        if (findStudentPlace(student, firstStudent, lastStudent) == "First")
        {
            firstStudent = student; // Student becomes new first place
        }
        if (findStudentPlace(student, firstStudent, lastStudent) == "Last")
        {
            lastStudent = student; // Student becomes new last place
        }

        studentCount++; // Add 1 to the count of students for each iteration
    }

    // Gives the results of the program
    cout << "The first student in line should be " << firstStudent << endl;
    cout << "The last student in line should be " << lastStudent << endl;
    cout << "There are " << studentCount << " students total.\n";

    // Closes the file and returns 0, ending the program.
    studentList.close();
    return 0;
}
