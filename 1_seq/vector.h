#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstdlib>
#include "vector-def.h"

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
inline vector_t<T>::~vector_t()
{
}


template<typename T>
bool vector_t<T>::empty() const
{
    return false;
}

#endif