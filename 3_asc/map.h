#ifndef _MAP_H_
#define _MAP_H_

#include <cstdlib>
#include "map-def.h"
#include <iostream>

// your answer

template <typename K, typename V>
inline iterator_m<K, V>::iterator_m() :
    ptr(0),
    first(0),
    second("") {
}

template <typename K, typename V>
inline iterator_m<K, V>::iterator_m(const iterator_m<K, V>& it)
{
}

template <typename K, typename V>
inline iterator_m<K, V>::~iterator_m() { }

template <typename K, typename V>
inline K& iterator_m<K, V>::operator*() const
{
    return ptr->value;
}

template <typename K, typename V>
inline iterator_m<K, V> iterator_m<K, V>::operator++(int)
{
    iterator_m<K, V> iter;
    iter.ptr = ptr; // Postfix Operator
    ptr = ptr->right;
    return iter;
}

template <typename K, typename V>
inline iterator_m<K, V> iterator_m<K, V>::operator++()
{
    iterator_m<K, V> iter;
    ptr = ptr->right;
    iter.ptr = ptr; // Prefix Operator
    return iter;
}

template <typename K, typename V>
inline iterator_m<K, V> iterator_m<K, V>::operator+(int s)
{
    iterator_m<K, V> iter;
    return iter;
}

template <typename K, typename V>
inline iterator_m<K, V> iterator_m<K, V>::operator--()
{
    iterator_m<K, V> iter;
    return iter;
}

template <typename K, typename V>
inline iterator_m<K, V> iterator_m<K, V>::operator-(int s)
{
    iterator_m<K, V> iter;
    return iter;
}

template <typename K, typename V>
inline bool iterator_m<K, V>::operator!=(const iterator_m<K, V>& it) const
{
    if (it.ptr == ptr) {
        return false;
    }
    else {
        return true;
    }
}

template <typename K, typename V>
inline bool iterator_m<K, V>::operator==(const iterator_m<K, V>& it) const
{
    if (it.ptr == ptr) {
        return true;
    }
    else {
        return false;
    }
}

template <typename K, typename V>
inline map_t<K, V>::map_t() :
    array(0),
    num_elements(0) {
    arrayCheck = (V*)calloc(5, sizeof(V));
}

template <typename K, typename V>
inline map_t<K, V>::~map_t() { num_elements = 0; free(array); }

template <typename K, typename V>
inline void map_t<K, V>::operator=(const map_t<K, V>& v)
{
    num_elements = v.num_elements;
    free(array);
    array = (V*)calloc(num_elements, sizeof(V));
    for (size_t i = 0; i < num_elements; i++)
    {
        array[i] = v.array[i];
    }
}

template<typename K, typename V>
inline V& map_t<K, V>::operator[](K s) const
{
    if (arrayCheck[s] == "") {
        this.push_back(s);
    }
    return array[s];
}

template<typename K, typename V>
inline void map_t<K, V>::push_back(const V& v)
{
    num_elements++;
    V* newArray = (V*)calloc(num_elements, sizeof(V));
    for (size_t i = 0; i < (num_elements - 1); i++)
    {
        newArray[i] = array[i];
    }
    newArray[num_elements - 1] = v;
    free(array);
    array = newArray;
    newArray = NULL;
}

template <typename K, typename V>
inline iterator_m<K, V> map_t<K, V>::begin() const
{
    iterator_m<K, V> iter;
    iter.ptr = array;
    return iter;
}

template <typename K, typename V>
inline iterator_m<K, V> map_t<K, V>::end() const
{
    iterator_m<K, V> iter;
    iter.ptr = array + num_elements;
    return iter;
}

template <typename K, typename V>
inline size_t map_t<K, V>::size() const
{
    return num_elements;
}

template <typename K, typename V>
inline bool map_t<K, V>::empty() const
{
    if (num_elements == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename K, typename V>
inline void map_t<K, V>::erase(const K& d)
{
    array[d] = "";
    for (size_t j = d; j < num_elements - 1; j++)
    {
        array[j] = array[j + 1];
    }
    num_elements--;
}

template <typename K, typename V>
inline iterator_m<K, V> map_t<K, V>::find(const K& d)
{
    map_t<K, V>::iterator it;
    for (it = this->begin(); it != this->end(); it++) {
        if (*it == d) {
            return it;
        }
    }
    return it;
}

template <typename K, typename V> 
inline void map_t<K, V>::clear()
{
    num_elements = 0;
    free(array);
    array = (V*)calloc(1, sizeof(K));
}

template <typename K, typename V>
inline void map_t<K, V>::sort()
{
    K tmp1;
    V tmp2;
    for (map_t<K, V>::iterator i = this->begin(); i != this->end(); i++) {
        for (map_t<K, V>::iterator j = (this->begin())++; j != this->end(); j++) {
            if ((i.first) < (j.first)) {
                tmp1 = i.first;
                tmp2 = i.second;
                i.first = j.first;
                i.second = j.second;
                j.first = tmp1;
                j.second = tmp2;
            }
        }
    }
}

#endif
