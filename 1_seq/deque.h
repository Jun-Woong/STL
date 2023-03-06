#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <cstdlib>
#include "deque-def.h"
#include "vector.h"

// your answer

template <typename T>
inline deque_t<T>::deque_t() :
    array(0),
    num_elements(0) {
}

template<typename T>
inline deque_t<T>::deque_t(const deque_t<T>& v)
{
    num_elements = v.num_elements;
    array = (T*)calloc(num_elements, sizeof(T));
    for (size_t i = 0; i < num_elements; i++)
    {
        array[i] = v.array[i];
    }
}

template<typename T>
inline deque_t<T>::~deque_t()
{
   num_elements = 0; free(array);
}

template<typename T>
inline iterator_t<T> deque_t<T>::begin() const
{
    iterator_t<T> iter;
    iter.ptr = array;
    return iter;
}

template<typename T>
inline iterator_t<T> deque_t<T>::end() const
{
    iterator_t<T> iter;
    iter.ptr = array + num_elements;
    return iter;
}

template<typename T>
inline size_t deque_t<T>::size() const
{
    return num_elements;
}

template<typename T>
inline bool deque_t<T>::empty() const
{
    if (num_elements == 0) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline T& deque_t<T>::operator[](size_t s) const
{
    return array[s];
}

template<typename T>
inline iterator_t<T> deque_t<T>::insert(const iterator& pos, const T& d)
{
    num_elements++;
    T* newArray = (T*)calloc(num_elements, sizeof(T));
    size_t index = 0;
    for (size_t i = 0; i < (num_elements); i++)
    {
        if (pos.ptr == (array + i)) {
            newArray[i] = d;
        }
        else {
            newArray[i] = array[index++];
        }
    }
    free(array);
    array = newArray;
    newArray = NULL;
    return pos;
}

template<typename T>
inline iterator_t<T> deque_t<T>::erase(const iterator pos)
{
    for (size_t i = 0; i < (num_elements); i++)
    {
        if (pos.ptr == (array + i)) {
            array[i] = static_cast<T>("");
            for (size_t j = i; j < num_elements - 1; j++)
            {
                array[j] = array[j + 1];
            }
            break;
        }
    }
    num_elements--;
    return pos;
}

template<typename T>
inline void deque_t<T>::push_back(const T& d)
{
    num_elements++;
    T* newArray = (T*)calloc(num_elements, sizeof(T));
    for (size_t i = 0; i < (num_elements - 1); i++)
    {
        newArray[i] = array[i];
    }
    newArray[num_elements - 1] = d;
    free(array);
    array = newArray;
    newArray = NULL;
}

template<typename T>
inline void deque_t<T>::pop_back()
{
    if (num_elements >= 1) {
        num_elements--;
        array[num_elements] = static_cast<T>("");
    }
    else {
        throw "error!!!";
    }
}

template<typename T>
inline void deque_t<T>::push_front(const T& d)
{
    num_elements++;
    T* newArray = (T*)calloc(num_elements, sizeof(T));
    for (size_t i = 1; i < (num_elements); i++)
    {
       newArray[i] = array[i - 1];
    }
    newArray[0] = d;
    free(array);
    array = newArray;
    newArray = NULL;
}

template<typename T>
inline void deque_t<T>::pop_front()
{
    if (num_elements >= 1) {
        num_elements--;
        T* newArray = (T*)calloc(num_elements, sizeof(T));
        for (size_t i = 1; i <= (num_elements); i++)
        {
            newArray[i-1] = array[i];
        }
        free(array);
        array = newArray;
        newArray = NULL;
    }
    else {
        throw "error!!!";
    }
}

#endif