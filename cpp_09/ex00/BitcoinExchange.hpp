#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iostream>

bool    getCsvData(std::map<std::string, double>& map_csv);
int     input_file(std::map<std::string, double>& map_csv, char*& filename );
bool    isValidDate(std::string& date);
bool    isHeader(std::string& line);
bool	checkFormat(std::string& line);
bool    getDate(std::string& date);
bool    getFactor(std::string line, double& factor);

void printValue(std::map<std::string, double> map_csv, std::string& date, double factor);