#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>

class PMergeMe {
private:
    std::vector<unsigned int> _verif;
    std::vector<unsigned int> _vector;
    std::deque<unsigned int> _dequeue;

public:
    PMergeMe();
    PMergeMe(const PMergeMe& other);
    PMergeMe& operator=(const PMergeMe& other);
    ~PMergeMe();

    class ArgWrongFormat : public std::exception {
    public:
        const char* what() const throw();
    };
    class ArgDuplicate : public std::exception {
    public:
        const char* what() const throw();
    };

    void verifArgs(char** args);
    void verif_to_vec();
    void print_vector();
    void vector_sort_pairs(u_int16_t depth);
};

#endif
