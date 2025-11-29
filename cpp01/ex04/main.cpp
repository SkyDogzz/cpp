#include "sed.hpp"

#include <iostream>
#include <string>

static int exitWithError(std::string const& message) {
	std::cerr << message << std::endl;
	return 1;
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		return exitWithError("Usage: ./sed_is_for_losers <filename> <s1> <s2>");
	}

	const std::string filename = argv[1];
	const std::string search = argv[2];
	const std::string replace = argv[3];

	if (search.empty()) {
		return exitWithError("s1 cannot be empty, nothing to replace.");
	}

	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		return exitWithError("Failed to open input file: " + filename);
	}

	std::string data = readFile(infile);
	if (!infile.good() && !infile.eof()) {
		return exitWithError("Error while reading input file.");
	}
	infile.close();

	std::string replaced = replaceOccurrences(data, search, replace);

	std::string outFilename = filename + ".replace";
	std::ofstream outfile(outFilename.c_str());
	if (!outfile.is_open()) {
		return exitWithError("Failed to open output file: " + outFilename);
	}

	if (!writeFile(outfile, replaced)) {
		return exitWithError("Failed to write to output file.");
	}
	outfile.close();
	std::cout << "Successfully wrote replacements to " << outFilename << std::endl;
	return 0;
}
