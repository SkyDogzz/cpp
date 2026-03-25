#ifndef ARRAYm_HPP
#define ARRAYm_HPP

#include <cstddef>
#include <stdexcept>

template <typename T> class Array {
private:
    T* m_elem;
    unsigned int m_size;

public:
    Array()
        : m_elem(NULL)
        , m_size(0)
    {
    }

    Array(unsigned int n)
        : m_elem(new T[n])
        , m_size(n)
    {
    }

    Array(const Array& other)
        : m_elem(NULL)
        , m_size(0)
    {
        if (other.m_size > 0) {
            m_elem = new T[other.m_size];
            m_size = other.m_size;
            for (unsigned int i = 0; i < m_size; ++i) {
                m_elem[i] = other.m_elem[i];
            }
        }
    }

    ~Array() { delete[] m_elem; }

    Array& operator=(const Array& other)
    {
        if (this != &other) {
            delete[] m_elem;

            m_elem = NULL;
            m_size = 0;

            if (other.m_size > 0) {
                m_elem = new T[other.m_size];
                m_size = other.m_size;
                for (unsigned int i = 0; i < m_size; ++i) {
                    m_elem[i] = other.m_elem[i];
                }
            }
        }
        return *this;
    }

    T& operator[](unsigned int i)
    {
        if (i >= m_size)
            throw std::out_of_range("Array index out of range");
        return m_elem[i];
    }

    const T& operator[](unsigned int i) const
    {
        if (i >= m_size)
            throw std::out_of_range("Array index out of range");
        return m_elem[i];
    }

    unsigned int size() const { return m_size; }
};

#endif
