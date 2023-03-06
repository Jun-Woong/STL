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
num_elements(0) {
    array = (list_element<T>*)calloc(1, sizeof(list_element<T>));
    array[0].left = array;
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

template<typename T>
inline void list_t<T>::push_back(const T& d)
{
    if (num_elements == 0) {
        array[0].value = d;
    }
    else {
        list_element<T> ne;
        array[num_elements - 1].right = ne.left;
        ne.value = d;
    }
    num_elements++;
}

template<typename T>
inline void list_t<T>::push_front(const T& d)
{
}

#endif