#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <cstdlib>
#include "queue-def.h"

template <typename T>
inline queue_t<T>::queue_t() :
    array(0),
    array_size(0) {
}

template<typename T>
inline queue_t<T>::queue_t(const queue_t<T>& v)
{
    array_size = v.array_size;
    array = (T*)calloc(array_size, sizeof(T));
    for (size_t i = 0; i < array_size; i++)
    {
        array[i] = v.array[i];
    }
}

template<typename T>
inline queue_t<T>::~queue_t() { array_size = 0; free(array); }


template<typename T>
size_t queue_t<T>::size() const
{
    return array_size;
}

template<typename T>
inline bool queue_t<T>::empty() const
{
    if (array_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline T& queue_t<T>::back() const
{
    return array[array_size - 1];
}

template<typename T>
inline void queue_t<T>::push(const T& v)
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
inline void queue_t<T>::pop()
{
    if (array_size >= 1) {
        array_size--;
        T* newArray = (T*)calloc(array_size, sizeof(T));
        for (size_t i = 1; i <= (array_size); i++)
        {
            newArray[i - 1] = array[i];
        }
        free(array);
        array = newArray;
        newArray = NULL;
    }
    else {
        throw "error!!!";
    }

}

template<typename T>
inline void queue_t<T>::swap(queue_t<T>& v)
{
    T* tmp_array = v.array;
    size_t tmp_array_size = v.array_size;

    v.array = array;
    v.array_size = array_size;

    array = tmp_array;
    array_size = tmp_array_size;
}

#endif