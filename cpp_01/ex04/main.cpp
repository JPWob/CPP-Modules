#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: could not open " << filename << std::endl;
        return 1;
    }
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        infile.close();
        std::cerr << "Error: could not create output file" << std::endl;
        return 1;
    }
    std::string line;
    size_t len_s1 = s1.length();
    size_t len_s2 = s2.length();

    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while (1)
        {
			pos = line.find(s1, pos);
            if(pos == std::string::npos)
				break;
			line.erase(pos, len_s1);    // Remove s1
            line.insert(pos, s2);       // Insert s2 
            pos += (len_s2);            // important in case s2 contains s1!
        }
        outfile << line;
        if (!infile.eof())
            outfile << std::endl;// std::getline removes the newline character, so we must re-add it if we haven't reached the end of the file yet.
    }

    infile.close();
    outfile.close();
    return 0;
}

/*

infile is an std::ifstream
	- reads from a file
	- connects to the filesystem (OS-level file).
	- contains a std::filebuf, which buffers part of the file from disk. 
	  It only holds small chunks, not the whole file.
	- std::filebuf stores OS filedescriptor, current read poition, buffer end and start.
	- contains a stream state flag
	- usage: Reading a file line by line, reading numbers from a file

std::stringstream
	- reads or writes from a string in memory
	- contains a std::stringbuf, which buffers the entire string in memory.
	- you can immediately do .str() on a stringstream to get the whole content
	- use: Parsing a string into numbers, building strings dynamically, replacing substrings

// ifstream
std::ifstream file("file.txt");  // opens file immediately, may fail if the file does not exist.

// stringstream
std::stringstream ss("some text"); // initializes buffer with string, never fails — it just has an empty or given string buffer.

--------
7️⃣ Practical Example (File Replacement)
std::ifstream infile("file.txt");
std::stringstream buffer;

buffer << infile.rdbuf(); 
	//Copy file into memory
	//Returns a pointer to the internal stream buffer (std::filebuf*)
	// rdbuf() does not read the whole file immediately — it exposes the buffer,
	//The operator reads the buffer chunk by chunk until EOF and writes it into buffer.

std::string content = buffer.str();
	// Get whole content as string
---------


std::cin        	→ reads from keyboard
std::ifstream   	→ reads from file
std::stringstream 	→ reads from / writes to a string (memory)

std::ifstream infile(filename.c_str());

- It creates an object infile of type std::ifstream that is connected to the file.
- constructor : explicit std::ifstream(const char* filename, std::ios_base::openmode mode = std::ios::in);
	- It opens the file named by the string you pass.
	- By default, it opens it in input mode (std::ios::in).
- filename is likely a std::string.
- c_str() converts a std::string to a C-style null-terminated string (const char*).
- ifstream in C++98 requires a const char* for the constructor, so c_str() is necessary.


Stream State Flags (for deeper understanding)

	-goodbit → everything fine
	-failbit → logical input failure  (File not found/ reading text into int)
	-badbit → serious I/O error			(Disk I/O corruption)
	-eofbit → reached end of file

	stream.fail() checks failbit or badbit.
	stream.bad() checks only badbit.
	stream.eof() checks only eofbit.

	1️⃣ if (!infile)  (most common)
		- This checks whether the stream is in a failed state.
		- Equivalent to: if (infile.fail() || infile.bad())
	2️⃣ if (infile.fail())
		- Checks specifically the failbit or badbit.
		- Works fine for open failure.
	3️⃣ if (!infile.is_open())
		- Checks whether the file descriptor is actually open.
		-→ checks if the file is associated with the stream


*/