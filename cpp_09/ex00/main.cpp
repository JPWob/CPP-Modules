#include "BitcoinExchange.hpp"



int main(int argc, char* argv[]){

    if(argc != 2){
        std::cerr << "Error: Usage \'./name filename\'" << std::endl;
        return 1;
    }
    
    // Create a map to hold the CSV data
    std::map<std::string, double> map_csv;
    if(! getCsvData(map_csv)){
        return 1;
    }
    // Process Input file
    if(! input_file(map_csv, argv[1])){
        return 1;
    }

    /* Test for printing out map_csv
    std::map<std::string, double>::const_iterator it;
    for(it = map_csv.begin(); it != map_csv.end(); ++it){
        // it->first is the Key (Date)
        // it->second is the Value (Decimal)
        std::cout << "Key: " << it->first << " | Value: " << it->second << std::endl;
    
    }*/
    
    return 0;
}


int input_file(std::map<std::string, double>& map_csv, char*& filename ){
    // Create stream, open file
    std::ifstream inFile(filename);
    if(!inFile.is_open()){
        std::cerr << "Error opening file: "<< filename << std::endl;
        return -1; 
    }
    
    // Read the file line by line
    std::string line;
    std::string date;
    double factor;
    bool isFirstLine = true;

    while(std::getline(inFile, line)){      //reading one line
        if(isFirstLine)                 //check for header, skip line if it is a header
        {                    
            isFirstLine = false;
            if(isHeader(line)) continue;
        }
        else
        {
            if(!findDelimiter(line))
                continue;
            std::stringstream ss(line);     //line to stream, 
            if(!getDate(ss, date) || !getFactor(ss, factor)){
                continue;
            }
            printValue(map_csv, date, factor);
        }
        continue;
    }
    return 1;
}



void printValue(std::map<std::string, double> map_csv, std::string& date, double factor){  

    double value;
    std::map<std::string, double>::const_iterator it = map_csv.upper_bound(date);

    // If the iterator is at the very beginning, it means our input date  is older than the earliest date in our database (e.g., input is 2001, database starts in 2009).
    if (it == map_csv.begin()) {
        std::cerr << "Error: no exchange rate available for date => " << date << std::endl; //though technicallz this will only ever print for 2009-01-01
        return;
    }
    --it; // Move the iterator back to the last date. absolutly necesary if date is not in csv file
    
    value = it->second * factor;   
    std::cout << date << " => " << factor << " = " << value << std::endl;
}
