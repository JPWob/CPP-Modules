#include "BitcoinExchange.hpp"

bool getDate(std::string& date){
    if(!isValidDate(date)){
        std::cerr << "Error: invalid date format: "<< date << std::endl;
        return false;
    }
    return true;
}

bool getFactor(std::string& line, double& factor){
    
    char leftover;
	std::stringstream ss(line);


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
        std::cerr << "Error: bad input2 => " << ss.str() << std::endl;
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

    // 3. Every other character must be a digit
    
    int year  = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10   + (date[3] - '0');
    int month = (date[5] - '0') * 10   + (date[6] - '0');
    int day   = (date[8] - '0') * 10   + (date[9] - '0');
    
    if (year < 2009 || year > 2026){
        std::cerr << "Error: invalid year: " << year << ". Please stay within 2009 and 2026" << std::endl;
        return false;
    }   
    if ((month < 1 || month > 12) || (day < 1 || day > 31)) {
        std::cerr << "Error: invalid date: " << date << std::endl;
        return false;
    }
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1]) {
        std::cerr << "Error: invalid date: " << date << std::endl;
        return false;
    }
    return true;
}

bool checkFormat(std::string& line){

    if (line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|'){
        std::cerr << "Error: bad format1 => " << line << std::endl;
        return false;
    }
	for (size_t i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) 
            continue;
        if ((line[i] < '0' || line[i] > '9')){
        	std::cerr << "Error: bad format2 => \"" << line << "\" Buchtsabe " << line[i] << " Index " << i << std::endl;
        	return false;
    	}
    }
    return true;
}



bool getCsvData(std::map<std::string, double>& map_csv){
    
	//OPEN
	std::ifstream	data("data.csv");
    std::string		csv_line;
    
	//check if open csv
	if(!data.is_open()){
        std::cerr << "Error: could not open data.csv" << std::endl;
        return false;
    }
	//discard first line
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