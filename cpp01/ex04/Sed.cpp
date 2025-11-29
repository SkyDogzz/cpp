#include "sed.hpp"

#include <sstream>

std::string readFile(std::ifstream& infile) {
	std::ostringstream buffer;
	buffer << infile.rdbuf();
	return buffer.str();
}

std::string replaceOccurrences(std::string const& data,
                               std::string const& search,
                               std::string const& replace) {
	if (search.empty()) {
		return data;
	}

	std::string result;
	std::string::size_type pos = 0;
	std::string::size_type found = data.find(search, pos);
	while (found != std::string::npos) {
		result.append(data, pos, found - pos);
		result.append(replace);
		pos = found + search.length();
		found = data.find(search, pos);
	}
	result.append(data, pos, std::string::npos);
	return result;
}

bool writeFile(std::ofstream& outfile, std::string const& data) {
	outfile << data;
	return outfile.good();
}
