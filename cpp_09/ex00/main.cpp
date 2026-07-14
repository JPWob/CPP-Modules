#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>


void get_data(std::map<std::string, double>& map_csv);
bool isValidDate(std::string& date);

int main(int argc, char* argv[]){

    
    if(argc != 2){
        std::cerr << "Error: Usage \'./name filename\'" << std::endl;
        return 1;
    }
    
    std::map<std::string, double> map_csv;
    get_data(map_csv);
    get_input(map_csv, argv[1]);

    /*
    std::map<std::string, double>::const_iterator it;
    for(it = map_csv.begin(); it != map_csv.end(); ++it){
        // it->first is the Key (Date)
        // it->second is the Value (Decimal)
        std::cout << "Key: " << it->first << " | Value: " << it->second << std::endl;
    
    }
    */
    
    
}

int get_input(std::map<std::string, double>& map_csv, char*& filename ){
    std::ifstream inFile(filename);
    if(inFile.is_open()){
        std::cout << "File is open" << std::endl;
    }
    std::string line;

    while(std::getline(inFile, line)){
        std::stringstream ss(line);
        std::string date;
        double factor;
        std::getline(ss, date, '|');
        if(!isValidDate(date)){
           return -1;
        }

    }
}


void get_data(std::map<std::string, double>& map_csv){
    std::ifstream data("data.csv");
    std::string csv_line;
    if(data.is_open()){
        std::cout << "Data is open" << std::endl;
    }
    std::getline(data, csv_line);
    
    while(std::getline(data, csv_line)){
        if (csv_line.empty()) continue; //skip empty lines
        
        std::stringstream ss(csv_line);
        std::string key;
        
        std::getline(ss, key, ','); //key becomes "2026-07-13"
        
        double value;
        if(ss >> value)             //chechking
            map_csv[key] = value;
    }
    
}

bool isValidDate(std::string& date) {
    // 3. Every other character must be a digit
    for (size_t i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) return false;
    }
    
    // 1. Must be exactly 10 characters long
    if (date.length() != 10) return false;
    
    // 2. Must have dashes at indices 4 and 7
    if (date[4] != '-' || date[7] != '-') return false;
    
    
    return true;
}

/*

Container 1: Datum - Multi
Conainer CVS: Datum - Wert

Wert * Multi

*/