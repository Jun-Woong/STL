#ifndef _LIST_H_
#define _LIST_H_

#include <cstdlib>
#include "list-def.h"
#include <iostream>

using namespace std;

// your answer

template<typename T>
inline iterator_l<T>::iterator_l() :
    ptr(0) {
}

template<typename T>
inline iterator_l<T>::iterator_l(const iterator_l<T>& it)
{
}

template<typename T>
inline iterator_l<T>::~iterator_l() { }

template<typename T>
inline T& iterator_l<T>::operator*() const
{
    return ptr->value;
}

template<typename T>
inline iterator_l<T> iterator_l<T>::operator++(int)
{
    iterator_l<T> iter;
    cout << " location " << ptr << endl;
    ptr = ptr->right;
    iter.ptr = ptr;
    return iter;
}

template<typename T>
inline iterator_l<T> iterator_l<T>::operator+(int s)
{
    iterator_l<T> iter;
    return iter;
}

template<typename T>
inline iterator_l<T> iterator_l<T>::operator--()
{
    iterator_l<T> iter;
    return iter;
}

template<typename T>
inline iterator_l<T> iterator_l<T>::operator-(int s)
{
    iterator_l<T> iter;
    return iter;
}

template<typename T>
inline bool iterator_l<T>::operator!=(const iterator_l<T>& it) const
{
    if (it.ptr == ptr) {
        return false;
    }
    else {
        return true;
    }
}

template<typename T>
inline bool iterator_l<T>::operator==(const iterator_l<T>& it) const
{
    if (it.ptr == ptr) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline list_element<T>::list_element() :
left(0),
right(0),
value("") {
}

template<typename T>
inline list_t<T>::list_t() :
num_elements(0) {
    head = new list_element<T>;
    head[0].left = head;
}

template<typename T>
inline list_t<T>::list_t(const list_t<T>& v)
{
}

template<typename T>
inline list_t<T>::~list_t() { num_elements = 0; free(head); }

template<typename T>
inline iterator_l<T> list_t<T>::begin() const
{
    iterator_l<T> iter;
    iter.ptr = head;
    return iter;
}

template<typename T>
inline iterator_l<T> list_t<T>::end() const
{
    iterator_l<T> iter;
    iter.ptr = NULL;
    return iter;
}

template<typename T>
inline size_t list_t<T>::size() const
{
    return num_elements;
}

template<typename T>
inline bool list_t<T>::empty() const
{
    if (num_elements == 0) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
inline iterator_l<T> list_t<T>::insert(const iterator& pos, const T& d)
{
    cout << "KKKKKKK" << pos.ptr << endl;
    num_elements++;
    list_element<T>* newElement = new list_element<T>;
    newElement->value = d;
    if (pos.ptr == head) {
        head[0].left = newElement;
        newElement->right = head;
        head = newElement;
        newElement->left = head;
    }
    else {

        pos.ptr->left->right = newElement;
        newElement->right = pos.ptr;
        pos.ptr->left = newElement;
    }
    return pos;
}

template<typename T>
inline iterator_l<T> list_t<T>::erase(const iterator& pos)
{
    num_elements--;
    cout << "CCCCCCCCCCCCCC" << pos.ptr << endl;
    if (pos.ptr == head) {
        cout << "AAAAAA" << endl;
        pos.ptr->right->left = pos.ptr->right;
        head = pos.ptr->right;
    }
    else {
        cout << " VVVVVVV " << pos.ptr << endl;

        pos.ptr->left->right = pos.ptr->right;
        cout << "VVVVVVV" << endl;
        pos.ptr->right->left = pos.ptr->left;
    }
    cout << "VVVVVVV" << endl;
    pos.ptr->left = NULL;
    pos.ptr->right = NULL;
    pos.ptr->value = "";

    return pos;
}

template<typename T>
inline void list_t<T>::push_back(const T& d)
{
    if (num_elements == 0) {
        head[0].value = d;
    }
    else {
        list_element<T>* newElement = new list_element<T>;
        head[num_elements - 1].right = newElement;
        newElement->left = &(head[num_elements - 1]);
        newElement->value = d;
    }
    num_elements++;
}

template<typename T>
inline void list_t<T>::push_front(const T& d)
{
    if (num_elements == 0) {
        head[0].value = d;
    }
    else {
        list_element<T>* newElement = new list_element<T>;
        head[0].left = newElement;
        newElement->right = head;
        head = newElement;
        newElement->left = head;
        newElement->value = d;
    }
    num_elements++;
}

#endif