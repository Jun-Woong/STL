#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstdlib>
#include <iostream>
#include "vector-def.h"

using namespace std;

template <typename T>
vector_t<T>::vector_t() :
    array(0),
    array_size(0),
    num_elements(0) {
}

// your answer

template<typename T>
inline vector_t<T>::vector_t(const vector_t& v)
{
}

template<typename T>
inline vector_t<T>::~vector_t() {}


template<typename T>
inline bool vector_t<T>::empty() const
{
    cout << "test empty : " << (sizeof(array) / sizeof(*array)) << " type is : " << typeid(sizeof(array) / sizeof(*array)) << endl;
    if (array_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

#endif