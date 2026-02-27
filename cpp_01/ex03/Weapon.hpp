#include <iostream>
#include <string>

class Weapon {

    const std::string& getType();
    void setType(std::string settype);


    private:

    std::string type;
};