// FIle Name: Chapter 5 Exercise 25
// Programmer Name: Ebram Azer
// Date: Nov 24
// Requrments:Create a new branch in your Exercise 14 project
// that modifies the Student Line Up program described in Programming 
// Challenge 14 so it reads the student names from the file LineUp.txt  
// The program should read names from the file until there is no more data to read.



#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // For min_element and max_element

using namespace std;

int main() {
    ifstream inputFile("LineUp.txt"); // Open the file
    vector<string> students;
    string name;

    // Check if the file opened successfully
    if (!inputFile) {
        cerr << "Error: Could not open the file LineUp.txt" << endl;
        return 1; // Exit the program with an error code
    }

    // Read names from the file
    cout << "Reading student names from LineUp.txt..." << endl;
    while (getline(inputFile, name)) {
        if (!name.empty()) { // Skip any empty lines
            students.push_back(name);
        }
    }

    // Close the file
    inputFile.close();

    // Check if there were any students in the file
    if (students.empty()) {
        cout << "No student names found in the file." << endl;
        return 0;
    }

    // Find the front and end of the line
    auto frontOfLine = *min_element(students.begin(), students.end());
    auto endOfLine = *max_element(students.begin(), students.end());

    // Report the results
    cout << "\nThe student at the front of the line is: " << frontOfLine << endl;
    cout << "The student at the end of the line is: " << endOfLine << endl;

    return 0;
}
