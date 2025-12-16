#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe& other) {
	(void)other;
}

PMergeMe& PMergeMe::operator=(const PMergeMe& other) {
	return *this;
	(void)other;
}

PMergeMe::~PMergeMe() {}
