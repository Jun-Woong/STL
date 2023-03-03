#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstdlib>
#include <iostream>
#include "vector-def.h"
#include <typeinfo>

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
    cout << "test empty : " << static_cast<int>((sizeof(array) / sizeof(*array))) << " type is : " << typeid((static_cast<int>(sizeof(array) / sizeof(*array)))).name() << endl;
    this.array_size = static_cast<int>((sizeof(array) / sizeof(*array)));
    if (array_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

#endif