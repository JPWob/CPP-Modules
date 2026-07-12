#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main(int argc, char* argv[]){

    if(argc != 2){
        std::cerr << "Error: Usage \'./name filename\'" << std::endl;
        return 1;
    }

    std::ifstream data("data.csv");
    std::ifstream inFile(argv[1]);

    if(inFile.is_open()){
        std::cout << "File is open" << std::endl;
    }
    if(data.is_open()){
        std::cout << "Data is open" << std::endl;
    }

    
}


/*

Container 1: Datum - Multi
Conainer CVS: Datum - Wert

Wert * Multi

*/