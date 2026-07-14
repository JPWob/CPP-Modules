/*


GETLINE
 std::getline can only read from streams. 
 It cannot read from a plain string variable.
 std::getline(std::istream& is, std::string& str, char delim)
 
 std::ifstream  inFile;
 inFile.is_open();
 std::string    line;
 std::getline(inFile, line);    //saving one line from inFile; Isolating exactly one row of data at a time

 std::stringstream ss(line);    //Once you have that single line saved in a string, you feed it into a std::stringstream
 std::getline(ss, token, ',');  //feeding line instead of ss is not possible. Must be a stream!

1. std::ofstream (Output File Stream)
    What it's for: Writing into files (creating or overwriting them).
    Analogy: Think of it like std::cout, but instead of printing to the screen, it prints to a file.

2. std::ifstream (Input File Stream)
    What it's for: Reading from files.
    Analogy: Think of it like std::cin, but instead of waiting for keyboard input, it grabs data out of a file.

3. std::fstream (File Stream)
    What it's for: Doing both at the same time.
    Analogy: It can read and write simultaneously, which is handy for editing a file in place, though it requires managing file pointers manually.

Writing to a file

#include <iostream>
#include <fstream>

    int main() {
        // 1. Create an output stream and open a file named "example.txt"
        std::ofstream outFile("example.txt");

        // 2. Always check if the file opened successfully
        if (outFile.is_open()) {
            outFile << "Hello, File World!\n";
            outFile << 42 << "\n";
            
            // 3. Close the file when done (good practice, though destructor does it automatically)
            outFile.close();
            std::cout << "File written successfully.\n";
        } else {
            std::cerr << "Error opening file for writing.\n";
        }
        return 0;
    }

Reading from a file

#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 1. Create an input stream and open the file
    std::ifstream inFile("example.txt");
    std::string line;

    // 2. Check if the file exists and opened correctly
    if (inFile.is_open()) {
        // 3. Read line by line until the end of the file
        while (std::getline(inFile, line)) {
            std::cout << "Read: " << line << '\n';
        }
        inFile.close();
    } else {
        std::cerr << "Error opening file for reading.\n";
    }
    return 0;
}

*/


/*
The container most suited for a key-value concept in C++ is the Map.

- The Key must be unique!!
- Value is associated to that key, musnt be unique

#include <map>
std::map

E.G.
    std::map<std::string, double> dataMap

    dataMap["2026-07-12"] = 42.5;   // Populating some dummy data for the example

Ordering: Elements are stored in no particular order.


💡💡 How to Search for Elements 💡💡

Common  mistake: Searching for a key using the square brackets like this:
    
    if (dataMap["2026-07-12"] == ... ) {...}
        -> That date doesn't exist in your map, the [] operator will accidentally 
           create it on the spot with a default value of 0.0. 
        -> This bloats your memory and messes up your data.




*/