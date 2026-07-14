#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

bool    getCsvData(std::map<std::string, double>& map_csv);
int     input_file(std::map<std::string, double>& map_csv, char*& filename );
bool    isValidDate(std::string& date);
bool    isHeader(std::string& line);
bool    findDelimiter(std::string& line);
bool    getDate(std::stringstream& ss, std::string& date);
bool    getFactor(std::stringstream& ss, double& factor);

void printValue(std::map<std::string, double> map_csv, std::string& date, double factor);