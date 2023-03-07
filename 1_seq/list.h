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
    return *ptr;
}

template<typename T>
inline iterator_l<T> iterator_l<T>::operator++(int)
{
    ptr = ptr + 1;
    iterator_l<T> iter;
    iter.ptr = ptr;
    return iter;
}

template<typename T>
inline iterator_l<T> iterator_l<T>::operator+(int s)
{
    ptr = ptr + s;
    iterator_l<T> iter;
    iter.ptr = ptr;
    return iter;
}

template<typename T>
inline iterator_l<T> iterator_l<T>::operator--()
{
    ptr = ptr - 1;
    iterator_l<T> iter;
    iter.ptr = ptr;
    return iter;
}

template<typename T>
inline iterator_l<T> iterator_l<T>::operator-(int s)
{
    ptr = ptr - s;
    iterator_l<T> iter;
    iter.ptr = ptr;
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
    iter.ptr = &(head[0].value);
    cout << " begin header : " << head << " left : " << head[0].left << " right : " << head[0].right << endl;
    cout << " next left : " << (head[0].right->left) << " right : " << (head[0].right->right) << " value : " << (head[0].right->value) << endl;
    return iter;
}

template<typename T>
inline iterator_l<T> list_t<T>::end() const
{
    //list_element<T> *tmp = head[0].right;
    //while (tmp->right != NULL) {
    //    tmp = tmp->right;
    //}
    iterator_l<T> iter;
    //iter.ptr = &(tmp->value);
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