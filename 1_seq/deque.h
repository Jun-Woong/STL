#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <cstdlib>
#include "deque-def.h"

// your answer

template <typename T>
inline deque_t<T>::deque_t() :
    array(0),
    num_elements(0) {
    cout << "create!!!!" << endl;
}

template<typename T>
inline deque_t<T>::deque_t(const deque_t<T>& v)
{
    num_elements = v.num_elements;
    array = (T*)malloc(num_elements * sizeof(T));
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
inline void deque_t<T>::push_back(const T& d)
{
    num_elements++;
    T* newArray = (T*)malloc(num_elements * sizeof(T));
    cout << " !!!! " << endl;
    for (size_t i = 0; i < (num_elements - 1); i++)
    {
        cout << i << endl;
        cout << array[i] << endl;
        cout << num_elements << endl;
        newArray[i] = array[i];
    }
    cout << " @@@@ " << endl;
    newArray[num_elements - 1] = d;
    cout << " #### " << endl;
    free(array);
    array = newArray;
    newArray = NULL;
}

template<typename T>
inline void deque_t<T>::push_front(const T& d)
{
    num_elements++;
    T* newArray = (T*)malloc(num_elements * sizeof(T));
    for (size_t i = 1; i < (num_elements); i++)
    {
       newArray[i] = array[i - 1];
    }
    newArray[0] = d;
    free(array);
    array = newArray;
    newArray = NULL;
}

#endif