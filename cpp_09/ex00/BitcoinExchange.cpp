#include "BitcoinExchange.hpp"

bool getDate(std::stringstream& ss, std::string& date){
    std::getline(ss, date, '|');
    ss.clear();
    if(!isValidDate(date)){
        std::cerr << "Error: invalid date format: "<< date << std::endl;
        return false;
    }
    return true;
}

bool getFactor(std::stringstream& ss, double& factor){
    
    char leftover;
    if(ss >> factor && !(ss >> leftover)){
        if(factor < 0){
            std::cerr << "Error: not a positive number." << std::endl;
            return false;
        }
        if(factor > 1000){
            std::cerr << "Error: too large a number." << std::endl;
            return false;
        }
        return true;
    }
    else{
        ss.clear();
        std::cerr << "Error: bad input => " << ss.str() << std::endl;
        return false;
    }
}


bool isHeader(std::string& line){
    if(line == "date | value") 
        return true;
    else 
        return false;
}


bool isValidDate(std::string& date) {

    //std::cout << "Checking date: " << date << "Check lenght " << date.length() << std::endl; // Debugging line
    // 1. Must be exactly 10 characters long
    if (date.length() != 11)
        return false;

    // 2. Must have dashes at indices 4 and 7
    if (date[4] != '-' || date[7] != '-' || date[10] != ' ') 
        return false;

    // 3. Every other character must be a digit
    for (size_t i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) 
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    
    int year  = std::atoi(date.substr(0, 4).c_str());   //std::atoi is legacy functions that expects a C-style string (null-terminated character array) as input.
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 2009 || year > 2026){
        std::cerr << "Error: invalid year: " << year << ". Please stay within 2009 and 2026" << std::endl;
        return false;
    }   
    if ((month < 1 || month > 12) || (day < 1 || day > 31)) {
        std::cerr << "Error: invalid date: " << date << std::endl;
        return false;
    }
    return true;
}

bool findDelimiter(std::string& line){
    if(line.find('|') == std::string::npos){
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    return true;
}



bool getCsvData(std::map<std::string, double>& map_csv){
    std::ifstream data("data.csv");
    std::string csv_line;
    if(!data.is_open()){
        std::cerr << "Error: could not open data.csv" << std::endl;
        return false;
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
    return true;
    
}