#include "PMergeMe.hpp"
#include <algorithm>
#include <sys/types.h>

PMergeMe::PMergeMe() { }

PMergeMe::PMergeMe(const PMergeMe& other) { (void)other; }

PMergeMe& PMergeMe::operator=(const PMergeMe& other)
{
    return *this;
    (void)other;
}

PMergeMe::~PMergeMe() { }

bool contains_bad_char(std::string& s, std::string set)
{
    const char* consted = static_cast<const char*>(s.data());

    while (*consted) {
        if (set.find(*consted) == std::string::npos)
            return true;
        consted++;
    }
    return false;
}

static bool validInt(const char* s)
{
    std::string set = "0123456789";
    std::string str = s;

    if (contains_bad_char(str, set))
        return false;
    else if (str.size() > 10)
        return false;
    else if (atol(str.c_str()) > UINT_MAX)
        return false;
    return true;
}

static bool findInVec(std::vector<unsigned int> vec, unsigned int search)
{
    std::vector<unsigned int>::iterator it = vec.begin();

    while (it != vec.end()) {
        if (*it == search)
            return true;
        it++;
    }
    return false;
}

void PMergeMe::verifArgs(char** args)
{
    while (*args) {
        if (!validInt(*args))
            throw PMergeMe::ArgWrongFormat();
        if (findInVec(_verif, atol(*args)))
            throw PMergeMe::ArgDuplicate();
        _verif.push_back(atol(*args));
        args++;
    }
}

const char* PMergeMe::ArgWrongFormat::what() const throw() { return "Wrong arg format"; }

const char* PMergeMe::ArgDuplicate::what() const throw() { return "Duplicate arg"; }

void PMergeMe::print_vector()
{
    std::vector<unsigned int>::iterator it = _vector.begin();
    std::cout << "Print vector" << std::endl;
    while (it != _vector.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

void PMergeMe::verif_to_vec() { _vector = _verif; }

double log2_98(double x) { return std::log(x) / std::log(2.0); }

void vector_swap(std::vector<unsigned int>::iterator v1, std::vector<unsigned int>::iterator v2, size_t block_size)
{
    const size_t half = block_size / 2;
    std::swap_ranges(v1, v1 + half, v2);
}

void PMergeMe::vector_sort_pairs(u_int16_t depth)
{
    const double limit = log2_98(static_cast<double>(_vector.size() - 1));
    const size_t block = static_cast<size_t>(1U << depth);
    const size_t half = block / 2;
    for (size_t i = 0; i + block <= _vector.size(); i += block) {
        if (_vector.at(i + half - 1) > _vector.at(i + half + half - 1)) {
            std::vector<unsigned int>::iterator v1 = _vector.begin() + i;
            std::vector<unsigned int>::iterator v2 = _vector.begin() + i + half;
            vector_swap(v1, v2, block);
        }
    }
    std::cout << "sorted pair (depth " << depth << ")" << std::endl;
    print_vector();

    if (static_cast<double>(depth) < limit) {
        vector_sort_pairs(depth + 1);
    }
}
