#ifndef _STACK_H_
#define _STACK_H_

#include <cstdlib>
#include "stack-def.h"

template <typename T>
inline stack_t<T>::stack_t() :
    array(0),
    array_size(0) {
}

template<typename T>
inline stack_t<T>::stack_t(const stack_t<T>& v)
{
    array_size = v.array_size;
    array = (T*)calloc(array_size, sizeof(T));
    for (size_t i = 0; i < array_size; i++)
    {
        array[i] = v.array[i];
    }
}

template<typename T>
inline stack_t<T>::~stack_t() { array_size = 0; free(array); }


template<typename T>
size_t stack_t<T>::size() const
{
    return array_size;
}

template<typename T>
inline bool stack_t<T>::empty() const
{
    if (array_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline T& stack_t<T>::top() const
{
    return array[array_size - 1];
}

template<typename T>
inline void stack_t<T>::push(const T& v)
{
    array_size++;
    T* newArray = (T*)calloc(array_size, sizeof(T));
    for (size_t i = 0; i < (array_size - 1); i++)
    {
        newArray[i] = array[i];
    }
    newArray[array_size - 1] = v;
    free(array);
    array = newArray;
    newArray = NULL;
}

template<typename T>
inline void stack_t<T>::pop()
{
    if (array_size >= 1) {
        array_size--;
        array[array_size] = static_cast<T>("");
    }
    else {
        throw "error!!!";
    }
}

#endif