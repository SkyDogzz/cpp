#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <deque>
#include <iostream>
#include <vector>

class PMergeMe {
private:
	std::vector<int> _vector;
	std::deque<int>	 _dequeue;

public:
	PMergeMe();
	PMergeMe(const PMergeMe& other);
	PMergeMe& operator=(const PMergeMe& other);
	~PMergeMe();
};

#endif
