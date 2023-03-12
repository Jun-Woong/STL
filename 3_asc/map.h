#ifndef _MAP_H_
#define _MAP_H_

#include <cstdlib>
#include "map-def.h"
#include <iostream>

// your answer

template <typename K, typename V>
inline iterator_m<K, V>::iterator_m() :
    ptr(0) {
}

template <typename K, typename V>
inline iterator_m<K, V>::iterator_m(const iterator_m<K, V>& it)
{
}

template <typename K, typename V>
inline iterator_m<K, V>::~iterator_m() { }

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

template<typename K, typename V>
inline K& iterator_m<K, V>::first() const
{
    return ptr->key;
}

template<typename K, typename V>
inline V& iterator_m<K, V>::second() const
{
    return ptr->value;
}

template <typename K, typename V>
inline map_element<K, V>::map_element() :
    left(0),
    right(0),
    key(0),
    value("") {
}

template <typename K, typename V>
inline map_t<K, V>::map_t() :
    num_elements(0) {
    head = new map_element<K, V>;
    head->left = head;
}

template <typename K, typename V>
inline map_t<K, V>::~map_t() { num_elements = 0; free(head); }


template<typename K, typename V>
inline void map_t<K, V>::operator=(const map_t<K, V>& v)
{
    num_elements = v.num_elements;
    head->key = v.head->key;
    head->value = v.head->value;
    map_element<K, V>* tmp = v.head->right;
    map_element<K, V>* ntmp = head;
    while (tmp->right != NULL) {
        map_element<K, V>* newElement = new map_element<K, V>;
        ntmp->right = newElement;
        newElement->key = tmp->key;
        newElement->value = tmp->value;
        newElement->left = ntmp;
        tmp = tmp->right;
        ntmp = ntmp->right;
    }
    map_element<K, V>* newElement = new map_element<K, V>;
    ntmp->right = newElement;
    newElement->key = tmp->key;
    newElement->value = tmp->value;
    newElement->left = ntmp;
}

template<typename K, typename V>
inline V& map_t<K, V>::operator[](K s)
{
    if (num_elements == 0) {
        num_elements++;
        head->key = s;
        return head->value;
    }
    else {
        map_t<K, V>::iterator it;
        for (it = this->begin(); it != this->end(); it++) {
            if (it.ptr->key == s) {
                return it.ptr->value;
            }
        }

        num_elements++;
        map_element<K, V>* newElement = new map_element<K, V>;
        newElement->key = s;
        map_element<K, V>* last = head;
        while (last->right != NULL) {
            last = last->right;
        }
        last->right = newElement;
        newElement->left = last;
        return newElement->value;
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

template<typename K, typename V>
inline void map_t<K, V>::erase(const iterator& pos)
{
    map_t<K, V>::iterator it;
    for (it = this->begin(); it != this->end(); it++) {
        if (it.ptr == pos.ptr) {
            if (it.ptr->right == NULL) {
                it.ptr->left->right = NULL;
            }
            else {
                it.ptr->left->right = it.ptr->right;
                it.ptr->right->left = it.ptr->left;
                it.ptr->value = "";
            }
            break;
        }
    }
}

template <typename K, typename V>
inline void map_t<K, V>::erase(const K& d)
{
    for (map_t<K, V>::iterator it = this->begin(); it != this->end(); it++) {
        if (it.ptr->key == d) {
            if (it.ptr->right == NULL) {
                it.ptr->left->right = NULL;
            }
            else {
                it.ptr->left->right = it.ptr->right;
                it.ptr->right->left = it.ptr->left;
                it.ptr->value = "";
            }
            break;
        }
    }
}

template <typename K, typename V>
inline iterator_m<K, V> map_t<K, V>::find(const K& d)
{
    iterator_m<K, V> iter;
    for (iterator_m<K, V> it = this->begin(); it != this->end(); it++) {
        if (it.ptr->key == d) {
            iter.ptr = it.ptr;
            return iter;
        }
    }
    return iter;
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
    K tmp1;
    V tmp2;
    for (map_t<K, V>::iterator i = this->begin(); i != this->end(); i++) {
        for (map_t<K, V>::iterator j = (this->begin())++; j != this->end(); j++) {
            if ((i.ptr->key) < (j.ptr->key)) {
                tmp1 = i.ptr->key;
                tmp2 = i.ptr->value;
                i.ptr->key = j.ptr->key;
                i.ptr->value = j.ptr->value;
                j.ptr->key = tmp1;
                j.ptr->value = tmp2;
            }
        }
    }
}

#endif