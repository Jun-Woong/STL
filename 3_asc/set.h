#ifndef _SET_H_
#define _SET_H_

#include <cstdlib>
#include "set-def.h"
#include <iostream>

// your answer

template<typename T>
inline iterator_s<T>::iterator_s() :
    first(0),
    second(0) {
}

template<typename T>
inline iterator_s<T>::iterator_s(const iterator_s<T>& it)
{
}

template<typename T>
inline iterator_s<T>::~iterator_s() { }

template<typename T>
inline T& iterator_s<T>::operator*() const
{
    return first->value;
}

template<typename T>
inline iterator_s<T> iterator_s<T>::operator++(int)
{
    iterator_s<T> iter;
    iter.first = first; // Postfix Operator
    first = first->right;
    return iter;
}

template<typename T>
inline iterator_s<T> iterator_s<T>::operator++()
{
    iterator_s<T> iter;
    first = first->right;
    iter.first = first; // Prefix Operator
    return iter;
}

template<typename T>
inline iterator_s<T> iterator_s<T>::operator+(int s)
{
    iterator_s<T> iter;
    return iter;
}

template<typename T>
inline iterator_s<T> iterator_s<T>::operator--()
{
    iterator_s<T> iter;
    return iter;
}

template<typename T>
inline iterator_s<T> iterator_s<T>::operator-(int s)
{
    iterator_s<T> iter;
    return iter;
}

template<typename T>
inline bool iterator_s<T>::operator!=(const iterator_s<T>& it) const
{
    if (it.first == first) {
        return false;
    }
    else {
        return true;
    }
}

template<typename T>
inline bool iterator_s<T>::operator==(const iterator_s<T>& it) const
{
    if (it.first == first) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline set_element<T>::set_element() :
    left(0),
    right(0),
    value("") {
}

template<typename T>
inline set_t<T>::set_t() :
    num_elements(0) {
    head = new set_element<T>;
    head->left = head;
}

template<typename T>
inline set_t<T>::set_t(const set_t<T>& v)
{
    num_elements = v.num_elements;
    head = new set_element<T>;
    head->left = head;
    head->value = v.head->value;

    set_element<T>* tmp = v.head->right;
    set_element<T>* ntmp = head;
    while (tmp->right != NULL) {
        set_element<T>* newElement = new set_element<T>;
        ntmp->right = newElement;
        newElement->value = tmp->value;
        tmp = tmp->right;
        ntmp = ntmp->right;
    }
    set_element<T>* newElement = new set_element<T>;
    ntmp->right = newElement;
    newElement->value = tmp->value;
}

template<typename T>
inline set_t<T>::~set_t() { num_elements = 0; free(head); }

template<typename T>
inline void set_t<T>::operator=(const set_t<T>& v)
{
    num_elements = v.num_elements;
    head->value = v.head->value;
    set_element<T>* tmp = v.head->right;
    set_element<T>* ntmp = head;
    while (tmp->right != NULL) {
        set_element<T>* newElement = new set_element<T>;
        ntmp->right = newElement;
        newElement->value = tmp->value;
        tmp = tmp->right;
        ntmp = ntmp->right;
    }
    set_element<T>* newElement = new set_element<T>;
    ntmp->right = newElement;
    newElement->value = tmp->value;
}

template<typename T>
inline iterator_s<T> set_t<T>::begin() const
{
    iterator_s<T> iter;
    iter.first = head;
    return iter;
}

template<typename T>
inline iterator_s<T> set_t<T>::end() const
{
    iterator_s<T> iter;
    iter.first = NULL;
    return iter;
}

template<typename T>
inline size_t set_t<T>::size() const
{
    return num_elements;
}

template<typename T>
inline bool set_t<T>::empty() const
{
    if (num_elements == 0) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline iterator_s<T> set_t<T>::insert(const T& d)
{
    set_t<T>::iterator it;
    bool check = true;
    for (it = this->begin(); it != this->end(); it++) {
        if (*it == d) {
            check = false;
            break;
        }
    }

    if (check) {
        if (num_elements == 0) {
            head->value = d;
        }
        else {
            set_element<T>* newElement = new set_element<T>;
            head->left = newElement;
            newElement->right = head;
            head = newElement;
            newElement->left = head;
            newElement->value = d;
        }
        num_elements++;
        this->sort();
    }
    it.second = check;
    return it;
}

template<typename T>
inline void set_t<T>::erase(const T& d)
{
    for (set_t<T>::iterator it = this->begin(); it != this->end(); it++) {
        if (*it == d) {
            if (it.first->right == NULL) {
                it.first->left->right = NULL;
            }
            else {
                it.first->left->right = it.first->right;
                it.first->right->left = it.first->left;
            }
        }
    }
}

template<typename T>
inline iterator_s<T> set_t<T>::find(const T& d)
{
    set_t<T>::iterator it;
    for (it = this->begin(); it != this->end(); it++) {
        if (*it == d) {
            return it;
        }
    }
    return it;
}

template<typename T>
inline void set_t<T>::clear()
{
    num_elements = 0;
    while (head->right != NULL) {
        head = head->right;
        delete(head->left);
    }
    head->value = "";
}

template<typename T>
inline void set_t<T>::sort()
{
    T tmp;
    for (set_t<T>::iterator i = this->begin(); i != this->end(); i++) {
        for (set_t<T>::iterator j = (this->begin())++; j != this->end(); j++) {
            if ((*i) < (*j)) {
                tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
}

template<typename T>
inline bool set_t<T>::count(const T& d)
{
    for (set_t<T>::iterator it = this->begin(); it != this->end(); it++) {
        std::cout << "BBBBBB" << *it << "CCCCCCC" << d << "\n";
        if (*it == d) {
            return true;
        }
    }
    return false;
}

#endif