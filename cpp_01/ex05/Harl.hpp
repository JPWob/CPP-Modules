#include <iostream>
#include <string>

class Harl {

public:

void complain( std::string level);

private:
void debug( void );
void info( void );
void warning( void );
void error( void );

}


/*


2️⃣ Pointers to member functions
In C++, you can store a pointer to a class’s member function:

class Robot {
public:
    void move() { std::cout << "Move\n"; }
    void stop() { std::cout << "Stop\n"; }
    void turn() { std::cout << "Turn\n"; }
};

// Type of pointer to member function that returns void and takes no arguments
// Action can point to any of Robot’s methods with signature void().
typedef void (Robot::*Action)();


3️⃣ Using PMFs with a map
Instead of if/else, you can use a std::map (or array) to associate strings with functions:

*/