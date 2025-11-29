#ifndef SED_HPP
#define SED_HPP

#include <fstream>
#include <string>

std::string readFile(std::ifstream& infile);
std::string replaceOccurrences(std::string const& data,
                               std::string const& search,
                               std::string const& replace);
bool writeFile(std::ofstream& outfile, std::string const& data);

#endif
