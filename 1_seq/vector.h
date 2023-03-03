#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstdlib>
#include "vector-def.h"

template<typename T>
inline iterator_t<T>::iterator_t() :
    ptr(0) {
}

template<typename T>
inline iterator_t<T>::iterator_t(const iterator_t<T>& it)
{

}

template<typename T>
inline iterator_t<T>::~iterator_t() { free(ptr); }

template <typename T>
inline vector_t<T>::vector_t() :
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
inline iterator_t<T> vector_t<T>::begin() const
{
    return array;
}

template<typename T>
inline iterator_t<T> vector_t<T>::end() const
{
    return array;
}

template<typename T>
size_t vector_t<T>::size() const
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
        T *newArray = (T*)malloc(s * sizeof(T));

        for (size_t i = 0; i < num_elements; i++)
        {
            newArray[i] = array[i];
        }
        free(array);
        array = newArray;
        newArray = NULL;
    }
}

template<typename T>
inline T& vector_t<T>::operator[](size_t s) const
{
    return array[s];
}

template<typename T>
inline void vector_t<T>::push_back(const T& v)
{
    num_elements++;
    if (array_size < num_elements) {
        array_size = num_elements;
        T *newArray = (T*)malloc(num_elements * sizeof(T));
        for (size_t i = 0; i < (num_elements - 1); i++)
        {
            newArray[i] = array[i];
        }
        newArray[num_elements - 1] = v;
        free(array);
        array = newArray;
        newArray = NULL;
    }
    else {
        array[num_elements - 1] = v;
    }
}

template<typename T>
inline void vector_t<T>::pop_back()
{
    if (num_elements >= 1) {
        num_elements--;
        array[num_elements] = static_cast<T>("");
    }
    else {
        throw "error!!!";
    }
}



#endif