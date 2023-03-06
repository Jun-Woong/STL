#ifndef _LIST_H_
#define _LIST_H_

#include <cstdlib>
#include "list-def.h"

// your answer

template<typename T>
inline list_element<T>::list_element() :
left(0),
right(0),
value(0) {
}

template<typename T>
inline list_t<T>::list_t() :
array(0),
num_elements(0) {
}

template<typename T>
inline list_t<T>::list_t(const list_t<T>& v)
{
}

template<typename T>
inline list_t<T>::~list_t() { num_elements = 0; free(array); }

template<typename T>
inline size_t list_t<T>::size() const
{
    return num_elements;
}

template<typename T>
inline bool list_t<T>::empty() const
{
    if (num_elements == 0) {
        return true;
    }
    else {
        return false;
    }
}

#endif