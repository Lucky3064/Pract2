/*Write a C++ program that creates an output file, writes information to it, closes
the file, open it again as an input file and read the information from the file*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Create and write to the file
    ofstream outFile("data.txt");
    if (!outFile) {
        cerr << "Error creating file." << endl;
        return 1;
    }
    outFile << "Hello, this is a sample text file.\n";
    outFile << "Writing and reading files in C++ is simple!\n";
    outFile.close();

    // Open and read from the file
    ifstream inFile("data.txt");
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    string line;
    cout << "File Contents:\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return 0;
}
