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
    // copy
    // array = new T[s]();
}

template<typename T>
inline vector_t<T>::~vector_t() { free(array); }


template<typename T>
inline size_t vector_t<T>::size() const
{
    return num_elements;
}

template<typename T>
inline bool vector_t<T>::empty() const
{
    if (num_elements == 0) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline size_t vector_t<T>::capacity() const
{
    return array_size;
}

template<typename T>
inline void vector_t<T>::reserve(size_t s)
{
    if (array_size < s) {
        array_size = s;
        T* newArray; 
        newArray = (T*)malloc(s * sizeof(T));
        //
        //for (size_t i = 0; i < array_size; i++)
        //{
        //    newArray[i] = array[i];
        //}
        //free(array);
        //array = newArray;
        //newArray = NULL;
    }
}

#endif