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
inline map_element<K, V>::map_element() :
    left(0),
    right(0),
    key(0),
    value("") {
}

template<typename K, typename V>
inline void map_element<K, V>::operator=(const V d)
{
    this->value = d;
}

template <typename K, typename V>
inline map_t<K, V>::map_t() :
    num_elements(0) {
    head = new map_element<K, V>;
    head->left = head;
}

template <typename K, typename V>
inline map_t<K, V>::~map_t() { num_elements = 0; free(head); }

template <typename K, typename V>
inline void map_t<K, V>::operator=(const map_t<K, V>& v)
{
    num_elements = v.num_elements;
    head->value = v.head->value;
    map_element<K, V>* tmp = v.head->right;
    map_element<K, V>* ntmp = head;
    while (tmp->right != NULL) {
        map_element<K, V>* newElement = new map_element<K, V>;
        ntmp->right = newElement;
        newElement->value = tmp->value;
        tmp = tmp->right;
        ntmp = ntmp->right;
    }
    map_element<K, V>* newElement = new map_element<K, V>;
    ntmp->right = newElement;
    newElement->value = tmp->value;
}

template<typename K, typename V>
inline map_element<K, V>* map_t<K, V>::operator[](K s) const
{
    for (map_t<K, V>::iterator i = this->begin(); i != this->end(); i++) {
        if (i.first == s) {
            return i.ptr;
        }
    }

    num_elements++;
    if (num_elements == 0) {
        head->key = s;
        return head;
    }
    else {
        map_element<K, V>* newElement = new map_element<K, V>;
        head->left = newElement;
        newElement->right = head;
        head = newElement;
        newElement->left = head;
        newElement->key = s;
        //this->sort();
        return newElement;
    }
}

template <typename K, typename V>
inline iterator_m<K, V> map_t<K, V>::begin() const
{
    iterator_m<K, V> iter;
    iter.ptr = head;
    return iter;
}

template <typename K, typename V>
inline iterator_m<K, V> map_t<K, V>::end() const
{
    iterator_m<K, V> iter;
    iter.ptr = NULL;
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
    for (map_t<K, V>::iterator it = this->begin(); it != this->end(); it++) {
        if (*it == d) {
            if (it.ptr->right == NULL) {
                it.ptr->left->right = NULL;
            }
            else {
                it.ptr->left->right = it.ptr->right;
                it.ptr->right->left = it.ptr->left;
            }
        }
    }
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
    while (head->right != NULL) {
        head = head->right;
        delete(head->left);
    }
    head->value = "";
}

template <typename K, typename V>
inline void map_t<K, V>::sort()
{
    K tmp;
    for (map_t<K, V>::iterator i = this->begin(); i != this->end(); i++) {
        for (map_t<K, V>::iterator j = (this->begin())++; j != this->end(); j++) {
            if ((*i) < (*j)) {
                tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
}

#endif
